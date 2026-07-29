
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08031cfc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  _DAT_40005400 = _DAT_40005400 & 0xfffe;
  FUN_08031858(10);
  local_20 = 0xc0;
  local_1c = 0x1000301;
  FUN_0802e4e8(0x40020400,&local_20);
  _DAT_40020414 = _DAT_40020414 & 0xffffff7f | 0x40;
  cVar3 = '\n';
  do {
    FUN_08031858(10);
    _DAT_40020414 = _DAT_40020414 | 0x80;
    FUN_08031858(10);
    cVar3 = cVar3 + -1;
    _DAT_40020414 = _DAT_40020414 & 0xffffff7f;
  } while (cVar3 != '\0');
  FUN_08031858(10);
  _DAT_40020414 = _DAT_40020414 | 0x80;
  FUN_08031858(1000);
  uVar1 = local_1c;
  local_1c = CONCAT31(local_1c._1_3_,2);
  uVar2 = local_1c;
  local_1c._3_1_ = SUB41(uVar1,3);
  local_1c._0_3_ = CONCAT12(1,(short)uVar2);
  FUN_0802e4e8(0x40020400,&local_20);
  _DAT_40005400 = ~((ushort)~(ushort)(((uint)_DAT_40005400 << 0x11) >> 0x10) >> 1);
  FUN_08031858(1000);
  _DAT_40005400 = (ushort)(((uint)_DAT_40005400 << 0x11) >> 0x11);
  FUN_0802e5ac(&DAT_40005400);
  local_14 = 0x4000;
  local_20 = 100000;
  local_1c = 0xbfff0000;
  local_18 = 0x4000000;
  FUN_0802e61c(&DAT_40005400,&local_20);
  FUN_0802e784(&DAT_40005400,1);
  FUN_0802e700(&DAT_40005400,1);
  FUN_08031858(10);
  FUN_08037970(s_i2c_reseted_0803d110);
  return;
}

