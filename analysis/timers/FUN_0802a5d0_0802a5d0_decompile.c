
void FUN_0802a5d0(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_08037e20(*(undefined4 *)(param_1 + 0x114),0,0xe0);
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 4) = 9400000;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x10) = 6;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xc) = 1;
  **(undefined4 **)(param_1 + 0x114) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x1c) = 0x6b2998;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x28) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x20) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x24) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x18) = 0;
  param_1[9] = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x30) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xd8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x114) + 0xdc) = 0;
  FUN_08037e20(*(undefined4 *)(param_1 + 0x11c),0,0x18);
  FUN_08037e20(*(undefined4 *)(param_1 + 0x110),0,8);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  *param_1 = 1;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[2] = 0;
  param_1[0x1c] = 0;
  param_1[0x4e] = 0;
  param_1[0x50] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[2] = 0;
  param_1[0x36] = 0;
  param_1[0x2c] = 0;
  param_1[0x38] = 0;
  param_1[0x3b] = 0;
  param_1[0x45] = 0;
  param_1[0x4c] = 10;
  param_1[0x4d] = 10;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0x41066666;
  *(undefined4 *)(param_1 + 0xe4) = 0x44e10000;
  *(undefined4 *)(param_1 + 0xec) = 0x42c80000;
  param_1[0xf8] = 0;
  FUN_080244b4();
  FUN_08023f20(0);
  FUN_0802d148(0x40021000,0x1000,1);
  (*DAT_2000c6cc)(0);
  FUN_0802d148(0x40021000,0x100,0);
  FUN_0802d148(0x40021800,0x800,0);
  FUN_0802d148(0x40021000,0x200,1);
  FUN_0803062c(&DAT_20000334,0,0);
  FUN_0803062c(&DAT_20000334,1,0);
  FUN_0802efa8(&DAT_40000400,1,1);
  FUN_0802ee38(&DAT_40000400,1);
  FUN_0802d148(0x40020c00,8,1);
  FUN_0802d148(0x40020c00,0x10,0);
  (*DAT_2000c6d0)(1);
  param_1[0x17] = 0;
  FUN_0802f8d0(0);
  iVar1 = FUN_0802c7c8(&DAT_2000e984,0,1);
  if (iVar1 == 0) {
    param_1[0x21] = 0;
  }
  else {
    param_1[0x21] = 1;
  }
  FUN_0802cf88(0xe);
  uVar2 = FUN_0803147c();
  if (1 < uVar2) {
    FUN_0802d15c();
    FUN_080349e4(10);
    FUN_0802d310(0x1b,0xd2);
    FUN_0802d310(0x1c,0xf);
    FUN_0802d310(0x1e,0);
  }
  return;
}

