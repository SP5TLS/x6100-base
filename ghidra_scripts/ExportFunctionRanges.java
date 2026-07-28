// Export all recovered function bodies without renaming symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportFunctionRanges extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException(
				"usage: ExportFunctionRanges.java <output-csv>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("entry,body_min,body_max_exclusive,body_bytes,name\n");
			FunctionIterator functions =
				currentProgram.getFunctionManager().getFunctions(true);
			while (functions.hasNext() && !monitor.isCancelled()) {
				Function function = functions.next();
				long bodyBytes = function.getBody().getNumAddresses();
				writer.write(String.format(
					"%s,%s,%s,%d,%s%n",
					function.getEntryPoint(),
					function.getBody().getMinAddress(),
					function.getBody().getMaxAddress().add(1),
					bodyBytes,
					csv(function.getName())));
			}
		}
	}

	private String csv(String value) {
		return "\"" + value.replace("\"", "\"\"") + "\"";
	}
}
