
void FUN_080311a8(uint param_1)

{
  undefined4 local_30 [10];
  
  local_30[0] = DAT_0803d0e8;
  local_30[1] = DAT_0803d0ec;
  local_30[2] = DAT_0803d0f0;
  local_30[3] = DAT_0803d0f4;
  local_30[4] = DAT_0803d0f8;
  local_30[5] = DAT_0803d0fc;
  local_30[6] = DAT_0803d100;
  local_30[7] = DAT_0803d104;
  local_30[8] = DAT_0803d108;
  local_30[9] = DAT_0803d10c;
  if (9 < param_1) {
    return;
  }
  FUN_080306a0(&DAT_20000360,0x3bf8,0);
  FUN_080306a0(&DAT_20000360,local_30[param_1],1);
  FUN_080306b0(&DAT_20000360);
  return;
}

