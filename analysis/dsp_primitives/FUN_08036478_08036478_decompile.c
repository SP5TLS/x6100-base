
void FUN_08036478(float param_1,float *param_2,float *param_3,uint param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  uVar4 = param_4 >> 2;
  uVar3 = uVar4;
  pfVar1 = param_3;
  pfVar2 = param_2;
  if (uVar4 != 0) {
    do {
      fVar5 = pfVar2[1];
      fVar6 = pfVar2[2];
      fVar7 = pfVar2[3];
      uVar3 = uVar3 - 1;
      *pfVar1 = *pfVar2 * param_1;
      pfVar1[1] = fVar5 * param_1;
      pfVar1[2] = fVar6 * param_1;
      pfVar1[3] = fVar7 * param_1;
      pfVar1 = pfVar1 + 4;
      pfVar2 = pfVar2 + 4;
    } while (uVar3 != 0);
    param_2 = param_2 + uVar4 * 4;
    param_3 = param_3 + uVar4 * 4;
  }
  for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
    fVar5 = *param_2;
    param_2 = param_2 + 1;
    *param_3 = fVar5 * param_1;
    param_3 = param_3 + 1;
  }
  return;
}

