// Export consecutive initialized IEEE-754 single-precision values.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;

public class ExportFloatArray extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 3) {
			throw new IllegalArgumentException(
				"usage: ExportFloatArray.java <output.csv> <address> <count>");
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
			writer.write("index,address,bits_le,float_value\n");
			for (int index = 0; index < count; index++) {
				Address address = start.add((long)index * 4);
				int bits = memory.getInt(address, false);
				float value = Float.intBitsToFloat(bits);
				writer.write(String.format("%d,%s,%08x,%.9g%n",
					index, address, bits, value));
			}
		}
	}
}
