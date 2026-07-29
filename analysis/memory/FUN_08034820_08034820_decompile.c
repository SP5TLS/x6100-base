
undefined * FUN_08034820(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uStack_8;
  
  puVar1 = (undefined *)DAT_2000e9b0;
  if (DAT_2000e9b0 == (undefined4 *)0x0) {
    puVar1 = &DAT_2000eb00;
  }
  if (&uStack_8 < puVar1 + param_1) {
    DAT_2000e9b0 = (undefined4 *)puVar1;
    uStack_8 = param_4;
    puVar2 = (undefined4 *)FUN_08037ec4();
    *puVar2 = 0xc;
    return (undefined *)0xffffffff;
  }
  DAT_2000e9b0 = (undefined4 *)(puVar1 + param_1);
  return puVar1;
}

