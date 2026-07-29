
void FUN_0802a168(void)

{
  if (DAT_2000000c != 0) {
    DAT_2000000c = 0;
    DAT_2000c6e4 = DAT_2000c6e4 & 0xffffff80;
    (*DAT_2000c6f0)();
  }
  if (DAT_20000008 == 0) {
    return;
  }
  DAT_20000008 = 0;
  DAT_2000c6e4 = DAT_2000c6e4 & 0xffd03fff;
                    /* WARNING: Could not recover jumptable at 0x0802a1b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_2000c6f0)();
  return;
}

