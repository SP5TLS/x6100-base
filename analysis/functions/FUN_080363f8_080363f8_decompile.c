
float FUN_080363f8(float param_1)

{
  float *pfVar1;
  uint in_fpscr;
  float fVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  
  fVar2 = param_1 * DAT_0803646c + 0.25;
  iVar3 = (int)fVar2;
  if (fVar2 < 0.0) {
    iVar3 = iVar3 + -1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar3,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  fVar2 = (fVar2 - fVar4) * DAT_08036470;
  uVar5 = VectorFloatToUnsigned(fVar2,3);
  fVar4 = (float)VectorUnsignedToFloat(uVar5 & 0x1ff,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  pfVar1 = (float *)(DAT_08036474 + (uVar5 & 0x1ff) * 4);
  fVar2 = fVar2 - fVar4;
  return (1.0 - fVar2) * *pfVar1 + fVar2 * pfVar1[1];
}

