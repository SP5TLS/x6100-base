
void FUN_0802a1b8(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  
  DAT_20000008 = 0xffffffff;
  DAT_20000004 = 0xffffffff;
  DAT_2000c6e4 = DAT_2000c6e4 & 0xffffff80;
  DAT_20000010 = 2;
  DAT_2000000c = 0;
  (*DAT_2000c6f0)(&DAT_2000c6e0);
  FUN_080349e4(10);
  if (DAT_20000008 != 0) {
    DAT_20000008 = 0;
    DAT_2000c6e4 = DAT_2000c6e4 & 0xffd03fff;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  FUN_080349e4(10);
  if (DAT_20000004 != 0) {
    DAT_2000c6e4 = DAT_2000c6e4 & 0xffefffff;
    DAT_20000004 = 0;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  FUN_080349e4(500);
  FUN_08028e48(&DAT_2000bf88);
  fVar5 = (float)VectorUnsignedToFloat(DAT_2000bf88,(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = in_fpscr & 0xfffffff | (uint)(fVar5 < 20.0) << 0x1f | (uint)(fVar5 == 20.0) << 0x1e;
  uVar4 = uVar2 | (uint)NAN(fVar5) << 0x1c;
  bVar1 = (byte)(uVar2 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar4 >> 0x1c) & 1)) {
    FUN_0802993c(&DAT_2000bf88);
  }
  FUN_080290e0(&DAT_2000bf88);
  if (DAT_2000bf8d != DAT_2000000c) {
    uVar2 = (uint)(DAT_2000bf8d & DAT_20000000);
    if ((int)(uVar2 << 0x1f) < 0) {
      uVar3 = DAT_2000c6e4 | 1;
    }
    else {
      uVar3 = DAT_2000c6e4 & 0xfffffffe;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      uVar3 = uVar3 | 2;
    }
    else {
      uVar3 = uVar3 & 0xfffffffd;
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      uVar3 = uVar3 | 4;
    }
    else {
      uVar3 = uVar3 & 0xfffffffb;
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      uVar3 = uVar3 | 8;
    }
    else {
      uVar3 = uVar3 & 0xfffffff7;
    }
    if ((int)(uVar2 << 0x1b) < 0) {
      uVar3 = uVar3 | 0x10;
    }
    else {
      uVar3 = uVar3 & 0xffffffef;
    }
    if ((int)(uVar2 << 0x1a) < 0) {
      uVar3 = uVar3 | 0x20;
    }
    else {
      uVar3 = uVar3 & 0xffffffdf;
    }
    if ((int)(uVar2 << 0x19) < 0) {
      DAT_2000c6e4 = uVar3 | 0x40;
    }
    else {
      DAT_2000c6e4 = uVar3 & 0xffffffbf;
    }
    DAT_2000000c = (uint)DAT_2000bf8d;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  if (DAT_2000bf8c != DAT_20000008) {
    uVar2 = (uint)(DAT_2000bf8c & DAT_20000001);
    if ((int)(uVar2 << 0x1f) < 0) {
      uVar3 = DAT_2000c6e4 | 0x200000;
    }
    else {
      uVar3 = DAT_2000c6e4 & 0xffdfffff;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      uVar3 = uVar3 | 0x10000;
    }
    else {
      uVar3 = uVar3 & 0xfffeffff;
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      uVar3 = uVar3 | 0x8000;
    }
    else {
      uVar3 = uVar3 & 0xffff7fff;
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      uVar3 = uVar3 | 0x4000;
    }
    else {
      uVar3 = uVar3 & 0xffffbfff;
    }
    if ((int)(uVar2 << 0x1b) < 0) {
      uVar3 = uVar3 | 0x20000;
    }
    else {
      uVar3 = uVar3 & 0xfffdffff;
    }
    if ((int)(uVar2 << 0x1a) < 0) {
      uVar3 = uVar3 | 0x40000;
    }
    else {
      uVar3 = uVar3 & 0xfffbffff;
    }
    if ((int)(uVar2 << 0x19) < 0) {
      DAT_2000c6e4 = uVar3 | 0x80000;
    }
    else {
      DAT_2000c6e4 = uVar3 & 0xfff7ffff;
    }
    DAT_20000008 = (uint)DAT_2000bf8c;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  uVar2 = (uint)DAT_2000bf8e;
  if (uVar2 != DAT_20000004) {
    if (uVar2 == 0) {
      DAT_2000c6e4 = DAT_2000c6e4 & 0xffefffff;
    }
    else {
      DAT_2000c6e4 = DAT_2000c6e4 | 0x100000;
    }
    DAT_20000004 = uVar2;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  fVar5 = (float)VectorUnsignedToFloat(DAT_2000bf88,(byte)(uVar4 >> 0x16) & 3);
  if (30.0 < fVar5) {
    DAT_20000010 = 3;
  }
  else {
    DAT_20000010 = 1;
  }
  return;
}

