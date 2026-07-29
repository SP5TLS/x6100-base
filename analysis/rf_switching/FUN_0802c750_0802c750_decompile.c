
void FUN_0802c750(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = DAT_2000c6e4 & 0xffffc07f;
  switch(param_1) {
  case 0:
    DAT_2000c6e4 = uVar1 | 0x2000;
    break;
  case 1:
    DAT_2000c6e4 = uVar1 | 0x1000;
    break;
  case 2:
    DAT_2000c6e4 = uVar1 | 0x800;
    break;
  case 3:
    DAT_2000c6e4 = uVar1 | 0x400;
    break;
  case 4:
    DAT_2000c6e4 = uVar1 | 0x200;
    break;
  case 5:
    DAT_2000c6e4 = uVar1 | 0x100;
    break;
  default:
    DAT_2000c6e4 = uVar1 | 0x80;
  }
                    /* WARNING: Could not recover jumptable at 0x0802c77c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_2000c6f0)(&DAT_2000c6e0);
  return;
}

