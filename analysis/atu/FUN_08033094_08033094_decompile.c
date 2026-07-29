
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08033094(void)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined2 local_1c;
  
  FUN_0802e938(0x10,1);
  FUN_0802e938(0x4000,1);
  FUN_0802e900(0x400000,1);
  FUN_0802e584(0x40020000,9,7);
  FUN_0802e584(0x40020000,10,7);
  local_30 = 0x600;
  local_2c = 0x1000302;
  FUN_0802e4e8(0x40020000,&local_30);
  local_28 = 0x1c200;
  local_24 = 0;
  uStack_20 = 0xc0000;
  local_1c = 0;
  FUN_0802f024(&DAT_40011000,&local_28);
  _DAT_40011014 = _DAT_40011014 | 0xc0;
  _DAT_4001100c = _DAT_4001100c | 0x2000;
  _DAT_40026488 = 0;
  FUN_0802e214(&DAT_40026488,&DAT_20000040);
  FUN_0802e214(&DAT_40026488,&DAT_20000100);
  FUN_0802e214(&DAT_40026488,&DAT_20000200);
  FUN_0802e214(&DAT_40026488,&DAT_20000400);
  FUN_0802e214(&DAT_40026488,&DAT_20000800);
  _DAT_4002649c = 0;
  _DAT_40026494 = &DAT_2000e718;
  _DAT_40026490 = &DAT_40011004;
  _DAT_4002648c = 100;
  _DAT_40026488 = 0x8000501;
  return;
}

