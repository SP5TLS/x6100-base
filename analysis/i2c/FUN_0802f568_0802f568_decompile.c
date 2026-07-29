
void FUN_0802f568(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  undefined2 local_1c;
  
  if (param_1 == 0) {
    return;
  }
  if (param_2 < -6) {
    bVar3 = 0x40;
  }
  else {
    if (0x1c < param_2) {
      param_2 = 0x1d;
    }
    bVar3 = (byte)param_2 & 0x3f;
  }
  local_1c = 0x100;
  FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  sVar1 = (short)param_2;
  sVar2 = DAT_200002a0;
  if ((param_1 << 0x1f < 0) && (sVar2 = sVar1, DAT_200002a0 != param_2)) {
    local_1c = CONCAT11(bVar3,0x12);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  DAT_200002a0 = sVar2;
  sVar2 = DAT_200002a2;
  if ((param_1 << 0x1e < 0) && (sVar2 = sVar1, DAT_200002a2 != param_2)) {
    local_1c = CONCAT11(bVar3,0x13);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  DAT_200002a2 = sVar2;
  return;
}

