
void FUN_0802eb64(int param_1,ushort param_2,int param_3)

{
  if (param_3 != 0) {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | param_2;
    return;
  }
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & ~param_2;
  return;
}

