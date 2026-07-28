// Export selected functions by address without renaming symbols.
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

public class ExportFunctionsByAddress extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length < 2) {
			throw new IllegalArgumentException(
				"usage: ExportFunctionsByAddress.java <output-directory> <address>...");
		}
		File outputDirectory = new File(args[0]);
		if (!outputDirectory.isDirectory() && !outputDirectory.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + outputDirectory);
		}

		for (int i = 1; i < args.length; i++) {
			Address address = toAddr(args[i]);
			Function function = getFunctionAt(address);
			if (function == null) {
				disassemble(address);
				function = createFunction(address, null);
			}
			if (function == null) {
				printerr("Unable to recover function at " + address);
				continue;
			}
			String stem = function.getName() + "_" + address;
			exportDisassembly(function, new File(outputDirectory, stem + "_disassembly.txt"));
			exportDecompilation(function, new File(outputDirectory, stem + "_decompile.c"));
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
