
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08030144(int *param_1)

{
  int iVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)param_1[3];
  if (-1 < (int)((uint)*puVar2 << 0x19)) {
    return;
  }
  iVar1 = param_1[1];
  if ((*param_1 == 0) && (param_1[2] == iVar1)) {
    *param_1 = 0;
    param_1[2] = iVar1;
    return;
  }
  puVar2[6] = (ushort)((uint)iVar1 >> 0x10);
  do {
  } while (-1 < (int)((uint)puVar2[4] << 0x1e));
  puVar2[6] = (ushort)((uint)iVar1 >> 8);
  do {
  } while (-1 < (int)((uint)puVar2[4] << 0x1e));
  puVar2[6] = (ushort)iVar1;
  do {
  } while (-1 < (int)((uint)puVar2[4] << 0x1e));
  _DAT_40021814 = _DAT_40021814 & 0xffffefff;
  *param_1 = 0;
  param_1[2] = iVar1;
  return;
}

