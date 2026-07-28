// Export direct callers of selected functions without renaming symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class ExportFunctionCallers extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length < 2) {
			throw new IllegalArgumentException(
				"usage: ExportFunctionCallers.java <output.csv> <function-address>...");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("target,target_function,call_site,caller\n");
			for (int i = 1; i < args.length; i++) {
				Address target = toAddr(args[i]);
				Function targetFunction = getFunctionAt(target);
				ReferenceIterator references =
					currentProgram.getReferenceManager().getReferencesTo(target);
				while (references.hasNext()) {
					Reference reference = references.next();
					if (!reference.getReferenceType().isCall()) {
						continue;
					}
					Address from = reference.getFromAddress();
					Function caller = getFunctionContaining(from);
					writer.write(target + "," +
						nameOf(targetFunction) + "," +
						from + "," +
						nameOf(caller) + "\n");
				}
			}
		}
	}

	private String nameOf(Function function) {
		return function == null ? "" : function.getName();
	}
}
