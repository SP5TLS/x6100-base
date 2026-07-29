
void FUN_0802397c(float param_1,float param_2,float param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_08020628((param_2 + param_2) / param_1);
  uVar3 = FUN_08020368((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0xd2f1a9fc,0x3f60624d);
  FUN_080206d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x408f1800);
  uVar1 = FUN_08020c38();
  if (0x3e2 < (int)uVar1) {
    uVar1 = 0x3e3;
  }
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  puVar2 = *(undefined4 **)(&DAT_20001484 + uVar1 * 4);
  if (*(int *)(param_4 + 200) == 1) {
    if (uVar1 == *(uint *)(param_4 + 0xc4)) goto LAB_08023abe;
    *(uint *)(param_4 + 0xc4) = uVar1;
  }
  else {
    *(undefined4 *)(param_4 + 200) = 1;
    if (uVar1 != *(uint *)(param_4 + 0xc4)) {
      *(uint *)(param_4 + 0xc4) = uVar1;
    }
  }
  if (param_5 != 0) {
    FUN_08034a6c(0,param_4 + 0x74,0x14);
  }
  if (puVar2 == (undefined4 *)0x0) {
    FUN_08034a6c(0,param_4 + 0x10,0x19);
    *(undefined4 *)(param_4 + 0xc) = 0;
  }
  else {
    *(undefined4 *)(param_4 + 0x10) = *puVar2;
    *(undefined4 *)(param_4 + 0x14) = puVar2[1];
    *(undefined4 *)(param_4 + 0x18) = puVar2[2];
    *(float *)(param_4 + 0x1c) = -(float)puVar2[4];
    *(float *)(param_4 + 0x20) = -(float)puVar2[5];
    *(undefined4 *)(param_4 + 0x24) = puVar2[6];
    *(undefined4 *)(param_4 + 0x28) = puVar2[7];
    *(undefined4 *)(param_4 + 0x2c) = puVar2[8];
    *(float *)(param_4 + 0x30) = -(float)puVar2[10];
    *(float *)(param_4 + 0x34) = -(float)puVar2[0xb];
    *(undefined4 *)(param_4 + 0x38) = puVar2[0xc];
    *(undefined4 *)(param_4 + 0x3c) = puVar2[0xd];
    *(undefined4 *)(param_4 + 0x40) = puVar2[0xe];
    *(float *)(param_4 + 0x44) = -(float)puVar2[0x10];
    *(float *)(param_4 + 0x48) = -(float)puVar2[0x11];
    *(undefined4 *)(param_4 + 0x4c) = puVar2[0x12];
    *(undefined4 *)(param_4 + 0x50) = puVar2[0x13];
    *(undefined4 *)(param_4 + 0x54) = puVar2[0x14];
    *(float *)(param_4 + 0x58) = -(float)puVar2[0x16];
    *(float *)(param_4 + 0x5c) = -(float)puVar2[0x17];
    *(undefined4 *)(param_4 + 0x60) = puVar2[0x18];
    *(undefined4 *)(param_4 + 100) = puVar2[0x19];
    *(undefined4 *)(param_4 + 0x68) = puVar2[0x1a];
    *(float *)(param_4 + 0x6c) = -(float)puVar2[0x1c];
    *(float *)(param_4 + 0x70) = -(float)puVar2[0x1d];
    *(undefined4 *)(param_4 + 0xc) = puVar2[0x1e];
  }
LAB_08023abe:
  uVar3 = FUN_08020628((param_3 + param_3) / param_1);
  uVar3 = FUN_08020368((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0xd2f1a9fc,0x3f60624d);
  FUN_080206d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x408f1800);
  uVar1 = FUN_08020c38();
  if (0x3e2 < (int)uVar1) {
    uVar1 = 0x3e3;
  }
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  puVar2 = *(undefined4 **)(&DAT_20002414 + uVar1 * 4);
  if (*(int *)(param_4 + 0x194) == 0) {
    if (uVar1 == *(uint *)(param_4 + 400)) {
      return;
    }
    *(uint *)(param_4 + 400) = uVar1;
  }
  else {
    *(undefined4 *)(param_4 + 0x194) = 0;
    if (uVar1 != *(uint *)(param_4 + 400)) {
      *(uint *)(param_4 + 400) = uVar1;
    }
  }
  if (param_5 != 0) {
    FUN_08034a6c(0,param_4 + 0x140,0x14);
  }
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_4 + 0xdc) = *puVar2;
    *(undefined4 *)(param_4 + 0xe0) = puVar2[1];
    *(undefined4 *)(param_4 + 0xe4) = puVar2[2];
    *(float *)(param_4 + 0xe8) = -(float)puVar2[4];
    *(float *)(param_4 + 0xec) = -(float)puVar2[5];
    *(undefined4 *)(param_4 + 0xf0) = puVar2[6];
    *(undefined4 *)(param_4 + 0xf4) = puVar2[7];
    *(undefined4 *)(param_4 + 0xf8) = puVar2[8];
    *(float *)(param_4 + 0xfc) = -(float)puVar2[10];
    *(float *)(param_4 + 0x100) = -(float)puVar2[0xb];
    *(undefined4 *)(param_4 + 0x104) = puVar2[0xc];
    *(undefined4 *)(param_4 + 0x108) = puVar2[0xd];
    *(undefined4 *)(param_4 + 0x10c) = puVar2[0xe];
    *(float *)(param_4 + 0x110) = -(float)puVar2[0x10];
    *(float *)(param_4 + 0x114) = -(float)puVar2[0x11];
    *(undefined4 *)(param_4 + 0x118) = puVar2[0x12];
    *(undefined4 *)(param_4 + 0x11c) = puVar2[0x13];
    *(undefined4 *)(param_4 + 0x120) = puVar2[0x14];
    *(float *)(param_4 + 0x124) = -(float)puVar2[0x16];
    *(float *)(param_4 + 0x128) = -(float)puVar2[0x17];
    *(undefined4 *)(param_4 + 300) = puVar2[0x18];
    *(undefined4 *)(param_4 + 0x130) = puVar2[0x19];
    *(undefined4 *)(param_4 + 0x134) = puVar2[0x1a];
    *(float *)(param_4 + 0x138) = -(float)puVar2[0x1c];
    *(float *)(param_4 + 0x13c) = -(float)puVar2[0x1d];
    *(undefined4 *)(param_4 + 0xd8) = puVar2[0x1e];
    return;
  }
  FUN_08034a6c(0,param_4 + 0xdc,0x19);
  *(undefined4 *)(param_4 + 0xd8) = 0;
  return;
}

