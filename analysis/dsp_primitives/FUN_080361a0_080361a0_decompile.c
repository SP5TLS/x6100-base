
/* WARNING: Removing unreachable block (ram,0x08036334) */
/* WARNING: Removing unreachable block (ram,0x0803635c) */
/* WARNING: Removing unreachable block (ram,0x08036312) */
/* WARNING: Removing unreachable block (ram,0x08036348) */
/* WARNING: Removing unreachable block (ram,0x08036326) */

void FUN_080361a0(int param_1,float *param_2,uint param_3)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  
  uVar4 = param_3 >> 2;
  if (uVar4 != 0) {
    iVar1 = param_1 + 0x20;
    pfVar2 = param_2 + 4;
    uVar3 = uVar4;
    do {
      while( true ) {
        fVar5 = *(float *)(iVar1 + -0x20) * *(float *)(iVar1 + -0x20) +
                *(float *)(iVar1 + -0x1c) * *(float *)(iVar1 + -0x1c);
        if (0.0 <= fVar5) {
          pfVar2[-4] = SQRT(fVar5);
        }
        else {
          pfVar2[-4] = 0.0;
        }
        fVar5 = *(float *)(iVar1 + -0x18) * *(float *)(iVar1 + -0x18) +
                *(float *)(iVar1 + -0x14) * *(float *)(iVar1 + -0x14);
        if (fVar5 < 0.0) {
          pfVar2[-3] = 0.0;
        }
        else {
          pfVar2[-3] = SQRT(fVar5);
        }
        fVar5 = *(float *)(iVar1 + -0x10) * *(float *)(iVar1 + -0x10) +
                *(float *)(iVar1 + -0xc) * *(float *)(iVar1 + -0xc);
        if (fVar5 < 0.0) {
          pfVar2[-2] = 0.0;
        }
        else {
          pfVar2[-2] = SQRT(fVar5);
        }
        fVar5 = *(float *)(iVar1 + -8) * *(float *)(iVar1 + -8) +
                *(float *)(iVar1 + -4) * *(float *)(iVar1 + -4);
        if (fVar5 < 0.0) break;
        uVar3 = uVar3 - 1;
        pfVar2[-1] = SQRT(fVar5);
        iVar1 = iVar1 + 0x20;
        pfVar2 = pfVar2 + 4;
        if (uVar3 == 0) goto LAB_080362a4;
      }
      uVar3 = uVar3 - 1;
      pfVar2[-1] = 0.0;
      iVar1 = iVar1 + 0x20;
      pfVar2 = pfVar2 + 4;
    } while (uVar3 != 0);
LAB_080362a4:
    param_1 = param_1 + uVar4 * 0x20;
    param_2 = param_2 + uVar4 * 4;
  }
  param_3 = param_3 & 3;
  if (param_3 != 0) {
    param_1 = param_1 + 8;
    do {
      while( true ) {
        fVar5 = *(float *)(param_1 + -8) * *(float *)(param_1 + -8) +
                *(float *)(param_1 + -4) * *(float *)(param_1 + -4);
        if (0.0 <= fVar5) break;
        param_3 = param_3 - 1;
        *param_2 = 0.0;
        param_1 = param_1 + 8;
        param_2 = param_2 + 1;
        if (param_3 == 0) {
          return;
        }
      }
      param_3 = param_3 - 1;
      *param_2 = SQRT(fVar5);
      param_1 = param_1 + 8;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  return;
}

