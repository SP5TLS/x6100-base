
void FUN_0802f4bc(int param_1,uint param_2)

{
  short sVar1;
  short sVar2;
  undefined2 local_1c;
  
  if (0x5e < param_2) {
    param_2 = 0x5f;
  }
  local_1c = 0x100;
  FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  sVar1 = (short)param_2;
  sVar2 = DAT_200002a8;
  if ((param_1 << 0x1f < 0) && (sVar2 = sVar1, (int)DAT_200002a8 != param_2)) {
    local_1c = CONCAT11((char)param_2,0x3b);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  DAT_200002a8 = sVar2;
  sVar2 = DAT_200002aa;
  if ((param_1 << 0x1e < 0) && (sVar2 = sVar1, (int)DAT_200002aa != param_2)) {
    local_1c = CONCAT11((char)param_2,0x3c);
    FUN_08031890(0x40005800,0x30,&local_1c,2,10000);
  }
  DAT_200002aa = sVar2;
  return;
}

