
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802e150(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0xff);
  if (param_2 != 0) {
    _DAT_40007400 = uVar1 | _DAT_40007400;
    return;
  }
  _DAT_40007400 = _DAT_40007400 & ~uVar1;
  return;
}

