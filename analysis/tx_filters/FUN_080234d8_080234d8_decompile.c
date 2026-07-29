
void FUN_080234d8(undefined1 *param_1,undefined4 param_2)

{
  FUN_08034a6c(0,param_1 + 0x10c,0x47);
  FUN_08034a6c(0,param_1 + 0x22c,8);
  *(undefined4 *)(param_1 + 0x228) = 0;
  FUN_08034aa8(param_2,param_1 + 0xc,0x40);
  *param_1 = 8;
  *(undefined1 **)(param_1 + 4) = param_1 + 0xc;
  *(undefined1 **)(param_1 + 8) = param_1 + 0x10c;
  *(undefined2 *)(param_1 + 2) = 0x40;
  return;
}

