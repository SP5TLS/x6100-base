
void FUN_08023ebc(undefined4 param_1)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorUnsignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  DAT_200082e4 = fVar1 * 0.003125;
  return;
}

