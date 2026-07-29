
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802db2c(void)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  float fVar9;
  undefined4 uVar10;
  uint uVar11;
  
  iVar1 = FUN_0802efc4(&DAT_40000400,1);
  if (iVar1 != 1) {
    return;
  }
  FUN_0802efdc(&DAT_40000400,1);
  bVar2 = ((uint)DAT_20000174 & *(uint *)(DAT_20000170 + 0x10)) == 0;
  if (DAT_20000180 == '\0') {
    if ((bool)DAT_20000181 != bVar2) {
      DAT_20000180 = '\x01';
      DAT_2000017c = DAT_20000178;
    }
  }
  else if (DAT_20000180 == '\x01') {
    if (DAT_2000017c == 0) {
      DAT_20000180 = '\0';
      DAT_20000182 = bVar2;
    }
    else {
      if ((bool)DAT_20000181 != bVar2) goto LAB_0802db84;
      DAT_2000017c = DAT_2000017c + -1;
    }
  }
  else {
LAB_0802db84:
    DAT_20000180 = '\0';
  }
  if (DAT_20000182 == '\0') {
    DAT_20000168 = DAT_20000168 & 0xfffffffd;
  }
  else {
    DAT_20000168 = DAT_20000168 | 2;
  }
  bVar3 = ((uint)DAT_2000019c & *(uint *)(DAT_20000198 + 0x10)) == 0;
  if (DAT_200001a8 == '\0') {
    if ((bool)DAT_200001a9 != bVar3) {
      DAT_200001a4 = DAT_200001a0;
      DAT_200001a8 = '\x01';
    }
  }
  else if (DAT_200001a8 == '\x01') {
    if (DAT_200001a4 == 0) {
      DAT_200001a8 = '\0';
      DAT_200001aa = bVar3;
    }
    else {
      if ((bool)DAT_200001a9 != bVar3) goto LAB_0802dd6e;
      DAT_200001a4 = DAT_200001a4 + -1;
    }
  }
  else {
LAB_0802dd6e:
    DAT_200001a8 = '\0';
  }
  bVar4 = ((uint)DAT_200001b0 & *(uint *)(DAT_200001ac + 0x10)) == 0;
  if (DAT_200001bc == '\0') {
    if ((bool)DAT_200001bd != bVar4) {
      DAT_200001b8 = DAT_200001b4;
      DAT_200001bc = '\x01';
    }
  }
  else if (DAT_200001bc == '\x01') {
    if (DAT_200001b8 == 0) {
      DAT_200001bc = '\0';
      DAT_200001be = bVar4;
    }
    else {
      if ((bool)DAT_200001bd != bVar4) goto LAB_0802dd62;
      DAT_200001b8 = DAT_200001b8 + -1;
    }
  }
  else {
LAB_0802dd62:
    DAT_200001bc = '\0';
  }
  bVar5 = ((uint)DAT_200001ec & *(uint *)(DAT_200001e8 + 0x10)) == 0;
  if (DAT_200001f8 == '\0') {
    if ((bool)DAT_200001f9 != bVar5) {
      DAT_200001f4 = DAT_200001f0;
      DAT_200001f8 = '\x01';
    }
  }
  else if (DAT_200001f8 == '\x01') {
    if (DAT_200001f4 == 0) {
      DAT_200001f8 = '\0';
      DAT_200001fa = bVar5;
    }
    else {
      if ((bool)DAT_200001f9 != bVar5) goto LAB_0802dd44;
      DAT_200001f4 = DAT_200001f4 + -1;
    }
  }
  else {
LAB_0802dd44:
    DAT_200001f8 = '\0';
  }
  bVar6 = ((uint)DAT_200001c4 & *(uint *)(DAT_200001c0 + 0x10)) == 0;
  if (DAT_200001d0 == '\0') {
    if ((bool)DAT_200001d1 != bVar6) {
      DAT_200001cc = DAT_200001c8;
      DAT_200001d0 = '\x01';
    }
  }
  else if (DAT_200001d0 == '\x01') {
    if (DAT_200001cc == 0) {
      DAT_200001d0 = '\0';
      DAT_200001d2 = bVar6;
    }
    else {
      if ((bool)DAT_200001d1 != bVar6) goto LAB_0802dd38;
      DAT_200001cc = DAT_200001cc + -1;
    }
  }
  else {
LAB_0802dd38:
    DAT_200001d0 = '\0';
  }
  bVar7 = ((uint)DAT_200001d8 & *(uint *)(DAT_200001d4 + 0x10)) == 0;
  if (DAT_200001e4 == '\0') {
    if ((bool)DAT_200001e5 != bVar7) {
      DAT_200001e0 = DAT_200001dc;
      DAT_200001e4 = '\x01';
    }
  }
  else if (DAT_200001e4 == '\x01') {
    if (DAT_200001e0 == 0) {
      DAT_200001e4 = '\0';
      DAT_200001e6 = bVar7;
    }
    else {
      if ((bool)DAT_200001e5 != bVar7) goto LAB_0802dd50;
      DAT_200001e0 = DAT_200001e0 + -1;
    }
  }
  else {
LAB_0802dd50:
    DAT_200001e4 = '\0';
  }
  if (_DAT_40021014 << 0x1d < 0) {
    DAT_20000168 = DAT_20000168 & 0xffffff7f;
    DAT_2000016c = 10;
    goto LAB_0802dcaa;
  }
  if (DAT_2000016c != 0) {
    DAT_2000016c = DAT_2000016c + -1;
    goto LAB_0802dcaa;
  }
  bVar8 = ((uint)DAT_20000188 & *(uint *)(DAT_20000184 + 0x10)) == 0;
  if (DAT_20000194 == '\0') {
    if ((bool)DAT_20000195 != bVar8) {
      DAT_20000190 = DAT_2000018c;
      DAT_20000194 = '\x01';
    }
  }
  else if (DAT_20000194 == '\x01') {
    if (DAT_20000190 == 0) {
      DAT_20000194 = '\0';
      DAT_20000196 = bVar8;
    }
    else {
      if ((bool)DAT_20000195 != bVar8) goto LAB_0802dea2;
      DAT_20000190 = DAT_20000190 + -1;
    }
  }
  else {
LAB_0802dea2:
    DAT_20000194 = '\0';
  }
  DAT_20000195 = bVar8;
  if (DAT_20000196 == '\0') {
    DAT_20000168 = DAT_20000168 & 0xffffff7f;
  }
  else {
    DAT_20000168 = DAT_20000168 | 0x80;
  }
LAB_0802dcaa:
  DAT_20000181 = bVar2;
  DAT_200001a9 = bVar3;
  DAT_200001bd = bVar4;
  DAT_200001d1 = bVar6;
  DAT_200001e5 = bVar7;
  DAT_200001f9 = bVar5;
  fVar9 = (float)FUN_0802442c();
  uVar11 = UnsignedSaturate((int)(fVar9 * 10.0),8);
  UnsignedDoesSaturate((int)(fVar9 * 10.0),8);
  FUN_08033910(uVar11 & 0xff);
  fVar9 = (float)FUN_08024454();
  uVar11 = UnsignedSaturate((int)(fVar9 * 10.0),8);
  UnsignedDoesSaturate((int)(fVar9 * 10.0),8);
  FUN_0803391c(uVar11 & 0xff);
  uVar10 = FUN_08024440();
  uVar11 = VectorFloatToUnsigned(uVar10,3);
  FUN_08033928(uVar11 & 0xff);
  if ((_DAT_40021810 & 0x10) == 0) {
    if (DAT_200000a0 < 2000) {
      DAT_200000a0 = DAT_200000a0 + 1;
    }
  }
  else if (DAT_200000a0 != 0) {
    DAT_200000a0 = DAT_200000a0 - 1;
  }
  return;
}

