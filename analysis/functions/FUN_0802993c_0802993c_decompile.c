
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0802993c(uint *param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  ushort uVar13;
  short *psVar14;
  uint uVar15;
  uint in_fpscr;
  float fVar16;
  float fVar17;
  float fVar18;
  int iVar19;
  uint local_74;
  uint local_70;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  
  bVar1 = *(byte *)((int)param_1 + 5);
  if (bVar1 != DAT_2000000c) {
    uVar3 = (uint)(DAT_20000000 & bVar1);
    if ((int)(uVar3 << 0x1f) < 0) {
      uVar5 = DAT_2000c6e4 | 1;
    }
    else {
      uVar5 = DAT_2000c6e4 & 0xfffffffe;
    }
    if ((int)(uVar3 << 0x1e) < 0) {
      uVar5 = uVar5 | 2;
    }
    else {
      uVar5 = uVar5 & 0xfffffffd;
    }
    if ((int)(uVar3 << 0x1d) < 0) {
      uVar5 = uVar5 | 4;
    }
    else {
      uVar5 = uVar5 & 0xfffffffb;
    }
    if ((int)(uVar3 << 0x1c) < 0) {
      uVar5 = uVar5 | 8;
    }
    else {
      uVar5 = uVar5 & 0xfffffff7;
    }
    if ((int)(uVar3 << 0x1b) < 0) {
      uVar5 = uVar5 | 0x10;
    }
    else {
      uVar5 = uVar5 & 0xffffffef;
    }
    if ((int)(uVar3 << 0x1a) < 0) {
      uVar5 = uVar5 | 0x20;
    }
    else {
      uVar5 = uVar5 & 0xffffffdf;
    }
    if ((int)(uVar3 << 0x19) < 0) {
      DAT_2000c6e4 = uVar5 | 0x40;
    }
    else {
      DAT_2000c6e4 = uVar5 & 0xffffffbf;
    }
    DAT_2000000c = (uint)bVar1;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  bVar1 = (byte)param_1[1];
  if (bVar1 != DAT_20000008) {
    uVar3 = (uint)(bVar1 & DAT_20000001);
    if ((int)(uVar3 << 0x1f) < 0) {
      uVar5 = DAT_2000c6e4 | 0x200000;
    }
    else {
      uVar5 = DAT_2000c6e4 & 0xffdfffff;
    }
    if ((int)(uVar3 << 0x1e) < 0) {
      uVar5 = uVar5 | 0x10000;
    }
    else {
      uVar5 = uVar5 & 0xfffeffff;
    }
    if ((int)(uVar3 << 0x1d) < 0) {
      uVar5 = uVar5 | 0x8000;
    }
    else {
      uVar5 = uVar5 & 0xffff7fff;
    }
    if ((int)(uVar3 << 0x1c) < 0) {
      uVar5 = uVar5 | 0x4000;
    }
    else {
      uVar5 = uVar5 & 0xffffbfff;
    }
    if ((int)(uVar3 << 0x1b) < 0) {
      uVar5 = uVar5 | 0x20000;
    }
    else {
      uVar5 = uVar5 & 0xfffdffff;
    }
    if ((int)(uVar3 << 0x1a) < 0) {
      uVar5 = uVar5 | 0x40000;
    }
    else {
      uVar5 = uVar5 & 0xfffbffff;
    }
    if ((int)(uVar3 << 0x19) < 0) {
      DAT_2000c6e4 = uVar5 | 0x80000;
    }
    else {
      DAT_2000c6e4 = uVar5 & 0xfff7ffff;
    }
    DAT_20000008 = (uint)bVar1;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  uVar3 = (uint)*(byte *)((int)param_1 + 6);
  if (uVar3 != DAT_20000004) {
    if (uVar3 == 0) {
      DAT_2000c6e4 = DAT_2000c6e4 & 0xffefffff;
    }
    else {
      DAT_2000c6e4 = DAT_2000c6e4 | 0x100000;
    }
    DAT_20000004 = uVar3;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  local_5c = (uint)(byte)param_1[1];
  local_60 = (uint)*(byte *)((int)param_1 + 5);
  local_70 = *param_1;
  iVar9 = 0;
  uVar13 = 0;
  local_58 = local_5c;
  local_54 = local_60;
  do {
    psVar11 = &DAT_0803dc18;
    local_50 = 0;
    do {
      psVar8 = &DAT_0803dc18;
      uVar3 = local_58;
      psVar14 = &DAT_0803dc1c;
      do {
        uVar5 = uVar3 & 0xff;
        if (uVar5 != DAT_20000008) {
          uVar4 = uVar5 & DAT_20000001;
          if ((int)(uVar4 << 0x1f) < 0) {
            uVar6 = DAT_2000c6e4 | 0x200000;
          }
          else {
            uVar6 = DAT_2000c6e4 & 0xffdfffff;
          }
          if ((int)(uVar4 << 0x1e) < 0) {
            uVar6 = uVar6 | 0x10000;
          }
          else {
            uVar6 = uVar6 & 0xfffeffff;
          }
          if ((int)(uVar4 << 0x1d) < 0) {
            uVar6 = uVar6 | 0x8000;
          }
          else {
            uVar6 = uVar6 & 0xffff7fff;
          }
          if ((int)(uVar4 << 0x1c) < 0) {
            uVar6 = uVar6 | 0x4000;
          }
          else {
            uVar6 = uVar6 & 0xffffbfff;
          }
          if ((int)(uVar4 << 0x1b) < 0) {
            uVar6 = uVar6 | 0x20000;
          }
          else {
            uVar6 = uVar6 & 0xfffdffff;
          }
          if ((int)(uVar4 << 0x1a) < 0) {
            uVar6 = uVar6 | 0x40000;
          }
          else {
            uVar6 = uVar6 & 0xfffbffff;
          }
          if ((int)(uVar4 << 0x19) < 0) {
            DAT_2000c6e4 = uVar6 | 0x80000;
          }
          else {
            DAT_2000c6e4 = uVar6 & 0xfff7ffff;
          }
          DAT_20000008 = uVar5;
          (*DAT_2000c6f0)(&DAT_2000c6e0);
        }
        FUN_080349e4(8);
        fVar16 = (float)FUN_08024468(100);
        sVar7 = 5;
        do {
          FUN_080349e4(10);
          fVar17 = (float)FUN_08024468(100);
          uVar5 = in_fpscr & 0xfffffff;
          in_fpscr = uVar5 | (uint)(fVar17 == fVar16) << 0x1e;
          sVar7 = sVar7 + -1;
          fVar18 = (fVar17 - fVar16) * (fVar17 - fVar16);
          if ((byte)(in_fpscr >> 0x1e) != 0) break;
          if (sVar7 == 0) {
            uVar5 = uVar5 | (uint)(fVar17 < fVar16) << 0x1f | (uint)(fVar17 == fVar16) << 0x1e;
            in_fpscr = uVar5 | (uint)(NAN(fVar17) || NAN(fVar16)) << 0x1c;
            bVar1 = (byte)(uVar5 >> 0x18);
            if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
              uVar5 = VectorFloatToUnsigned(fVar16 * 10.0,3);
              goto joined_r0x08029d00;
            }
            break;
          }
          uVar5 = uVar5 | (uint)(fVar18 < 1.0) << 0x1f | (uint)(fVar18 == 1.0) << 0x1e;
          in_fpscr = uVar5 | (uint)NAN(fVar18) << 0x1c;
          bVar1 = (byte)(uVar5 >> 0x18);
          fVar16 = fVar17;
        } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
        uVar5 = VectorFloatToUnsigned(fVar17 * 10.0,3);
joined_r0x08029d00:
        if (uVar5 < local_70) {
          local_74 = 5;
          uVar4 = uVar5;
          do {
            iVar10 = 3;
            uVar6 = 0;
            do {
              FUN_080349e4(0x10);
              fVar16 = (float)FUN_08024468(100);
              sVar7 = 5;
              do {
                FUN_080349e4(10);
                fVar17 = (float)FUN_08024468(100);
                uVar15 = in_fpscr & 0xfffffff;
                in_fpscr = uVar15 | (uint)(fVar17 == fVar16) << 0x1e;
                sVar7 = sVar7 + -1;
                fVar18 = (fVar17 - fVar16) * (fVar17 - fVar16);
                if ((byte)(in_fpscr >> 0x1e) != 0) break;
                if (sVar7 == 0) {
                  uVar15 = uVar15 | (uint)(fVar17 < fVar16) << 0x1f |
                           (uint)(fVar17 == fVar16) << 0x1e;
                  in_fpscr = uVar15 | (uint)(NAN(fVar17) || NAN(fVar16)) << 0x1c;
                  bVar1 = (byte)(uVar15 >> 0x18);
                  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                    iVar19 = VectorFloatToUnsigned(fVar16 * 10.0,3);
                    goto joined_r0x08029dce;
                  }
                  break;
                }
                uVar15 = uVar15 | (uint)(fVar18 < 1.0) << 0x1f | (uint)(fVar18 == 1.0) << 0x1e;
                in_fpscr = uVar15 | (uint)NAN(fVar18) << 0x1c;
                bVar1 = (byte)(uVar15 >> 0x18);
                fVar16 = fVar17;
              } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
              iVar19 = VectorFloatToUnsigned(fVar17 * 10.0,3);
joined_r0x08029dce:
              uVar6 = uVar6 + iVar19;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            iVar10 = uVar6 / 3 - uVar4;
            uVar6 = uVar6 / 3;
            if (iVar10 * iVar10 < 0x9c4) {
              if (uVar4 <= uVar6) {
                uVar6 = uVar4;
              }
              break;
            }
            local_74 = local_74 + -1;
            uVar4 = uVar6;
          } while (local_74 != 0);
          if (uVar6 <= uVar5) {
            local_54 = local_60;
            local_50 = 1;
            local_70 = uVar6;
            local_5c = uVar3;
          }
        }
        uVar3 = (uint)(short)(*psVar11 * *psVar14 + (short)uVar3);
        if ((int)uVar3 < 0x80) {
          if (((int)uVar3 < 0) && (*psVar8 < 0)) {
            uVar3 = 0x7f;
          }
        }
        else if (0 < *psVar8) {
          uVar3 = 0;
        }
        psVar8 = psVar8 + 1;
        psVar14 = psVar14 + 1;
      } while (psVar8 != (short *)0x803dc2c);
      psVar11 = psVar11 + 1;
    } while (psVar11 != &DAT_0803dc1c);
    if (local_50 == 0) {
      uVar13 = uVar13 + 1;
      local_58 = (uint)(byte)param_1[1];
      if (uVar13 < 10) {
        sVar7 = (&DAT_0803dc1c)[uVar13];
        sVar2 = (&DAT_0803dc18)[iVar9] * sVar7 + (short)local_60;
        local_60 = (uint)sVar2;
        if ((int)local_60 < 0x80) {
          if ((-1 < (int)local_60) || (-1 < sVar7)) goto LAB_08029ee6;
          uVar3 = 0x7f;
          local_60 = 0x7f;
LAB_08029eea:
          if (uVar3 == DAT_2000000c) goto LAB_08029cb2;
          uVar5 = uVar3 & DAT_20000000;
          DAT_2000000c = uVar3;
          if (-1 < (int)(uVar5 << 0x1f)) {
            local_74 = uVar5 & 4;
            uVar3 = uVar5 & 2;
            uVar4 = uVar5 & 8;
            uVar15 = uVar5 & 0x10;
            uVar6 = uVar5 & 0x20;
            uVar5 = uVar5 & 0x40;
            goto LAB_08029fb4;
          }
          uVar3 = uVar5 & 2;
          uVar12 = DAT_2000c6e4 | 1;
          local_74 = uVar5 & 4;
          uVar4 = uVar5 & 8;
          uVar15 = uVar5 & 0x10;
          uVar6 = uVar5 & 0x20;
          uVar5 = uVar5 & 0x40;
        }
        else {
          if (sVar7 < 1) {
LAB_08029ee6:
            uVar3 = (uint)(byte)sVar2;
            goto LAB_08029eea;
          }
          local_60 = local_50;
          if (DAT_2000000c == 0) goto LAB_08029cb2;
          DAT_2000000c = 0;
          local_74 = local_50;
          local_60 = local_50;
          uVar5 = 0;
          uVar3 = 0;
          uVar4 = 0;
          uVar6 = 0;
          uVar15 = 0;
LAB_08029fb4:
          uVar12 = DAT_2000c6e4 & 0xfffffffe;
        }
        if (uVar3 == 0) {
          uVar12 = uVar12 & 0xfffffffd;
          if (local_74 == 0) goto LAB_08029f36;
LAB_08029f86:
          uVar12 = uVar12 | 4;
          if (uVar4 != 0) goto LAB_08029f90;
LAB_08029f40:
          uVar12 = uVar12 & 0xfffffff7;
          if (uVar15 == 0) goto LAB_08029f4a;
LAB_08029f9a:
          uVar12 = uVar12 | 0x10;
        }
        else {
          uVar12 = uVar12 | 2;
          if (local_74 != 0) goto LAB_08029f86;
LAB_08029f36:
          uVar12 = uVar12 & 0xfffffffb;
          if (uVar4 == 0) goto LAB_08029f40;
LAB_08029f90:
          uVar12 = uVar12 | 8;
          if (uVar15 != 0) goto LAB_08029f9a;
LAB_08029f4a:
          uVar12 = uVar12 & 0xffffffef;
        }
        if (uVar6 == 0) {
          uVar12 = uVar12 & 0xffffffdf;
          if (uVar5 == 0) goto LAB_08029f5a;
LAB_08029f76:
          DAT_2000c6e4 = uVar12 | 0x40;
        }
        else {
          uVar12 = uVar12 | 0x20;
          if (uVar5 != 0) goto LAB_08029f76;
LAB_08029f5a:
          DAT_2000c6e4 = uVar12 & 0xffffffbf;
        }
        (*DAT_2000c6f0)(&DAT_2000c6e0);
      }
      else {
        if (iVar9 != 0) break;
        bVar1 = *(byte *)((int)param_1 + 5);
        local_60 = (int)(short)(ushort)bVar1;
        if (bVar1 == DAT_2000000c) {
          iVar9 = 1;
          uVar13 = 0;
        }
        else {
          uVar3 = (uint)(bVar1 & DAT_20000000);
          if ((int)(uVar3 << 0x1f) < 0) {
            uVar5 = DAT_2000c6e4 | 1;
          }
          else {
            uVar5 = DAT_2000c6e4 & 0xfffffffe;
          }
          if ((int)(uVar3 << 0x1e) < 0) {
            uVar5 = uVar5 | 2;
          }
          else {
            uVar5 = uVar5 & 0xfffffffd;
          }
          if ((int)(uVar3 << 0x1d) < 0) {
            uVar5 = uVar5 | 4;
          }
          else {
            uVar5 = uVar5 & 0xfffffffb;
          }
          if ((int)(uVar3 << 0x1c) < 0) {
            uVar5 = uVar5 | 8;
          }
          else {
            uVar5 = uVar5 & 0xfffffff7;
          }
          if ((int)(uVar3 << 0x1b) < 0) {
            uVar5 = uVar5 | 0x10;
          }
          else {
            uVar5 = uVar5 & 0xffffffef;
          }
          if ((int)(uVar3 << 0x1a) < 0) {
            uVar5 = uVar5 | 0x20;
          }
          else {
            uVar5 = uVar5 & 0xffffffdf;
          }
          if ((int)(uVar3 << 0x19) < 0) {
            DAT_2000c6e4 = uVar5 | 0x40;
          }
          else {
            DAT_2000c6e4 = uVar5 & 0xffffffbf;
          }
          DAT_2000000c = (uint)bVar1;
          (*DAT_2000c6f0)(&DAT_2000c6e0);
          uVar13 = 0;
          iVar9 = 1;
        }
      }
    }
    else {
      if ((local_5c & 0xff) != DAT_20000008) {
        uVar3 = (uint)((byte)local_5c & DAT_20000001);
        if ((int)(uVar3 << 0x1f) < 0) {
          uVar5 = DAT_2000c6e4 | 0x200000;
        }
        else {
          uVar5 = DAT_2000c6e4 & 0xffdfffff;
        }
        if ((int)(uVar3 << 0x1e) < 0) {
          uVar5 = uVar5 | 0x10000;
        }
        else {
          uVar5 = uVar5 & 0xfffeffff;
        }
        if ((int)(uVar3 << 0x1d) < 0) {
          uVar5 = uVar5 | 0x8000;
        }
        else {
          uVar5 = uVar5 & 0xffff7fff;
        }
        if ((int)(uVar3 << 0x1c) < 0) {
          uVar5 = uVar5 | 0x4000;
        }
        else {
          uVar5 = uVar5 & 0xffffbfff;
        }
        if ((int)(uVar3 << 0x1b) < 0) {
          uVar5 = uVar5 | 0x20000;
        }
        else {
          uVar5 = uVar5 & 0xfffdffff;
        }
        if ((int)(uVar3 << 0x1a) < 0) {
          uVar5 = uVar5 | 0x40000;
        }
        else {
          uVar5 = uVar5 & 0xfffbffff;
        }
        if ((int)(uVar3 << 0x19) < 0) {
          DAT_2000c6e4 = uVar5 | 0x80000;
        }
        else {
          DAT_2000c6e4 = uVar5 & 0xfff7ffff;
        }
        DAT_20000008 = local_5c & 0xff;
        (*DAT_2000c6f0)(&DAT_2000c6e0);
      }
      local_58 = local_5c;
    }
LAB_08029cb2:
    fVar16 = (float)VectorUnsignedToFloat(local_70,(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar16 == 20.0) << 0x1e |
               (uint)(20.0 <= fVar16) << 0x1d;
    bVar1 = (byte)(in_fpscr >> 0x18);
  } while ((bool)(bVar1 >> 5 & 1) && !(bool)(bVar1 >> 6));
  *(char *)((int)param_1 + 5) = (char)local_54;
  *(byte *)(param_1 + 1) = (byte)local_5c;
  *param_1 = local_70;
  return;
}

