
void FUN_0802adf4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  
  FUN_08033974(4,0);
  FUN_08023ee4(4);
  FUN_08024010(0x40a00000);
  FUN_08023d78(1);
  FUN_0802d7cc(0x10,1);
  FUN_0802aaf4(&DAT_20000024,DAT_20000168,1);
  FUN_080349e4(100);
  FUN_0802a1b8();
  FUN_080349e4(500);
  FUN_08023ee4(*(uint *)(DAT_20000140 + 0x10) & 0xff);
  FUN_08031300(1,0);
  fVar4 = (float)VectorUnsignedToFloat((uint)DAT_2000002e,(byte)(in_fpscr >> 0x16) & 3);
  FUN_08024010(fVar4 * 0.1);
  FUN_0802d7cc(0x10,0);
  FUN_0802aaf4(&DAT_20000024,DAT_20000168,0);
  FUN_08023d78(0);
  uVar1 = FUN_0802a008();
  uVar2 = FUN_08029ff0();
  uVar3 = FUN_08029ffc();
  FUN_0803394c(uVar1,uVar2,uVar3);
  FUN_080349e4(100);
  FUN_08033974(4,1);
  do {
    FUN_080349e4(100);
  } while ((*(uint *)(DAT_20000138 + 0x30) & 0x2000) != 0);
  return;
}

