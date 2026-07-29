
void FUN_080226f8(float param_1,int param_2)

{
  float fVar1;
  
  if (0.0 < *(float *)(param_2 + 0x2c)) {
    if (100.0 < param_1) {
      param_1 = 100.0;
    }
    if (param_1 < 5.0) {
      param_1 = 5.0;
    }
    fVar1 = 380000.0 / (param_1 * *(float *)(param_2 + 0x2c));
    if (-1 < (int)((uint)(fVar1 < 1000.0) << 0x1f)) {
      fVar1 = 1000.0;
    }
    if (fVar1 < 1.0) {
      fVar1 = 1.0;
    }
    *(float *)(param_2 + 0x24) = fVar1;
    return;
  }
  *(undefined4 *)(param_2 + 0x24) = 0x41733333;
  return;
}

