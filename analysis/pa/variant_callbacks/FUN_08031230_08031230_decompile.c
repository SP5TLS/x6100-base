
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08031230(int param_1)

{
  if (param_1 != 0) {
    _DAT_40020c14 = _DAT_40020c14 | 0x8000;
    return;
  }
  _DAT_40020c14 = _DAT_40020c14 & 0xffff7fff;
  return;
}

