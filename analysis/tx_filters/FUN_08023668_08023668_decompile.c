
void FUN_08023668(undefined4 *param_1)

{
  FUN_08034a6c(0,param_1 + 0x1d,0x14);
  param_1[0x31] = 0xffffffff;
  param_1[0x32] = 0xffffffff;
  FUN_08034a6c(0,param_1 + 4,0x19);
  param_1[4] = 0x3f800000;
  param_1[3] = 0x3f800000;
  param_1[1] = param_1 + 0x1d;
  *param_1 = 5;
  param_1[2] = param_1 + 4;
  FUN_08034a6c(0,param_1 + 0x50,0x14);
  param_1[100] = 0xffffffff;
  param_1[0x65] = 0xffffffff;
  FUN_08034a6c(0,param_1 + 0x37,0x19);
  param_1[0x37] = 0x3f800000;
  param_1[0x36] = 0x3f800000;
  param_1[0x34] = param_1 + 0x50;
  param_1[0x35] = param_1 + 0x37;
  param_1[0x33] = 5;
  return;
}

