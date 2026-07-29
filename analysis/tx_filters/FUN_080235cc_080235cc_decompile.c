
void FUN_080235cc(undefined1 *param_1,undefined4 param_2)

{
  FUN_08034a6c(0,param_1 + 0x9c,0x27);
  FUN_08034a6c(0,param_1 + 0x13c,4);
  *(undefined4 *)(param_1 + 0x138) = 0;
  FUN_08034aa8(param_2,param_1 + 0xc);
  *(undefined1 **)(param_1 + 8) = param_1 + 0x9c;
  *(undefined1 **)(param_1 + 4) = param_1 + 0xc;
  *param_1 = 4;
  *(undefined2 *)(param_1 + 2) = 0x24;
  FUN_08034a6c(0,param_1 + 0x1e8,0x27);
  FUN_08034a6c(0,param_1 + 0x288,4);
  *(undefined4 *)(param_1 + 0x284) = 0;
  FUN_08034aa8(param_2,param_1 + 0x158,0x24);
  param_1[0x14c] = 4;
  *(undefined1 **)(param_1 + 0x150) = param_1 + 0x158;
  *(undefined1 **)(param_1 + 0x154) = param_1 + 0x1e8;
  *(undefined2 *)(param_1 + 0x14e) = 0x24;
  return;
}

