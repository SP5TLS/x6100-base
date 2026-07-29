
void FUN_08033514(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_18;
  undefined1 local_14;
  
  uVar1 = local_18;
  if (param_2 <= *(int *)(param_1 + 4)) {
    uVar3 = *(uint *)(param_1 + param_2 * 4 + 0x3c);
    uVar2 = (param_2 + -1) * 0x10;
    local_18._3_1_ = SUB41(uVar1,3);
    local_18._0_3_ =
         CONCAT12((char)(*(uint *)(param_1 + param_2 * 4 + 0x28) << 4),
                  CONCAT11((char)(*(uint *)(param_1 + param_2 * 4 + 0x28) >> 4),(char)uVar2 + '-'));
    (**(code **)(param_1 + 0x50))(*param_1,&local_18,3);
    local_18 = (uVar2 & 0xff) + 0x22 & 0xff | (uVar3 >> 0x16 & 0xff) << 8 |
               (uVar3 >> 0xe & 0xff) << 0x10 | (uVar3 >> 6) << 0x18;
    local_14 = (undefined1)(uVar3 << 2);
    (**(code **)(param_1 + 0x50))(*param_1,&local_18,5);
    return;
  }
  return;
}

