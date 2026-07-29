
void FUN_08035364(byte *param_1,float *param_2,float *param_3,uint param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  ushort uVar5;
  float *pfVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  float *pfVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  uint uVar16;
  float *pfVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float *local_5c;
  uint local_58;
  float *local_54;
  float *local_50;
  float *local_4c;
  float *local_48;
  uint local_40;
  float *local_3c;
  float *local_38;
  
  uVar5 = *(ushort *)(param_1 + 2);
  uVar16 = (uint)uVar5;
  local_3c = *(float **)(param_1 + 8);
  local_38 = local_3c + uVar16 + 0x3fffffff;
  uVar8 = param_4 & 3;
  param_4 = param_4 >> 2;
  iVar20 = *(int *)(param_1 + 4);
  local_54 = param_3;
  local_48 = param_2;
  if (param_4 != 0) {
    iVar9 = (ushort)((uVar5 >> 2) - 1) + 1;
    pfVar15 = local_3c + iVar9 * 4 + 3;
    pfVar14 = local_3c + 3;
    local_40 = param_4;
    pfVar6 = local_38;
    pfVar7 = param_2;
    do {
      local_4c = pfVar7 + 4;
      local_50 = pfVar6 + 4;
      *pfVar6 = *pfVar7;
      pfVar6[1] = pfVar7[1];
      pfVar6[2] = pfVar7[2];
      pfVar6[3] = pfVar7[3];
      uVar11 = (uint)*param_1;
      if (uVar11 == 0) {
        uVar11 = 0;
      }
      else {
        iVar21 = 1;
        uVar18 = uVar11;
        pfVar6 = local_54;
        while( true ) {
          fVar27 = pfVar14[-3];
          fVar26 = pfVar14[-2];
          fVar25 = pfVar14[-1];
          pfVar17 = (float *)(iVar20 + (uVar18 - iVar21) * 4);
          pfVar7 = pfVar14;
          fVar24 = DAT_080356e8;
          fVar29 = DAT_080356e8;
          fVar32 = DAT_080356e8;
          fVar39 = DAT_080356e8;
          if (uVar5 >> 2 != 0) {
            iVar19 = (int)(short)uVar18;
            pfVar7 = pfVar14 + 4;
            pfVar10 = pfVar17;
            do {
              fVar33 = pfVar7[-4];
              fVar34 = *pfVar10;
              pfVar10 = pfVar10 + iVar19;
              fVar35 = *pfVar10;
              fVar36 = fVar27 * fVar34;
              fVar22 = fVar26 * fVar34;
              fVar27 = pfVar7[-3];
              fVar28 = fVar25 * fVar34;
              pfVar10 = pfVar10 + iVar19;
              fVar30 = fVar26 * fVar35;
              fVar26 = pfVar7[-2];
              fVar37 = *pfVar10;
              fVar23 = fVar25 * fVar35;
              fVar38 = pfVar10[iVar19];
              fVar31 = fVar25 * fVar37;
              fVar25 = pfVar7[-1];
              pfVar7 = pfVar7 + 4;
              pfVar10 = pfVar10 + iVar19 + iVar19;
              fVar32 = fVar33 * fVar38 + fVar31 + fVar30 + fVar36 + fVar32;
              fVar24 = fVar27 * fVar38 + fVar33 * fVar37 + fVar23 + fVar22 + fVar24;
              fVar29 = fVar26 * fVar38 + fVar27 * fVar37 + fVar33 * fVar35 + fVar28 + fVar29;
              fVar39 = fVar25 * fVar38 +
                       fVar26 * fVar37 + fVar27 * fVar35 + fVar33 * fVar34 + fVar39;
            } while (pfVar7 != pfVar15 + 4);
            pfVar17 = (float *)(iVar19 * 0x10 * iVar9 + (int)pfVar17);
            pfVar7 = pfVar15;
          }
          if ((uVar5 & 3) != 0) {
            pfVar10 = pfVar7 + ((uVar16 & 3) - 1 & 0xffff) + 1;
            do {
              fVar22 = fVar26;
              fVar26 = fVar25;
              fVar23 = *pfVar17;
              fVar25 = *pfVar7;
              pfVar7 = pfVar7 + 1;
              fVar32 = fVar32 + fVar27 * fVar23;
              pfVar17 = pfVar17 + uVar18;
              fVar24 = fVar24 + fVar22 * fVar23;
              fVar29 = fVar29 + fVar26 * fVar23;
              fVar39 = fVar39 + fVar25 * fVar23;
              fVar27 = fVar22;
            } while (pfVar7 != pfVar10);
          }
          *pfVar6 = fVar32;
          pfVar6[*param_1] = fVar24;
          pfVar6[(uint)*param_1 * 2] = fVar29;
          iVar21 = iVar21 + 1;
          pfVar6[(uint)*param_1 * 3] = fVar39;
          pfVar6 = pfVar6 + 1;
          if (iVar21 == uVar11 + 1) break;
          uVar18 = (uint)*param_1;
        }
        local_54 = local_54 + uVar11;
        uVar11 = (uint)*param_1;
      }
      pfVar14 = pfVar14 + 4;
      pfVar15 = pfVar15 + 4;
      local_54 = local_54 + uVar11 * 3;
      local_40 = local_40 - 1;
      pfVar6 = local_50;
      pfVar7 = local_4c;
    } while (local_40 != 0);
    local_38 = local_38 + param_4 * 4;
    local_48 = param_2 + param_4 * 4;
    local_3c = local_3c + param_4 * 4;
  }
  if (uVar8 != 0) {
    iVar9 = (ushort)((uVar5 >> 2) - 1) + 1;
    pfVar7 = local_3c + iVar9 * 4;
    local_5c = local_38;
    pfVar6 = local_3c;
    local_58 = uVar8;
    do {
      *local_5c = *local_48;
      uVar11 = (uint)*param_1;
      if (uVar11 != 0) {
        iVar21 = 1;
        uVar18 = uVar11;
        pfVar15 = local_54;
        while( true ) {
          pfVar17 = (float *)(iVar20 + (uVar18 - iVar21) * 4);
          pfVar14 = pfVar6;
          fVar24 = DAT_080356e8;
          if (uVar5 >> 2 != 0) {
            pfVar10 = pfVar6 + 4;
            pfVar14 = pfVar17;
            do {
              pfVar1 = pfVar10 + -4;
              fVar25 = *pfVar14;
              pfVar2 = pfVar10 + -3;
              pfVar3 = pfVar10 + -2;
              pfVar4 = pfVar10 + -1;
              pfVar12 = pfVar14 + uVar18;
              pfVar13 = pfVar12 + uVar18;
              pfVar10 = pfVar10 + 4;
              pfVar14 = pfVar13 + uVar18 + uVar18;
              fVar24 = *pfVar4 * pfVar13[uVar18] +
                       *pfVar3 * *pfVar13 + *pfVar2 * *pfVar12 + *pfVar1 * fVar25 + fVar24;
            } while (pfVar10 != pfVar7 + 4);
            pfVar17 = (float *)(iVar9 * uVar18 * 0x10 + (int)pfVar17);
            pfVar14 = pfVar7;
          }
          if ((uVar5 & 3) != 0) {
            pfVar10 = pfVar14 + ((uVar16 & 3) - 1 & 0xffff) + 1;
            do {
              fVar25 = *pfVar14;
              pfVar14 = pfVar14 + 1;
              fVar26 = *pfVar17;
              pfVar17 = pfVar17 + uVar18;
              fVar24 = fVar24 + fVar25 * fVar26;
            } while (pfVar14 != pfVar10);
          }
          iVar21 = iVar21 + 1;
          *pfVar15 = fVar24;
          pfVar15 = pfVar15 + 1;
          if (iVar21 == uVar11 + 1) break;
          uVar18 = (uint)*param_1;
        }
        local_54 = local_54 + uVar11;
      }
      local_58 = local_58 - 1;
      pfVar6 = pfVar6 + 1;
      pfVar7 = pfVar7 + 1;
      local_5c = local_5c + 1;
      local_48 = local_48 + 1;
    } while (local_58 != 0);
    local_3c = local_3c + uVar8;
  }
  pfVar6 = *(float **)(param_1 + 8);
  uVar8 = (uVar16 - 1 & 0x3ffff) >> 2;
  if (uVar8 != 0) {
    uVar8 = uVar8 - 1 & 0xffff;
    pfVar15 = pfVar6 + 4;
    pfVar7 = local_3c;
    do {
      pfVar15[-4] = *pfVar7;
      pfVar15[-3] = pfVar7[1];
      pfVar15[-2] = pfVar7[2];
      pfVar15[-1] = pfVar7[3];
      pfVar15 = pfVar15 + 4;
      pfVar7 = pfVar7 + 4;
    } while (pfVar15 != pfVar6 + (uVar8 + 2) * 4);
    iVar20 = uVar8 + 1;
    local_3c = local_3c + iVar20 * 4;
    pfVar6 = pfVar6 + iVar20 * 4;
  }
  uVar8 = uVar16 - 1 & 3;
  if (uVar8 != 0) {
    pfVar7 = local_3c;
    do {
      pfVar15 = pfVar7 + 1;
      *pfVar6 = *pfVar7;
      pfVar7 = pfVar15;
      pfVar6 = pfVar6 + 1;
    } while (pfVar15 != local_3c + (uVar8 - 1 & 0xffff) + 1);
  }
  return;
}

