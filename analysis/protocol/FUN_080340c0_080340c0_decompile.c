
undefined4 FUN_080340c0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *param_3 = 0xaa5555aa;
  uVar1 = FUN_0802a3cc(param_3,0xcb);
  param_3[0xcb] = uVar1;
  FUN_0802e30c();
  FUN_0802e330();
  FUN_0802e4a4(0xfff,0);
  iVar2 = FUN_0802e4d4();
  if (iVar2 == 9) {
    FUN_08037a50(s__OK__Change_flash_option_bytes_0803d310);
    iVar2 = FUN_0802e404(param_1,2);
    if (iVar2 == 9) {
      puVar3 = param_3 + -1;
      FUN_08037970(s__OK__Erase_flash_sector__08lX_0803d354,param_1);
      do {
        iVar4 = ((param_2 + 4) - (int)param_3) + (int)puVar3;
        puVar3 = puVar3 + 1;
        iVar2 = FUN_0802e464(iVar4,*puVar3);
        if (iVar2 != 9) {
          FUN_08037970(s__ERR__Program_flash_word_addr__0_0803d374,iVar4);
        }
      } while (puVar3 != param_3 + 0xcb);
      return 0;
    }
    FUN_08037970(s__ERR__Erase_flash_sector__08lX_0803d330,param_1);
  }
  else {
    FUN_08037a50(s__ERR__Change_flash_option_bytes_0803d2ec);
  }
  return 0xfffffffd;
}

