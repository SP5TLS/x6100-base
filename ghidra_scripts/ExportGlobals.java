// Export non-function global symbols without modifying the program.
// @category X6100

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolType;

public class ExportGlobals extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException("usage: ExportGlobals.java <output.csv>");
		}

		File output = new File(args[0]);
		File parent = output.getParentFile();
		if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
			throw new IllegalStateException("cannot create output directory: " + parent);
		}

		Memory memory = currentProgram.getMemory();
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
			writer.write(
				"address,name,namespace,source,primary,block,initialized,data_type,length,references_to\n");
			SymbolIterator symbols = currentProgram.getSymbolTable().getAllSymbols(true);
			while (symbols.hasNext() && !monitor.isCancelled()) {
				Symbol symbol = symbols.next();
				if (symbol.getSymbolType() != SymbolType.LABEL ||
						symbol.isExternal() ||
						!symbol.getParentNamespace().isGlobal() ||
						!symbol.getAddress().isMemoryAddress()) {
					continue;
				}

				MemoryBlock block = memory.getBlock(symbol.getAddress());
				if (block == null) {
					continue;
				}

				Data data = currentProgram.getListing().getDataAt(symbol.getAddress());
				if (data == null) {
					continue;
				}
				int references = 0;
				ReferenceIterator iterator =
					currentProgram.getReferenceManager().getReferencesTo(symbol.getAddress());
				while (iterator.hasNext()) {
					iterator.next();
					references++;
				}

				writer.write(String.format(
					"%s,%s,%s,%s,%s,%s,%s,%s,%s,%d%n",
					symbol.getAddress(),
					csv(symbol.getName()),
					csv(symbol.getParentNamespace().getName(true)),
					source(symbol.getSource()),
					symbol.isPrimary(),
					csv(block.getName()),
					block.isInitialized(),
					csv(data.getDataType().getDisplayName()),
					Integer.toString(data.getLength()),
					references));
			}
		}
	}

	private String source(SourceType source) {
		return source == null ? "" : source.toString();
	}

	private String csv(String value) {
		return "\"" + value.replace("\"", "\"\"") + "\"";
	}
}
