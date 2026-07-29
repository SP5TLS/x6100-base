
void FUN_0802a8a4(int param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xb) != '\0') {
    *param_2 = '\0';
    return;
  }
  if (*(char *)(param_1 + 2) == '\0') {
    if ((*(int *)(*(int *)(param_1 + 0x120) + 0x10) != 4) &&
       (*(int *)(*(int *)(param_1 + 0x120) + 0x10) != 5)) goto LAB_0802a906;
    bVar1 = true;
  }
  else if ((*(int *)(*(int *)(param_1 + 0x124) + 0x10) == 4) ||
          (*(int *)(*(int *)(param_1 + 0x124) + 0x10) == 5)) {
    bVar1 = true;
  }
  else {
LAB_0802a906:
    bVar1 = false;
  }
  if (bVar1) {
    if (param_2[0x4a] == '\0') {
      FUN_08031300(1,0);
    }
    else {
      FUN_08031300(1,1);
    }
    if (param_2[0x5e] == '\0') {
      FUN_08031300(2,0);
    }
    else {
      FUN_08031300(2,1);
    }
    if (param_2[2] == '\0') {
      param_2[4] = param_2[0x72];
      param_2[2] = '\x01';
      param_2[1] = '\0';
    }
    else if (param_2[2] == '\x01') {
      if (((param_2[4] != param_2[0x72]) && (param_2[0x5e] == '\0')) && (param_2[0x4a] == '\0')) {
        param_2[1] = param_2[0x72];
      }
      param_2[4] = param_2[0x72];
    }
    if ((param_2[0x9a] == '\0') && (param_2[1] == '\0')) {
      if ((param_2[0x9a] == '\0') && (param_2[1] == '\0')) {
        FUN_08031300(4,0);
      }
    }
    else {
      FUN_08031300(4,1);
    }
  }
  else {
    FUN_08031300(7,0);
  }
  if ((*(uint *)(param_2 + 8) & 0x10) == 0) {
    if ((*(uint *)(param_2 + 8) & 0x100) == 0) {
      if ((*(uint *)(param_2 + 8) & 0x200) == 0) {
        if ((*(uint *)(param_2 + 8) & 0x20) == 0) {
          if ((*(uint *)(param_2 + 8) & 0x40) == 0) {
            if (*(char *)(param_1 + 2) == '\0') {
              if ((**(uint **)(param_1 + 0x120) & 1) == 0) {
                *param_2 = '\0';
                goto LAB_0802aabc;
              }
            }
            else if ((**(uint **)(param_1 + 0x124) & 1) == 0) {
              *param_2 = '\0';
              goto LAB_0802aabc;
            }
            iVar2 = FUN_080244a4();
            if (iVar2 == 0) {
              if ((*(uint *)(param_2 + 8) & 2) == 0) {
                if ((*(uint *)(param_2 + 8) & 1) != 0) {
                  *param_2 = '\x01';
                }
              }
              else {
                *param_2 = '\x01';
              }
            }
            else {
              *param_2 = '\x01';
            }
          }
          else {
            *param_2 = '\x01';
          }
        }
        else {
          *param_2 = '\x01';
        }
      }
      else {
        *param_2 = '\x01';
      }
    }
    else {
      *param_2 = '\x01';
    }
  }
  else {
    *param_2 = '\x01';
  }
LAB_0802aabc:
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_2 + 8);
  if (((*param_2 == '\x01') && (iVar2 = FUN_080244a4(), iVar2 == 0)) && (*(int *)(param_2 + 8) == 0)
     ) {
    *param_2 = '\0';
  }
  return;
}

