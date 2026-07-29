
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08031480(void)

{
  uint uVar1;
  undefined4 local_10;
  
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  local_10 = 0;
  do {
    local_10 = local_10 + 1;
    if ((_DAT_40023800 & 0x20000) != 0) break;
  } while (local_10 != 0x5000);
  uVar1 = _DAT_40023800 | 0x10000;
  if ((_DAT_40023800 & 0x20000) != 0) {
    _DAT_40023840 = _DAT_40023840 | 0x10000000;
    _DAT_40007000 = _DAT_40007000 | 0xc000;
    _DAT_40023808 = _DAT_40023808 | 0x9400;
    _DAT_40023804 = 0x4403c0c;
    do {
      uVar1 = _DAT_40023800 | 0x1010000;
    } while (-1 < (int)((_DAT_40023800 | 0x1010000) << 6));
  }
  _DAT_40023800 = uVar1;
  _DAT_40023c00 = 0x705;
  do {
  } while ((_DAT_40023808 & 0xc) != 8);
  _DAT_40023808 = _DAT_40023808 & 0xfffffffc | 2;
  FUN_080348b0();
  FUN_0802e938(0x4000,1);
  FUN_0802e900(0x400000,1);
  FUN_0802e900(0x1000,1);
  return;
}

