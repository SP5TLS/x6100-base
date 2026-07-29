
void FUN_0802f7c8(int param_1,uint param_2)

{
  byte bVar1;
  undefined2 local_1c;
  
  if (param_1 << 0x1f < 0) {
    bVar1 = (byte)((param_2 & 1) << 6);
    if ((int)(param_2 << 0x1e) < 0) {
      bVar1 = bVar1 | 0x10;
    }
    local_1c = 0x100;
    if ((int)(param_2 << 0x1d) < 0) {
      bVar1 = bVar1 | 4;
    }
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
    local_1c = CONCAT11(bVar1,0x34);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
    local_1c = 0x4036;
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  if (param_1 << 0x1e < 0) {
    bVar1 = (byte)((param_2 & 1) << 6);
    if ((int)(param_2 << 0x1e) < 0) {
      bVar1 = bVar1 | 0x10;
    }
    local_1c = 0x100;
    if ((int)(param_2 << 0x1d) < 0) {
      bVar1 = bVar1 | 4;
    }
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
    local_1c = CONCAT11(bVar1,0x37);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
    local_1c = 0x8039;
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  return;
}

