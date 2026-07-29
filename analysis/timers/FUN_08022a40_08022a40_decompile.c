
void FUN_08022a40(undefined4 *param_1,undefined4 param_2)

{
  *(undefined1 *)(param_1 + 0x28) = 4;
  *(undefined1 *)(param_1 + 0x76) = 0;
  param_1[0x29] = param_1 + 0x2b;
  param_1[0x2a] = param_1 + 0x4f;
  *(undefined2 *)((int)param_1 + 0xa2) = 0x24;
  FUN_08034a6c(param_1 + 0x77,4);
  FUN_08034a6c(param_1 + 0x4f,0x27);
  FUN_08034aa8(param_2,param_1 + 0x2b,0x24);
  param_1[7] = 0xbf4d8a5b;
  param_1[0xc] = 0x3f4d8a5b;
  param_1[5] = 0x3ffeaf20;
  param_1[8] = 0xbefdf5f9;
  param_1[10] = 0xbffeaf20;
  param_1[0xd] = 0xbefdf5f9;
  param_1[4] = 0x3f800000;
  param_1[6] = 0x3f800000;
  param_1[9] = 0x3f800000;
  param_1[0xb] = 0x3f800000;
  param_1[0xe] = 0x3f800000;
  param_1[0xf] = 0x3ff8eec2;
  param_1[0x10] = 0x3f800000;
  param_1[0x11] = 0xbfc24e67;
  param_1[0x12] = 0xbf61b5d5;
  param_1[0x13] = 0x3f800000;
  param_1[0x14] = 0xbff8eec2;
  param_1[0x15] = 0x3f800000;
  param_1[0x16] = 0x3fc24e67;
  param_1[0x17] = 0xbf61b5d5;
  param_1[3] = 0x3f800000;
  FUN_08034a6c(0,param_1 + 0x18,0x10);
  *param_1 = 2;
  param_1[1] = param_1 + 0x18;
  param_1[2] = param_1 + 4;
  FUN_08034a6c(0,param_1 + 0x7c,0x32);
  *(undefined2 *)((int)param_1 + 0x2c5) = 0;
  param_1[0x7b] = 0;
  param_1[0xb0] = 0;
  param_1[0xb5] = 0x3f800000;
  param_1[0xae] = 0x31;
  param_1[0xaf] = 0;
  param_1[0xb3] = 0x40000000;
  param_1[0xb4] = 0x42480000;
  return;
}

