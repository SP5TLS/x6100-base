
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802d878(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  
  cVar2 = DAT_2000011d;
  DAT_200000d4 = (DAT_200000d4 + 1) % 5000;
  if (DAT_200000d4 != 0) {
    return;
  }
  if (DAT_2000011d == '\0') {
    iVar3 = FUN_08031e1c(0x6c,0,&DAT_2000bf90,0x200);
    if (iVar3 == 0) {
      fVar7 = (float)VectorUnsignedToFloat((uint)DAT_2000c144,(byte)(in_fpscr >> 0x16) & 3);
      fVar4 = (float)VectorUnsignedToFloat((uint)DAT_2000bf9c,(byte)(in_fpscr >> 0x16) & 3);
      fVar5 = (float)VectorSignedToFloat((int)DAT_2000bfa6,(byte)(in_fpscr >> 0x16) & 3);
      DAT_20000110 = fVar4 * 0.0039;
      DAT_200000f4 = fVar7 * 1.25;
      DAT_20000114 = fVar5 * 0.15625;
      DAT_20000118 = VectorSignedFixedToFloat((int)DAT_2000bfa0,0x20,8);
      DAT_2000011e = '\x01';
    }
    else {
      DAT_2000011e = cVar2;
      DAT_200000dc = DAT_200000dc + 1;
      DAT_20000118 = 0;
      DAT_200000f4 = 0.0;
      DAT_20000110 = 0.0;
      DAT_20000114 = 0.0;
    }
    DAT_2000011d = 1;
    return;
  }
  if (DAT_2000011d != '\x01') {
    DAT_2000011d = 0;
    return;
  }
  iVar3 = DAT_200000d8 + 1;
  DAT_200000d8 = iVar3 % 0x14;
  if (DAT_200000d8 != 0) {
    return;
  }
  uVar6 = VectorFloatToUnsigned(DAT_20000110,3);
  FUN_0803395c(uVar6 & 0xff,iVar3 * 0x66666667);
  uVar1 = FUN_08030808(0);
  fVar7 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  DAT_200000f0 = fVar7 * 4.835165;
  if (DAT_2000003e == '\0') {
    if (DAT_20000045 != '\0') {
      (*DAT_2000c6c8)(0);
      FUN_08030140(&DAT_200002ac,0);
      _DAT_40021414 = _DAT_40021414 & 0xffffefff;
    }
    _DAT_20000044 = 0;
  }
  else {
    if (DAT_2000011c != '\0') {
      if (DAT_20000110 < 98.0) {
        cVar2 = DAT_20000045;
        if ((-1 < (int)((uint)(DAT_20000110 < 90.0) << 0x1f)) || (DAT_20000045 != '\0'))
        goto LAB_0802d9a2;
      }
      else {
        if (DAT_20000045 != '\0') {
          _DAT_20000044 = 3;
        }
        if (-1 < (int)((uint)(DAT_20000110 < 90.0) << 0x1f)) goto LAB_0802d9a0;
      }
      (*DAT_2000c6c8)(1);
      FUN_08030140(&DAT_200002ac,1);
      _DAT_40021414 = _DAT_40021414 | 0x1000;
      _DAT_20000044 = 0x102;
      cVar2 = '\x01';
      goto LAB_0802d9a2;
    }
    if (DAT_20000045 != '\0') {
      (*DAT_2000c6c8)(0);
      FUN_08030140(&DAT_200002ac,0);
      _DAT_40021414 = _DAT_40021414 & 0xffffefff;
    }
    _DAT_20000044 = 1;
  }
LAB_0802d9a0:
  cVar2 = '\0';
LAB_0802d9a2:
  FUN_08033974(0x10,cVar2);
  if (DAT_2000011c == '\0') {
    if (DAT_200000f4 < DAT_200000f0 + 500.0) {
      DAT_2000011c = '\x01';
    }
  }
  else if (DAT_200000f0 < DAT_200000f4 + 500.0) {
    DAT_2000011c = '\0';
  }
  DAT_2000011d = 0;
  return;
}

