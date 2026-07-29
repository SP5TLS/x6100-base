
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080348b0(void)

{
  uint uVar1;
  
  if ((_DAT_40023808 & 0xc) == 4) {
    uVar1 = 25000000;
  }
  else if ((_DAT_40023808 & 0xc) == 8) {
    if ((_DAT_40023804 & 0x400000) == 0) {
      uVar1 = (16000000 / (_DAT_40023804 & 0x3f)) * ((_DAT_40023804 & 0x7fff) >> 6);
    }
    else {
      uVar1 = (25000000 / (_DAT_40023804 & 0x3f)) * ((_DAT_40023804 & 0x7fff) >> 6);
    }
    uVar1 = uVar1 / ((((_DAT_40023804 & 0x3ffff) >> 0x10) + 1) * 2);
  }
  else {
    uVar1 = 16000000;
  }
  DAT_200033a4 = uVar1 >> (&DAT_0807a9c4)[(_DAT_40023808 & 0xff) >> 4];
  return;
}

