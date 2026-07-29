
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08034950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0802efc4(0x40000000,1,param_3,param_4,param_4);
  if (iVar1 != 1) {
    return;
  }
  FUN_0802efdc(0x40000000,1);
  FUN_080337fc();
  FUN_0803082c();
  FUN_0803031c(0x2000c670);
  if ((uint)DAT_20000073 == (_DAT_40021410 & 0xffff) >> 0xf) {
    if (DAT_20000072 == DAT_2000003f) {
      if (0 < _DAT_20000078) {
        _DAT_20000078 = _DAT_20000078 + -1;
        return;
      }
      if (DAT_20000074 != '\0') {
        DAT_20000074 = 0;
        if ((DAT_20000073 == 0) && (DAT_20000072 != '\0')) {
          DAT_20008368 = 1;
        }
        else {
          DAT_20008368 = 0;
        }
        return;
      }
      return;
    }
  }
  else {
    DAT_20000073 = (byte)(_DAT_40021410 >> 8) >> 7;
    if (DAT_20000072 == DAT_2000003f) {
      DAT_20000074 = 1;
      _DAT_20000078 = 9;
      return;
    }
  }
  _DAT_20000078 = 9;
  DAT_20000074 = 1;
  DAT_20000072 = DAT_2000003f;
  return;
}

