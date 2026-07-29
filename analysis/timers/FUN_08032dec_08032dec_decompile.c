
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08032dec(void)

{
  ushort uVar1;
  uint in_fpscr;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined2 local_38;
  uint local_34 [2];
  undefined2 local_2c;
  undefined1 local_2a;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  
  FUN_0802e844(auStack_28);
  FUN_0802e91c(1);
  FUN_0802e91c(2,1);
  FUN_0802e91c(4,1);
  FUN_0802eb78(0x40000000);
  local_34[0] = 0x14;
  local_34[1] = 4000;
  local_2c = 0;
  FUN_0802ed4c(0x40000000,local_34);
  _DAT_40000010 = 0;
  FUN_0802ee1c(0x40000000,1);
  FUN_0802efa8(0x40000000,1,0);
  FUN_0802ee38(0x40000000,0);
  FUN_0802eb78(&DAT_40000400);
  uVar2 = VectorUnsignedToFloat(local_20,(byte)(in_fpscr >> 0x16) & 3);
  local_34[1] = 5000;
  uVar3 = FUN_08020628(uVar2);
  uVar3 = FUN_080206d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0xa0b5ed8d,0x3eb0c6f7);
  FUN_08020368((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x3ff00000);
  uVar1 = FUN_08020c88();
  local_2c = 0;
  local_34[0] = (uint)uVar1;
  FUN_0802ed4c(&DAT_40000400,local_34);
  _DAT_40000410 = 0;
  FUN_0802ee1c(&DAT_40000400,1);
  FUN_0802efa8(&DAT_40000400,1,0);
  FUN_0802ee38(&DAT_40000400,0);
  FUN_0802eb78(&DAT_40000800);
  local_34[1] = 0xffff;
  local_34[0] = 8;
  local_2c = 0;
  local_2a = 0;
  FUN_0802ed4c(&DAT_40000800,local_34);
  local_38 = 0xf;
  local_40 = 0;
  uStack_3c = 1;
  FUN_0802ee54(&DAT_40000800,&local_40);
  FUN_0802efe4(&DAT_40000800,0x50);
  FUN_0802eff4(&DAT_40000800,4);
  FUN_0802f00c(&DAT_40000800,0x80);
  FUN_0802efbc(&DAT_40000800,2);
  FUN_0802efa8(&DAT_40000800,2,1);
  FUN_0802ee38(&DAT_40000800,1);
  return;
}

