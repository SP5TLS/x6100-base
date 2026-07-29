
void FUN_0802f6e8(uint param_1,int param_2)

{
  undefined2 local_14;
  
  if (param_1 != 0) {
    if ((int)(param_1 << 0x1f) < 0) {
      if (param_2 != 0) {
        if ((param_1 & 2) == 0) {
          param_2 = 8;
        }
        else {
          param_2 = 0xc;
        }
      }
    }
    else if ((param_1 & 2) == 0) {
      param_2 = 0;
    }
    else if (param_2 != 0) {
      param_2 = 4;
    }
    local_14 = 0;
    FUN_08031890(0x40005800,0x30,&local_14,2,10000);
    local_14 = CONCAT11((char)param_2,0x40);
    FUN_08031890(0x40005800,0x30,&local_14,2,10000);
    return;
  }
  return;
}

