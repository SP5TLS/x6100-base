
void FUN_08024010(float param_1)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  
  uVar1 = in_fpscr & 0xfffffff | (uint)(param_1 < 10.0) << 0x1f;
  if (SUB41(uVar1 >> 0x1f,0) == NAN(param_1)) {
    DAT_2000b79c = 40.338257;
    param_1 = 11.0;
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(param_1 * 1000.0 + 0.001,(byte)(uVar1 >> 0x16) & 3);
    DAT_2000b79c = (fVar2 * 1.1920929e-07 + -126.942696) * 3.0103002;
  }
  if (DAT_2000b750 != param_1) {
    DAT_2000b7a8 = 0xc2200000;
    DAT_2000b7cc = 0;
    DAT_2000b7bc = 0;
    DAT_2000b7c0 = 0;
    DAT_2000b750 = param_1;
  }
  return;
}

