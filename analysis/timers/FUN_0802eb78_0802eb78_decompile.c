
void FUN_0802eb78(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  
  if (param_1 == (undefined1 *)0x40010000) {
    FUN_0802e970(1);
    FUN_0802e970(1,0,extraout_r2_00,param_4);
    return;
  }
  if (param_1 == (undefined1 *)0x40000000) {
    FUN_0802e954(1);
    FUN_0802e954(1,0,extraout_r2_01,param_4);
    return;
  }
  if (param_1 == &DAT_40000400) {
    FUN_0802e954(2,1);
    FUN_0802e954(2,0,extraout_r2_02,param_4);
    return;
  }
  if (param_1 == &DAT_40000800) {
    FUN_0802e954(4,1);
    FUN_0802e954(4,0,extraout_r2,param_4);
    return;
  }
  if (param_1 == (undefined1 *)0x40000c00) {
    FUN_0802e954(8,1);
    FUN_0802e954(8,0,extraout_r2_03,param_4);
    return;
  }
  if (param_1 == (undefined1 *)0x40001000) {
    FUN_0802e954(0x10,1);
    FUN_0802e954(0x10,0,extraout_r2_04,param_4);
    return;
  }
  if (param_1 == (undefined1 *)0x40001400) {
    FUN_0802e954(0x20,1);
    FUN_0802e954(0x20,0,extraout_r2_05,param_4);
    return;
  }
  if (param_1 != (undefined1 *)0x40010400) {
    if (param_1 == (undefined1 *)0x40014000) {
      FUN_0802e970(0x10000,1);
      FUN_0802e970(0x10000,0,extraout_r2_06,param_4);
      return;
    }
    if (param_1 == (undefined1 *)0x40014400) {
      FUN_0802e970(0x20000,1);
      FUN_0802e970(0x20000,0,extraout_r2_08,param_4);
      return;
    }
    if (param_1 == (undefined1 *)0x40014800) {
      FUN_0802e970(0x40000,1);
      FUN_0802e970(0x40000,0,extraout_r2_09,param_4);
      return;
    }
    if (param_1 != (undefined1 *)0x40001800) {
      if (param_1 == (undefined1 *)0x40001c00) {
        FUN_0802e954(0x80,1);
        FUN_0802e954(0x80,0,extraout_r2_11,param_4);
        return;
      }
      if (param_1 != (undefined1 *)0x40002000) {
        return;
      }
      FUN_0802e954(0x100,1);
      FUN_0802e954(0x100,0,extraout_r2_12,param_4);
      return;
    }
    FUN_0802e954(0x40,1);
    FUN_0802e954(0x40,0,extraout_r2_10,param_4);
    return;
  }
  FUN_0802e970(2,1);
  FUN_0802e970(2,0,extraout_r2_07,param_4);
  return;
}

