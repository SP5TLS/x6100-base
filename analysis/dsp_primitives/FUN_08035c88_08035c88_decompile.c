
void FUN_08035c88(byte *param_1,float *param_2,float *param_3,uint param_4)

{
  ushort uVar1;
  byte bVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  float *pfVar13;
  float *pfVar14;
  uint uVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  float *pfVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float *local_74;
  uint local_6c;
  float *local_58;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar4 = (uint)uVar1;
  uVar5 = (uint)*param_1;
  uVar12 = param_4 / uVar5 >> 2;
  iVar10 = param_4 / uVar5 + uVar12 * -4;
  pfVar16 = *(float **)(param_1 + 8);
  pfVar11 = *(float **)(param_1 + 4);
  local_74 = pfVar16 + uVar4 + 0x3fffffff;
  local_58 = param_3;
  if (uVar12 != 0) {
    uVar15 = (uint)(uVar1 >> 2);
    pfVar7 = param_3;
    local_6c = uVar12;
    while( true ) {
      iVar8 = uVar5 << 2;
      pfVar14 = param_2;
      pfVar13 = local_74;
      do {
        *pfVar13 = *pfVar14;
        iVar8 = iVar8 + -1;
        pfVar14 = pfVar14 + 1;
        pfVar13 = pfVar13 + 1;
      } while (iVar8 != 0);
      bVar2 = *param_1;
      pfVar19 = pfVar16 + bVar2;
      pfVar18 = pfVar19 + bVar2;
      local_74 = local_74 + uVar5 * 4;
      param_2 = param_2 + uVar5 * 4;
      pfVar17 = pfVar18 + bVar2;
      pfVar6 = pfVar17;
      pfVar9 = pfVar11;
      uVar5 = uVar15;
      fVar20 = DAT_08035ffc;
      fVar21 = DAT_08035ffc;
      fVar22 = DAT_08035ffc;
      fVar23 = DAT_08035ffc;
      pfVar14 = pfVar19;
      pfVar13 = pfVar18;
      pfVar3 = pfVar16;
      if (uVar15 != 0) {
        do {
          fVar24 = *pfVar9;
          fVar25 = pfVar9[1];
          fVar26 = pfVar9[2];
          fVar27 = pfVar9[3];
          uVar5 = uVar5 - 1;
          fVar20 = fVar27 * pfVar3[3] +
                   fVar26 * pfVar3[2] + fVar25 * pfVar3[1] + fVar24 * *pfVar3 + fVar20;
          fVar21 = fVar27 * pfVar14[3] +
                   fVar26 * pfVar14[2] + fVar25 * pfVar14[1] + fVar24 * *pfVar14 + fVar21;
          fVar22 = fVar27 * pfVar13[3] +
                   fVar26 * pfVar13[2] + fVar25 * pfVar13[1] + fVar24 * *pfVar13 + fVar22;
          fVar23 = fVar27 * pfVar6[3] +
                   fVar26 * pfVar6[2] + fVar25 * pfVar6[1] + fVar24 * *pfVar6 + fVar23;
          pfVar14 = pfVar14 + 4;
          pfVar13 = pfVar13 + 4;
          pfVar6 = pfVar6 + 4;
          pfVar3 = pfVar3 + 4;
          pfVar9 = pfVar9 + 4;
        } while (uVar5 != 0);
        pfVar16 = pfVar16 + uVar15 * 4;
        pfVar19 = pfVar19 + uVar15 * 4;
        pfVar18 = pfVar18 + uVar15 * 4;
        pfVar6 = pfVar17 + uVar15 * 4;
        pfVar9 = pfVar11 + uVar15 * 4;
      }
      uVar5 = uVar4 & 3;
      if ((uVar1 & 3) != 0) {
        do {
          fVar28 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          fVar24 = *pfVar16;
          pfVar16 = pfVar16 + 1;
          fVar25 = *pfVar19;
          pfVar19 = pfVar19 + 1;
          fVar26 = *pfVar18;
          pfVar18 = pfVar18 + 1;
          fVar27 = *pfVar6;
          pfVar6 = pfVar6 + 1;
          uVar5 = uVar5 - 1;
          fVar20 = fVar20 + fVar28 * fVar24;
          fVar21 = fVar21 + fVar28 * fVar25;
          fVar22 = fVar22 + fVar28 * fVar26;
          fVar23 = fVar23 + fVar28 * fVar27;
        } while (uVar5 != 0);
      }
      *pfVar7 = fVar20;
      local_6c = local_6c - 1;
      pfVar7[1] = fVar21;
      pfVar7[2] = fVar22;
      pfVar7[3] = fVar23;
      pfVar16 = pfVar17 + bVar2;
      if (local_6c == 0) break;
      uVar5 = (uint)*param_1;
      pfVar7 = pfVar7 + 4;
    }
    local_58 = param_3 + uVar12 * 4;
  }
  if (iVar10 != 0) {
    uVar5 = (uint)(uVar1 >> 2);
    do {
      uVar15 = (uint)*param_1;
      pfVar7 = local_74;
      pfVar14 = param_2;
      uVar12 = uVar15;
      do {
        fVar20 = *pfVar14;
        pfVar14 = pfVar14 + 1;
        uVar12 = uVar12 - 1;
        *pfVar7 = fVar20;
        pfVar7 = pfVar7 + 1;
      } while (uVar12 != 0);
      local_74 = local_74 + uVar15;
      param_2 = param_2 + uVar15;
      pfVar14 = pfVar16;
      uVar12 = uVar5;
      pfVar7 = pfVar11;
      fVar20 = DAT_08035ffc;
      if (uVar5 != 0) {
        do {
          uVar12 = uVar12 - 1;
          fVar20 = pfVar14[3] * pfVar7[3] +
                   pfVar14[2] * pfVar7[2] + pfVar14[1] * pfVar7[1] + *pfVar14 * *pfVar7 + fVar20;
          pfVar7 = pfVar7 + 4;
          pfVar14 = pfVar14 + 4;
        } while (uVar12 != 0);
        pfVar14 = pfVar16 + uVar5 * 4;
        pfVar7 = pfVar11 + uVar5 * 4;
      }
      uVar12 = uVar4 & 3;
      if ((uVar1 & 3) != 0) {
        do {
          fVar21 = *pfVar14;
          pfVar14 = pfVar14 + 1;
          fVar22 = *pfVar7;
          pfVar7 = pfVar7 + 1;
          uVar12 = uVar12 - 1;
          fVar20 = fVar20 + fVar21 * fVar22;
        } while (uVar12 != 0);
      }
      bVar2 = *param_1;
      *local_58 = fVar20;
      local_58 = local_58 + 1;
      iVar10 = iVar10 + -1;
      pfVar16 = pfVar16 + bVar2;
    } while (iVar10 != 0);
  }
  pfVar14 = *(float **)(param_1 + 8);
  uVar12 = uVar4 - 1 >> 2;
  uVar5 = uVar12;
  pfVar11 = pfVar14;
  pfVar7 = pfVar16;
  if (uVar12 != 0) {
    do {
      *pfVar11 = *pfVar7;
      pfVar11[1] = pfVar7[1];
      pfVar11[2] = pfVar7[2];
      pfVar11[3] = pfVar7[3];
      uVar5 = uVar5 - 1;
      pfVar11 = pfVar11 + 4;
      pfVar7 = pfVar7 + 4;
    } while (uVar5 != 0);
    pfVar14 = pfVar14 + uVar12 * 4;
    pfVar16 = pfVar16 + uVar12 * 4;
  }
  for (uVar4 = uVar4 - 1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pfVar14 = *pfVar16;
    pfVar14 = pfVar14 + 1;
    pfVar16 = pfVar16 + 1;
  }
  return;
}

