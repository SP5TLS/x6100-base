
int FUN_08031890(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  FUN_0802e71c(param_1,1,param_3,param_4,param_4);
  iVar1 = FUN_08031818(param_1,0x30001,param_5);
  if (iVar1 == 0) {
    FUN_0802e754(param_1,param_2,0);
    iVar2 = FUN_08031818(param_1,0x70082,param_5);
    iVar1 = iVar2;
    if ((iVar2 == 0) && (param_4 != 0)) {
      puVar3 = (undefined1 *)(param_3 + -1);
      do {
        puVar3 = puVar3 + 1;
        FUN_0802e7a0(param_1,*puVar3);
        iVar1 = FUN_08031818(param_1,0x70084,param_5);
        if (iVar1 != 0) break;
        iVar1 = iVar2;
      } while (puVar3 != (undefined1 *)(param_3 + param_4 + -1));
    }
  }
  FUN_0802e738(param_1,1);
  FUN_08031858(100);
  return iVar1;
}

