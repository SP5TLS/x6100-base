
void FUN_08036000(int *param_1,float *param_2,float *param_3,uint param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  uVar8 = param_4 >> 2;
  iVar7 = *param_1;
  pfVar5 = (float *)param_1[1];
  pfVar6 = (float *)param_1[2];
  do {
    fVar13 = *pfVar6;
    fVar12 = pfVar6[1];
    fVar11 = pfVar6[2];
    fVar10 = pfVar6[3];
    fVar9 = pfVar6[4];
    fVar18 = *pfVar5;
    fVar19 = pfVar5[1];
    fVar16 = pfVar5[2];
    fVar17 = pfVar5[3];
    uVar4 = uVar8;
    pfVar1 = param_2;
    pfVar2 = param_3;
    uVar3 = param_4 & 3;
    if (uVar8 != 0) {
      do {
        fVar15 = *pfVar1;
        fVar17 = fVar13 * fVar15 + fVar12 * fVar18 + fVar11 * fVar19 + fVar10 * fVar16 +
                 fVar9 * fVar17;
        *pfVar2 = fVar17;
        fVar14 = pfVar1[1];
        fVar16 = fVar13 * fVar14 + fVar12 * fVar15 + fVar11 * fVar18 + fVar10 * fVar17 +
                 fVar9 * fVar16;
        pfVar2[1] = fVar16;
        fVar19 = pfVar1[2];
        fVar17 = fVar13 * fVar19 + fVar12 * fVar14 + fVar11 * fVar15 + fVar10 * fVar16 +
                 fVar9 * fVar17;
        uVar4 = uVar4 - 1;
        pfVar2[2] = fVar17;
        fVar18 = pfVar1[3];
        fVar16 = fVar13 * fVar18 + fVar12 * fVar19 + fVar11 * fVar14 + fVar10 * fVar17 +
                 fVar9 * fVar16;
        pfVar2[3] = fVar16;
        pfVar1 = pfVar1 + 4;
        pfVar2 = pfVar2 + 4;
      } while (uVar4 != 0);
      param_2 = param_2 + uVar8 * 4;
      pfVar2 = param_3 + uVar8 * 4;
    }
    for (; fVar15 = fVar18, fVar14 = fVar16, uVar3 != 0; uVar3 = uVar3 - 1) {
      fVar18 = *param_2;
      param_2 = param_2 + 1;
      fVar16 = fVar13 * fVar18 + fVar12 * fVar15 + fVar11 * fVar19 + fVar10 * fVar14 +
               fVar9 * fVar17;
      *pfVar2 = fVar16;
      pfVar2 = pfVar2 + 1;
      fVar17 = fVar14;
      fVar19 = fVar15;
    }
    iVar7 = iVar7 + -1;
    *pfVar5 = fVar15;
    pfVar5[1] = fVar19;
    pfVar5[2] = fVar14;
    pfVar5[3] = fVar17;
    param_2 = param_3;
    pfVar5 = pfVar5 + 4;
    pfVar6 = pfVar6 + 5;
  } while (iVar7 != 0);
  return;
}

