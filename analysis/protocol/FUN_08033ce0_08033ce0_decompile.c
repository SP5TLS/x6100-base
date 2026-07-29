
void FUN_08033ce0(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3;
    param_1 = param_1 - (int)param_2;
    do {
      puVar3 = param_2 + param_1;
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      (&DAT_2000e8e4)[(uint)puVar3 & 0x7f] = uVar1;
    } while (param_2 != puVar2);
    return;
  }
  return;
}

