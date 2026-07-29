
void FUN_08033580(undefined1 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  ushort local_1c;
  
  if (*(code **)(param_1 + 0x54) != (code *)0x0) {
    (**(code **)(param_1 + 0x54))(0);
    FUN_080349e4(100);
    (**(code **)(param_1 + 0x54))(1);
    FUN_080349e4(100);
  }
  if (0 < *(int *)(param_1 + 4)) {
    FUN_08037e20(param_1 + 0x28,0,*(int *)(param_1 + 4) << 2);
  }
  (**(code **)(param_1 + 0x50))(*param_1,&DAT_0803e0c4,0x6b);
  FUN_080349e4(10);
  local_20 = 0x4376;
  (**(code **)(param_1 + 0x50))(*param_1,&local_20,2);
  FUN_080349e4(10);
  local_20 = 0x6376;
  (**(code **)(param_1 + 0x50))(*param_1,&local_20,2);
  FUN_080349e4(10);
  uVar3 = *(uint *)(param_1 + 8);
  uVar2 = uVar3 * 0x6f;
  if (2999999999 < uVar3 * 0x6f) {
    uVar2 = 3000000000;
  }
  if (uVar2 < 2500000000) {
    uVar2 = 2500000000;
  }
  uVar4 = uVar2 / uVar3;
  *(uint *)(param_1 + 0x10) = uVar2;
  uVar5 = uVar4;
  if (0xfff < uVar4) {
    uVar2 = uVar3 * 0xfff;
    uVar5 = uVar2 / uVar3;
  }
  lVar1 = (ulonglong)(uVar2 - uVar3 * uVar5) * 0xffffff;
  uVar2 = FUN_08020d68((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar3,0);
  local_1c = (ushort)((uVar2 & 0xff) << 8) | (ushort)(uVar2 >> 8) & 0xff;
  local_1d = (undefined1)(uVar2 >> 0x10);
  local_20 = CONCAT11((char)(uVar4 >> 4),0x17);
  local_1e = (undefined1)(uVar4 << 4);
  (**(code **)(param_1 + 0x50))(*param_1,&local_20,6);
  if (0 < *(int *)(param_1 + 4)) {
    uVar6 = FUN_080205e4(*(undefined4 *)(param_1 + 0x10));
    uVar6 = FUN_080206d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0x1cf6524a,0x3e42cfa9);
    uVar2 = FUN_08020c88();
    uVar7 = FUN_080205e4();
    uVar6 = FUN_08020368((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                         (int)((ulonglong)uVar7 >> 0x20));
    uVar6 = FUN_080206d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x41700000);
    FUN_0802036c((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
    uVar3 = FUN_08020c88();
    uVar5 = *(uint *)(param_1 + 0x2c);
    *(uint *)(param_1 + 0x2c) = uVar2;
    if (uVar2 != uVar5) {
      param_1[0xc] = 1;
    }
    *(uint *)(param_1 + 0x40) = uVar3;
    local_20 = CONCAT11((char)(uVar2 >> 4),0x2d);
    local_1e = (undefined1)(uVar2 << 4);
    (**(code **)(param_1 + 0x50))(*param_1,&local_20,3);
    local_20 = CONCAT11((char)(uVar3 >> 0x16),0x22);
    local_1e = (undefined1)(uVar3 >> 0xe);
    local_1d = (undefined1)(uVar3 >> 6);
    local_1c = CONCAT11(local_1c._1_1_,(char)(uVar3 << 2));
    (**(code **)(param_1 + 0x50))(*param_1,&local_20,5);
    if (3 < *(int *)(param_1 + 4)) {
      uVar6 = FUN_080205e4(*(undefined4 *)(param_1 + 0x10));
      uVar6 = FUN_080206d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0xa0b5ed8d,0x3e90c6f7);
      uVar2 = FUN_08020c88();
      uVar7 = FUN_080205e4();
      uVar6 = FUN_08020368((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                           (int)((ulonglong)uVar7 >> 0x20));
      uVar6 = FUN_080206d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x41700000);
      FUN_0802036c((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
      uVar3 = FUN_08020c88();
      uVar5 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x38) = uVar2;
      if (uVar2 != uVar5) {
        param_1[0xc] = 1;
      }
      *(uint *)(param_1 + 0x4c) = uVar3;
      local_20 = CONCAT11((char)(uVar2 >> 4),0x5d);
      local_1e = (undefined1)(uVar2 << 4);
      (**(code **)(param_1 + 0x50))(*param_1,&local_20,3);
      local_20 = CONCAT11((char)(uVar3 >> 0x16),0x52);
      local_1e = (undefined1)(uVar3 >> 0xe);
      local_1d = (undefined1)(uVar3 >> 6);
      local_1c = CONCAT11(local_1c._1_1_,(char)(uVar3 << 2));
      (**(code **)(param_1 + 0x50))(*param_1,&local_20,5);
    }
  }
  FUN_080349e4(10);
  local_20 = 0x4376;
  (**(code **)(param_1 + 0x50))(*param_1,&local_20,2);
  FUN_080349e4(10);
  local_20 = 0x6376;
  (**(code **)(param_1 + 0x50))(*param_1,&local_20,2);
  return;
}

