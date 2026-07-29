
uint FUN_08030808(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 3) {
    uVar1 = VectorFloatToUnsigned((&DAT_2000c688)[param_1],3);
    return uVar1 & 0xffff;
  }
  return 0;
}

