
void FUN_080306b0(undefined1 *param_1)

{
  param_1[3] = (char)*(undefined4 *)(param_1 + 4);
  param_1[2] = 2;
  (**(code **)(param_1 + 8))(*param_1,2,param_1 + 3,1);
  param_1[3] = (char)((uint)*(undefined4 *)(param_1 + 4) >> 8);
  param_1[2] = 3;
                    /* WARNING: Could not recover jumptable at 0x080306e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 8))(*param_1,3,param_1 + 3,1);
  return;
}

