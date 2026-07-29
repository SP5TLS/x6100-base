
uint FUN_0802a3cc(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (param_2 != 0) {
    puVar3 = (uint *)(param_1 + -4);
    puVar2 = puVar3 + param_2;
    uVar1 = 0xffffffff;
    do {
      puVar3 = puVar3 + 1;
      uVar1 = *(uint *)(&DAT_0803dc3c + ((uVar1 ^ *puVar3) >> 0x18) * 4) ^ (uVar1 ^ *puVar3) << 8;
      uVar1 = *(uint *)(&DAT_0803dc3c + (uVar1 >> 0x18) * 4) ^ uVar1 << 8;
      uVar1 = *(uint *)(&DAT_0803dc3c + (uVar1 >> 0x18) * 4) ^ uVar1 << 8;
      uVar1 = *(uint *)(&DAT_0803dc3c + (uVar1 >> 0x18) * 4) ^ uVar1 << 8;
    } while (puVar2 != puVar3);
    return uVar1;
  }
  return 0xffffffff;
}

