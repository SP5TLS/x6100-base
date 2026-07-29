
void FUN_08033e3c(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint local_10;
  undefined4 *local_c;
  
  iVar1 = FUN_0802a3cc(param_3,10);
  if (iVar1 != *(int *)(param_2 + 0x28)) {
    param_3[10] = iVar1;
    FUN_0802e30c();
    FUN_0802e330();
    FUN_0802e4a4(0xfff,0);
    iVar1 = FUN_0802e4d4();
    if (iVar1 == 9) {
      iVar1 = FUN_0802e404(param_1,2);
      if (iVar1 == 9) {
        local_c = param_3;
        for (local_10 = 0; local_10 < 0xb; local_10 = local_10 + 1) {
          FUN_0802e464(local_10 * 4 + param_2,*local_c);
          local_c = local_c + 1;
        }
      }
      else {
        FUN_08037a50(s_Can_t_erase_sector__0803d200);
      }
    }
    else {
      FUN_08037a50(s_Can_t_apply_operation_to_FLASH_O_0803d1cc);
    }
  }
  return;
}

