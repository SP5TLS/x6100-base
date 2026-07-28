// Export Cortex-M vector entries and Reset_Handler evidence without renaming symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.FlowType;

public class ExportStartupEvidence extends GhidraScript {
	private static final long IMAGE_BASE = 0x08020000L;
	private static final int VECTOR_COUNT = 16 + 91; // STM32F427: core vectors plus IRQ0..IRQ90

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException("usage: ExportStartupEvidence.java <output-directory>");
		}

		File outputDirectory = new File(args[0]);
		if (!outputDirectory.isDirectory() && !outputDirectory.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + outputDirectory);
		}

		Memory memory = currentProgram.getMemory();
		Address vectorBase = toAddr(IMAGE_BASE);
		long initialMsp = readUnsignedInt(memory, vectorBase);
		long resetVector = readUnsignedInt(memory, vectorBase.add(4));
		Address resetAddress = toAddr(resetVector & ~1L);

		exportVectors(memory, vectorBase, new File(outputDirectory, "vectors.csv"));

		Function resetFunction = getFunctionAt(resetAddress);
		if (resetFunction == null) {
			disassemble(resetAddress);
			resetFunction = createFunction(resetAddress, null);
		}
		if (resetFunction == null) {
			throw new IllegalStateException("failed to recover function at " + resetAddress);
		}

		exportDisassembly(resetFunction, new File(outputDirectory, "reset_disassembly.txt"));
		exportDecompilation(resetFunction, new File(outputDirectory, "reset_decompile.c"));
		exportDirectCallees(resetFunction, outputDirectory);

		try (BufferedWriter writer =
			new BufferedWriter(new FileWriter(new File(outputDirectory, "startup_summary.txt")))) {
			writer.write(String.format("image_base=0x%08X%n", IMAGE_BASE));
			writer.write(String.format("initial_msp=0x%08X%n", initialMsp));
			writer.write(String.format("reset_vector=0x%08X%n", resetVector));
			writer.write(String.format("reset_code_address=0x%08X%n", resetVector & ~1L));
			writer.write("reset_current_name=" + resetFunction.getName() + "\n");
			writer.write("reset_body=" + resetFunction.getBody() + "\n");
		}
	}

	private void exportDirectCallees(Function caller, File outputDirectory) throws Exception {
		InstructionIterator instructions =
			currentProgram.getListing().getInstructions(caller.getBody(), true);
		int callIndex = 0;
		while (instructions.hasNext()) {
			Instruction instruction = instructions.next();
			FlowType flowType = instruction.getFlowType();
			if (!flowType.isCall()) {
				continue;
			}
			for (Address destination : instruction.getFlows()) {
				Function callee = getFunctionAt(destination);
				if (callee == null) {
					disassemble(destination);
					callee = createFunction(destination, null);
				}
				if (callee == null) {
					continue;
				}
				callIndex++;
				String stem =
					String.format("startup_call_%d_%s", callIndex, destination.toString());
				exportDisassembly(callee, new File(outputDirectory, stem + "_disassembly.txt"));
				exportDecompilation(callee, new File(outputDirectory, stem + "_decompile.c"));
			}
		}
	}

	private long readUnsignedInt(Memory memory, Address address) throws Exception {
		return Integer.toUnsignedLong(memory.getInt(address));
	}

	private void exportVectors(Memory memory, Address base, File output) throws Exception {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("index,offset,kind,irq,value,code_address,thumb,in_image\n");
			Address imageMin = currentProgram.getMinAddress();
			Address imageMax = currentProgram.getMaxAddress();
			for (int index = 0; index < VECTOR_COUNT; index++) {
				long value = readUnsignedInt(memory, base.add(index * 4L));
				long codeValue = value & ~1L;
				boolean thumb = (value & 1L) != 0;
				Address codeAddress = toAddr(codeValue);
				boolean inImage = codeAddress.compareTo(imageMin) >= 0 &&
					codeAddress.compareTo(imageMax) <= 0;
				String kind = index == 0 ? "initial_msp" : index < 16 ? "core" : "external";
				String irq = index < 16 ? "" : Integer.toString(index - 16);
				writer.write(String.format("%d,0x%03X,%s,%s,0x%08X,0x%08X,%s,%s%n",
					index, index * 4, kind, irq, value, codeValue, thumb, inImage));
			}
		}
	}

	private void exportDisassembly(Function function, File output) throws Exception {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			InstructionIterator instructions =
				currentProgram.getListing().getInstructions(function.getBody(), true);
			while (instructions.hasNext()) {
				Instruction instruction = instructions.next();
				writer.write(instruction.getAddress() + "  " + instruction + "\n");
			}
		}
	}

	private void exportDecompilation(Function function, File output) throws Exception {
		DecompInterface decompiler = new DecompInterface();
		try {
			decompiler.openProgram(currentProgram);
			DecompileResults results = decompiler.decompileFunction(function, 60, monitor);
			try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
				if (results.decompileCompleted()) {
					writer.write(results.getDecompiledFunction().getC());
				}
				else {
					writer.write("/* Decompilation failed: " + results.getErrorMessage() + " */\n");
				}
			}
		}
		finally {
			decompiler.dispose();
		}
	}
}
