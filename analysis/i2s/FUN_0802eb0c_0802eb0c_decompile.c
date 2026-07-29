
void FUN_0802eb0c(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = param_2[1];
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xf040;
  uVar4 = (uint)*param_2;
  bVar5 = uVar4 != 0x200;
  if (bVar5) {
    uVar4 = LZCOUNT(uVar4);
  }
  uVar2 = param_2[2];
  *(undefined2 *)(param_1 + 0x20) = 2;
  if (bVar5) {
    uVar4 = uVar4 >> 5;
  }
  if (bVar5) {
    uVar3 = (ushort)(uVar4 << 8);
  }
  else {
    uVar3 = 0x100;
  }
  *(ushort *)(param_1 + 0x1c) =
       uVar3 | uVar1 | uVar2 | param_2[6] | *(ushort *)(param_1 + 0x1c) | 0x800;
  return;
}

