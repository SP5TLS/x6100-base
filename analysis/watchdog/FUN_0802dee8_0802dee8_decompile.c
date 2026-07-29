
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802dee8(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  iVar2 = 1 << (bVar1 & 0x1f);
  if (param_1[3] != 0) {
    uVar3 = (~_DAT_e000ed0c & 0x7ff) >> 8;
    *(char *)(bVar1 + 0xe000e400) =
         (char)(((uint)param_1[2] & 0xf >> uVar3 | (uint)param_1[1] << (4 - uVar3 & 0xff) & 0xff) <<
               4);
    *(int *)((uint)(bVar1 >> 5) * 4 + -0x1fff1f00) = iVar2;
    return;
  }
  *(int *)(((bVar1 >> 5) + 0x20) * 4 + -0x1fff1f00) = iVar2;
  return;
}

