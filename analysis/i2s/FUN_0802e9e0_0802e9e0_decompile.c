
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802e9e0(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_2[2];
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xf040;
  uVar3 = *(uint *)(param_2 + 4);
  *(undefined2 *)(param_1 + 0x20) = 2;
  if (uVar3 != 2) {
    if (uVar1 == 0) {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x40;
    }
    if ((int)(_DAT_40023808 << 8) < 0) {
      _DAT_40023808 = _DAT_40023808 & 0xff7fffff;
    }
    if ((_DAT_40023804 & 0x400000) == 0) {
      uVar4 = 16000000;
    }
    else {
      uVar4 = 25000000;
    }
    uVar4 = (((_DAT_40023884 & 0x7fff) >> 6) * (uVar4 / (_DAT_40023804 & 0x3f))) /
            ((_DAT_40023884 & 0x7fffffff) >> 0x1c);
    if (param_2[3] == 0x200) {
      uVar4 = uVar4 >> 8;
    }
    else {
      uVar4 = uVar4 / uVar5;
    }
    uVar3 = (uVar4 * 10) / uVar3 + 5 & 0xffff;
    uVar5 = uVar3 / 0x14;
    if (uVar5 - 2 < 0xfe) {
      uVar2 = (ushort)uVar5 |
              (ushort)((((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xf) >> 3) << 8);
      goto LAB_0802ea9e;
    }
  }
  uVar2 = 2;
LAB_0802ea9e:
  *(ushort *)(param_1 + 0x20) = uVar2 | param_2[3];
  *(ushort *)(param_1 + 0x1c) =
       *(ushort *)(param_1 + 0x1c) | uVar1 | *param_2 | param_2[1] | param_2[6] | 0x800;
  return;
}

