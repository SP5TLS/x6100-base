
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08033b88(void)

{
  int iVar1;
  
  _DAT_20001432 = _DAT_20001464[10];
  _DAT_20001434 = _DAT_20001464[0xc];
  iVar1 = FUN_0802e814(_DAT_20001464,0x1008000);
  if (iVar1 == 0) {
    iVar1 = FUN_0802e814(_DAT_20001464,0x1004000);
    if (iVar1 == 0) {
      iVar1 = FUN_0802e814(_DAT_20001464,0x1001000);
      if (iVar1 == 0) {
        iVar1 = FUN_0802e814(_DAT_20001464,0x1000800);
        if (iVar1 == 0) {
          iVar1 = FUN_0802e814(_DAT_20001464,0x1000400);
          if (iVar1 == 0) {
            iVar1 = FUN_0802e814(_DAT_20001464,0x1000200);
            if (iVar1 == 0) {
              iVar1 = FUN_0802e814(_DAT_20001464,0x1000100);
              if (iVar1 != 0) {
                FUN_0802e830(_DAT_20001464,0x1000100);
              }
            }
            else {
              FUN_0802e830(_DAT_20001464,0x1000200);
            }
          }
          else {
            FUN_0802e830(_DAT_20001464,0x1000400);
          }
        }
        else {
          FUN_0802e830(_DAT_20001464,0x1000800);
        }
      }
      else {
        FUN_0802e830(_DAT_20001464,0x1001000);
      }
    }
    else {
      FUN_0802e830(_DAT_20001464,0x1004000);
    }
  }
  else {
    FUN_0802e830(_DAT_20001464,0x1008000);
  }
  *_DAT_20001464 = *_DAT_20001464 | 1;
  _DAT_20001432 = 0;
  return;
}

