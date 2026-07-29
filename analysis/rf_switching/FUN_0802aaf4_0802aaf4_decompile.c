
void FUN_0802aaf4(int param_1,uint param_2,char param_3)

{
  bool bVar1;
  
  *(char *)(param_1 + 3) = param_3;
  if (param_3 == '\0') {
    FUN_0802d148(0x40021000,0x1000,1);
    (*DAT_2000c6cc)(0);
    FUN_0803062c(&DAT_20000334,0,0);
    FUN_0803062c(&DAT_20000334,1,0);
    FUN_0802d148(0x40021000,0x200,1);
    FUN_0802d148(0x40021000,0x100,0);
    FUN_0802d148(0x40021800,0x800,0);
    FUN_0802d148(0x40021000,4,0);
    FUN_08023f20(0);
    FUN_0802d148(0x40020c00,8,1);
    FUN_0802d148(0x40020c00,0x10,0);
    FUN_08033974(2,0);
    if (*(char *)(param_1 + 0x17) != '\0') {
      *(undefined1 *)(param_1 + 0x17) = 0;
      FUN_0802f8d0(0);
    }
  }
  else {
    FUN_08023f20(1);
    FUN_080243f0(0x3f800000);
    if ((((param_2 & 0x100) == 0) && ((param_2 & 0x10) == 0)) && ((param_2 & 0x200) == 0)) {
      if ((param_2 & 0x40) == 0) {
        if (((*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 0) ||
            (*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 2)) ||
           ((*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 6 ||
            (*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 7)))) {
          bVar1 = false;
          if (*(char *)(param_1 + 0x18) == '\0') {
            FUN_0802f4b8(1,*(undefined1 *)(param_1 + 0x15));
            FUN_0802f7c8(1,1);
            bVar1 = true;
          }
          else if (*(char *)(param_1 + 0x18) == '\x01') {
            FUN_0802f4b8(1,*(undefined1 *)(param_1 + 0x16));
            FUN_0802f7c8(1,2);
          }
          else if ((param_2 & 2) == 0) {
            FUN_0802f4b8(1,*(undefined1 *)(param_1 + 0x15));
            FUN_0802f7c8(1,1);
            bVar1 = true;
          }
          else {
            FUN_0802f4b8(1,*(undefined1 *)(param_1 + 0x16));
            FUN_0802f7c8(1,2);
          }
          if (bVar1) {
            if (*(char *)(param_1 + 0x17) == '\0') {
              *(undefined1 *)(param_1 + 0x17) = 1;
              FUN_0802f8d0(1);
            }
            FUN_080243f0(0x40a00000);
          }
        }
        else if ((*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 1) ||
                (*(int *)(*(int *)(param_1 + 0x11c) + 0x10) == 3)) {
          FUN_0802f7c8(1,0);
          FUN_0802f4b8(2,*(undefined1 *)(param_1 + 0x13));
          FUN_0802f7c8(2,2);
        }
      }
      else {
        FUN_0802f7c8(1,0);
        FUN_0802f4b8(2,*(undefined1 *)(param_1 + 0x4c));
        FUN_0802f7c8(2,4);
      }
    }
    else {
      FUN_0802f7c8(3,0);
    }
    FUN_0803062c(&DAT_20000334,0,*(undefined2 *)(param_1 + 0x10c));
    FUN_0803062c(&DAT_20000334,1,*(undefined2 *)(param_1 + 0x10e));
    (*DAT_2000c6cc)(1);
    FUN_0802d148(0x40021000,0x200,0);
    FUN_0802d148(0x40021000,0x100,1);
    FUN_0802d148(0x40021800,0x800,1);
    FUN_0802d148(0x40021000,4,1);
    FUN_0802d148(0x40020c00,8,0);
    FUN_0802d148(0x40020c00,0x10,1);
    FUN_08033974(2,1);
  }
  return;
}

