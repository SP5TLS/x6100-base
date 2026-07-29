
void FUN_08033ef4(void)

{
  int iVar1;
  uint local_14;
  undefined4 *local_10;
  int local_c;
  
  iVar1 = FUN_08034058(0x8004000,&DAT_2000c190);
  if (iVar1 == 0) {
    FUN_08037a50(s__OK__Found_valid_calibration_dat_0803d218);
    local_c = 0;
  }
  else {
    FUN_08037a50(s__OK__Move_calibration_data_from_s_0803d248);
    iVar1 = FUN_08034058(0x80e0000,&DAT_2000c190);
    if (iVar1 == 0) {
      local_c = FUN_080340c0(8,0x8004000,&DAT_2000c190);
      if (local_c == 0) {
        FUN_0802e404(0x58,2);
      }
      else {
        FUN_08037a50(s__ERR__Can_t_store_calibration_da_0803d280);
      }
    }
    else {
      FUN_08037a50(s__ERR__No_calibration_data_found__0803d2b4);
      local_c = -4;
    }
  }
  if (local_c == 0) {
    if (0xaf0 < DAT_2000c194) {
      DAT_2000c194 = 0xaf0;
    }
    if (0xce4 < DAT_2000c198) {
      DAT_2000c198 = 0xce4;
    }
  }
  else {
    local_10 = &DAT_2000c190;
    for (local_14 = 0; local_14 < 0xcc; local_14 = local_14 + 1) {
      *local_10 = 0;
      local_10 = local_10 + 1;
    }
    DAT_2000c190 = 0xaa5555aa;
    DAT_2000c194 = 300;
    DAT_2000c198 = 0x28a;
    DAT_2000c4bc = FUN_0802a3cc(local_10,0xcb);
  }
  return;
}

