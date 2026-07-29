
void FUN_080357c0(ushort *param_1,float *param_2,float *param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  float *pfVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
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
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float fVar65;
  float fVar66;
  float fVar67;
  float fVar68;
  float *local_88;
  
  uVar1 = *param_1;
  uVar4 = (uint)uVar1;
  pfVar15 = *(float **)(param_1 + 2);
  local_88 = pfVar15 + uVar4 + 0x3fffffff;
  uVar6 = param_4 >> 3;
  pfVar11 = *(float **)(param_1 + 4);
  if (uVar6 != 0) {
    uVar12 = (uint)(uVar1 >> 3);
    uVar16 = uVar6;
    pfVar10 = pfVar15;
    pfVar9 = param_3;
    pfVar8 = param_2;
    pfVar3 = local_88;
    do {
      *pfVar3 = *pfVar8;
      pfVar3[1] = pfVar8[1];
      pfVar3[2] = pfVar8[2];
      pfVar3[3] = pfVar8[3];
      pfVar3[4] = pfVar8[4];
      pfVar3[5] = pfVar8[5];
      pfVar3[6] = pfVar8[6];
      fVar24 = DAT_08035c30;
      pfVar3[7] = pfVar8[7];
      fVar23 = *pfVar10;
      fVar22 = pfVar10[1];
      fVar21 = pfVar10[2];
      fVar20 = pfVar10[3];
      fVar19 = pfVar10[4];
      fVar18 = pfVar10[5];
      fVar17 = pfVar10[6];
      pfVar14 = pfVar11;
      fVar39 = fVar24;
      fVar51 = fVar24;
      fVar47 = fVar24;
      fVar43 = fVar24;
      fVar53 = fVar24;
      fVar54 = fVar24;
      iVar2 = -4;
      fVar55 = fVar24;
      if (uVar12 != 0) {
        pfVar7 = pfVar10 + 0xf;
        uVar13 = uVar12;
        pfVar5 = pfVar11;
        do {
          fVar38 = pfVar7[-8];
          fVar25 = *pfVar5;
          fVar29 = pfVar5[1];
          fVar32 = pfVar5[2];
          fVar33 = pfVar5[3];
          fVar34 = pfVar5[4];
          fVar35 = pfVar5[5];
          fVar36 = pfVar5[6];
          fVar37 = pfVar5[7];
          fVar63 = fVar23 * fVar25;
          fVar60 = fVar22 * fVar25;
          fVar23 = pfVar7[-7];
          fVar58 = fVar21 * fVar25;
          fVar56 = fVar20 * fVar25;
          fVar48 = fVar19 * fVar25;
          fVar44 = fVar18 * fVar25;
          fVar40 = fVar17 * fVar25;
          fVar66 = fVar21 * fVar29;
          fVar59 = fVar20 * fVar29;
          fVar57 = fVar19 * fVar29;
          fVar49 = fVar18 * fVar29;
          fVar45 = fVar17 * fVar29;
          fVar64 = fVar22 * fVar29;
          fVar22 = pfVar7[-6];
          fVar26 = fVar21 * fVar32;
          fVar61 = fVar19 * fVar32;
          fVar21 = pfVar7[-5];
          fVar65 = fVar18 * fVar32;
          fVar67 = fVar20 * fVar32;
          fVar50 = fVar17 * fVar32;
          fVar41 = fVar19 * fVar33;
          fVar52 = fVar17 * fVar33;
          fVar27 = fVar20 * fVar33;
          fVar20 = pfVar7[-4];
          fVar62 = fVar18 * fVar33;
          fVar30 = fVar19 * fVar34;
          fVar42 = fVar18 * fVar34;
          fVar68 = fVar17 * fVar34;
          fVar19 = pfVar7[-3];
          fVar28 = fVar17 * fVar35;
          fVar31 = fVar18 * fVar35;
          fVar18 = pfVar7[-2];
          fVar46 = fVar17 * fVar36;
          fVar17 = pfVar7[-1];
          uVar13 = uVar13 - 1;
          fVar55 = fVar55 + fVar63 + fVar64 + fVar26 + fVar27 + fVar30 + fVar31 + fVar46 +
                   fVar38 * fVar37;
          fVar54 = fVar54 + fVar60 + fVar66 + fVar67 + fVar41 + fVar42 + fVar28 + fVar38 * fVar36 +
                   fVar23 * fVar37;
          fVar53 = fVar53 + fVar58 + fVar59 + fVar61 + fVar62 + fVar68 + fVar38 * fVar35 +
                   fVar23 * fVar36 + fVar22 * fVar37;
          fVar51 = fVar51 + fVar56 + fVar57 + fVar65 + fVar52 + fVar38 * fVar34 + fVar23 * fVar35 +
                   fVar22 * fVar36 + fVar21 * fVar37;
          fVar47 = fVar47 + fVar48 + fVar49 + fVar50 + fVar38 * fVar33 + fVar23 * fVar34 +
                   fVar22 * fVar35 + fVar21 * fVar36 + fVar20 * fVar37;
          fVar43 = fVar43 + fVar44 + fVar45 + fVar38 * fVar32 + fVar23 * fVar33 + fVar22 * fVar34 +
                   fVar21 * fVar35 + fVar20 * fVar36 + fVar19 * fVar37;
          fVar39 = fVar39 + fVar40 + fVar38 * fVar29 + fVar23 * fVar32 + fVar22 * fVar33 +
                   fVar21 * fVar34 + fVar20 * fVar35 + fVar19 * fVar36 + fVar18 * fVar37;
          fVar24 = fVar24 + fVar38 * fVar25 + fVar23 * fVar29 + fVar22 * fVar32 + fVar21 * fVar33 +
                   fVar20 * fVar34 + fVar19 * fVar35 + fVar18 * fVar36 + fVar17 * fVar37;
          pfVar7 = pfVar7 + 8;
          pfVar14 = pfVar11 + uVar12 * 8;
          iVar2 = uVar12 * 0x20 + -4;
          pfVar5 = pfVar5 + 8;
        } while (uVar13 != 0);
      }
      pfVar5 = (float *)(iVar2 + (int)(pfVar10 + 8));
      uVar13 = uVar4 & 7;
      if ((uVar1 & 7) != 0) {
        do {
          fVar25 = fVar22;
          fVar22 = fVar21;
          fVar21 = fVar20;
          fVar20 = fVar19;
          fVar19 = fVar18;
          fVar18 = fVar17;
          fVar26 = *pfVar14;
          pfVar14 = pfVar14 + 1;
          fVar17 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          uVar13 = uVar13 - 1;
          fVar55 = fVar55 + fVar23 * fVar26;
          fVar54 = fVar54 + fVar25 * fVar26;
          fVar53 = fVar53 + fVar22 * fVar26;
          fVar51 = fVar51 + fVar21 * fVar26;
          fVar47 = fVar47 + fVar20 * fVar26;
          fVar43 = fVar43 + fVar19 * fVar26;
          fVar39 = fVar39 + fVar18 * fVar26;
          fVar24 = fVar24 + fVar17 * fVar26;
          fVar23 = fVar25;
        } while (uVar13 != 0);
      }
      uVar16 = uVar16 - 1;
      *pfVar9 = fVar55;
      pfVar9[1] = fVar54;
      pfVar9[2] = fVar53;
      pfVar9[3] = fVar51;
      pfVar9[4] = fVar47;
      pfVar9[5] = fVar43;
      pfVar9[6] = fVar39;
      pfVar9[7] = fVar24;
      pfVar10 = pfVar10 + 8;
      pfVar9 = pfVar9 + 8;
      pfVar8 = pfVar8 + 8;
      pfVar3 = pfVar3 + 8;
    } while (uVar16 != 0);
    local_88 = local_88 + uVar6 * 8;
    param_2 = param_2 + uVar6 * 8;
    pfVar15 = pfVar15 + uVar6 * 8;
    param_3 = param_3 + uVar6 * 8;
  }
  param_4 = param_4 & 7;
  pfVar10 = pfVar15;
  uVar6 = param_4;
  if (param_4 != 0) {
    do {
      fVar24 = DAT_08035c30;
      *local_88 = *param_2;
      pfVar9 = pfVar10;
      uVar16 = uVar4;
      pfVar8 = pfVar11;
      do {
        fVar17 = *pfVar9;
        pfVar9 = pfVar9 + 1;
        fVar18 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        uVar16 = uVar16 - 1;
        fVar24 = fVar24 + fVar17 * fVar18;
      } while (uVar16 != 0);
      uVar6 = uVar6 - 1;
      *param_3 = fVar24;
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
      pfVar10 = pfVar10 + 1;
      local_88 = local_88 + 1;
    } while (uVar6 != 0);
    pfVar15 = pfVar15 + param_4;
  }
  uVar16 = uVar4 - 1 >> 2;
  pfVar9 = *(float **)(param_1 + 2);
  uVar6 = uVar16;
  pfVar11 = pfVar9;
  pfVar10 = pfVar15;
  if (uVar16 != 0) {
    do {
      *pfVar11 = *pfVar10;
      pfVar11[1] = pfVar10[1];
      pfVar11[2] = pfVar10[2];
      pfVar11[3] = pfVar10[3];
      uVar6 = uVar6 - 1;
      pfVar11 = pfVar11 + 4;
      pfVar10 = pfVar10 + 4;
    } while (uVar6 != 0);
    pfVar9 = pfVar9 + uVar16 * 4;
    pfVar15 = pfVar15 + uVar16 * 4;
  }
  for (uVar4 = uVar4 - 1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pfVar9 = *pfVar15;
    pfVar9 = pfVar9 + 1;
    pfVar15 = pfVar15 + 1;
  }
  return;
}

