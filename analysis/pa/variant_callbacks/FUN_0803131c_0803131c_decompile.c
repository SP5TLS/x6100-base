
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0803131c(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  _DAT_40021014 = _DAT_40021014 | 0x4000;
  FUN_080349e4(10);
  FUN_08031fc0();
  FUN_0802ffd0(&DAT_200002ac);
  iVar1 = FUN_08030670(&DAT_20000360);
  if (iVar1 == 0) {
    DAT_2000c6bc = (undefined1 *)0x8031185;
    DAT_2000c6d0 = (code *)0x8031165;
    DAT_2000c6c8 = (code *)0x8031141;
    DAT_2000c6cc = (code *)0x8031121;
    DAT_2000c6c0 = (code *)0x8031101;
    DAT_2000c6c4 = &LAB_080310e0_1;
    DAT_2000c6d4 = (code *)0x80311a9;
  }
  else {
    FUN_0802e900(8,1);
    FUN_0802e900(0x40,1);
    local_18 = 0xee00;
    uStack_14 = 0x1000001;
    FUN_0802e4e8(0x40020c00,&local_18);
    uStack_14._0_3_ = CONCAT12(1,(undefined2)uStack_14);
    local_18 = 0xc;
    FUN_0802e4e8(0x40021800,&local_18);
    DAT_2000c6bc = &LAB_080312d8_1;
    DAT_2000c6d0 = (code *)&LAB_08031230_1;
    DAT_2000c6c8 = (code *)&LAB_080312a0_1;
    DAT_2000c6cc = (code *)&LAB_080312bc_1;
    DAT_2000c6c0 = (code *)&LAB_08031284_1;
    DAT_2000c6c4 = &LAB_08031214_1;
    DAT_2000c6d4 = (code *)0x8030af9;
  }
  (*DAT_2000c6d4)(0);
  (*DAT_2000c6c8)(0);
  FUN_08030140(&DAT_200002ac,0);
  (*DAT_2000c6cc)(0);
  (*DAT_2000c6c0)(0);
  (*DAT_2000c6d0)(0);
  FUN_0802ffc0(&DAT_200002bc,0,&local_18,1);
  if (DAT_200002ad != '\0') {
    DAT_2000c6bc = &LAB_08031268_1;
  }
  return;
}

