
void FUN_08033974(uint param_1,int param_2)

{
  if (param_2 != 0) {
    DAT_20001420 = DAT_20001420 | param_1;
    return;
  }
  DAT_20001420 = DAT_20001420 & ~param_1;
  return;
}

