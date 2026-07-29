
float FUN_08036370(float param_1)

{
  uint uVar1;
  float *pfVar2;
  uint in_fpscr;
  uint uVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  
  iVar5 = (int)(param_1 * DAT_080363ec);
  if (param_1 < 0.0) {
    iVar5 = iVar5 + -1;
  }
  fVar6 = (float)VectorSignedToFloat(iVar5,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  fVar6 = (param_1 * DAT_080363ec - fVar6) * DAT_080363f0;
  uVar1 = in_fpscr & 0xfffffff | (uint)(fVar6 < DAT_080363f0) << 0x1f;
  if (SUB41(uVar1 >> 0x1f,0) == (NAN(fVar6) || NAN(DAT_080363f0))) {
    fVar6 = fVar6 - DAT_080363f0;
  }
  uVar3 = VectorFloatToUnsigned(fVar6,3);
  fVar4 = (float)VectorUnsignedToFloat(uVar3 & 0x1ff,(byte)(uVar1 >> 0x16) & 3);
  pfVar2 = (float *)(DAT_080363f4 + (uVar3 & 0x1ff) * 4);
  return (1.0 - (fVar6 - fVar4)) * *pfVar2 + (fVar6 - fVar4) * pfVar2[1];
}

