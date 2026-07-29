
void FUN_08033a20(uint param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = param_1 - *(uint *)(param_4 + 0x50) * (param_1 / *(uint *)(param_4 + 0x50));
  *(int *)(param_4 + 0x4c) = iVar3;
  *(undefined1 *)(*(int *)(param_4 + 0x48) + iVar3) = param_2;
  uVar1 = *(ushort *)(param_4 + 2);
  uVar5 = (uint)uVar1;
  *(int *)(param_4 + 8) = *(int *)(param_4 + 8) + 1;
  *(undefined4 *)(*(int *)(param_4 + 0x24) + 8) = 0;
  *(undefined2 *)(param_4 + 0x20) = *(undefined2 *)(param_4 + 0x22);
  *(undefined2 *)(param_4 + 0x1a) = 1;
  if ((uVar1 & 0x10) != 0) {
    sVar2 = *(short *)(param_4 + 0x1a);
    **(ushort **)(param_4 + 0x34) = **(ushort **)(param_4 + 0x34) | 1;
    *(undefined4 *)(param_4 + 2) = 0;
    *(undefined4 *)(param_4 + 0xc) = 0;
    if (sVar2 == 0) {
      return;
    }
    *(undefined4 *)(param_4 + 0x1a) = 0x10000;
    return;
  }
  if (-1 < (int)(uVar5 << 0x18)) {
    if (-1 < (int)(uVar5 << 0x15)) {
      return;
    }
    uVar1 = *(ushort *)(*(int *)(param_4 + 0x34) + 0x14);
    *(undefined4 *)(param_4 + 2) = 0;
    *(ushort *)(*(int *)(param_4 + 0x34) + 0x14) = uVar1 & 0xfdff;
    *(undefined4 *)(param_4 + 0xc) = 0;
    return;
  }
  uVar6 = *(uint *)(param_4 + 8);
  iVar3 = *(int *)(param_4 + 0x34);
  *(uint *)(param_4 + 2) = uVar5 & 0x10;
  if (uVar6 < 0x80) {
    if (*(int *)(param_4 + 0x30) != 0) {
      uVar5 = *(uint *)(param_4 + 0x2c);
      *(ushort *)(iVar3 + 0x10) =
           (ushort)*(byte *)(*(int *)(param_4 + 0x30) + (uVar6 - uVar5 * (uVar6 / uVar5)));
      *(uint *)(param_4 + 8) = (uVar6 + 1) - uVar5 * ((uVar6 + 1) / uVar5);
      goto LAB_08033aa0;
    }
  }
  else if (0x7f < uVar6 - 0x80) {
    uVar7 = uVar6 - 0x100;
    if (uVar7 < 0xf00) {
      iVar4 = uVar7 - *(uint *)(param_4 + 0x50) * (uVar7 / *(uint *)(param_4 + 0x50));
      *(int *)(param_4 + 0x4c) = iVar4;
      *(ushort *)(iVar3 + 0x10) = (ushort)*(byte *)(*(int *)(param_4 + 0x48) + iVar4);
      *(uint *)(param_4 + 8) = uVar6 + 1;
      goto LAB_08033aa0;
    }
    if (0xdfff < uVar6 - 0x1000) {
      uVar5 = uVar6 - 0xf000;
      if (uVar5 < 0xffe) {
        iVar4 = uVar5 - *(uint *)(param_4 + 0x50) * (uVar5 / *(uint *)(param_4 + 0x50));
        *(int *)(param_4 + 0x4c) = iVar4;
        *(ushort *)(iVar3 + 0x10) = (ushort)*(byte *)(*(int *)(param_4 + 0x48) + iVar4);
        *(uint *)(param_4 + 8) = uVar6 + 1;
      }
      else {
        *(undefined2 *)(iVar3 + 0x10) = 0x61;
      }
      goto LAB_08033aa0;
    }
  }
  *(short *)(iVar3 + 0x10) = (short)(uVar5 & 0x10);
LAB_08033aa0:
  *(undefined2 *)(param_4 + 0x20) = *(undefined2 *)(param_4 + 0x22);
  return;
}

