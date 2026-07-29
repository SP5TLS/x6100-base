
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080312bc(int param_1)

{
  if (param_1 != 0) {
    _DAT_40020c14 = _DAT_40020c14 | 0x4000;
    return;
  }
  _DAT_40020c14 = _DAT_40020c14 & 0xffffbfff;
  return;
}

