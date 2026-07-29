
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080244b4(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined2 local_14 [2];
  undefined4 uStack_10;
  
  uStack_10 = in_r3;
  FUN_08021744();
  _DAT_40021814 = _DAT_40021814 & 0xfffffeff;
  FUN_080320fc(&DAT_200003c4);
  _DAT_40021014 = _DAT_40021014 & 0xffff7fff;
  FUN_080349e4(1);
  _DAT_40021014 = _DAT_40021014 | 0x8000;
  FUN_0802f9a4();
  FUN_080349e4(100);
  FUN_08030754();
  FUN_080322f8();
  FUN_0802f924();
  _DAT_40021814 = _DAT_40021814 | 0x100;
  iVar1 = FUN_0803022c();
  if (iVar1 == 0) {
    return;
  }
  FUN_080349e4(10);
  local_14[0] = 0x10;
  FUN_08031890(0x40005800,0x98,local_14,2,10000);
  FUN_080349e4(10);
  local_14[0] = 0xc210;
  FUN_08031890(0x40005800,0x98,local_14,2,10000);
  local_14[0] = 0x8011;
  FUN_08031890(0x40005800,0x98,local_14,2,10000);
  local_14[0] = 0x14;
  FUN_08031890(0x40005800,0x98,local_14,2,10000);
  return;
}

