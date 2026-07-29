
undefined4 FUN_08034058(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  if (param_2 == param_1 + 1) {
    piVar4 = param_2;
    do {
      piVar5 = piVar4 + 1;
      *piVar4 = *(int *)((int)piVar4 + ((int)param_1 - (int)param_2));
      piVar4 = piVar5;
    } while (param_1 + 0xcd != piVar5);
  }
  else {
    puVar2 = param_1;
    do {
      uVar6 = puVar2[1];
      *(undefined4 *)(((int)param_2 - (int)param_1) + (int)puVar2) = *puVar2;
      puVar3 = puVar2 + 2;
      *(undefined4 *)((int)puVar2 + ((int)param_2 - (int)param_1) + 4) = uVar6;
      puVar2 = puVar3;
    } while (puVar3 != param_1 + 0xcc);
  }
  iVar1 = FUN_0802a3cc(param_2,0xcb);
  if (iVar1 != param_1[0xcb]) {
    return 0xfffffffe;
  }
  uVar6 = 0;
  if (*param_2 != -0x55aaaa56) {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}

