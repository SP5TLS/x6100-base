
int FUN_08031e1c(undefined4 param_1,undefined1 param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  FUN_0802e71c(&DAT_40005400,1);
  iVar2 = FUN_08031818(&DAT_40005400,0x30001,5000);
  if (iVar2 == 0) {
    FUN_0802e754(&DAT_40005400,param_1,0);
    iVar2 = FUN_08031818(&DAT_40005400,0x70082,5000);
    if (iVar2 == 0) {
      FUN_0802e7a0(&DAT_40005400,param_2);
      iVar2 = FUN_08031818(&DAT_40005400,0x70084,5000);
      if (iVar2 == 0) {
        FUN_0802e71c(&DAT_40005400,1);
        iVar2 = FUN_08031818(&DAT_40005400,0x30001,5000);
        if (iVar2 == 0) {
          FUN_0802e754(&DAT_40005400,param_1,1);
          iVar2 = FUN_08031818(&DAT_40005400,0x30002,250000);
          if (iVar2 == 0) {
            if (param_4 != 0) {
              iVar5 = 0;
              puVar4 = param_3;
              do {
                FUN_0802e768(&DAT_40005400,param_4 + -1 != iVar5);
                iVar2 = FUN_08031818(&DAT_40005400,0x30040,500000);
                iVar5 = iVar5 + 1;
                if (iVar2 != 0) {
                  FUN_0802e738(&DAT_40005400,1);
                  FUN_08031858(100);
                  goto LAB_08031e66;
                }
                uVar1 = FUN_0802e7a4(&DAT_40005400);
                puVar3 = puVar4 + 1;
                *puVar4 = uVar1;
                FUN_08031858(10);
                puVar4 = puVar3;
              } while (puVar3 != param_3 + param_4);
            }
            FUN_0802e738(&DAT_40005400,1);
            FUN_08031858(100);
            return 0;
          }
        }
      }
    }
  }
  FUN_0802e738(&DAT_40005400,1);
  FUN_08031858(100);
LAB_08031e66:
  FUN_08031cfc();
  return iVar2;
}

