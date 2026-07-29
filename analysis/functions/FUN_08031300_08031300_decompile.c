
void FUN_08031300(uint param_1,int param_2)

{
  if (param_2 != 0) {
    DAT_2000c6d8 = DAT_2000c6d8 | param_1;
    return;
  }
  DAT_2000c6d8 = DAT_2000c6d8 & ~param_1;
  return;
}

