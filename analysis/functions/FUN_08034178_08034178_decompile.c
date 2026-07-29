
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08034178(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint in_fpscr;
  float fVar4;
  undefined8 uVar5;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(0);
  }
  FUN_0803485c();
  FUN_080348b0();
  FUN_08037a60(*(undefined4 *)(DAT_200033b4 + 8),0,2,0);
  FUN_08037e20(&DAT_2000e964,0,0x20);
  FUN_08037bc8(&DAT_2000e964,0x20,s__s__s_0803d3a8,s_Nov_27_2025_0803d39c,s_10_31_57_0803d3b0);
  FUN_08033ce0(0,s_V1_1_9_0803d3bc,7);
  FUN_08033ce0(7,&DAT_2000e964,0x20);
  FUN_08032500();
  FUN_080317b4();
  FUN_08037a50(&DAT_0803d3c4);
  _DAT_40021014 = _DAT_40021014 & 0xffff7fff;
  _DAT_40021814 = _DAT_40021814 & 0xfffffeff;
  FUN_08033ef4();
  FUN_08033e38();
  FUN_0802efa8(0x40000000,1);
  FUN_0802ee38(0x40000000,1);
  FUN_0802a5d0(&DAT_20000024);
  FUN_0802f758(3,0);
  FUN_0802f6e8(3,0);
  FUN_0802f628(1,10);
  FUN_0802f628(2,0xfffffff9);
  FUN_0802f568(3,0xf);
  FUN_0802f4b8(1,0x1e);
  FUN_0802f4b8(2,0);
  _DAT_40021814 = _DAT_40021814 | 3;
  (*DAT_2000c6d0)(1);
  _DAT_40020c14 = _DAT_40020c14 | 4;
  _DAT_40021414 = _DAT_40021414 & 0xfffff7ff;
  FUN_0803062c(&DAT_20000334,0,0);
  FUN_0803062c(&DAT_20000334,1,0);
  DAT_20000130 = 0;
  FUN_08037a50(s__OK__Checking_PA_bias_0803d3c8);
  (*DAT_2000c6cc)(1);
  _DAT_40021014 = _DAT_40021014 & 0xfffffdff | 0x100;
  _DAT_40021814 = _DAT_40021814 | 0x800;
  FUN_080349e4(200);
  FUN_0803062c(&DAT_20000334,0,DAT_2000c194);
  FUN_080349e4(100);
  iVar2 = FUN_08030808(1);
  fVar4 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
  FUN_080349e4(100);
  FUN_0803062c(&DAT_20000334,0,0);
  if ((iVar2 - 0x5eU & 0xffff) < 0x7c) {
    uVar5 = FUN_08020628(fVar4 * 0.0016113281);
    FUN_08037970(s__OK__PA_drive_stage_current__N___0803d3e0,DAT_2000c194,(int)uVar5,
                 (int)((ulonglong)uVar5 >> 0x20));
    DAT_20000130 = CONCAT22(DAT_20000130._2_2_,(short)DAT_2000c194);
  }
  else {
    uVar5 = FUN_08020628(fVar4 * 0.0016113281);
    FUN_08037970(s__ERR__PA_drive_stage_current__N___0803d410,DAT_2000c194,(int)uVar5,
                 (int)((ulonglong)uVar5 >> 0x20));
  }
  FUN_0803062c(&DAT_20000334,1,DAT_2000c198);
  FUN_080349e4(100);
  iVar2 = FUN_08030808(1);
  fVar4 = (float)VectorUnsignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
  FUN_080349e4(100);
  FUN_0803062c(&DAT_20000334,1,0);
  if ((iVar2 - 0x1b3U & 0xffff) < 0x136) {
    uVar5 = FUN_08020628(fVar4 * 0.0016113281);
    FUN_08037970(s__OK__PA_final_stage_current__N___0803d440,DAT_2000c198,(int)uVar5,
                 (int)((ulonglong)uVar5 >> 0x20));
    uVar3 = DAT_20000130;
    DAT_20000130 = CONCAT22((short)DAT_2000c198,(undefined2)DAT_20000130);
    if ((uVar3 & 0xffff) != 0) goto LAB_08034436;
LAB_080345cc:
    FUN_08037a50(s__ERR__PA_drive_stage_needs_re_ca_0803d4a0);
    FUN_080349e4(100);
    iVar2 = 0x96;
    while( true ) {
      FUN_0803062c(&DAT_20000334,0,iVar2);
      FUN_080349e4(10);
      uVar3 = FUN_08030808(1);
      fVar4 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      uVar5 = FUN_08020628(fVar4 * 0.0016113281);
      FUN_08037970(s_Drive_stage__N____04d__I____f_0803d4cc,iVar2,(int)uVar5,
                   (int)((ulonglong)uVar5 >> 0x20));
      if (0x7c < uVar3) break;
      iVar2 = iVar2 + 5;
      if (iVar2 == 0x1004) {
        FUN_08037a50(s___Failed__0803d4f8);
        DAT_20000130 = CONCAT22(DAT_20000130._2_2_,(short)DAT_2000c194);
        FUN_0803062c(&DAT_20000334,0);
        goto LAB_08034436;
      }
      FUN_08037994(0xd);
    }
    FUN_08037a50(s___Done__0803d4ec);
    DAT_20000130 = CONCAT22(DAT_20000130._2_2_,(short)iVar2);
    DAT_2000c194 = iVar2;
    FUN_0803062c(&DAT_20000334,0);
    if (DAT_20000130._2_2_ == 0) {
      bVar1 = true;
      goto LAB_0803469a;
    }
  }
  else {
    uVar5 = FUN_08020628(fVar4 * 0.0016113281);
    FUN_08037970(s__ERR__PA_final_stage_current__N___0803d470,DAT_2000c198,(int)uVar5,
                 (int)((ulonglong)uVar5 >> 0x20));
    if ((DAT_20000130 & 0xffff) == 0) goto LAB_080345cc;
LAB_08034436:
    if (DAT_20000130._2_2_ != 0) goto LAB_08034440;
    bVar1 = false;
LAB_0803469a:
    FUN_08037a50(s__ERR__PA_final_stage_needs_re_ca_0803d504);
    FUN_080349e4(100);
    iVar2 = 0xfa;
    while( true ) {
      FUN_0803062c(&DAT_20000334,1,iVar2);
      FUN_080349e4(10);
      uVar3 = FUN_08030808(1);
      fVar4 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      uVar5 = FUN_08020628(fVar4 * 0.0016113281);
      FUN_08037970(s_Final_stage__N____04d__I____f_0803d530,iVar2,(int)uVar5,
                   (int)((ulonglong)uVar5 >> 0x20));
      if (0x1f0 < uVar3) break;
      iVar2 = iVar2 + 5;
      if (iVar2 == 0x1004) {
        FUN_08037a50(s___Failed__0803d4f8);
        DAT_20000130 = CONCAT22((short)DAT_2000c198,(undefined2)DAT_20000130);
        FUN_0803062c(&DAT_20000334,1,0);
        if (bVar1) goto LAB_0803473e;
        goto LAB_08034440;
      }
      FUN_08037994(0xd);
    }
    FUN_08037a50(s___Done__0803d550);
    DAT_20000130 = CONCAT22((short)iVar2,(undefined2)DAT_20000130);
    DAT_2000c198 = iVar2;
    FUN_0803062c(&DAT_20000334,1,0);
  }
LAB_0803473e:
  iVar2 = FUN_080340c0(8,0x8004000,&DAT_2000c190);
  if (iVar2 == 0) {
    FUN_08037a50(s__OK__Save_calibration_data_0803d55c);
  }
  else {
    FUN_08037a50(s__ERR__Save_calibration_data_0803d578);
  }
LAB_08034440:
  (*DAT_2000c6cc)(0);
  _DAT_40021014 = _DAT_40021014 & 0xfffffeff | 0x200;
  _DAT_40021814 = _DAT_40021814 & 0xfffff7ff;
  FUN_080349e4(100);
  while (iVar2 = FUN_0802af0c(&DAT_20000024,&DAT_20000160), iVar2 == 0) {
    FUN_080349e4(1);
  }
  FUN_0802d7bc();
  FUN_08032dac();
  FUN_0803304c();
  FUN_08033e3c(0x10,0x8008000,&DAT_2000e984);
  (*DAT_2000c6c8)(0);
  FUN_08030140(&DAT_200002ac,0);
  _DAT_40021814 = _DAT_40021814 & 0xfffff7fc;
  _DAT_40021014 = _DAT_40021014 & 0xffffbc7f;
  _DAT_40020c14 = _DAT_40020c14 & 0xffffffef;
  _DAT_40021414 = _DAT_40021414 | 0x800;
  FUN_080349e4(5000);
  _DAT_40020c14 = _DAT_40020c14 & 0xfffffff7;
  FUN_080349e4(3000);
  _DAT_40020c14 = _DAT_40020c14 & 0xfffffffb;
  _DAT_40021014 = _DAT_40021014 & 0xfffff7ff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(1);
  }
  do {
  } while (-1 < _DAT_40021810 << 0x1b);
  FUN_080349e4(100);
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

