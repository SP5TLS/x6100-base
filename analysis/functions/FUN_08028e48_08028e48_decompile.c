
void FUN_08028e48(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  short sVar9;
  uint uVar10;
  byte *pbVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  uint local_34 [2];
  
  iVar6 = 0;
  uVar10 = 0xffffffff;
  do {
    if (iVar6 != DAT_20000004) {
      if (iVar6 == 0) {
        DAT_2000c6e4 = DAT_2000c6e4 & 0xffefffff;
      }
      else {
        DAT_2000c6e4 = DAT_2000c6e4 | 0x100000;
      }
      DAT_20000004 = iVar6;
      (*DAT_2000c6f0)(&DAT_2000c6e0);
    }
    pbVar8 = (byte *)0x803dc2f;
    do {
      pbVar8 = pbVar8 + 1;
      bVar1 = *pbVar8;
      if (bVar1 != DAT_20000008) {
        uVar4 = (uint)(DAT_20000001 & bVar1);
        if ((int)(uVar4 << 0x1f) < 0) {
          uVar7 = DAT_2000c6e4 | 0x200000;
        }
        else {
          uVar7 = DAT_2000c6e4 & 0xffdfffff;
        }
        if ((int)(uVar4 << 0x1e) < 0) {
          uVar7 = uVar7 | 0x10000;
        }
        else {
          uVar7 = uVar7 & 0xfffeffff;
        }
        if ((int)(uVar4 << 0x1d) < 0) {
          uVar7 = uVar7 | 0x8000;
        }
        else {
          uVar7 = uVar7 & 0xffff7fff;
        }
        if ((int)(uVar4 << 0x1c) < 0) {
          uVar7 = uVar7 | 0x4000;
        }
        else {
          uVar7 = uVar7 & 0xffffbfff;
        }
        if ((int)(uVar4 << 0x1b) < 0) {
          uVar7 = uVar7 | 0x20000;
        }
        else {
          uVar7 = uVar7 & 0xfffdffff;
        }
        if ((int)(uVar4 << 0x1a) < 0) {
          uVar7 = uVar7 | 0x40000;
        }
        else {
          uVar7 = uVar7 & 0xfffbffff;
        }
        if ((int)(uVar4 << 0x19) < 0) {
          DAT_2000c6e4 = uVar7 | 0x80000;
        }
        else {
          DAT_2000c6e4 = uVar7 & 0xfff7ffff;
        }
        DAT_20000008 = (uint)bVar1;
        (*DAT_2000c6f0)(&DAT_2000c6e0);
      }
      pbVar11 = (byte *)0x803dc2f;
      do {
        pbVar11 = pbVar11 + 1;
        bVar2 = *pbVar11;
        if (bVar2 != DAT_2000000c) {
          uVar4 = (uint)(DAT_20000000 & bVar2);
          if ((int)(uVar4 << 0x1f) < 0) {
            uVar7 = DAT_2000c6e4 | 1;
          }
          else {
            uVar7 = DAT_2000c6e4 & 0xfffffffe;
          }
          if ((int)(uVar4 << 0x1e) < 0) {
            uVar7 = uVar7 | 2;
          }
          else {
            uVar7 = uVar7 & 0xfffffffd;
          }
          if ((int)(uVar4 << 0x1d) < 0) {
            uVar7 = uVar7 | 4;
          }
          else {
            uVar7 = uVar7 & 0xfffffffb;
          }
          if ((int)(uVar4 << 0x1c) < 0) {
            uVar7 = uVar7 | 8;
          }
          else {
            uVar7 = uVar7 & 0xfffffff7;
          }
          if ((int)(uVar4 << 0x1b) < 0) {
            uVar7 = uVar7 | 0x10;
          }
          else {
            uVar7 = uVar7 & 0xffffffef;
          }
          if ((int)(uVar4 << 0x1a) < 0) {
            uVar7 = uVar7 | 0x20;
          }
          else {
            uVar7 = uVar7 & 0xffffffdf;
          }
          if ((int)(uVar4 << 0x19) < 0) {
            DAT_2000c6e4 = uVar7 | 0x40;
          }
          else {
            DAT_2000c6e4 = uVar7 & 0xffffffbf;
          }
          DAT_2000000c = (uint)bVar2;
          (*DAT_2000c6f0)(&DAT_2000c6e0);
        }
        FUN_080349e4(3);
        fVar12 = (float)FUN_08024468(100);
        sVar9 = 5;
        do {
          FUN_080349e4(10);
          fVar13 = (float)FUN_08024468(100);
          uVar4 = in_fpscr & 0xfffffff;
          in_fpscr = uVar4 | (uint)(fVar13 == fVar12) << 0x1e;
          sVar9 = sVar9 + -1;
          fVar14 = (fVar13 - fVar12) * (fVar13 - fVar12);
          if ((byte)(in_fpscr >> 0x1e) != 0) break;
          if (sVar9 == 0) {
            uVar4 = uVar4 | (uint)(fVar13 < fVar12) << 0x1f | (uint)(fVar13 == fVar12) << 0x1e;
            in_fpscr = uVar4 | (uint)(NAN(fVar13) || NAN(fVar12)) << 0x1c;
            bVar3 = (byte)(uVar4 >> 0x18);
            if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
              local_34[0] = VectorFloatToUnsigned(fVar12 * 10.0,3);
              goto joined_r0x08029088;
            }
            break;
          }
          uVar4 = uVar4 | (uint)(fVar14 < 1.0) << 0x1f | (uint)(fVar14 == 1.0) << 0x1e;
          in_fpscr = uVar4 | (uint)NAN(fVar14) << 0x1c;
          bVar3 = (byte)(uVar4 >> 0x18);
          fVar12 = fVar13;
        } while (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
        local_34[0] = VectorFloatToUnsigned(fVar13 * 10.0,3);
joined_r0x08029088:
        if ((local_34[0] < uVar10) && (iVar5 = FUN_08028d68(local_34), iVar5 != 0)) {
          *(byte *)(param_1 + 1) = bVar1;
          *(char *)((int)param_1 + 6) = (char)iVar6;
          *(byte *)((int)param_1 + 5) = bVar2;
          *param_1 = local_34[0];
          uVar10 = local_34[0];
        }
        fVar12 = (float)VectorUnsignedToFloat(local_34[0],(byte)(in_fpscr >> 0x16) & 3);
        in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar12 == 20.0) << 0x1e |
                   (uint)(20.0 <= fVar12) << 0x1d;
        bVar3 = (byte)(in_fpscr >> 0x18);
        if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) &&
           (iVar5 = FUN_08028d68(local_34), iVar5 != 0)) {
          *param_1 = local_34[0];
          *(byte *)((int)param_1 + 5) = bVar2;
          *(byte *)(param_1 + 1) = bVar1;
          *(char *)((int)param_1 + 6) = (char)iVar6;
          return;
        }
      } while (pbVar11 != (byte *)0x803dc38);
    } while (pbVar8 != (byte *)0x803dc38);
    if (iVar6 != 0) {
      return;
    }
    iVar6 = 1;
  } while( true );
}

