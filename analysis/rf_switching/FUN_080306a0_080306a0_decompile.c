
void FUN_080306a0(int param_1,uint param_2,int param_3)

{
  if (param_3 == 1) {
    param_2 = *(uint *)(param_1 + 4) | param_2;
  }
  else {
    param_2 = *(uint *)(param_1 + 4) & ~param_2;
  }
  *(uint *)(param_1 + 4) = param_2;
  return;
}

