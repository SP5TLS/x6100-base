
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_080290e0(uint *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint in_fpscr;
  float fVar13;
  float fVar14;
  float fVar15;
  uint local_4c;
  uint local_40;
  uint local_34 [2];
  
  uVar12 = (uint)*(byte *)((int)param_1 + 5);
  uVar10 = (uint)(byte)param_1[1];
  uVar8 = *param_1;
  uVar4 = (uint)(short)(ushort)(byte)param_1[1];
  uVar5 = (uint)(short)(ushort)*(byte *)((int)param_1 + 5);
  uVar3 = uVar5;
  uVar6 = uVar8;
  if (uVar12 < 0x7f) {
    uVar11 = uVar12 + 1;
    local_40 = uVar5;
    do {
      uVar5 = (uint)(short)uVar11;
      if (uVar11 != DAT_2000000c) {
        uVar3 = DAT_20000000 & uVar11;
        if ((int)(uVar3 << 0x1f) < 0) {
          uVar6 = DAT_2000c6e4 | 1;
        }
        else {
          uVar6 = DAT_2000c6e4 & 0xfffffffe;
        }
        if ((int)(uVar3 << 0x1e) < 0) {
          uVar6 = uVar6 | 2;
        }
        else {
          uVar6 = uVar6 & 0xfffffffd;
        }
        if ((int)(uVar3 << 0x1d) < 0) {
          uVar6 = uVar6 | 4;
        }
        else {
          uVar6 = uVar6 & 0xfffffffb;
        }
        if ((int)(uVar3 << 0x1c) < 0) {
          uVar6 = uVar6 | 8;
        }
        else {
          uVar6 = uVar6 & 0xfffffff7;
        }
        if ((int)(uVar3 << 0x1b) < 0) {
          uVar6 = uVar6 | 0x10;
        }
        else {
          uVar6 = uVar6 & 0xffffffef;
        }
        if ((int)(uVar3 << 0x1a) < 0) {
          uVar6 = uVar6 | 0x20;
        }
        else {
          uVar6 = uVar6 & 0xffffffdf;
        }
        if ((int)(uVar3 << 0x19) < 0) {
          DAT_2000c6e4 = uVar6 | 0x40;
        }
        else {
          DAT_2000c6e4 = uVar6 & 0xffffffbf;
        }
        DAT_2000000c = uVar11;
        (*DAT_2000c6f0)(&DAT_2000c6e0);
      }
      FUN_080349e4(8);
      fVar13 = (float)FUN_08024468(100);
      sVar9 = 5;
      do {
        FUN_080349e4(10);
        fVar14 = (float)FUN_08024468(100);
        uVar3 = in_fpscr & 0xfffffff;
        in_fpscr = uVar3 | (uint)(fVar14 == fVar13) << 0x1e;
        sVar9 = sVar9 + -1;
        fVar15 = (fVar14 - fVar13) * (fVar14 - fVar13);
        if ((byte)(in_fpscr >> 0x1e) != 0) break;
        if (sVar9 == 0) {
          uVar3 = uVar3 | (uint)(fVar14 < fVar13) << 0x1f | (uint)(fVar14 == fVar13) << 0x1e;
          in_fpscr = uVar3 | (uint)(NAN(fVar14) || NAN(fVar13)) << 0x1c;
          bVar1 = (byte)(uVar3 >> 0x18);
          if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            local_34[0] = VectorFloatToUnsigned(fVar13 * 10.0,3);
            goto LAB_0802920a;
          }
          break;
        }
        uVar3 = uVar3 | (uint)(fVar15 < 1.0) << 0x1f | (uint)(fVar15 == 1.0) << 0x1e;
        in_fpscr = uVar3 | (uint)NAN(fVar15) << 0x1c;
        bVar1 = (byte)(uVar3 >> 0x18);
        fVar13 = fVar14;
      } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
      local_34[0] = VectorFloatToUnsigned(fVar14 * 10.0,3);
LAB_0802920a:
      fVar13 = (float)VectorUnsignedToFloat(local_34[0],(byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar13 == 15.0) << 0x1e |
                 (uint)(15.0 <= fVar13) << 0x1d;
      bVar1 = (byte)(in_fpscr >> 0x18);
      uVar3 = uVar5;
      uVar6 = local_34[0];
      if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) break;
      if ((local_34[0] < uVar8) && (iVar2 = FUN_08028d68(local_34), iVar2 != 0)) {
        uVar8 = local_34[0];
        local_40 = uVar5;
      }
      uVar3 = local_40;
      uVar6 = uVar8;
      if ((uVar12 + 10 == uVar11) ||
         (uVar11 = uVar11 + 1, uVar11 == uVar12 + 2 + (0x7e - uVar12 & 0xffff))) break;
    } while( true );
  }
  uVar8 = uVar5 - 1 & 0xffff;
  local_40 = uVar3;
  do {
    uVar3 = (uint)(short)uVar8;
    uVar12 = uVar8 & 0xff;
    if (uVar8 != DAT_2000000c) {
      uVar11 = uVar12 & DAT_20000000;
      if ((int)(uVar11 << 0x1f) < 0) {
        uVar7 = DAT_2000c6e4 | 1;
      }
      else {
        uVar7 = DAT_2000c6e4 & 0xfffffffe;
      }
      if ((int)(uVar11 << 0x1e) < 0) {
        uVar7 = uVar7 | 2;
      }
      else {
        uVar7 = uVar7 & 0xfffffffd;
      }
      if ((int)(uVar11 << 0x1d) < 0) {
        uVar7 = uVar7 | 4;
      }
      else {
        uVar7 = uVar7 & 0xfffffffb;
      }
      if ((int)(uVar11 << 0x1c) < 0) {
        uVar7 = uVar7 | 8;
      }
      else {
        uVar7 = uVar7 & 0xfffffff7;
      }
      if ((int)(uVar11 << 0x1b) < 0) {
        uVar7 = uVar7 | 0x10;
      }
      else {
        uVar7 = uVar7 & 0xffffffef;
      }
      if ((int)(uVar11 << 0x1a) < 0) {
        uVar7 = uVar7 | 0x20;
      }
      else {
        uVar7 = uVar7 & 0xffffffdf;
      }
      if ((int)(uVar11 << 0x19) < 0) {
        DAT_2000c6e4 = uVar7 | 0x40;
      }
      else {
        DAT_2000c6e4 = uVar7 & 0xffffffbf;
      }
      DAT_2000000c = uVar8;
      (*DAT_2000c6f0)(&DAT_2000c6e0);
    }
    FUN_080349e4(8);
    fVar13 = (float)FUN_08024468(100);
    sVar9 = 5;
    do {
      FUN_080349e4(10);
      fVar14 = (float)FUN_08024468(100);
      uVar11 = in_fpscr & 0xfffffff;
      in_fpscr = uVar11 | (uint)(fVar14 == fVar13) << 0x1e;
      sVar9 = sVar9 + -1;
      fVar15 = (fVar14 - fVar13) * (fVar14 - fVar13);
      if ((byte)(in_fpscr >> 0x1e) != 0) break;
      if (sVar9 == 0) {
        uVar11 = uVar11 | (uint)(fVar14 < fVar13) << 0x1f | (uint)(fVar14 == fVar13) << 0x1e;
        in_fpscr = uVar11 | (uint)(NAN(fVar14) || NAN(fVar13)) << 0x1c;
        bVar1 = (byte)(uVar11 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          uVar11 = VectorFloatToUnsigned(fVar13 * 10.0,3);
          goto LAB_08029338;
        }
        break;
      }
      uVar11 = uVar11 | (uint)(fVar15 < 1.0) << 0x1f | (uint)(fVar15 == 1.0) << 0x1e;
      in_fpscr = uVar11 | (uint)NAN(fVar15) << 0x1c;
      bVar1 = (byte)(uVar11 >> 0x18);
      fVar13 = fVar14;
    } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
    uVar11 = VectorFloatToUnsigned(fVar14 * 10.0,3);
LAB_08029338:
    fVar13 = (float)VectorUnsignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar13 == 15.0) << 0x1e |
               (uint)(15.0 <= fVar13) << 0x1d;
    bVar1 = (byte)(in_fpscr >> 0x18);
    local_34[0] = uVar11;
    if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) goto LAB_08029374;
    if ((uVar11 < uVar6) && (iVar2 = FUN_08028d68(local_34), iVar2 != 0)) {
      uVar6 = local_34[0];
      local_40 = uVar3;
    }
  } while ((uVar8 != (uVar5 - 10 & 0xffff)) && (uVar8 = uVar8 - 1 & 0xffff, uVar8 != 0xffff));
  uVar12 = local_40 & 0xff;
  uVar3 = local_40;
  uVar11 = uVar6;
LAB_08029374:
  if (uVar3 != DAT_2000000c) {
    uVar6 = uVar12 & DAT_20000000;
    if ((int)(uVar6 << 0x1f) < 0) {
      uVar8 = DAT_2000c6e4 | 1;
    }
    else {
      uVar8 = DAT_2000c6e4 & 0xfffffffe;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      uVar8 = uVar8 | 2;
    }
    else {
      uVar8 = uVar8 & 0xfffffffd;
    }
    if ((int)(uVar6 << 0x1d) < 0) {
      uVar8 = uVar8 | 4;
    }
    else {
      uVar8 = uVar8 & 0xfffffffb;
    }
    if ((int)(uVar6 << 0x1c) < 0) {
      uVar8 = uVar8 | 8;
    }
    else {
      uVar8 = uVar8 & 0xfffffff7;
    }
    if ((int)(uVar6 << 0x1b) < 0) {
      uVar8 = uVar8 | 0x10;
    }
    else {
      uVar8 = uVar8 & 0xffffffef;
    }
    if ((int)(uVar6 << 0x1a) < 0) {
      uVar8 = uVar8 | 0x20;
    }
    else {
      uVar8 = uVar8 & 0xffffffdf;
    }
    if ((int)(uVar6 << 0x19) < 0) {
      DAT_2000c6e4 = uVar8 | 0x40;
    }
    else {
      DAT_2000c6e4 = uVar8 & 0xffffffbf;
    }
    DAT_2000000c = uVar3;
    (*DAT_2000c6f0)(&DAT_2000c6e0);
  }
  uVar3 = uVar11;
  uVar6 = uVar4;
  if (uVar4 < 0x7f) {
    uVar8 = uVar10 + 1;
    local_4c = uVar4;
    do {
      uVar4 = (uint)(short)uVar8;
      if (uVar8 != DAT_20000008) {
        uVar3 = DAT_20000001 & uVar8;
        if ((int)(uVar3 << 0x1f) < 0) {
          uVar6 = DAT_2000c6e4 | 0x200000;
        }
        else {
          uVar6 = DAT_2000c6e4 & 0xffdfffff;
        }
        if ((int)(uVar3 << 0x1e) < 0) {
          uVar6 = uVar6 | 0x10000;
        }
        else {
          uVar6 = uVar6 & 0xfffeffff;
        }
        if ((int)(uVar3 << 0x1d) < 0) {
          uVar6 = uVar6 | 0x8000;
        }
        else {
          uVar6 = uVar6 & 0xffff7fff;
        }
        if ((int)(uVar3 << 0x1c) < 0) {
          uVar6 = uVar6 | 0x4000;
        }
        else {
          uVar6 = uVar6 & 0xffffbfff;
        }
        if ((int)(uVar3 << 0x1b) < 0) {
          uVar6 = uVar6 | 0x20000;
        }
        else {
          uVar6 = uVar6 & 0xfffdffff;
        }
        if ((int)(uVar3 << 0x1a) < 0) {
          uVar6 = uVar6 | 0x40000;
        }
        else {
          uVar6 = uVar6 & 0xfffbffff;
        }
        if ((int)(uVar3 << 0x19) < 0) {
          DAT_2000c6e4 = uVar6 | 0x80000;
        }
        else {
          DAT_2000c6e4 = uVar6 & 0xfff7ffff;
        }
        DAT_20000008 = uVar8;
        (*DAT_2000c6f0)(&DAT_2000c6e0);
      }
      FUN_080349e4(8);
      fVar13 = (float)FUN_08024468(100);
      sVar9 = 5;
      do {
        FUN_080349e4(10);
        fVar14 = (float)FUN_08024468(100);
        uVar3 = in_fpscr & 0xfffffff;
        in_fpscr = uVar3 | (uint)(fVar14 == fVar13) << 0x1e;
        sVar9 = sVar9 + -1;
        fVar15 = (fVar14 - fVar13) * (fVar14 - fVar13);
        if ((byte)(in_fpscr >> 0x1e) != 0) break;
        if (sVar9 == 0) {
          uVar3 = uVar3 | (uint)(fVar14 < fVar13) << 0x1f | (uint)(fVar14 == fVar13) << 0x1e;
          in_fpscr = uVar3 | (uint)(NAN(fVar14) || NAN(fVar13)) << 0x1c;
          bVar1 = (byte)(uVar3 >> 0x18);
          if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            local_34[0] = VectorFloatToUnsigned(fVar13 * 10.0,3);
            goto LAB_08029508;
          }
          break;
        }
        uVar3 = uVar3 | (uint)(fVar15 < 1.0) << 0x1f | (uint)(fVar15 == 1.0) << 0x1e;
        in_fpscr = uVar3 | (uint)NAN(fVar15) << 0x1c;
        bVar1 = (byte)(uVar3 >> 0x18);
        fVar13 = fVar14;
      } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
      local_34[0] = VectorFloatToUnsigned(fVar14 * 10.0,3);
LAB_08029508:
      fVar13 = (float)VectorUnsignedToFloat(local_34[0],(byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar13 == 15.0) << 0x1e |
                 (uint)(15.0 <= fVar13) << 0x1d;
      bVar1 = (byte)(in_fpscr >> 0x18);
      uVar3 = local_34[0];
      uVar6 = uVar4;
      if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) break;
      if ((local_34[0] < uVar11) && (iVar2 = FUN_08028d68(local_34), iVar2 != 0)) {
        uVar11 = local_34[0];
        local_4c = uVar4;
      }
      uVar3 = uVar11;
      uVar6 = local_4c;
      if ((uVar8 == uVar10 + 10) ||
         (uVar8 = uVar8 + 1, uVar8 == uVar10 + 2 + (0x7e - uVar10 & 0xffff))) break;
    } while( true );
  }
  local_4c = uVar6;
  uVar6 = uVar4 - 1 & 0xffff;
  do {
    if (uVar6 != DAT_20000008) {
      uVar8 = DAT_20000001 & uVar6;
      if ((int)(uVar8 << 0x1f) < 0) {
        uVar5 = DAT_2000c6e4 | 0x200000;
      }
      else {
        uVar5 = DAT_2000c6e4 & 0xffdfffff;
      }
      if ((int)(uVar8 << 0x1e) < 0) {
        uVar5 = uVar5 | 0x10000;
      }
      else {
        uVar5 = uVar5 & 0xfffeffff;
      }
      if ((int)(uVar8 << 0x1d) < 0) {
        uVar5 = uVar5 | 0x8000;
      }
      else {
        uVar5 = uVar5 & 0xffff7fff;
      }
      if ((int)(uVar8 << 0x1c) < 0) {
        uVar5 = uVar5 | 0x4000;
      }
      else {
        uVar5 = uVar5 & 0xffffbfff;
      }
      if ((int)(uVar8 << 0x1b) < 0) {
        uVar5 = uVar5 | 0x20000;
      }
      else {
        uVar5 = uVar5 & 0xfffdffff;
      }
      if ((int)(uVar8 << 0x1a) < 0) {
        uVar5 = uVar5 | 0x40000;
      }
      else {
        uVar5 = uVar5 & 0xfffbffff;
      }
      if ((int)(uVar8 << 0x19) < 0) {
        DAT_2000c6e4 = uVar5 | 0x80000;
      }
      else {
        DAT_2000c6e4 = uVar5 & 0xfff7ffff;
      }
      DAT_20000008 = uVar6;
      (*DAT_2000c6f0)(&DAT_2000c6e0);
    }
    FUN_080349e4(8);
    fVar13 = (float)FUN_08024468(100);
    sVar9 = 5;
    do {
      FUN_080349e4(10);
      fVar14 = (float)FUN_08024468(100);
      uVar8 = in_fpscr & 0xfffffff;
      in_fpscr = uVar8 | (uint)(fVar14 == fVar13) << 0x1e;
      sVar9 = sVar9 + -1;
      fVar15 = (fVar14 - fVar13) * (fVar14 - fVar13);
      if ((byte)(in_fpscr >> 0x1e) != 0) break;
      if (sVar9 == 0) {
        uVar8 = uVar8 | (uint)(fVar14 < fVar13) << 0x1f | (uint)(fVar14 == fVar13) << 0x1e;
        in_fpscr = uVar8 | (uint)(NAN(fVar14) || NAN(fVar13)) << 0x1c;
        bVar1 = (byte)(uVar8 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          local_34[0] = VectorFloatToUnsigned(fVar13 * 10.0,3);
          goto LAB_08029640;
        }
        break;
      }
      uVar8 = uVar8 | (uint)(fVar15 < 1.0) << 0x1f | (uint)(fVar15 == 1.0) << 0x1e;
      in_fpscr = uVar8 | (uint)NAN(fVar15) << 0x1c;
      bVar1 = (byte)(uVar8 >> 0x18);
      fVar13 = fVar14;
    } while (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1));
    local_34[0] = VectorFloatToUnsigned(fVar14 * 10.0,3);
LAB_08029640:
    fVar13 = (float)VectorUnsignedToFloat(local_34[0],(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar13 == 15.0) << 0x1e |
               (uint)(15.0 <= fVar13) << 0x1d;
    bVar1 = (byte)(in_fpscr >> 0x18);
    uVar8 = local_34[0];
    uVar5 = (int)(short)uVar6;
    if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) break;
    if ((local_34[0] < uVar3) && (iVar2 = FUN_08028d68(local_34), iVar2 != 0)) {
      uVar3 = local_34[0];
      local_4c = (int)(short)uVar6;
    }
    uVar8 = uVar3;
    uVar5 = local_4c;
    if ((uVar6 == (uVar4 - 10 & 0xffff)) || (uVar6 = uVar6 - 1 & 0xffff, uVar6 == 0xffff)) break;
  } while( true );
  local_4c = uVar5;
  if (uVar8 < *param_1) {
    if (local_4c != DAT_20000008) {
      DAT_20000008 = local_4c;
      uVar3 = (uint)DAT_20000001 & local_4c & 0xff;
      if ((int)(uVar3 << 0x1f) < 0) {
        uVar6 = DAT_2000c6e4 | 0x200000;
      }
      else {
        uVar6 = DAT_2000c6e4 & 0xffdfffff;
      }
      if ((int)(uVar3 << 0x1e) < 0) {
        uVar6 = uVar6 | 0x10000;
      }
      else {
        uVar6 = uVar6 & 0xfffeffff;
      }
      if ((int)(uVar3 << 0x1d) < 0) {
        uVar6 = uVar6 | 0x8000;
      }
      else {
        uVar6 = uVar6 & 0xffff7fff;
      }
      if ((int)(uVar3 << 0x1c) < 0) {
        uVar6 = uVar6 | 0x4000;
      }
      else {
        uVar6 = uVar6 & 0xffffbfff;
      }
      if ((int)(uVar3 << 0x1b) < 0) {
        uVar6 = uVar6 | 0x20000;
      }
      else {
        uVar6 = uVar6 & 0xfffdffff;
      }
      if ((int)(uVar3 << 0x1a) < 0) {
        uVar6 = uVar6 | 0x40000;
      }
      else {
        uVar6 = uVar6 & 0xfffbffff;
      }
      if ((int)(uVar3 << 0x19) < 0) {
        DAT_2000c6e4 = uVar6 | 0x80000;
      }
      else {
        DAT_2000c6e4 = uVar6 & 0xfff7ffff;
      }
      (*DAT_2000c6f0)(&DAT_2000c6e0);
    }
    *(char *)(param_1 + 1) = (char)local_4c;
    *(char *)((int)param_1 + 5) = (char)uVar12;
    *param_1 = uVar8;
  }
  else {
    bVar1 = (byte)param_1[1];
    if (bVar1 == DAT_20000008) {
      uVar3 = (uint)*(byte *)((int)param_1 + 5);
      if (uVar3 != DAT_2000000c) {
LAB_08029768:
        uVar6 = DAT_20000000 & uVar3;
        if ((int)(uVar6 << 0x1f) < 0) {
          uVar8 = DAT_2000c6e4 | 1;
        }
        else {
          uVar8 = DAT_2000c6e4 & 0xfffffffe;
        }
        if ((int)(uVar6 << 0x1e) < 0) {
          uVar8 = uVar8 | 2;
        }
        else {
          uVar8 = uVar8 & 0xfffffffd;
        }
        if ((int)(uVar6 << 0x1d) < 0) {
          uVar8 = uVar8 | 4;
        }
        else {
          uVar8 = uVar8 & 0xfffffffb;
        }
        if ((int)(uVar6 << 0x1c) < 0) {
          uVar8 = uVar8 | 8;
        }
        else {
          uVar8 = uVar8 & 0xfffffff7;
        }
        if ((int)(uVar6 << 0x1b) < 0) {
          uVar8 = uVar8 | 0x10;
        }
        else {
          uVar8 = uVar8 & 0xffffffef;
        }
        if ((int)(uVar6 << 0x1a) < 0) {
          uVar8 = uVar8 | 0x20;
        }
        else {
          uVar8 = uVar8 & 0xffffffdf;
        }
        if ((int)(uVar6 << 0x19) < 0) {
          DAT_2000c6e4 = uVar8 | 0x40;
        }
        else {
          DAT_2000c6e4 = uVar8 & 0xffffffbf;
        }
        DAT_2000000c = uVar3;
                    /* WARNING: Could not recover jumptable at 0x080297ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*DAT_2000c6f0)(&DAT_2000c6e0);
        return;
      }
    }
    else {
      uVar3 = (uint)(DAT_20000001 & bVar1);
      if ((int)(uVar3 << 0x1f) < 0) {
        uVar6 = DAT_2000c6e4 | 0x200000;
      }
      else {
        uVar6 = DAT_2000c6e4 & 0xffdfffff;
      }
      if ((int)(uVar3 << 0x1e) < 0) {
        uVar6 = uVar6 | 0x10000;
      }
      else {
        uVar6 = uVar6 & 0xfffeffff;
      }
      if ((int)(uVar3 << 0x1d) < 0) {
        uVar6 = uVar6 | 0x8000;
      }
      else {
        uVar6 = uVar6 & 0xffff7fff;
      }
      if ((int)(uVar3 << 0x1c) < 0) {
        uVar6 = uVar6 | 0x4000;
      }
      else {
        uVar6 = uVar6 & 0xffffbfff;
      }
      if ((int)(uVar3 << 0x1b) < 0) {
        uVar6 = uVar6 | 0x20000;
      }
      else {
        uVar6 = uVar6 & 0xfffdffff;
      }
      if ((int)(uVar3 << 0x1a) < 0) {
        uVar6 = uVar6 | 0x40000;
      }
      else {
        uVar6 = uVar6 & 0xfffbffff;
      }
      if ((int)(uVar3 << 0x19) < 0) {
        DAT_2000c6e4 = uVar6 | 0x80000;
      }
      else {
        DAT_2000c6e4 = uVar6 & 0xfff7ffff;
      }
      DAT_20000008 = (uint)bVar1;
      (*DAT_2000c6f0)(&DAT_2000c6e0);
      uVar3 = (uint)*(byte *)((int)param_1 + 5);
      if (uVar3 != DAT_2000000c) goto LAB_08029768;
    }
  }
  return;
}

