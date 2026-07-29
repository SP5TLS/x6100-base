
void FUN_08030670(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 2;
  do {
    param_1[2] = (char)iVar1;
    param_1[3] = 0;
    iVar2 = iVar1 + 1;
    iVar1 = (**(code **)(param_1 + 8))(*param_1,iVar1,param_1 + 3);
    if (iVar1 != 0) break;
    iVar1 = iVar2;
  } while (iVar2 != 8);
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

