
bool FUN_08028d68(uint *param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  
  iVar5 = 5;
  uVar1 = *param_1;
  do {
    iVar3 = 3;
    uVar4 = 0;
LAB_08028d88:
    do {
      FUN_080349e4(0x10);
      fVar6 = (float)FUN_08024468(100);
      sVar2 = 5;
      do {
        FUN_080349e4(10);
        fVar7 = (float)FUN_08024468(100);
        fVar8 = fVar7 - fVar6;
        sVar2 = sVar2 + -1;
        if (fVar7 == fVar6) break;
        if (sVar2 == 0) {
          if (fVar6 < fVar7) {
            iVar3 = iVar3 + -1;
            iVar9 = VectorFloatToUnsigned(fVar6 * 10.0,3);
            uVar4 = uVar4 + iVar9;
            if (iVar3 == 0) goto LAB_08028de6;
            goto LAB_08028d88;
          }
          break;
        }
        fVar6 = fVar7;
      } while (1.0 < fVar8 * fVar8);
      iVar3 = iVar3 + -1;
      iVar9 = VectorFloatToUnsigned(fVar7 * 10.0,3);
      uVar4 = uVar4 + iVar9;
    } while (iVar3 != 0);
LAB_08028de6:
    iVar3 = uVar4 / 3 - uVar1;
    uVar4 = uVar4 / 3;
    if (iVar3 * iVar3 < 0x9c4) {
      if (uVar1 <= uVar4) {
        uVar4 = uVar1;
      }
      goto LAB_08028e2e;
    }
    iVar5 = iVar5 + -1;
    uVar1 = uVar4;
    if (iVar5 == 0) {
LAB_08028e2e:
      uVar1 = *param_1;
      if (uVar4 <= uVar1) {
        *param_1 = uVar4;
      }
      return uVar4 <= uVar1;
    }
  } while( true );
}

