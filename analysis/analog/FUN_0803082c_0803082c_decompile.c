
void FUN_0803082c(void)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar14 = (float)VectorUnsignedToFloat((uint)DAT_2000c69a,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorUnsignedToFloat((uint)DAT_2000c694,(byte)(in_fpscr >> 0x16) & 3);
  fVar8 = (float)VectorUnsignedToFloat((uint)DAT_2000c69c,(byte)(in_fpscr >> 0x16) & 3);
  fVar10 = (float)VectorUnsignedToFloat((uint)DAT_2000c698,(byte)(in_fpscr >> 0x16) & 3);
  fVar12 = (float)VectorUnsignedToFloat((uint)DAT_2000c696,(byte)(in_fpscr >> 0x16) & 3);
  fVar13 = (float)VectorUnsignedToFloat((uint)DAT_2000c69e,(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorUnsignedToFloat((uint)DAT_2000c6a0,(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorUnsignedToFloat((uint)DAT_2000c6a2,(byte)(in_fpscr >> 0x16) & 3);
  fVar15 = (float)VectorUnsignedToFloat((uint)DAT_2000c6a4,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorUnsignedToFloat((uint)DAT_2000c6a6,(byte)(in_fpscr >> 0x16) & 3);
  fVar4 = (float)VectorUnsignedToFloat((uint)DAT_2000c6a8,(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = (float)VectorUnsignedToFloat((uint)DAT_2000c6aa,(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = (float)VectorUnsignedToFloat((uint)DAT_2000c6ac,(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorUnsignedToFloat((uint)DAT_2000c6ae,(byte)(in_fpscr >> 0x16) & 3);
  fVar9 = (float)VectorUnsignedToFloat((uint)DAT_2000c6b0,(byte)(in_fpscr >> 0x16) & 3);
  DAT_2000c688 = DAT_2000c688 * 0.92 + (fVar6 + fVar3 + fVar1 + fVar11 + fVar14) * 0.016;
  DAT_2000c68c = DAT_2000c68c * 0.92 + (fVar7 + fVar4 + fVar2 + fVar12 + fVar8) * 0.016;
  DAT_2000c690 = DAT_2000c690 * 0.92 + (fVar9 + fVar5 + fVar15 + fVar13 + fVar10) * 0.016;
  return;
}

