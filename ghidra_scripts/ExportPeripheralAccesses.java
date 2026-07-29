// Export instruction references into MCU peripheral and core-register ranges.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.Symbol;

public class ExportPeripheralAccesses extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException(
				"usage: ExportPeripheralAccesses.java <output.csv>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write(
				"site,function,mnemonic,reference_type,target,region,target_symbol\n");
			InstructionIterator instructions =
				currentProgram.getListing().getInstructions(true);
			while (instructions.hasNext() && !monitor.isCancelled()) {
				Instruction instruction = instructions.next();
				for (Reference reference : instruction.getReferencesFrom()) {
					Address target = reference.getToAddress();
					String region = region(target);
					if (region == null || !reference.getReferenceType().isData()) {
						continue;
					}

					Function function =
						currentProgram.getFunctionManager().getFunctionContaining(
							instruction.getAddress());
					Symbol symbol =
						currentProgram.getSymbolTable().getPrimarySymbol(target);
					writer.write(String.format(
						"%s,%s,%s,%s,%s,%s,%s%n",
						instruction.getAddress(),
						csv(function == null ? "" : function.getName()),
						csv(instruction.getMnemonicString()),
						reference.getReferenceType(),
						target,
						region,
						csv(symbol == null ? "" : symbol.getName())));
				}
			}
		}
	}

	private String region(Address address) {
		long value = address.getOffset();
		if (value >= 0x40000000L && value < 0x60000000L) {
			return "STM32_PERIPHERAL";
		}
		if (value >= 0xA0000000L && value < 0xA0010000L) {
			return "STM32_EXTERNAL_CONTROL";
		}
		if (value >= 0xE0000000L && value < 0xE0100000L) {
			return "CORTEX_M_SYSTEM";
		}
		return null;
	}

	private String csv(String value) {
		return "\"" + value.replace("\"", "\"\"") + "\"";
	}
}
