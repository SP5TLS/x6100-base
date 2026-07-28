// Add volatile memory regions that are absent from a raw binary import.
// @category X6100

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class MapSTM32F427Memory extends GhidraScript {
	@Override
	protected void run() throws Exception {
		Memory memory = currentProgram.getMemory();
		addBlock(memory, "CCMRAM", 0x10000000L, 0x10000L, true, true, false);
		addBlock(memory, "SRAM", 0x20000000L, 0x30000L, true, true, false);
	}

	private void addBlock(Memory memory, String name, long startValue, long size, boolean read,
			boolean write, boolean execute) throws Exception {
		Address start = toAddr(startValue);
		MemoryBlock existing = memory.getBlock(start);
		if (existing != null) {
			return;
		}
		MemoryBlock block = memory.createUninitializedBlock(name, start, size, false);
		block.setRead(read);
		block.setWrite(write);
		block.setExecute(execute);
	}
}
