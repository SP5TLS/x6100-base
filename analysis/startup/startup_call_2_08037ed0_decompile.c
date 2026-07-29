
void FUN_08037ed0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar3 = DAT_08037f0c - (int)DAT_08037f08;
  puVar4 = DAT_08037f08;
  for (iVar5 = 0; iVar2 = DAT_08037f14, puVar1 = DAT_08037f10, iVar5 != iVar3 >> 2;
      iVar5 = iVar5 + 1) {
    (*(code *)*puVar4)();
    puVar4 = puVar4 + 1;
  }
  FUN_0803ced8();
  puVar4 = puVar1;
  for (iVar3 = 0; iVar3 != iVar2 - (int)puVar1 >> 2; iVar3 = iVar3 + 1) {
    (*(code *)*puVar4)();
    puVar4 = puVar4 + 1;
  }
  return;
}

