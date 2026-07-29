
void FUN_0802a014(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = param_1[1];
  if (bVar1 != DAT_2000000c) {
    uVar2 = (uint)(DAT_20000000 & bVar1);
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
    DAT_2000000c = (uint)bVar1;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  bVar1 = *param_1;
  if (bVar1 != DAT_20000008) {
    uVar2 = (uint)(DAT_20000001 & bVar1);
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
    DAT_20000008 = (uint)bVar1;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  uVar2 = (uint)param_1[2];
  if (uVar2 == DAT_20000004) {
    return;
  }
  if (uVar2 == 0) {
    DAT_2000c6e4 = DAT_2000c6e4 & 0xffefffff;
  }
  else {
    DAT_2000c6e4 = DAT_2000c6e4 | 0x100000;
  }
  DAT_20000004 = uVar2;
                    /* WARNING: Could not recover jumptable at 0x0802a15e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_2000c6f0)(&DAT_2000c6e0);
  return;
}

