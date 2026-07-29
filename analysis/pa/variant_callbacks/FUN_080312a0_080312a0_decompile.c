
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080312a0(int param_1)

{
  if (param_1 != 0) {
    _DAT_40021414 = _DAT_40021414 | 0x1000;
    return;
  }
  _DAT_40021414 = _DAT_40021414 & 0xffffefff;
  return;
}

