
void FUN_0803062c(undefined1 *param_1,uint param_2,int param_3)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    return;
  }
  if (*(int *)(param_1 + param_2 * 4 + 0x10) != param_3) {
    *(int *)(param_1 + param_2 * 4 + 0x10) = param_3;
    local_c = (undefined1)(param_2 << 3);
    local_b = (undefined1)((uint)param_3 >> 8);
    local_a = (undefined1)param_3;
    (**(code **)(param_1 + 0x20))(*param_1,&local_c,3);
                    /* WARNING: Could not recover jumptable at 0x08030668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x28))(10);
    return;
  }
  return;
}

