
void FUN_08023e88(undefined4 param_1)

{
  uint in_fpscr;
  
  DAT_200082e8 = (float)VectorUnsignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  DAT_200082dc = DAT_200082e8 * 6.283185e-05;
  return;
}

