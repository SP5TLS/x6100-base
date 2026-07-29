
void FUN_0802a428(int param_1,int param_2)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int local_c;
  
  uVar1 = FUN_0803147c();
  if ((uVar1 < 2) && (param_2 != *(int *)(param_1 + 0x74))) {
    local_c = 2000000;
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)VectorSignedToFloat(2000000,(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = (float)FUN_0803b7ec(fVar2 / fVar4);
    iVar5 = (int)fVar2;
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)VectorSignedToFloat(2000000,(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = (float)FUN_0803b768(fVar2 / fVar4);
    iVar6 = (int)fVar2;
    if ((iVar5 != 0) || (iVar6 != 0)) {
      if (iVar5 == 0) {
        local_c = 2100000;
      }
      else if (param_2 + iVar5 * -2000000 < 100000) {
        fVar3 = (float)VectorSignedToFloat(2000000,(byte)(in_fpscr >> 0x16) & 3);
        fVar2 = (float)VectorSignedToFloat(100000,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
        local_c = (int)(fVar3 - fVar2 / fVar4);
      }
      else if (iVar6 * 2000000 - param_2 < 100000) {
        fVar3 = (float)VectorSignedToFloat(2000000,(byte)(in_fpscr >> 0x16) & 3);
        fVar2 = (float)VectorSignedToFloat(100000,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
        local_c = (int)(fVar3 + fVar2 / fVar4);
      }
    }
    if (*(int *)(param_1 + 0x6c) != local_c) {
      *(int *)(param_1 + 0x6c) = local_c;
      if (local_c < 1000000) {
        local_c = 1000000;
      }
      else if (2200000 < local_c) {
        local_c = 2200000;
      }
      FUN_08033428(&DAT_2000036c,4,local_c,1);
    }
  }
  return;
}

