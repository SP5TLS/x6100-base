
void FUN_08024318(undefined4 param_1)

{
  uint uVar1;
  byte bVar2;
  uint in_fpscr;
  float fVar3;
  
  uVar1 = in_fpscr & 0xfffffff | (uint)(DAT_20008318 == 0.0) << 0x1e |
          (uint)(0.0 <= DAT_20008318) << 0x1d;
  bVar2 = (byte)(uVar1 >> 0x18);
  if (!(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6)) {
    DAT_20008310 = 15.2;
  }
  else {
    fVar3 = (float)VectorUnsignedToFloat(param_1,(byte)(uVar1 >> 0x16) & 3);
    if (100.0 < fVar3) {
      fVar3 = 100.0;
    }
    if (fVar3 < 5.0) {
      fVar3 = 5.0;
    }
    fVar3 = 380000.0 / (fVar3 * DAT_20008318);
    DAT_20008310 = 1000.0;
    if ((int)((uint)(fVar3 < 1000.0) << 0x1f) < 0) {
      DAT_20008310 = fVar3;
    }
    if (DAT_20008310 < 1.0) {
      DAT_20008310 = 1.0;
    }
  }
  return;
}

