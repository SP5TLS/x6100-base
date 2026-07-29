
void FUN_08033428(undefined1 *param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 local_28;
  undefined1 local_24;
  
  if (param_2 <= *(int *)(param_1 + 4)) {
    uVar4 = FUN_080205e4(*(undefined4 *)(param_1 + 0x10));
    uVar4 = FUN_080206d8((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
    uVar5 = FUN_080205e4(param_3);
    uVar4 = FUN_0802092c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                         (int)((ulonglong)uVar5 >> 0x20));
    uVar1 = FUN_08020c88();
    uVar5 = FUN_080205e4();
    uVar4 = FUN_08020368((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                         (int)((ulonglong)uVar5 >> 0x20));
    uVar4 = FUN_080206d8((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x41700000);
    FUN_0802036c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
    uVar2 = FUN_08020c88();
    if (uVar1 != *(uint *)(param_1 + param_2 * 4 + 0x28)) {
      param_1[0xc] = 1;
    }
    *(uint *)(param_1 + param_2 * 4 + 0x28) = uVar1;
    *(uint *)(param_1 + param_2 * 4 + 0x3c) = uVar2;
    if (param_4 != 0) {
      uVar3 = (param_2 + -1) * 0x10;
      local_28._0_3_ = CONCAT12((char)(uVar1 << 4),CONCAT11((char)(uVar1 >> 4),(char)uVar3 + '-'));
      (**(code **)(param_1 + 0x50))(*param_1,&local_28,3);
      local_28 = (uVar3 & 0xff) + 0x22 & 0xff | (uVar2 >> 0x16 & 0xff) << 8 |
                 (uVar2 >> 0xe & 0xff) << 0x10 | (uVar2 >> 6) << 0x18;
      local_24 = (undefined1)(uVar2 << 2);
      (**(code **)(param_1 + 0x50))(*param_1,&local_28,5);
      return;
    }
  }
  return;
}

