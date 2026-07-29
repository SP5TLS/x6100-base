
void FUN_08033b0e(undefined4 param_1,int param_2,int param_3,int param_4)

{
  uint unaff_r4;
  int iVar1;
  
  iVar1 = unaff_r4 - *(uint *)(param_4 + 0x50) * (unaff_r4 / *(uint *)(param_4 + 0x50));
  *(int *)(param_4 + 0x4c) = iVar1;
  *(ushort *)(param_2 + 0x10) = (ushort)*(byte *)(*(int *)(param_4 + 0x48) + iVar1);
  *(int *)(param_4 + 8) = param_3 + 1;
  *(undefined2 *)(param_4 + 0x20) = *(undefined2 *)(param_4 + 0x22);
  return;
}

