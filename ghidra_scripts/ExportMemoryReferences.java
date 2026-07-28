// Export direct references to a strided memory region.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportMemoryReferences extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 4) {
			throw new IllegalArgumentException(
				"usage: ExportMemoryReferences.java <output.csv> <start> <count> <stride>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		Address start = toAddr(args[1]);
		int count = Integer.decode(args[2]);
		int stride = Integer.decode(args[3]);
		ReferenceManager references = currentProgram.getReferenceManager();

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("index,target,from,type,function\n");
			for (int index = 0; index < count; index++) {
				Address target = start.add((long)index * stride);
				ReferenceIterator iterator = references.getReferencesTo(target);
				while (iterator.hasNext()) {
					Reference reference = iterator.next();
					Address from = reference.getFromAddress();
					Function function =
						currentProgram.getFunctionManager().getFunctionContaining(from);
					String functionName = function == null ? "" : function.getName();
					writer.write(String.format("%d,%s,%s,%s,%s%n", index, target, from,
						reference.getReferenceType(), functionName));
				}
			}
		}
	}
}
