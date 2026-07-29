
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080301b0(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)_DAT_40015400;
  *param_1 = 1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = &DAT_40015400;
  param_1[4] = &LAB_08030144_1;
  if ((int)(uVar1 << 0x19) < 0) {
    do {
    } while (-1 < (int)((uint)_DAT_40015408 << 0x1e));
    do {
    } while (-1 < (int)((uint)_DAT_40015408 << 0x1e));
    _DAT_4001540c = 0;
    do {
    } while (-1 < (int)((uint)_DAT_40015408 << 0x1e));
    _DAT_40021814 = _DAT_40021814 & 0xffffefff;
    *param_1 = 0;
    param_1[2] = 0;
  }
  return;
}

