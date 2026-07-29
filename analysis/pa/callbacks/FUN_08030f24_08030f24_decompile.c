
int FUN_08030f24(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_2000c6dc != '\0') {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_2000c6dc = 1;
  iVar1 = FUN_08031890(&DAT_40005400,param_1,param_2,param_3,5000);
  if (iVar1 == 0) {
    DAT_2000c6dc = 0;
    return 0;
  }
  FUN_08031cfc();
  DAT_2000c6dc = 0;
  return iVar1;
}

