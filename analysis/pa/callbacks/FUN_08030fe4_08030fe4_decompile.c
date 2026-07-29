
int FUN_08030fe4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (DAT_2000c6dc != '\0') {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_2000c6dc = 1;
  iVar1 = FUN_08031aa4(&DAT_40005400,param_1,param_2,param_3,param_4,0x9c4);
  if (iVar1 == 0) {
    DAT_2000c6dc = 0;
    return 0;
  }
  FUN_08031cfc();
  DAT_2000c6dc = 0;
  return iVar1;
}

