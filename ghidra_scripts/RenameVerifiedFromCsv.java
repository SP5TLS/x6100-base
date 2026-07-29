// Apply only explicitly VERIFIED function renames from a CSV file.
// @category X6100

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class RenameVerifiedFromCsv extends GhidraScript {
	private static class Rename {
		Address address;
		String currentName;
		String newName;
		boolean create;

		Rename(Address address, String currentName, String newName, boolean create) {
			this.address = address;
			this.currentName = currentName;
			this.newName = newName;
			this.create = create;
		}
	}

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		if (args.length != 1) {
			throw new IllegalArgumentException(
				"usage: RenameVerifiedFromCsv.java <renames.csv>");
		}

		List<Rename> renames = readAndValidate(new File(args[0]));
		for (Rename rename : renames) {
			Function function = getFunctionAt(rename.address);
			if (rename.create) {
				if (currentProgram.getListing().getInstructionAt(rename.address) == null) {
					disassemble(rename.address);
				}
				function = createFunction(rename.address, rename.newName);
				if (function == null) {
					throw new IllegalStateException(
						"could not create function at " + rename.address);
				}
				println(rename.address + ": <missing> -> " + rename.newName);
				continue;
			}
			if (function.getName().equals(rename.newName)) {
				continue;
			}
			function.setName(rename.newName, SourceType.USER_DEFINED);
			println(rename.address + ": " + rename.currentName + " -> " + rename.newName);
		}
	}

	private List<Rename> readAndValidate(File input) throws Exception {
		List<Rename> renames = new ArrayList<>();
		try (BufferedReader reader = new BufferedReader(new FileReader(input))) {
			String header = reader.readLine();
			if (!"address,current_name,new_name,confidence,evidence".equals(header)) {
				throw new IllegalArgumentException("unexpected CSV header");
			}

			String line;
			int lineNumber = 1;
			while ((line = reader.readLine()) != null) {
				lineNumber++;
				if (line.isBlank()) {
					continue;
				}
				String[] fields = line.split(",", 5);
				if (fields.length != 5 || !"VERIFIED".equals(fields[3])) {
					throw new IllegalArgumentException(
						"line " + lineNumber + " is not an explicit VERIFIED rename");
				}

				Address address = toAddr(fields[0]);
				Function function = getFunctionAt(address);
				boolean create = false;
				if (function == null) {
					if (getFunctionContaining(address) != null) {
						throw new IllegalArgumentException(
							"address " + address + " lies inside another function");
					}
					if (!currentProgram.getMemory().contains(address)) {
						throw new IllegalArgumentException(
							"address is outside loaded memory at " + address +
							" on line " + lineNumber);
					}
					create = true;
				}
				if (!create && !function.getName().equals(fields[1]) &&
						!function.getName().equals(fields[2])) {
					throw new IllegalArgumentException(
						"name mismatch at " + address + ": expected " + fields[1] +
						" or " + fields[2] + ", found " + function.getName());
				}

				for (Symbol collision :
						currentProgram.getSymbolTable().getGlobalSymbols(fields[2])) {
					if (collision.getAddress().compareTo(address) != 0) {
						throw new IllegalArgumentException(
							"target name already exists at " + collision.getAddress());
					}
				}
				renames.add(new Rename(address, fields[1], fields[2], create));
			}
		}
		return renames;
	}
}
