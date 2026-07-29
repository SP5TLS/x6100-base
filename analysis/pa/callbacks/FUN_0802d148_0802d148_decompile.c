
void FUN_0802d148(int param_1,uint param_2,int param_3)

{
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x14) = param_2 | *(uint *)(param_1 + 0x14);
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
  return;
}

