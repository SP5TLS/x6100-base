// Export the program's direct call graph without renaming symbols.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;

public class ExportCallGraph extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException("usage: ExportCallGraph.java <output.csv>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write("caller_address,caller,call_site,callee_address,callee\n");
			FunctionIterator functions =
				currentProgram.getFunctionManager().getFunctions(true);
			while (functions.hasNext()) {
				Function caller = functions.next();
				InstructionIterator instructions =
					currentProgram.getListing().getInstructions(caller.getBody(), true);
				while (instructions.hasNext()) {
					Instruction instruction = instructions.next();
					for (Reference reference : instruction.getReferencesFrom()) {
						if (!reference.getReferenceType().isCall()) {
							continue;
						}
						Address target = reference.getToAddress();
						Function callee = getFunctionAt(target);
						writer.write(caller.getEntryPoint() + "," +
							caller.getName() + "," +
							instruction.getAddress() + "," +
							target + "," +
							(callee == null ? "" : callee.getName()) + "\n");
					}
				}
			}
		}
	}
}
