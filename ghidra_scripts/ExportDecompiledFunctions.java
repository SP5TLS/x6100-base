// Export selected functions through Ghidra's decompiler without renaming symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class ExportDecompiledFunctions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length < 2) {
			throw new IllegalArgumentException(
				"usage: ExportDecompiledFunctions.java <output.txt> <function-address>...");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		DecompInterface decompiler = new DecompInterface();
		if (!decompiler.openProgram(currentProgram)) {
			throw new IllegalStateException("cannot initialize decompiler");
		}

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			for (int i = 1; i < args.length; i++) {
				Address address = toAddr(args[i]);
				Function function = getFunctionAt(address);
				if (function == null) {
					writer.write("/* no function at " + address + " */\n\n");
					continue;
				}

				DecompileResults result =
					decompiler.decompileFunction(function, 120, monitor);
				writer.write("/* " + address + " " + function.getName() + " */\n");
				if (!result.decompileCompleted()) {
					writer.write("/* decompilation failed: " +
						result.getErrorMessage() + " */\n\n");
					continue;
				}
				writer.write(result.getDecompiledFunction().getC());
				writer.write("\n\n");
			}
		}
		finally {
			decompiler.dispose();
		}
	}
}
