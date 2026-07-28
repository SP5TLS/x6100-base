// Export consecutive initialized 32-bit words without modifying symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;

public class ExportDataWords extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 3) {
			throw new IllegalArgumentException(
				"usage: ExportDataWords.java <output.csv> <address> <word-count>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		Address start = toAddr(args[1]);
		int count = Integer.decode(args[2]);
		Memory memory = currentProgram.getMemory();

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("address,value_le\n");
			for (int i = 0; i < count; i++) {
				Address address = start.add((long)i * 4);
				int value = memory.getInt(address, false);
				writer.write(String.format("%s,%08x%n", address, value));
			}
		}
	}
}
