
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_08024528(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined *puVar13;
  float fVar14;
  float fVar15;
  float *pfVar16;
  uint *puVar17;
  int iVar18;
  uint uVar19;
  undefined1 *puVar20;
  undefined4 *puVar21;
  uint uVar22;
  undefined1 *puVar23;
  uint *puVar24;
  undefined1 *puVar25;
  undefined4 *puVar26;
  float *pfVar27;
  float *pfVar28;
  byte bVar29;
  byte bVar30;
  char cVar31;
  byte bVar32;
  bool bVar33;
  uint in_fpscr;
  uint uVar34;
  uint uVar35;
  float fVar36;
  undefined4 uVar37;
  float fVar38;
  float fVar39;
  undefined4 uVar40;
  float fVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  uint local_ac;
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 uStack_94;
  float *local_74;
  float local_68;
  undefined1 auStack_64 [4];
  float local_60;
  float local_5c;
  undefined1 auStack_58 [4];
  float local_54;
  float local_50;
  float local_4c;
  
  iVar12 = FUN_0802e284(&DAT_40026058,0x18008000);
  if (iVar12 != 1) {
    return;
  }
  FUN_0802e2dc(&DAT_40026058,0x18008000);
  iVar12 = FUN_0802e1d4(&DAT_40026058);
  _DAT_200003d4 = _DAT_200003e8;
  _DAT_200003cc = _DAT_200003d8;
  if (iVar12 != 1) {
    _DAT_200003d4 = _DAT_200003ec;
    _DAT_200003cc = _DAT_200003dc;
  }
  iVar12 = FUN_0802e1d4(&DAT_40026070);
  bVar8 = DAT_200085ad;
  _DAT_200003d0 = _DAT_200003f0;
  _DAT_200003c8 = _DAT_200003e0;
  if (iVar12 != 1) {
    _DAT_200003d0 = _DAT_200003f4;
    _DAT_200003c8 = _DAT_200003e4;
  }
  _DAT_40020414 = _DAT_40020414 & 0xfffffffb;
  if (DAT_2000b738 == '\0') {
    FUN_0802145c(&DAT_200082ec);
  }
  else {
    _DAT_200082f5 = 0x101;
  }
  fVar36 = _DAT_2000ba44;
  bVar33 = (_DAT_200085b4 & 8) != 0;
  if (bVar33) {
    _DAT_200085b4 = _DAT_200085b4 & 0xfffffff7;
  }
  if ((int)(_DAT_200085b4 << 0x1d) < 0) {
    _DAT_2000b7a8 = -40.0;
    _DAT_200085b4 = _DAT_200085b4 & 0xfffffffb;
    _DAT_2000b7cc = 0.0;
    _DAT_2000b7bc = 0.0;
    _DAT_2000b7c0 = 0;
    if (DAT_200085ad < 6) {
      if (DAT_200085ad < 4) {
        _DAT_20008394 = _DAT_2000ba48;
        uVar42 = FUN_08020628(6600.0 / _DAT_2000ba48);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
        if (_DAT_20006e44 == 0) {
          uVar35 = _DAT_20006e40;
          if (uVar34 != _DAT_20006e40) goto LAB_08025616;
        }
        else {
          _DAT_20006e44 = 0;
          if (uVar34 != _DAT_20006e40) {
LAB_08025616:
            _DAT_20006e40 = uVar34;
          }
          FUN_08034a6c(0,0x20006df0,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006d8c,0x19);
            _DAT_20006d88 = 0.0;
          }
          else {
            _DAT_20006d8c = *puVar26;
            _DAT_20006d90 = puVar26[1];
            _DAT_20006d94 = puVar26[2];
            _DAT_20006d98 = -(float)puVar26[4];
            _DAT_20006d9c = -(float)puVar26[5];
            _DAT_20006da0 = puVar26[6];
            _DAT_20006da4 = puVar26[7];
            _DAT_20006da8 = puVar26[8];
            _DAT_20006dac = -(float)puVar26[10];
            _DAT_20006db0 = -(float)puVar26[0xb];
            _DAT_20006db4 = puVar26[0xc];
            _DAT_20006db8 = puVar26[0xd];
            _DAT_20006dbc = puVar26[0xe];
            _DAT_20006dc0 = -(float)puVar26[0x10];
            _DAT_20006dc4 = -(float)puVar26[0x11];
            _DAT_20006dc8 = puVar26[0x12];
            _DAT_20006dcc = puVar26[0x13];
            _DAT_20006dd0 = puVar26[0x14];
            _DAT_20006dd4 = -(float)puVar26[0x16];
            _DAT_20006dd8 = -(float)puVar26[0x17];
            _DAT_20006ddc = puVar26[0x18];
            _DAT_20006de0 = puVar26[0x19];
            _DAT_20006de4 = puVar26[0x1a];
            _DAT_20006de8 = -(float)puVar26[0x1c];
            _DAT_20006dec = -(float)puVar26[0x1d];
            _DAT_20006d88 = (float)puVar26[0x1e];
          }
          uVar42 = FUN_08020628(6600.0 / _DAT_2000ba48);
          uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
          FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
          uVar35 = FUN_08020c38();
          if (0x3e2 < (int)uVar35) {
            uVar35 = 0x3e3;
          }
          uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
          puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20002414);
        }
        if (_DAT_20006f10 == 0) {
          if (uVar35 != _DAT_20006f0c) goto LAB_080257cc;
        }
        else {
          _DAT_20006f10 = 0;
          if (uVar35 != _DAT_20006f0c) {
LAB_080257cc:
            _DAT_20006f0c = uVar35;
          }
          FUN_08034a6c(0,0x20006ebc,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006e58,0x19);
            _DAT_20006e54 = 0.0;
          }
          else {
            _DAT_20006e58 = *puVar26;
            _DAT_20006e5c = puVar26[1];
            _DAT_20006e60 = puVar26[2];
            _DAT_20006e64 = -(float)puVar26[4];
            _DAT_20006e68 = -(float)puVar26[5];
            _DAT_20006e6c = puVar26[6];
            _DAT_20006e70 = puVar26[7];
            _DAT_20006e74 = puVar26[8];
            _DAT_20006e78 = -(float)puVar26[10];
            _DAT_20006e7c = -(float)puVar26[0xb];
            _DAT_20006e80 = puVar26[0xc];
            _DAT_20006e84 = puVar26[0xd];
            _DAT_20006e88 = puVar26[0xe];
            _DAT_20006e8c = -(float)puVar26[0x10];
            _DAT_20006e90 = -(float)puVar26[0x11];
            _DAT_20006e94 = puVar26[0x12];
            _DAT_20006e98 = puVar26[0x13];
            _DAT_20006e9c = puVar26[0x14];
            _DAT_20006ea0 = -(float)puVar26[0x16];
            _DAT_20006ea4 = -(float)puVar26[0x17];
            _DAT_20006ea8 = puVar26[0x18];
            _DAT_20006eac = puVar26[0x19];
            _DAT_20006eb0 = puVar26[0x1a];
            _DAT_20006eb4 = -(float)puVar26[0x1c];
            _DAT_20006eb8 = -(float)puVar26[0x1d];
            _DAT_20006e54 = (float)puVar26[0x1e];
          }
        }
        _DAT_2000b798 = 0.5;
LAB_0802591e:
        _DAT_2000b7ac = 0.5;
        _DAT_2000b7b0 = 0.01;
      }
      else {
        _DAT_20008394 = _DAT_2000ba48;
        uVar42 = FUN_08020628(3000.0 / _DAT_2000ba48);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
        if (_DAT_20006e44 == 0) {
          uVar35 = _DAT_20006e40;
          if (uVar34 != _DAT_20006e40) goto LAB_080278f8;
        }
        else {
          _DAT_20006e44 = 0;
          if (uVar34 != _DAT_20006e40) {
LAB_080278f8:
            _DAT_20006e40 = uVar34;
          }
          FUN_08034a6c(0,0x20006df0,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006d8c,0x19);
            _DAT_20006d88 = 0.0;
          }
          else {
            _DAT_20006d8c = *puVar26;
            _DAT_20006d90 = puVar26[1];
            _DAT_20006d94 = puVar26[2];
            _DAT_20006d98 = -(float)puVar26[4];
            _DAT_20006d9c = -(float)puVar26[5];
            _DAT_20006da0 = puVar26[6];
            _DAT_20006da4 = puVar26[7];
            _DAT_20006da8 = puVar26[8];
            _DAT_20006dac = -(float)puVar26[10];
            _DAT_20006db0 = -(float)puVar26[0xb];
            _DAT_20006db4 = puVar26[0xc];
            _DAT_20006db8 = puVar26[0xd];
            _DAT_20006dbc = puVar26[0xe];
            _DAT_20006dc0 = -(float)puVar26[0x10];
            _DAT_20006dc4 = -(float)puVar26[0x11];
            _DAT_20006dc8 = puVar26[0x12];
            _DAT_20006dcc = puVar26[0x13];
            _DAT_20006dd0 = puVar26[0x14];
            _DAT_20006dd4 = -(float)puVar26[0x16];
            _DAT_20006dd8 = -(float)puVar26[0x17];
            _DAT_20006ddc = puVar26[0x18];
            _DAT_20006de0 = puVar26[0x19];
            _DAT_20006de4 = puVar26[0x1a];
            _DAT_20006de8 = -(float)puVar26[0x1c];
            _DAT_20006dec = -(float)puVar26[0x1d];
            _DAT_20006d88 = (float)puVar26[0x1e];
          }
          uVar42 = FUN_08020628(3000.0 / _DAT_2000ba48);
          uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
          FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
          uVar35 = FUN_08020c38();
          if (0x3e2 < (int)uVar35) {
            uVar35 = 0x3e3;
          }
          uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
          puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20002414);
        }
        if (_DAT_20006f10 == 0) {
          if (uVar35 != _DAT_20006f0c) goto LAB_08027aae;
        }
        else {
          _DAT_20006f10 = 0;
          if (uVar35 != _DAT_20006f0c) {
LAB_08027aae:
            _DAT_20006f0c = uVar35;
          }
          FUN_08034a6c(0,0x20006ebc,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006e58,0x19);
            _DAT_20006e54 = 0.0;
          }
          else {
            _DAT_20006e58 = *puVar26;
            _DAT_20006e5c = puVar26[1];
            _DAT_20006e60 = puVar26[2];
            _DAT_20006e64 = -(float)puVar26[4];
            _DAT_20006e68 = -(float)puVar26[5];
            _DAT_20006e6c = puVar26[6];
            _DAT_20006e70 = puVar26[7];
            _DAT_20006e74 = puVar26[8];
            _DAT_20006e78 = -(float)puVar26[10];
            _DAT_20006e7c = -(float)puVar26[0xb];
            _DAT_20006e80 = puVar26[0xc];
            _DAT_20006e84 = puVar26[0xd];
            _DAT_20006e88 = puVar26[0xe];
            _DAT_20006e8c = -(float)puVar26[0x10];
            _DAT_20006e90 = -(float)puVar26[0x11];
            _DAT_20006e94 = puVar26[0x12];
            _DAT_20006e98 = puVar26[0x13];
            _DAT_20006e9c = puVar26[0x14];
            _DAT_20006ea0 = -(float)puVar26[0x16];
            _DAT_20006ea4 = -(float)puVar26[0x17];
            _DAT_20006ea8 = puVar26[0x18];
            _DAT_20006eac = puVar26[0x19];
            _DAT_20006eb0 = puVar26[0x1a];
            _DAT_20006eb4 = -(float)puVar26[0x1c];
            _DAT_20006eb8 = -(float)puVar26[0x1d];
            _DAT_20006e54 = (float)puVar26[0x1e];
          }
        }
        _DAT_2000b7ac = 0.2;
        _DAT_2000b7b0 = 0.05;
        _DAT_2000b798 = 0.5;
      }
    }
    else {
      if (DAT_200085ad == 6) {
        _DAT_200085b4 = _DAT_200085b4 | 1;
        _DAT_20008394 = _DAT_2000ba4c;
        uVar42 = FUN_08020628(0);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20001484);
        if (_DAT_20006fdc == 1) {
          if (uVar34 != _DAT_20006fd8) goto LAB_08025b54;
        }
        else {
          _DAT_20006fdc = 1;
          if (uVar34 != _DAT_20006fd8) {
LAB_08025b54:
            _DAT_20006fd8 = uVar34;
          }
          FUN_08034a6c(0,0x20006f88,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006f24,0x19);
            _DAT_20006f20 = 0.0;
          }
          else {
            _DAT_20006f24 = *puVar26;
            _DAT_20006f28 = puVar26[1];
            _DAT_20006f2c = puVar26[2];
            _DAT_20006f30 = -(float)puVar26[4];
            _DAT_20006f34 = -(float)puVar26[5];
            _DAT_20006f38 = puVar26[6];
            _DAT_20006f3c = puVar26[7];
            _DAT_20006f40 = puVar26[8];
            _DAT_20006f44 = -(float)puVar26[10];
            _DAT_20006f48 = -(float)puVar26[0xb];
            _DAT_20006f4c = puVar26[0xc];
            _DAT_20006f50 = puVar26[0xd];
            _DAT_20006f54 = puVar26[0xe];
            _DAT_20006f58 = -(float)puVar26[0x10];
            _DAT_20006f5c = -(float)puVar26[0x11];
            _DAT_20006f60 = puVar26[0x12];
            _DAT_20006f64 = puVar26[0x13];
            _DAT_20006f68 = puVar26[0x14];
            _DAT_20006f6c = -(float)puVar26[0x16];
            _DAT_20006f70 = -(float)puVar26[0x17];
            _DAT_20006f74 = puVar26[0x18];
            _DAT_20006f78 = puVar26[0x19];
            _DAT_20006f7c = puVar26[0x1a];
            _DAT_20006f80 = -(float)puVar26[0x1c];
            _DAT_20006f84 = -(float)puVar26[0x1d];
            _DAT_20006f20 = (float)puVar26[0x1e];
          }
        }
        uVar42 = FUN_08020628(12000.0 / fVar36);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
        if (_DAT_200070a8 == 0) {
          if (uVar34 != _DAT_200070a4) goto LAB_08025d0a;
        }
        else {
          _DAT_200070a8 = 0;
          if (uVar34 != _DAT_200070a4) {
LAB_08025d0a:
            _DAT_200070a4 = uVar34;
          }
          FUN_08034a6c(0,0x20007054,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20006ff0,0x19);
            _DAT_20006fec = 0.0;
          }
          else {
            _DAT_20006ff0 = *puVar26;
            _DAT_20006ff4 = puVar26[1];
            _DAT_20006ff8 = puVar26[2];
            _DAT_20006ffc = -(float)puVar26[4];
            _DAT_20007000 = -(float)puVar26[5];
            _DAT_20007004 = puVar26[6];
            _DAT_20007008 = puVar26[7];
            _DAT_2000700c = puVar26[8];
            _DAT_20007010 = -(float)puVar26[10];
            _DAT_20007014 = -(float)puVar26[0xb];
            _DAT_20007018 = puVar26[0xc];
            _DAT_2000701c = puVar26[0xd];
            _DAT_20007020 = puVar26[0xe];
            _DAT_20007024 = -(float)puVar26[0x10];
            _DAT_20007028 = -(float)puVar26[0x11];
            _DAT_2000702c = puVar26[0x12];
            _DAT_20007030 = puVar26[0x13];
            _DAT_20007034 = puVar26[0x14];
            _DAT_20007038 = -(float)puVar26[0x16];
            _DAT_2000703c = -(float)puVar26[0x17];
            _DAT_20007040 = puVar26[0x18];
            _DAT_20007044 = puVar26[0x19];
            _DAT_20007048 = puVar26[0x1a];
            _DAT_2000704c = -(float)puVar26[0x1c];
            _DAT_20007050 = -(float)puVar26[0x1d];
            _DAT_20006fec = (float)puVar26[0x1e];
          }
        }
        fVar36 = _DAT_2000ba44;
        uVar42 = FUN_08020628(0);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20001484);
        if (_DAT_20007174 == 1) {
          if (uVar34 != _DAT_20007170) goto LAB_08025eac;
        }
        else {
          _DAT_20007174 = 1;
          if (uVar34 != _DAT_20007170) {
LAB_08025eac:
            _DAT_20007170 = uVar34;
          }
          FUN_08034a6c(0,0x20007120,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_200070bc,0x19);
            _DAT_200070b8 = 0.0;
          }
          else {
            _DAT_200070bc = *puVar26;
            _DAT_200070c0 = puVar26[1];
            _DAT_200070c4 = puVar26[2];
            _DAT_200070c8 = -(float)puVar26[4];
            _DAT_200070cc = -(float)puVar26[5];
            _DAT_200070d0 = puVar26[6];
            _DAT_200070d4 = puVar26[7];
            _DAT_200070d8 = puVar26[8];
            _DAT_200070dc = -(float)puVar26[10];
            _DAT_200070e0 = -(float)puVar26[0xb];
            _DAT_200070e4 = puVar26[0xc];
            _DAT_200070e8 = puVar26[0xd];
            _DAT_200070ec = puVar26[0xe];
            _DAT_200070f0 = -(float)puVar26[0x10];
            _DAT_200070f4 = -(float)puVar26[0x11];
            _DAT_200070f8 = puVar26[0x12];
            _DAT_200070fc = puVar26[0x13];
            _DAT_20007100 = puVar26[0x14];
            _DAT_20007104 = -(float)puVar26[0x16];
            _DAT_20007108 = -(float)puVar26[0x17];
            _DAT_2000710c = puVar26[0x18];
            _DAT_20007110 = puVar26[0x19];
            _DAT_20007114 = puVar26[0x1a];
            _DAT_20007118 = -(float)puVar26[0x1c];
            _DAT_2000711c = -(float)puVar26[0x1d];
            _DAT_200070b8 = (float)puVar26[0x1e];
          }
        }
        uVar42 = FUN_08020628(12000.0 / fVar36);
        uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
        FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
        uVar34 = FUN_08020c38();
        if (0x3e2 < (int)uVar34) {
          uVar34 = 0x3e3;
        }
        uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
        puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
        if (_DAT_20007240 == 0) {
          if (uVar34 != _DAT_2000723c) goto LAB_08026058;
        }
        else {
          _DAT_20007240 = 0;
          if (uVar34 != _DAT_2000723c) {
LAB_08026058:
            _DAT_2000723c = uVar34;
          }
          FUN_08034a6c(0,0x200071ec,0x14);
          if (puVar26 == (undefined4 *)0x0) {
            FUN_08034a6c(0,&DAT_20007188,0x19);
            _DAT_20007184 = 0.0;
          }
          else {
            _DAT_20007188 = *puVar26;
            _DAT_2000718c = puVar26[1];
            _DAT_20007190 = puVar26[2];
            _DAT_20007194 = -(float)puVar26[4];
            _DAT_20007198 = -(float)puVar26[5];
            _DAT_2000719c = puVar26[6];
            _DAT_200071a0 = puVar26[7];
            _DAT_200071a4 = puVar26[8];
            _DAT_200071a8 = -(float)puVar26[10];
            _DAT_200071ac = -(float)puVar26[0xb];
            _DAT_200071b0 = puVar26[0xc];
            _DAT_200071b4 = puVar26[0xd];
            _DAT_200071b8 = puVar26[0xe];
            _DAT_200071bc = -(float)puVar26[0x10];
            _DAT_200071c0 = -(float)puVar26[0x11];
            _DAT_200071c4 = puVar26[0x12];
            _DAT_200071c8 = puVar26[0x13];
            _DAT_200071cc = puVar26[0x14];
            _DAT_200071d0 = -(float)puVar26[0x16];
            _DAT_200071d4 = -(float)puVar26[0x17];
            _DAT_200071d8 = puVar26[0x18];
            _DAT_200071dc = puVar26[0x19];
            _DAT_200071e0 = puVar26[0x1a];
            _DAT_200071e4 = -(float)puVar26[0x1c];
            _DAT_200071e8 = -(float)puVar26[0x1d];
            _DAT_20007184 = (float)puVar26[0x1e];
          }
        }
        goto LAB_0802591e;
      }
      _DAT_20008394 = _DAT_2000ba4c;
      FUN_0802282c(_DAT_2000ba4c,0x45ea6000,0x20006d7c,0,1);
      FUN_0802282c(_DAT_2000ba4c,0x45ea6000,0x20006e48,0,1);
      fVar36 = _DAT_2000ba44;
      uVar42 = FUN_08020628(0);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar34 = FUN_08020c38();
      if (0x3e2 < (int)uVar34) {
        uVar34 = 0x3e3;
      }
      uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20001484);
      if (_DAT_20006fdc == 1) {
        if (uVar34 != _DAT_20006fd8) goto LAB_08027196;
      }
      else {
        _DAT_20006fdc = 1;
        if (uVar34 != _DAT_20006fd8) {
LAB_08027196:
          _DAT_20006fd8 = uVar34;
        }
        FUN_08034a6c(0,0x20006f88,0x14);
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20006f24,0x19);
          _DAT_20006f20 = 0.0;
        }
        else {
          _DAT_20006f24 = *puVar26;
          _DAT_20006f28 = puVar26[1];
          _DAT_20006f2c = puVar26[2];
          _DAT_20006f30 = -(float)puVar26[4];
          _DAT_20006f34 = -(float)puVar26[5];
          _DAT_20006f38 = puVar26[6];
          _DAT_20006f3c = puVar26[7];
          _DAT_20006f40 = puVar26[8];
          _DAT_20006f44 = -(float)puVar26[10];
          _DAT_20006f48 = -(float)puVar26[0xb];
          _DAT_20006f4c = puVar26[0xc];
          _DAT_20006f50 = puVar26[0xd];
          _DAT_20006f54 = puVar26[0xe];
          _DAT_20006f58 = -(float)puVar26[0x10];
          _DAT_20006f5c = -(float)puVar26[0x11];
          _DAT_20006f60 = puVar26[0x12];
          _DAT_20006f64 = puVar26[0x13];
          _DAT_20006f68 = puVar26[0x14];
          _DAT_20006f6c = -(float)puVar26[0x16];
          _DAT_20006f70 = -(float)puVar26[0x17];
          _DAT_20006f74 = puVar26[0x18];
          _DAT_20006f78 = puVar26[0x19];
          _DAT_20006f7c = puVar26[0x1a];
          _DAT_20006f80 = -(float)puVar26[0x1c];
          _DAT_20006f84 = -(float)puVar26[0x1d];
          _DAT_20006f20 = (float)puVar26[0x1e];
        }
      }
      uVar42 = FUN_08020628(12000.0 / fVar36);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar34 = FUN_08020c38();
      if (0x3e2 < (int)uVar34) {
        uVar34 = 0x3e3;
      }
      uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
      if (_DAT_200070a8 == 0) {
        if (uVar34 != _DAT_200070a4) goto LAB_0802734c;
      }
      else {
        _DAT_200070a8 = 0;
        if (uVar34 != _DAT_200070a4) {
LAB_0802734c:
          _DAT_200070a4 = uVar34;
        }
        FUN_08034a6c(0,0x20007054,0x14);
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20006ff0,0x19);
          _DAT_20006fec = 0.0;
        }
        else {
          _DAT_20006ff0 = *puVar26;
          _DAT_20006ff4 = puVar26[1];
          _DAT_20006ff8 = puVar26[2];
          _DAT_20006ffc = -(float)puVar26[4];
          _DAT_20007000 = -(float)puVar26[5];
          _DAT_20007004 = puVar26[6];
          _DAT_20007008 = puVar26[7];
          _DAT_2000700c = puVar26[8];
          _DAT_20007010 = -(float)puVar26[10];
          _DAT_20007014 = -(float)puVar26[0xb];
          _DAT_20007018 = puVar26[0xc];
          _DAT_2000701c = puVar26[0xd];
          _DAT_20007020 = puVar26[0xe];
          _DAT_20007024 = -(float)puVar26[0x10];
          _DAT_20007028 = -(float)puVar26[0x11];
          _DAT_2000702c = puVar26[0x12];
          _DAT_20007030 = puVar26[0x13];
          _DAT_20007034 = puVar26[0x14];
          _DAT_20007038 = -(float)puVar26[0x16];
          _DAT_2000703c = -(float)puVar26[0x17];
          _DAT_20007040 = puVar26[0x18];
          _DAT_20007044 = puVar26[0x19];
          _DAT_20007048 = puVar26[0x1a];
          _DAT_2000704c = -(float)puVar26[0x1c];
          _DAT_20007050 = -(float)puVar26[0x1d];
          _DAT_20006fec = (float)puVar26[0x1e];
        }
      }
      fVar36 = _DAT_2000ba44;
      uVar42 = FUN_08020628(0);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar34 = FUN_08020c38();
      if (0x3e2 < (int)uVar34) {
        uVar34 = 0x3e3;
      }
      uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20001484);
      if (_DAT_20007174 == 1) {
        if (uVar34 != _DAT_20007170) goto LAB_080274ee;
      }
      else {
        _DAT_20007174 = 1;
        if (uVar34 != _DAT_20007170) {
LAB_080274ee:
          _DAT_20007170 = uVar34;
        }
        FUN_08034a6c(0,0x20007120,0x14);
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_200070bc,0x19);
          _DAT_200070b8 = 0.0;
        }
        else {
          _DAT_200070bc = *puVar26;
          _DAT_200070c0 = puVar26[1];
          _DAT_200070c4 = puVar26[2];
          _DAT_200070c8 = -(float)puVar26[4];
          _DAT_200070cc = -(float)puVar26[5];
          _DAT_200070d0 = puVar26[6];
          _DAT_200070d4 = puVar26[7];
          _DAT_200070d8 = puVar26[8];
          _DAT_200070dc = -(float)puVar26[10];
          _DAT_200070e0 = -(float)puVar26[0xb];
          _DAT_200070e4 = puVar26[0xc];
          _DAT_200070e8 = puVar26[0xd];
          _DAT_200070ec = puVar26[0xe];
          _DAT_200070f0 = -(float)puVar26[0x10];
          _DAT_200070f4 = -(float)puVar26[0x11];
          _DAT_200070f8 = puVar26[0x12];
          _DAT_200070fc = puVar26[0x13];
          _DAT_20007100 = puVar26[0x14];
          _DAT_20007104 = -(float)puVar26[0x16];
          _DAT_20007108 = -(float)puVar26[0x17];
          _DAT_2000710c = puVar26[0x18];
          _DAT_20007110 = puVar26[0x19];
          _DAT_20007114 = puVar26[0x1a];
          _DAT_20007118 = -(float)puVar26[0x1c];
          _DAT_2000711c = -(float)puVar26[0x1d];
          _DAT_200070b8 = (float)puVar26[0x1e];
        }
      }
      uVar42 = FUN_08020628(12000.0 / fVar36);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar34 = FUN_08020c38();
      if (0x3e2 < (int)uVar34) {
        uVar34 = 0x3e3;
      }
      uVar34 = uVar34 & ~((int)uVar34 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar34 * 4 + 0x20002414);
      if (_DAT_20007240 == 0) {
        if (uVar34 != _DAT_2000723c) goto LAB_0802769a;
      }
      else {
        _DAT_20007240 = 0;
        if (uVar34 != _DAT_2000723c) {
LAB_0802769a:
          _DAT_2000723c = uVar34;
        }
        FUN_08034a6c(0,0x200071ec,0x14);
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20007188,0x19);
          _DAT_20007184 = 0.0;
        }
        else {
          _DAT_20007188 = *puVar26;
          _DAT_2000718c = puVar26[1];
          _DAT_20007190 = puVar26[2];
          _DAT_20007194 = -(float)puVar26[4];
          _DAT_20007198 = -(float)puVar26[5];
          _DAT_2000719c = puVar26[6];
          _DAT_200071a0 = puVar26[7];
          _DAT_200071a4 = puVar26[8];
          _DAT_200071a8 = -(float)puVar26[10];
          _DAT_200071ac = -(float)puVar26[0xb];
          _DAT_200071b0 = puVar26[0xc];
          _DAT_200071b4 = puVar26[0xd];
          _DAT_200071b8 = puVar26[0xe];
          _DAT_200071bc = -(float)puVar26[0x10];
          _DAT_200071c0 = -(float)puVar26[0x11];
          _DAT_200071c4 = puVar26[0x12];
          _DAT_200071c8 = puVar26[0x13];
          _DAT_200071cc = puVar26[0x14];
          _DAT_200071d0 = -(float)puVar26[0x16];
          _DAT_200071d4 = -(float)puVar26[0x17];
          _DAT_200071d8 = puVar26[0x18];
          _DAT_200071dc = puVar26[0x19];
          _DAT_200071e0 = puVar26[0x1a];
          _DAT_200071e4 = -(float)puVar26[0x1c];
          _DAT_200071e8 = -(float)puVar26[0x1d];
          _DAT_20007184 = (float)puVar26[0x1e];
        }
      }
      fVar36 = -1256.6371 / _DAT_2000ba4c;
      _DAT_20004d94 = _DAT_2000ba4c;
      _DAT_20004d90 = 0xc3480000;
      _DAT_20004da0 = 0x3f800000;
      _DAT_20004da4 = 0;
      _DAT_20004d98 = FUN_080363f8(fVar36);
      _DAT_20004d9c = FUN_08036370(fVar36);
      _DAT_2000b7b0 = 0.01;
      _DAT_2000b798 = 0.1;
      _DAT_2000b7ac = 0.5;
    }
    if (DAT_200085ad == 7) {
      DAT_20008598 = '\0';
    }
    else {
      if (DAT_200085b1 != '\0') {
        DAT_20008598 = '\x01';
      }
      if ((1 < DAT_200085ad - 6) && (DAT_200085ae - 6 < 2)) {
        _DAT_200085b4 = _DAT_200085b4 | 1;
      }
    }
    DAT_200085ae = DAT_200085ad;
    DAT_2000832c = '\x01';
    if (DAT_200085b3 != DAT_200085b2) {
      DAT_200085b3 = DAT_200085b2;
      _DAT_2000b7a8 = -40.0;
      _DAT_2000b7cc = 0.0;
      _DAT_2000b7bc = 0.0;
      _DAT_2000b7c0 = 0;
    }
LAB_08025998:
    _DAT_200078d4 = 0;
    _DAT_20004dac = 0;
    FUN_08034a6c(0,0x20007a78,0x65);
    FUN_08034a6c(0,0x20007c0c,100);
    if (_DAT_2000ba38 != 0) {
      iVar12 = _DAT_2000ba38 * 8;
      puVar21 = (undefined4 *)&DAT_20003590;
      puVar26 = (undefined4 *)&DAT_20005dc4;
      do {
        puVar21[0x300] = 0;
        puVar21[0x301] = 0;
        *puVar21 = 0;
        puVar21[1] = 0;
        puVar21 = puVar21 + 2;
        *puVar26 = 0;
        puVar26[0x80] = 0;
        puVar26[0x100] = 0;
        puVar26 = puVar26 + 1;
      } while ((undefined4 *)(&DAT_20003590 + iVar12) != puVar21);
    }
    _DAT_2000b73c = 0.0;
    _DAT_2000b740 = 0.0;
    _DAT_2000b744 = 0.0;
    _DAT_2000b758 = 0.0;
    _DAT_2000b75c = 0.0;
    _DAT_2000b74c = 0.0;
    _DAT_2000b748 = 0.0;
    _DAT_2000b770 = 0.0;
    _DAT_2000b77c = 0;
    _DAT_2000b9d4 = 0;
    _DAT_2000b780 = 100;
    _DAT_2000b760 = 1.0;
    _DAT_2000b768 = 1.0;
    FUN_08034a6c(0,0x2000b9d8,10);
    FUN_08034a6c(0,0x2000ba00,10);
    if (DAT_200085af != '\x01') goto LAB_08024642;
    if ((bVar8 == 4) || (bVar8 == 5)) {
      DAT_2000b78c = '\0';
    }
    else {
      _DAT_40021014 = _DAT_40021014 & 0xffffefff;
      DAT_2000b78c = '\x01';
    }
LAB_08025aba:
    _DAT_20008370 = _DAT_2000836c;
  }
  else {
    if (DAT_200085b3 != DAT_200085b2) {
      _DAT_2000b7a8 = -40.0;
      DAT_200085b3 = DAT_200085b2;
      _DAT_2000b7cc = 0.0;
      _DAT_2000b7bc = 0.0;
      _DAT_2000b7c0 = 0;
    }
    if (bVar33) goto LAB_08025998;
    if (DAT_200085af == '\x01') goto LAB_08025aba;
LAB_08024642:
    if (DAT_20008374 == '\0') {
      _DAT_20008370 = 0.0;
    }
    else {
      _DAT_20008370 = 0.5;
    }
  }
  fVar36 = _DAT_2000ba44;
  cVar31 = DAT_2000832c;
  uVar34 = in_fpscr & 0xfffffff | (uint)(_DAT_20008390 == _DAT_20008394) << 0x1e;
  if ((byte)(uVar34 >> 0x1e) == 0) {
    _DAT_20008390 = _DAT_20008394;
  }
  _DAT_2000b7c8 = 0.9;
  if (DAT_200085b2 < 0x14) {
    _DAT_2000b7c8 = 1.0;
  }
  _DAT_2000b7c4 = 0.0;
  if (DAT_200085b2 >= 0x14) {
    _DAT_2000b7c4 = 6.0;
  }
  if ((int)(_DAT_200085b4 << 0x1f) < 0) {
    _DAT_200085b4 = _DAT_200085b4 & 0xfffffffe;
    if (DAT_200085ad == 6) {
      uVar35 = _DAT_2000859c;
      if ((int)_DAT_2000859c < (int)_DAT_200085a4) {
        uVar35 = _DAT_200085a4;
      }
      uVar22 = _DAT_200085a8;
      if ((int)_DAT_200085a0 <= (int)_DAT_200085a8) {
        uVar22 = _DAT_200085a0;
      }
      uVar37 = VectorSignedToFloat((uVar35 ^ (int)uVar35 >> 0x1f) - ((int)uVar35 >> 0x1f),
                                   (byte)(uVar34 >> 0x16) & 3);
      FUN_0802282c(_DAT_2000ba4c,uVar37,0x20006d7c,0,DAT_2000832c);
      uVar37 = VectorSignedToFloat((uVar22 ^ (int)uVar22 >> 0x1f) - ((int)uVar22 >> 0x1f),
                                   (byte)(uVar34 >> 0x16) & 3);
      FUN_0802282c(_DAT_2000ba4c,uVar37,0x20006e48,0,DAT_2000832c);
    }
    else if (DAT_200085ad != 7) {
      fVar38 = (float)VectorSignedToFloat(_DAT_2000859c,(byte)(uVar34 >> 0x16) & 3);
      fVar41 = (float)VectorSignedToFloat(_DAT_200085a0,(byte)(uVar34 >> 0x16) & 3);
      uVar42 = FUN_08020628((fVar38 + fVar38) / _DAT_2000ba44);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar35 = FUN_08020c38();
      if (0x3e2 < (int)uVar35) {
        uVar35 = 0x3e3;
      }
      uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20001484);
      if (_DAT_20006fdc == 1) {
        if (uVar35 != _DAT_20006fd8) goto LAB_08026ac2;
      }
      else {
        _DAT_20006fdc = 1;
        if (uVar35 != _DAT_20006fd8) {
LAB_08026ac2:
          _DAT_20006fd8 = uVar35;
        }
        if (cVar31 != '\0') {
          FUN_08034a6c(0,0x20006f88,0x14);
        }
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20006f24,0x19);
          _DAT_20006f20 = 0.0;
        }
        else {
          _DAT_20006f24 = *puVar26;
          _DAT_20006f28 = puVar26[1];
          _DAT_20006f2c = puVar26[2];
          _DAT_20006f30 = -(float)puVar26[4];
          _DAT_20006f34 = -(float)puVar26[5];
          _DAT_20006f38 = puVar26[6];
          _DAT_20006f3c = puVar26[7];
          _DAT_20006f40 = puVar26[8];
          _DAT_20006f44 = -(float)puVar26[10];
          _DAT_20006f48 = -(float)puVar26[0xb];
          _DAT_20006f4c = puVar26[0xc];
          _DAT_20006f50 = puVar26[0xd];
          _DAT_20006f54 = puVar26[0xe];
          _DAT_20006f58 = -(float)puVar26[0x10];
          _DAT_20006f5c = -(float)puVar26[0x11];
          _DAT_20006f60 = puVar26[0x12];
          _DAT_20006f64 = puVar26[0x13];
          _DAT_20006f68 = puVar26[0x14];
          _DAT_20006f6c = -(float)puVar26[0x16];
          _DAT_20006f70 = -(float)puVar26[0x17];
          _DAT_20006f74 = puVar26[0x18];
          _DAT_20006f78 = puVar26[0x19];
          _DAT_20006f7c = puVar26[0x1a];
          _DAT_20006f80 = -(float)puVar26[0x1c];
          _DAT_20006f84 = -(float)puVar26[0x1d];
          _DAT_20006f20 = (float)puVar26[0x1e];
        }
      }
      uVar42 = FUN_08020628((fVar41 + fVar41) / fVar36);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar35 = FUN_08020c38();
      if (0x3e2 < (int)uVar35) {
        uVar35 = 0x3e3;
      }
      uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20002414);
      if (_DAT_200070a8 == 0) {
        if (uVar35 != _DAT_200070a4) goto LAB_08026c60;
      }
      else {
        _DAT_200070a8 = 0;
        if (uVar35 != _DAT_200070a4) {
LAB_08026c60:
          _DAT_200070a4 = uVar35;
        }
        if (cVar31 != '\0') {
          FUN_08034a6c(0,0x20007054,0x14);
        }
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20006ff0,0x19);
          _DAT_20006fec = 0.0;
        }
        else {
          _DAT_20006ff0 = *puVar26;
          _DAT_20006ff4 = puVar26[1];
          _DAT_20006ff8 = puVar26[2];
          _DAT_20006ffc = -(float)puVar26[4];
          _DAT_20007000 = -(float)puVar26[5];
          _DAT_20007004 = puVar26[6];
          _DAT_20007008 = puVar26[7];
          _DAT_2000700c = puVar26[8];
          _DAT_20007010 = -(float)puVar26[10];
          _DAT_20007014 = -(float)puVar26[0xb];
          _DAT_20007018 = puVar26[0xc];
          _DAT_2000701c = puVar26[0xd];
          _DAT_20007020 = puVar26[0xe];
          _DAT_20007024 = -(float)puVar26[0x10];
          _DAT_20007028 = -(float)puVar26[0x11];
          _DAT_2000702c = puVar26[0x12];
          _DAT_20007030 = puVar26[0x13];
          _DAT_20007034 = puVar26[0x14];
          _DAT_20007038 = -(float)puVar26[0x16];
          _DAT_2000703c = -(float)puVar26[0x17];
          _DAT_20007040 = puVar26[0x18];
          _DAT_20007044 = puVar26[0x19];
          _DAT_20007048 = puVar26[0x1a];
          _DAT_2000704c = -(float)puVar26[0x1c];
          _DAT_20007050 = -(float)puVar26[0x1d];
          _DAT_20006fec = (float)puVar26[0x1e];
        }
      }
      fVar36 = _DAT_2000ba44;
      fVar38 = (float)VectorSignedToFloat(_DAT_200085a4,(byte)(uVar34 >> 0x16) & 3);
      fVar41 = (float)VectorSignedToFloat(_DAT_200085a8,(byte)(uVar34 >> 0x16) & 3);
      uVar42 = FUN_08020628((fVar38 + fVar38) / _DAT_2000ba44);
      cVar31 = DAT_2000832c;
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar35 = FUN_08020c38();
      if (0x3e2 < (int)uVar35) {
        uVar35 = 0x3e3;
      }
      uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20001484);
      if (_DAT_20007174 == 1) {
        if (uVar35 != _DAT_20007170) goto LAB_08026e12;
      }
      else {
        _DAT_20007174 = 1;
        if (uVar35 != _DAT_20007170) {
LAB_08026e12:
          _DAT_20007170 = uVar35;
        }
        if (cVar31 != '\0') {
          FUN_08034a6c(0,0x20007120,0x14);
        }
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_200070bc,0x19);
          _DAT_200070b8 = 0.0;
        }
        else {
          _DAT_200070bc = *puVar26;
          _DAT_200070c0 = puVar26[1];
          _DAT_200070c4 = puVar26[2];
          _DAT_200070c8 = -(float)puVar26[4];
          _DAT_200070cc = -(float)puVar26[5];
          _DAT_200070d0 = puVar26[6];
          _DAT_200070d4 = puVar26[7];
          _DAT_200070d8 = puVar26[8];
          _DAT_200070dc = -(float)puVar26[10];
          _DAT_200070e0 = -(float)puVar26[0xb];
          _DAT_200070e4 = puVar26[0xc];
          _DAT_200070e8 = puVar26[0xd];
          _DAT_200070ec = puVar26[0xe];
          _DAT_200070f0 = -(float)puVar26[0x10];
          _DAT_200070f4 = -(float)puVar26[0x11];
          _DAT_200070f8 = puVar26[0x12];
          _DAT_200070fc = puVar26[0x13];
          _DAT_20007100 = puVar26[0x14];
          _DAT_20007104 = -(float)puVar26[0x16];
          _DAT_20007108 = -(float)puVar26[0x17];
          _DAT_2000710c = puVar26[0x18];
          _DAT_20007110 = puVar26[0x19];
          _DAT_20007114 = puVar26[0x1a];
          _DAT_20007118 = -(float)puVar26[0x1c];
          _DAT_2000711c = -(float)puVar26[0x1d];
          _DAT_200070b8 = (float)puVar26[0x1e];
        }
      }
      uVar42 = FUN_08020628((fVar41 + fVar41) / fVar36);
      uVar42 = FUN_08020368((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0xd2f1a9fc,0x3f60624d);
      FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0,0x408f1800);
      uVar35 = FUN_08020c38();
      if (0x3e2 < (int)uVar35) {
        uVar35 = 0x3e3;
      }
      uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
      puVar26 = *(undefined4 **)(uVar35 * 4 + 0x20002414);
      if (_DAT_20007240 == 0) {
        if (uVar35 != _DAT_2000723c) goto LAB_08026fa6;
      }
      else {
        _DAT_20007240 = 0;
        if (uVar35 != _DAT_2000723c) {
LAB_08026fa6:
          _DAT_2000723c = uVar35;
        }
        if (cVar31 != '\0') {
          FUN_08034a6c(0,0x200071ec,0x14);
        }
        if (puVar26 == (undefined4 *)0x0) {
          FUN_08034a6c(0,&DAT_20007188,0x19);
          _DAT_20007184 = 0.0;
        }
        else {
          _DAT_20007188 = *puVar26;
          _DAT_2000718c = puVar26[1];
          _DAT_20007190 = puVar26[2];
          _DAT_20007194 = -(float)puVar26[4];
          _DAT_20007198 = -(float)puVar26[5];
          _DAT_2000719c = puVar26[6];
          _DAT_200071a0 = puVar26[7];
          _DAT_200071a4 = puVar26[8];
          _DAT_200071a8 = -(float)puVar26[10];
          _DAT_200071ac = -(float)puVar26[0xb];
          _DAT_200071b0 = puVar26[0xc];
          _DAT_200071b4 = puVar26[0xd];
          _DAT_200071b8 = puVar26[0xe];
          _DAT_200071bc = -(float)puVar26[0x10];
          _DAT_200071c0 = -(float)puVar26[0x11];
          _DAT_200071c4 = puVar26[0x12];
          _DAT_200071c8 = puVar26[0x13];
          _DAT_200071cc = puVar26[0x14];
          _DAT_200071d0 = -(float)puVar26[0x16];
          _DAT_200071d4 = -(float)puVar26[0x17];
          _DAT_200071d8 = puVar26[0x18];
          _DAT_200071dc = puVar26[0x19];
          _DAT_200071e0 = puVar26[0x1a];
          _DAT_200071e4 = -(float)puVar26[0x1c];
          _DAT_200071e8 = -(float)puVar26[0x1d];
          _DAT_20007184 = (float)puVar26[0x1e];
        }
      }
    }
    uVar35 = _DAT_200085a8;
    if ((int)_DAT_200085a0 <= (int)_DAT_200085a8) {
      uVar35 = _DAT_200085a0;
    }
    uVar22 = _DAT_200085a4;
    if ((int)_DAT_200085a4 < (int)_DAT_2000859c) {
      uVar22 = _DAT_2000859c;
    }
    _DAT_20009020 = VectorSignedToFloat(uVar22,(byte)(uVar34 >> 0x16) & 3);
    _DAT_20009024 = VectorSignedToFloat(uVar35,(byte)(uVar34 >> 0x16) & 3);
    if (DAT_2000832c != '\0') {
      DAT_2000832c = '\0';
    }
  }
  if (_DAT_20009038 != DAT_20008fbd) {
    _DAT_20009038 = (uint)DAT_20008fbd;
  }
  if (DAT_20008328 != '\0') {
    DAT_20008328 = '\0';
    _DAT_20008378 = 0.0;
    _DAT_20008384 = 0xc0;
    FUN_08034a6c(0,0x20006df0,0x14);
    FUN_08034a6c(0,0x20006ebc,0x14);
    FUN_08034a6c(0,0x20007054,0x14);
    FUN_08034a6c(0,0x20006f88,0x14);
    FUN_08034a6c(0,0x200071ec,0x14);
    FUN_08034a6c(0,0x20007120,0x14);
    FUN_08034a6c(0,0x20006768,0x47);
    FUN_08034a6c(0,0x20006888,8);
    _DAT_20006884 = 0;
    FUN_08034a6c(0,0x200069b4,0x47);
    FUN_08034a6c(0,0x20006ad4,8);
    _DAT_20006ad0 = 0;
    FUN_08034a6c(0,0x20006460,0x27);
    FUN_08034a6c(0,0x20006500,4);
    _DAT_200064fc = 0;
    FUN_08034a6c(0,0x200065ac,0x27);
    FUN_08034a6c(0,0x2000664c,4);
    _DAT_20006648 = 0;
    _DAT_20006c24 = 0;
    FUN_08034a6c(0,0x20006c28,2);
    FUN_08034a6c(0,0x20006b90,0x25);
    FUN_08034a6c(0,0x20006d3c,8);
    FUN_08034a6c(0,0x20006d5c,8);
  }
  uVar35 = _DAT_2000ba38;
  if (_DAT_2000ba38 == 0) {
    if (DAT_200085af != '\0') goto LAB_08027cdc;
  }
  else {
    puVar24 = _DAT_200003cc + _DAT_2000ba38 * 2;
    pfVar28 = (float *)&DAT_20004990;
    puVar17 = _DAT_200003cc;
    do {
      fVar36 = (float)VectorSignedToFloat(*puVar17 >> 0x10 | *puVar17 << 0x10,
                                          (byte)(uVar34 >> 0x16) & 3);
      fVar38 = (float)VectorSignedToFloat(puVar17[1] >> 0x10 | puVar17[1] << 0x10,
                                          (byte)(uVar34 >> 0x16) & 3);
      puVar17 = puVar17 + 2;
      *pfVar28 = fVar36 * 4.656612e-10;
      pfVar28[0x80] = fVar38 * 4.656612e-10;
      pfVar28 = pfVar28 + 1;
    } while (puVar24 != puVar17);
    if (DAT_200085af != '\0') {
      fVar36 = _DAT_2000b778;
      if (DAT_2000b739 != '\0') {
        fVar36 = 0.0;
      }
      local_ac = 0;
      iVar12 = 0;
      pfVar28 = (float *)&DAT_20004990;
      do {
        iVar18 = _DAT_2000746c + 0xfb6;
        local_68 = (*pfVar28 + pfVar28[0x80]) * fVar36;
        _DAT_2000746c = _DAT_2000746c + 1 & 7;
        *(float *)(&DAT_20003598 + iVar18 * 4) = local_68;
        if (_DAT_2000746c == 0) {
          FUN_08035c88(0x20007244,0x20007470,&local_68,8);
          FUN_08036000(0x20007728,&local_68,auStack_64,1);
          FUN_08036000(0x200077f4,auStack_64,&local_68,1);
          local_68 = _DAT_20007734 * _DAT_20007800 * local_68;
          if (DAT_200085ad < 2) {
            uVar35 = _DAT_200078d4 + 0x32;
            local_54 = local_68 * 10.0;
            *(float *)(&DAT_200078d4 + (_DAT_200078d4 + 0xce) * 4) = local_54;
            _DAT_200078d4 = (_DAT_200078d4 + 1) % 100;
            local_50 = *(float *)(&DAT_200078d4 + (uVar35 % 100 + 0xce) * 4);
            FUN_080357c0(0x200078d8,&local_54,&local_4c,1);
            local_5c = local_50 * 8.0;
            local_60 = local_4c * 8.0;
          }
          else {
            switch(DAT_200085ad) {
            case 2:
            case 3:
              uVar35 = _DAT_200078d4 + 0x32;
              local_54 = local_68 * 10.0;
              *(float *)(&DAT_200078d4 + (_DAT_200078d4 + 0xce) * 4) = local_54;
              _DAT_200078d4 = (_DAT_200078d4 + 1) % 100;
              local_50 = *(float *)(&DAT_200078d4 + (uVar35 % 100 + 0xce) * 4);
              FUN_080357c0(0x200078d8,&local_54,&local_4c,1);
              local_60 = local_50 * 8.0;
              local_5c = local_4c * 8.0;
              break;
            case 4:
            case 5:
              if (DAT_200082f6 == '\0') {
                DAT_200082d0 = DAT_200082f6;
LAB_080287b2:
                local_5c = _DAT_200080e8;
                if (_DAT_200082cc != 0) {
                  _DAT_200082cc = _DAT_200082cc - 1;
LAB_08026788:
                  local_5c = *(float *)(&DAT_20003590 + (_DAT_200082cc + 0x12d6) * 4);
                }
              }
              else {
                local_5c = *(float *)(&DAT_20003590 + (_DAT_200082cc + 0x12d6) * 4);
                DAT_200082d0 = DAT_200082f5;
                uVar35 = uVar34 & 0xfffffff | (uint)(local_5c < 0.0) << 0x1f |
                         (uint)(local_5c == 0.0) << 0x1e;
                uVar34 = uVar35 | (uint)NAN(local_5c) << 0x1c;
                bVar8 = (byte)(uVar35 >> 0x18);
                if ((bool)(bVar8 >> 6 & 1) || bVar8 >> 7 != ((byte)(uVar34 >> 0x1c) & 1)) {
                  _DAT_40021014 = _DAT_40021014 | 0x1000;
                }
                else {
                  _DAT_40021014 = _DAT_40021014 & 0xffffefff;
                }
                if (DAT_200082f5 == '\0') goto LAB_080287b2;
                if (_DAT_200082cc < _DAT_200082c8 - 1U) {
                  _DAT_200082cc = _DAT_200082cc + 1;
                  goto LAB_08026788;
                }
              }
              local_5c = local_5c * 8.0;
              DAT_2000b78c = _DAT_200082c8 - 1U <= _DAT_200082cc;
              local_60 = local_5c;
              break;
            case 6:
              local_50 = _DAT_20007df8 + local_68 * _DAT_20007dfc;
              local_5c = local_50 * 8.0;
              local_60 = local_5c;
              local_4c = local_50;
              break;
            case 7:
              fVar41 = local_68 * _DAT_20007e08;
              uVar34 = uVar34 & 0xfffffff;
              fVar38 = -_DAT_20007e04;
              if ((-_DAT_20007e04 <= fVar41) &&
                 (uVar34 = uVar34 | (uint)(fVar41 == _DAT_20007e04) << 0x1e |
                           (uint)(_DAT_20007e04 <= fVar41) << 0x1d, bVar8 = (byte)(uVar34 >> 0x18),
                 fVar38 = _DAT_20007e04, !(bool)(bVar8 >> 5 & 1) || (bool)(bVar8 >> 6))) {
                fVar38 = fVar41;
              }
              uVar42 = FUN_08020628((_DAT_20007e00 + _DAT_20007e00) * fVar38);
              FUN_080206d8((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),0x54442d18,0x400921fb);
              uVar37 = FUN_08020cc8();
              local_50 = (float)FUN_080363f8(uVar37);
              local_4c = (float)FUN_08036370(uVar37);
              local_5c = local_4c * 8.0;
              local_60 = local_50 * 8.0;
              break;
            default:
              local_5c = 0.0;
              local_60 = 0.0;
            }
          }
          iVar18 = (iVar12 + 0x180) * 8;
          FUN_08035364(0x20007490,&local_60,&DAT_200075bc,1);
          *(float *)(&DAT_20003590 + iVar18) = _DAT_200075bc;
          iVar1 = (iVar12 + 0x181) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar1) = _DAT_200075c0;
          uVar37 = _DAT_200075c8;
          iVar2 = (iVar12 + 0x182) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar2) = _DAT_200075c4;
          uVar11 = _DAT_200075d8;
          uVar10 = _DAT_200075d4;
          uVar9 = _DAT_200075d0;
          uVar40 = _DAT_200075cc;
          iVar3 = (iVar12 + 0x183) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar3) = uVar37;
          iVar4 = (iVar12 + 0x184) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar4) = uVar40;
          iVar5 = (iVar12 + 0x185) * 8;
          iVar6 = (iVar12 + 0x186) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar5) = uVar9;
          iVar7 = (iVar12 + 0x187) * 8;
          *(undefined4 *)(&DAT_20003590 + iVar6) = uVar10;
          *(undefined4 *)(&DAT_20003590 + iVar7) = uVar11;
          FUN_08035364(0x200075dc,&local_5c,&DAT_20007708,1);
          *(undefined4 *)(&DAT_20003594 + iVar18) = _DAT_20007708;
          *(undefined4 *)(&DAT_20003594 + iVar1) = _DAT_2000770c;
          *(undefined4 *)(&DAT_20003594 + iVar2) = _DAT_20007710;
          *(undefined4 *)(&DAT_20003594 + iVar3) = _DAT_20007714;
          *(undefined4 *)(&DAT_20003594 + iVar4) = _DAT_20007718;
          uVar22 = (uint)DAT_200085ad;
          *(undefined4 *)(&DAT_20003594 + iVar5) = _DAT_2000771c;
          *(undefined4 *)(&DAT_20003594 + iVar6) = _DAT_20007720;
          fVar38 = _DAT_20007724;
          *(float *)(&DAT_20003594 + iVar7) = _DAT_20007724;
          uVar35 = _DAT_2000ba3c;
          if ((1 < uVar22 - 4) && (DAT_20004da8 == '\0')) {
            fVar41 = *(float *)(&DAT_20003594 + iVar18);
            iVar1 = (_DAT_20004dac + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar1) = *(float *)(&DAT_20003590 + iVar18) * 0.01;
            *(float *)(&DAT_20003594 + iVar1) = fVar41 * 0.01;
            iVar18 = (_DAT_20004dac + 1U) - uVar35 * ((_DAT_20004dac + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x181) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x182) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x183) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x184) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x185) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar12 + 0x186) * 8;
            fVar41 = *(float *)(&DAT_20003594 + iVar1);
            iVar2 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar2) = *(float *)(&DAT_20003590 + iVar1) * 0.01;
            *(float *)(&DAT_20003594 + iVar2) = fVar41 * 0.01;
            iVar18 = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (iVar18 == 0) {
              DAT_20004da8 = '\x01';
            }
            iVar1 = (iVar18 + 0x304) * 8;
            *(float *)(&DAT_20003590 + iVar1) =
                 *(float *)(&DAT_20003590 + (iVar12 + 0x187) * 8) * 0.01;
            *(float *)(&DAT_20003594 + iVar1) = fVar38 * 0.01;
            _DAT_20004dac = (iVar18 + 1U) - uVar35 * ((iVar18 + 1U) / uVar35);
            if (_DAT_20004dac == 0) {
              DAT_20004da8 = '\x01';
            }
          }
          iVar12 = iVar12 + 8;
          uVar35 = _DAT_2000ba38;
        }
        local_ac = local_ac + 1;
        pfVar28 = pfVar28 + 1;
      } while (local_ac < uVar35);
LAB_08027cdc:
      local_74 = &local_54;
      fVar36 = (float)VectorSignedToFloat(4000 - (uint)_DAT_2000c6b8,(byte)(uVar34 >> 0x16) & 3);
      fVar38 = (float)VectorUnsignedToFloat((uint)_DAT_2000c6b4,(byte)(uVar34 >> 0x16) & 3);
      fVar41 = (float)VectorUnsignedToFloat((uint)_DAT_2000c6b6,(byte)(uVar34 >> 0x16) & 3);
      _DAT_2000b73c = fVar38 * 0.012165527;
      uVar34 = uVar34 & 0xfffffff;
      if (fVar36 * 0.005 < 0.0) {
        fVar36 = 1.0;
      }
      else {
        uVar35 = uVar34 | (uint)(fVar36 < 3800.0) << 0x1f | (uint)(fVar36 == 3800.0) << 0x1e;
        uVar34 = uVar35 | (uint)NAN(fVar36) << 0x1c;
        bVar8 = (byte)(uVar35 >> 0x18);
        if ((bool)(bVar8 >> 6 & 1) || bVar8 >> 7 != ((byte)(uVar34 >> 0x1c) & 1)) {
          fVar36 = fVar36 * 0.005 + 1.0;
        }
        else {
          fVar36 = 20.0;
        }
      }
      _DAT_2000b740 = fVar41 * 0.012165527;
      _DAT_2000b744 = fVar36;
      _DAT_2000ba30 = fVar38;
      _DAT_2000ba34 = fVar41;
      uVar42 = FUN_08020628(_DAT_2000b73c);
      uVar37 = (undefined4)((ulonglong)uVar42 >> 0x20);
      uVar43 = FUN_080206d8((int)uVar42,uVar37,0x96bb98d,0x3f87a0f9);
      uVar43 = FUN_0802036c((int)uVar43,(int)((ulonglong)uVar43 >> 0x20),0xeb851eb8,0x3faeb851);
      FUN_080206d8((int)uVar43,(int)((ulonglong)uVar43 >> 0x20),(int)uVar42,uVar37);
      fVar15 = (float)FUN_08020cc8();
      _DAT_2000b74c = fVar15;
      uVar42 = FUN_08020628(fVar41 * 0.012165527);
      uVar37 = (undefined4)((ulonglong)uVar42 >> 0x20);
      uVar43 = FUN_080206d8((int)uVar42,uVar37,0x96bb98d,0x3f87a0f9);
      uVar43 = FUN_0802036c((int)uVar43,(int)((ulonglong)uVar43 >> 0x20),0xeb851eb8,0x3faeb851);
      FUN_080206d8((int)uVar43,(int)((ulonglong)uVar43 >> 0x20),(int)uVar42,uVar37);
      _DAT_2000b770 = (float)FUN_08020cc8();
      uVar34 = uVar34 & 0xfffffff;
      uVar22 = uVar34 | (uint)(fVar15 < _DAT_2000b748) << 0x1f |
               (uint)(fVar15 == _DAT_2000b748) << 0x1e;
      uVar35 = uVar22 | (uint)(NAN(fVar15) || NAN(_DAT_2000b748)) << 0x1c;
      bVar8 = (byte)(uVar22 >> 0x18);
      bVar30 = -((char)bVar8 >> 7);
      fVar14 = fVar15;
      if (((bool)(bVar8 >> 6 & 1) || bVar30 != ((byte)(uVar35 >> 0x1c) & 1)) &&
         (fVar14 = _DAT_2000b748, bVar30 != 0)) {
        fVar14 = _DAT_2000b748 + (fVar15 - _DAT_2000b748) * _DAT_2000b754;
      }
      _DAT_2000b748 = fVar14;
      if (_DAT_2000b780 < 1) {
        _DAT_2000b758 = fVar38 + _DAT_2000b758;
        _DAT_2000b75c = fVar41 + _DAT_2000b75c;
        _DAT_2000b9d4 = (_DAT_2000b9d4 + 1) % 10;
        if (_DAT_2000b9d4 == 0) {
          uVar35 = uVar34 | (uint)(_DAT_2000b758 < 10.0) << 0x1f;
          uVar22 = uVar35 | (uint)NAN(_DAT_2000b758) << 0x1c;
          if (((((byte)(uVar35 >> 0x1f) != ((byte)(uVar22 >> 0x1c) & 1)) ||
               (uVar35 = uVar34 | (uint)(_DAT_2000b75c < 10.0) << 0x1f,
               uVar22 = uVar35 | (uint)NAN(_DAT_2000b75c) << 0x1c,
               (byte)(uVar35 >> 0x1f) != ((byte)(uVar22 >> 0x1c) & 1))) ||
              (uVar35 = uVar34 | (uint)(_DAT_2000b758 < _DAT_2000b75c) << 0x1f |
                        (uint)(_DAT_2000b758 == _DAT_2000b75c) << 0x1e,
              uVar22 = uVar35 | (uint)(NAN(_DAT_2000b758) || NAN(_DAT_2000b75c)) << 0x1c,
              bVar8 = (byte)(uVar35 >> 0x18),
              (bool)(bVar8 >> 6 & 1) || bVar8 >> 7 != ((byte)(uVar22 >> 0x1c) & 1))) ||
             (_DAT_2000b764 = (_DAT_2000b758 + _DAT_2000b75c) / (_DAT_2000b758 - _DAT_2000b75c),
             uVar22 = uVar34, _DAT_2000b764 < 1.0)) {
            _DAT_2000b764 = 1.0;
            _DAT_2000b76c = 0.0;
          }
          else {
            uVar34 = uVar34 | (uint)(_DAT_2000b764 < 65535.0) << 0x1f |
                     (uint)(_DAT_2000b764 == 65535.0) << 0x1e;
            uVar22 = uVar34 | (uint)NAN(_DAT_2000b764) << 0x1c;
            bVar8 = (byte)(uVar34 >> 0x18);
            if ((bool)(bVar8 >> 6 & 1) || bVar8 >> 7 != ((byte)(uVar22 >> 0x1c) & 1)) {
              _DAT_2000b76c = _DAT_2000b764 - 1.0;
            }
            else {
              _DAT_2000b764 = 65535.0;
              _DAT_2000b76c = 65534.0;
            }
          }
          _DAT_2000b758 = _DAT_2000b758 * 0.1;
          _DAT_2000b75c = _DAT_2000b75c * 0.1;
          uVar34 = uVar22 & 0xfffffff | (uint)(fVar15 + _DAT_2000b770 < 0.075) << 0x1f;
          uVar35 = uVar34 | (uint)NAN(fVar15 + _DAT_2000b770) << 0x1c;
          if ((byte)(uVar34 >> 0x1f) == ((byte)(uVar35 >> 0x1c) & 1)) {
            _DAT_2000b768 = _DAT_2000b764;
            if ((_DAT_2000b77c < 3) && (_DAT_2000b77c = _DAT_2000b77c + 1, _DAT_2000b77c != 3))
            goto LAB_08028872;
          }
          else {
            _DAT_2000b77c = 0;
LAB_08028872:
            _DAT_2000b768 = 1.0;
          }
          DAT_2000b73a = 1;
          _DAT_2000b760 = _DAT_2000b764;
        }
        else {
          _DAT_2000b76c = _DAT_2000b760 - 1.0;
        }
        uVar35 = uVar35 & 0xfffffff;
        if (_DAT_2000b760 < 1.0) goto LAB_08027e50;
        uVar34 = uVar35 | (uint)(_DAT_2000b760 < 4.16) << 0x1f |
                 (uint)(_DAT_2000b760 == 4.16) << 0x1e;
        uVar35 = uVar34 | (uint)NAN(_DAT_2000b760) << 0x1c;
        bVar8 = (byte)(uVar34 >> 0x18);
        if ((bool)(bVar8 >> 6 & 1) || bVar8 >> 7 != ((byte)(uVar35 >> 0x1c) & 1)) {
          _DAT_2000b774 = _DAT_2000b76c * _DAT_2000b76c;
          fVar15 = fVar15 + _DAT_2000b770 * _DAT_2000b774;
        }
        else {
          _DAT_2000b774 = 9.9856;
          fVar15 = fVar15 + _DAT_2000b770 * 9.9856;
          _DAT_2000b76c = 3.16;
        }
      }
      else {
        _DAT_2000b780 = _DAT_2000b780 + -1;
        _DAT_2000b760 = 1.0;
        _DAT_2000b764 = 1.0;
        _DAT_2000b768 = 1.0;
        _DAT_2000b758 = 0.0;
        _DAT_2000b75c = 0.0;
        _DAT_2000b9d4 = 0;
        _DAT_2000b77c = 0;
        DAT_2000b73b = 0;
LAB_08027e50:
        _DAT_2000b774 = 0.0;
        _DAT_2000b76c = 0.0;
      }
      local_54 = 0.0;
      _DAT_2000b790 = fVar15;
      _DAT_2000b7b4 = fVar36;
      FUN_080361a0(&DAT_20004190,_DAT_2000b7d0,0x80);
      FUN_08034b08(_DAT_2000b7d0,0x80,local_74,auStack_58);
      uVar35 = uVar35 & 0xfffffff;
      bVar30 = (byte)(uVar35 >> 0x18);
      bVar8 = (byte)(((uint)(_DAT_2000b7cc == local_54) << 0x1e) >> 0x18);
      if ((char)(bVar30 | (byte)(((uint)(_DAT_2000b7cc < local_54) << 0x1f) >> 0x18) | bVar8) < '\0'
         ) {
        _DAT_2000b7cc = _DAT_2000b7cc * 0.00999999 + local_54 * 0.99;
      }
      else if (!(bool)(bVar8 >> 6) && (!NAN(_DAT_2000b7cc) && !NAN(local_54))) {
        _DAT_2000b7cc = _DAT_2000b7cc * 0.995 + local_54 * 0.005;
      }
      bVar8 = (byte)(((uint)(_DAT_2000b790 == _DAT_2000b794) << 0x1e) >> 0x18);
      cVar31 = -((char)(bVar30 | (byte)(((uint)(_DAT_2000b790 < _DAT_2000b794) << 0x1f) >> 0x18) |
                       bVar8) >> 7);
      if ((bool)(bVar8 >> 6) || (bool)cVar31 != (NAN(_DAT_2000b790) || NAN(_DAT_2000b794))) {
        if (cVar31 != '\0') {
          _DAT_2000b794 = (1.0 - _DAT_2000b798) * _DAT_2000b794 + _DAT_2000b790 * _DAT_2000b798;
        }
      }
      else {
        _DAT_2000b794 = _DAT_2000b794 * 0.00999999 + _DAT_2000b790 * 0.99;
      }
      uVar22 = uVar35 | (uint)(_DAT_2000b794 < 0.0) << 0x1f;
      uVar34 = uVar22 | (uint)NAN(_DAT_2000b794) << 0x1c;
      if (((byte)(uVar22 >> 0x1f) == ((byte)(uVar34 >> 0x1c) & 1)) && (DAT_2000b78c != '\0')) {
        fVar36 = (float)VectorUnsignedToFloat
                                  (_DAT_2000b7b4 * _DAT_2000b7c8 * 1000.0 * _DAT_2000b794 + 0.001,
                                   (byte)(uVar34 >> 0x16) & 3);
        _DAT_2000b7bc = _DAT_2000b79c + -(fVar36 * 1.1920929e-07 + -126.942696) * 3.0103002;
        bVar8 = (byte)(((uint)(_DAT_2000b7bc == 0.0) << 0x1e) >> 0x18);
        cVar31 = -((char)(bVar30 | (byte)(((uint)(_DAT_2000b7bc < 0.0) << 0x1f) >> 0x18) | bVar8) >>
                  7);
        if ((bool)(bVar8 >> 6) || (bool)cVar31 != NAN(_DAT_2000b7bc)) {
          if (cVar31 != '\0') {
            _DAT_2000b7a8 = _DAT_2000b7a8 + _DAT_2000b7bc * _DAT_2000b7ac;
          }
        }
        else {
          _DAT_2000b7a8 = _DAT_2000b7a8 + _DAT_2000b7bc * _DAT_2000b7b0;
        }
        if (-40.0 <= _DAT_2000b7a8) {
          uVar34 = uVar35 | (uint)(_DAT_2000b7a8 < 0.0) << 0x1f |
                   (uint)(_DAT_2000b7a8 == 0.0) << 0x1e;
          uVar35 = uVar34 | (uint)NAN(_DAT_2000b7a8) << 0x1c;
          bVar8 = (byte)(uVar34 >> 0x18);
          if (!(bool)(bVar8 >> 6 & 1) && bVar8 >> 7 == ((byte)(uVar35 >> 0x1c) & 1)) {
            _DAT_2000b7a8 = 0.0;
          }
        }
        else {
          _DAT_2000b7a8 = -40.0;
        }
        bVar33 = true;
        uVar34 = uVar35;
      }
      else {
        _DAT_2000b7bc = 0.0;
        _DAT_2000b7c0 = 0;
        bVar33 = false;
      }
      fVar36 = _DAT_2000b7a8 + _DAT_2000b7c4;
      _DAT_2000b7a0 = -40.0;
      uVar34 = uVar34 & 0xfffffff;
      if (fVar36 < -40.0) {
        _DAT_2000b7b8 = 1.0686948;
        fVar38 = 0.010375679;
      }
      else {
        uVar35 = uVar34 | (uint)(fVar36 < 0.0) << 0x1f | (uint)(fVar36 == 0.0) << 0x1e;
        bVar8 = (byte)(uVar35 >> 0x18);
        if ((bool)(bVar8 >> 6 & 1) || (bool)(bVar8 >> 7) != NAN(fVar36)) {
          fVar38 = fVar36 * 0.16536522;
          uVar34 = uVar34 | (uint)(fVar38 < -126.0) << 0x1f;
          if (SUB41(uVar34 >> 0x1f,0) != NAN(fVar38)) {
            fVar38 = -126.0;
          }
          fVar38 = (float)VectorFloatToUnsigned((fVar38 + 126.942696) * 8388608.0,3);
          _DAT_2000b7b8 = fVar38 * 103.0;
          _DAT_2000b7a0 = fVar36;
        }
        else {
          _DAT_2000b7b8 = 100.04883;
          fVar38 = 0.9713478;
          uVar34 = uVar35;
          _DAT_2000b7a0 = 0.0;
        }
      }
      if (bVar33) {
        if ((_DAT_2000b7cc * fVar38 <= 0.0) || (_DAT_2000b790 <= 0.0)) {
          _DAT_2000b7a4 = 0.0;
        }
        else {
          fVar36 = _DAT_2000b790 * 50.0;
          uVar34 = uVar34 & 0xfffffff | (uint)(fVar36 < 0.0) << 0x1f;
          if (SUB41(uVar34 >> 0x1f,0) == NAN(fVar36)) {
            fVar36 = SQRT(fVar36);
          }
          else {
            fVar36 = 0.0;
          }
          fVar36 = (float)VectorUnsignedToFloat
                                    (fVar36 / (_DAT_2000b7cc * fVar38),(byte)(uVar34 >> 0x16) & 3);
          _DAT_2000b7a4 = (fVar36 * 1.1920929e-07 + -126.942696) * 6.0206003;
        }
      }
      else {
        _DAT_2000b7a4 = 0.0;
      }
      puVar20 = &DAT_20004194;
      puVar25 = &DAT_20004190;
      do {
        puVar23 = puVar25 + 8;
        *(float *)(puVar20 + -4) = *(float *)(puVar20 + -4) * fVar38;
        puVar20 = puVar20 + 8;
        *(float *)(puVar25 + 4) = *(float *)(puVar25 + 4) * fVar38;
        uVar34 = _DAT_2000ba38;
        puVar25 = puVar23;
      } while (puVar23 != (undefined1 *)0x20004590);
      goto LAB_08026450;
    }
  }
  if (_DAT_20008384 == 0) {
    uVar22 = uVar34 & 0xfffffff | (uint)(_DAT_20008380 < 0.0) << 0x1f |
             (uint)(_DAT_20008380 == 0.0) << 0x1e;
    uVar34 = uVar22 | (uint)NAN(_DAT_20008380) << 0x1c;
    bVar30 = (byte)(uVar22 >> 0x18);
    if (!(bool)(bVar30 >> 6 & 1) && bVar30 >> 7 == ((byte)(uVar34 >> 0x1c) & 1)) {
      _DAT_20008380 = _DAT_20008380 * 0.95;
    }
    _DAT_20008378 = 1.0 - _DAT_20008380;
  }
  else {
    _DAT_20008384 = _DAT_20008384 + -1;
    _DAT_20008380 = 1.0;
    _DAT_20008378 = 0.0;
  }
  if ((DAT_2000bf71 == '\0') && (_DAT_2000bf78 != _DAT_2000bf74)) {
    fVar36 = (float)VectorSignedToFloat(_DAT_2000bf74,(byte)(uVar34 >> 0x16) & 3);
    uVar34 = uVar34 & 0xfffffff;
    _DAT_2000bf78 = _DAT_2000bf74;
    _DAT_2000bf84 = -1.0;
    if (0.0 <= fVar36) {
      _DAT_2000bf84 = 1.0;
    }
    _DAT_2000bf7c =
         (float)VectorSignedToFloat((_DAT_2000bf74 ^ (int)_DAT_2000bf74 >> 0x1f) -
                                    ((int)_DAT_2000bf74 >> 0x1f),(byte)(uVar34 >> 0x16) & 3);
    _DAT_2000bf7c = _DAT_2000bf7c * 6.283185e-05;
  }
  if (uVar35 == 0) {
    if ((((bVar8 != 0) && (bVar8 != 1)) && (bVar8 != 2)) && ((bVar8 != 3 && (bVar8 != 4))))
    goto LAB_08024d1a;
  }
  else {
    iVar12 = 0;
    local_ac = 0;
    do {
      fVar36 = _DAT_200078d0;
      iVar18 = _DAT_200003d4 + iVar12;
      *(uint *)(&DAT_20003590 + local_ac * 8) =
           *(uint *)(_DAT_200003d4 + iVar12) >> 0x10 | *(uint *)(_DAT_200003d4 + iVar12) << 0x10;
      uVar35 = *(uint *)(iVar18 + 4);
      *(uint *)(&DAT_20003590 + (local_ac * 2 + 1) * 4) = uVar35 >> 0x10 | uVar35 << 0x10;
      fVar38 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_20003590 + iVar12),
                                          (byte)(uVar34 >> 0x16) & 3);
      fVar36 = _DAT_200078cc * fVar36 * 4.656612e-10;
      fVar41 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_20003594 + iVar12),
                                          (byte)(uVar34 >> 0x16) & 3);
      fVar38 = fVar38 * fVar36;
      fVar41 = fVar41 * fVar36;
      pfVar27 = (float *)(&DAT_20003990 + iVar12);
      uVar34 = uVar34 & 0xfffffff | (uint)(fVar38 < 0.0) << 0x1f;
      uVar35 = uVar34 | (uint)NAN(fVar38) << 0x1c;
      pfVar28 = (float *)(&DAT_20003994 + iVar12);
      *pfVar27 = fVar38;
      *pfVar28 = fVar41;
      fVar36 = _DAT_2000b6f8;
      if ((byte)(uVar34 >> 0x1f) == ((byte)(uVar35 >> 0x1c) & 1)) {
        uVar42 = FUN_08020628(fVar41);
        uVar34 = uVar35 & 0xfffffff | (uint)(fVar38 < 0.0) << 0x1f | (uint)(fVar38 == 0.0) << 0x1e;
        uVar35 = uVar34 | (uint)NAN(fVar38) << 0x1c;
        bVar30 = (byte)(uVar34 >> 0x18);
        if ((bool)(bVar30 >> 6 & 1) || bVar30 >> 7 != ((byte)(uVar35 >> 0x1c) & 1)) {
          local_a8 = DAT_0803cef0;
        }
        else {
          local_a8 = FUN_08020628(fVar38);
          fVar36 = fVar36 + fVar41;
        }
      }
      else {
        uVar42 = FUN_08020628(fVar41);
        uVar43 = FUN_08020628(fVar38);
        fVar36 = fVar36 - fVar41;
        local_a8 = CONCAT44((int)((ulonglong)uVar43 >> 0x20) + -0x80000000,(int)uVar43);
      }
      uStack_94 = (undefined4)((ulonglong)uVar42 >> 0x20);
      local_98 = (undefined4)uVar42;
      _DAT_2000b6f8 = fVar36;
      uVar42 = FUN_08020628(_DAT_2000b6fc);
      FUN_0802036c((int)uVar42,(int)((ulonglong)uVar42 >> 0x20),(undefined4)local_a8,local_a8._4_4_)
      ;
      fVar15 = (float)FUN_08020cc8();
      fVar14 = _DAT_2000b700;
      _DAT_2000b6fc = fVar15;
      uVar42 = FUN_08020628(_DAT_2000b700);
      uVar37 = (undefined4)((ulonglong)uVar42 >> 0x20);
      uVar35 = uVar35 & 0xfffffff | (uint)(fVar41 < 0.0) << 0x1f | (uint)(fVar41 == 0.0) << 0x1e;
      uVar34 = uVar35 | (uint)NAN(fVar41) << 0x1c;
      bVar30 = (byte)(uVar35 >> 0x18);
      bVar29 = bVar30 >> 7;
      bVar32 = (byte)(uVar34 >> 0x1c) & 1;
      if (bVar29 == bVar32) {
        if (!(bool)(bVar30 >> 6 & 1) && bVar29 == bVar32) {
          FUN_0802036c((int)uVar42,uVar37,local_98,uStack_94);
          fVar14 = (float)FUN_08020cc8();
        }
      }
      else {
        FUN_08020368((int)uVar42,uVar37,local_98,uStack_94);
        fVar14 = (float)FUN_08020cc8();
      }
      _DAT_2000b6ec = (_DAT_2000b6ec + 1U) - _DAT_2000b6f0 * ((_DAT_2000b6ec + 1U) / _DAT_2000b6f0);
      if (_DAT_2000b6ec == 0) {
        fVar39 = (float)VectorUnsignedToFloat(_DAT_2000b6f0,(byte)(uVar34 >> 0x16) & 3);
        fVar39 = -0.003 / fVar39;
        _DAT_2000b708 = _DAT_2000b708 * 0.997 + -fVar39 * fVar15;
        uVar35 = uVar34 & 0xfffffff;
        uVar34 = uVar35 | (uint)(_DAT_2000b708 == 0.0) << 0x1e;
        _DAT_2000b70c = _DAT_2000b70c * 0.997 + -fVar39 * fVar14;
        _DAT_2000b704 = _DAT_2000b704 * 0.997 + fVar39 * fVar36;
        if ((byte)(uVar34 >> 0x1e) == 0) {
          _DAT_2000b710 = _DAT_2000b704 / _DAT_2000b708;
          _DAT_2000b714 = _DAT_2000b708 * _DAT_2000b708;
          fVar41 = fVar41 + fVar38 * _DAT_2000b710;
          uVar22 = uVar35 | (uint)(_DAT_2000b714 < 0.0) << 0x1f |
                   (uint)(_DAT_2000b714 == 0.0) << 0x1e;
          uVar34 = uVar22 | (uint)NAN(_DAT_2000b714) << 0x1c;
          bVar30 = (byte)(uVar22 >> 0x18);
          if ((bool)(bVar30 >> 6 & 1) || bVar30 >> 7 != ((byte)(uVar34 >> 0x1c) & 1))
          goto LAB_08024bd0;
          _DAT_2000b714 =
               (-(_DAT_2000b704 * _DAT_2000b704) + _DAT_2000b70c * _DAT_2000b70c) / _DAT_2000b714;
          uVar35 = uVar35 | (uint)(_DAT_2000b714 < 0.0) << 0x1f |
                   (uint)(_DAT_2000b714 == 0.0) << 0x1e;
          uVar34 = uVar35 | (uint)NAN(_DAT_2000b714) << 0x1c;
          bVar30 = (byte)(uVar35 >> 0x18);
          if ((bool)(bVar30 >> 6 & 1) || bVar30 >> 7 != ((byte)(uVar34 >> 0x1c) & 1))
          goto LAB_08024bd0;
          _DAT_2000b714 = SQRT(_DAT_2000b714);
          fVar38 = fVar38 * _DAT_2000b714;
        }
        else {
          _DAT_2000b710 = 0.0;
LAB_08024bd0:
          _DAT_2000b714 = 1.0;
        }
        _DAT_2000b6f8 = 0.0;
        _DAT_2000b6fc = 0.0;
        _DAT_2000b700 = 0.0;
      }
      else {
        fVar41 = fVar41 + fVar38 * _DAT_2000b710;
        fVar38 = fVar38 * _DAT_2000b714;
        _DAT_2000b700 = fVar14;
      }
      *pfVar28 = fVar41;
      *pfVar27 = fVar38;
      if (DAT_20004da8 == '\0') {
        uVar35 = (uint)DAT_2000bf6e;
        if (DAT_2000bf6f == uVar35) {
          uVar19 = (uint)DAT_2000bf70;
          uVar22 = uVar19 + 1 & 0xff;
        }
        else {
          DAT_2000bf6f = DAT_2000bf6e;
          if (uVar35 == 2) {
            FUN_08034aa8(&DAT_0803d698,0x2000baf4,0x20);
            puVar13 = &DAT_0803d698;
          }
          else if (uVar35 == 4) {
            FUN_08034aa8(&DAT_0803d618,0x2000baf4,0x20);
            puVar13 = &DAT_0803d618;
          }
          else {
            FUN_08034aa8(&DAT_0803d598,0x2000baf4,0x20);
            puVar13 = &DAT_0803d598;
          }
          FUN_08034aa8(puVar13,0x2000bbf4,0x20);
          FUN_08034a6c(0,0x2000bcf4,0x4f);
          FUN_08034a6c(0,0x2000be30,0x4f);
          FUN_08034a6c(0,&DAT_2000ba74,0x10);
          FUN_08034a6c(0,&DAT_2000bab4,0x10);
          uVar35 = (uint)DAT_2000bf6e;
          DAT_2000ba5c = DAT_2000bf6e;
          DAT_2000ba68 = DAT_2000bf6e;
          uVar19 = 0;
          fVar38 = *pfVar27;
          _DAT_20004dac = 0;
          uVar22 = 1;
        }
        *(float *)(&DAT_20003594 + (uVar19 + 0x2138) * 4) = fVar38;
        *(float *)(&DAT_20003594 + (uVar19 + 0x2148) * 4) = *pfVar28;
        uVar37 = _DAT_2000bab4;
        uVar22 = uVar22 - uVar35 * (uVar22 / uVar35);
        DAT_2000bf70 = (byte)uVar22;
        if ((uVar22 & 0xff) == 0) {
          if (uVar35 < 2) {
            iVar18 = (_DAT_20004dac + 0x304) * 8;
            *(undefined4 *)(&DAT_20003590 + iVar18) = _DAT_2000ba74;
            *(undefined4 *)(&DAT_20003594 + iVar18) = uVar37;
          }
          else {
            FUN_08035c88(&DAT_2000ba5c,&DAT_2000ba74,&DAT_20003590 + (_DAT_20004dac + 0x304) * 8);
            FUN_08035c88(&DAT_2000ba68,&DAT_2000bab4,_DAT_20004dac * 8 + 0x20004db4,DAT_2000bf6e);
          }
          _DAT_20004dac =
               (_DAT_20004dac + 1U) - _DAT_2000ba3c * ((_DAT_20004dac + 1U) / _DAT_2000ba3c);
          if (_DAT_20004dac == 0) {
            DAT_20004da8 = '\x01';
          }
        }
      }
      if (DAT_2000bf71 == '\0') {
        fVar36 = (float)FUN_080363f8(_DAT_2000bf80);
        fVar38 = (float)FUN_08036370(_DAT_2000bf80);
        fVar41 = *pfVar27;
        fVar38 = fVar38 * _DAT_2000bf84;
        *pfVar27 = -(*pfVar28 * fVar38) + fVar36 * fVar41;
        *pfVar28 = fVar38 * fVar41 + fVar36 * *pfVar28;
        _DAT_2000bf80 = _DAT_2000bf80 + _DAT_2000bf7c;
        uVar35 = uVar34 & 0xfffffff | (uint)(_DAT_2000bf80 < 6.2831855) << 0x1f |
                 (uint)(_DAT_2000bf80 == 6.2831855) << 0x1e;
        uVar34 = uVar35 | (uint)NAN(_DAT_2000bf80) << 0x1c;
        bVar30 = (byte)(uVar35 >> 0x18);
        if (!(bool)(bVar30 >> 6 & 1) && bVar30 >> 7 == ((byte)(uVar34 >> 0x1c) & 1)) {
          _DAT_2000bf80 = _DAT_2000bf80 - 6.2831855;
        }
      }
      local_ac = local_ac + 1;
      iVar12 = iVar12 + 8;
    } while (local_ac < _DAT_2000ba38);
    uVar35 = _DAT_2000ba38;
    if (((bVar8 == 0) || (bVar8 == 1)) || ((bVar8 == 2 || ((bVar8 == 3 || (bVar8 == 4)))))) {
LAB_080250d6:
      if (uVar35 == 0) goto LAB_08028866;
      pfVar28 = (float *)&DAT_20003990;
      uVar34 = 0;
      local_ac = 0;
      do {
        fVar36 = _DAT_20008378;
        *(float *)(&DAT_20003598 + (_DAT_20006884 + 0xcbc) * 4) = *pfVar28 * _DAT_20008378;
        iVar12 = _DAT_20006884 + 0xd4e;
        _DAT_20006884 = _DAT_20006884 + 1 & 7;
        *(float *)(&DAT_2000359c + iVar12 * 4) = pfVar28[1] * fVar36;
        if (_DAT_20006884 == 0) {
          FUN_08035c88(0x2000665c,0x20006888,&DAT_20005db0,8);
          FUN_08035c88(0x200068a8,0x20006ad4,&DAT_20005db4,8);
          fVar36 = _DAT_20005db0;
          if ((DAT_2000bf71 == '\0') && ((bVar8 == 4 || (bVar8 == 5)))) {
            _DAT_20005db0 = (float)FUN_08036370(_DAT_2000358c * 6.2831855);
            fVar38 = _DAT_20005db4;
            _DAT_20005db0 = fVar36 * _DAT_20005db0;
            _DAT_20005db4 = (float)FUN_080363f8(_DAT_2000358c * 6.2831855);
            _DAT_20005db4 = fVar38 * _DAT_20005db4;
            _DAT_2000358c = _DAT_2000358c + _DAT_200082e8 * 8e-05;
            if (1.0 <= _DAT_2000358c) {
              do {
                bVar33 = 2.0 <= _DAT_2000358c;
                _DAT_2000358c = _DAT_2000358c - 1.0;
              } while (bVar33);
            }
            FUN_08036000(0x20006d7c,&DAT_20005db0,&DAT_20005db8,1);
            FUN_08036000(0x20006e48,&DAT_20005db4,&DAT_20005dbc,1);
            fVar38 = _DAT_20005db8 * _DAT_20006d88;
            fVar36 = _DAT_20005dbc * _DAT_20006e54;
            _DAT_20005db8 = fVar38;
            _DAT_20005dbc = fVar36;
            if (bVar8 == 4) {
LAB_08025280:
              fVar38 = fVar38 - fVar36;
              goto LAB_08025262;
            }
            *(float *)(&DAT_20003594 + (local_ac + 0xa0c) * 4) = fVar38 + fVar36;
          }
          else {
            FUN_08036000(0x20006d7c,&DAT_20005db0,&DAT_20005db8,1);
            FUN_08036000(0x20006e48,&DAT_20005db4,&DAT_20005dbc,1);
            _DAT_20005db8 = _DAT_20005db8 * _DAT_20006d88;
            *(float *)(&DAT_200078d4 + (_DAT_200078d4 + 0xce) * 4) = _DAT_20005db8;
            local_50 = *(float *)(&DAT_200078d4 + ((_DAT_200078d4 + 0x32) % 100 + 0xce) * 4);
            _DAT_20005dbc = _DAT_20005dbc * _DAT_20006e54;
            _DAT_200078d4 = (_DAT_200078d4 + 1) % 100;
            FUN_080357c0(0x200078d8,&DAT_20005dbc,&local_4c,1);
            if ((1 < bVar8) && (fVar36 = local_4c, fVar38 = local_50, bVar8 != 5))
            goto LAB_08025280;
            fVar38 = local_50 + local_4c;
LAB_08025262:
            *(float *)(&DAT_20003594 + (local_ac + 0xa0c) * 4) = fVar38;
          }
          local_ac = local_ac + 1;
          uVar35 = _DAT_2000ba38;
        }
        uVar34 = uVar34 + 1;
        pfVar28 = pfVar28 + 2;
      } while (uVar34 < uVar35);
    }
    else {
LAB_08024d1a:
      if (bVar8 == 5) goto LAB_080250d6;
      if ((bVar8 == 6) || (bVar8 == 7)) {
        if (uVar35 == 0) goto LAB_08028866;
        pfVar28 = (float *)&DAT_20003990;
        uVar34 = 0;
        local_ac = 0;
        do {
          fVar36 = _DAT_20008378;
          *(float *)(&DAT_20003598 + (_DAT_200064fc + 0xbda) * 4) = *pfVar28 * _DAT_20008378;
          iVar12 = _DAT_200064fc + 0xc2c;
          _DAT_200064fc = _DAT_200064fc + 1 & 3;
          *(float *)(&DAT_2000359c + iVar12 * 4) = pfVar28[1] * fVar36;
          if (_DAT_200064fc == 0) {
            FUN_08035c88(0x200063c4,0x20006500,&DAT_20005db0,4);
            FUN_08035c88(0x20006510,0x2000664c,&DAT_20005db4,4);
            FUN_08036000(0x20006d7c,&DAT_20005db0,&DAT_20005db8,1);
            FUN_08036000(0x20006e48,&DAT_20005db4,&DAT_20005dbc,1);
            _DAT_20005db8 = _DAT_20005db8 * _DAT_20006d88;
            _DAT_20005dbc = _DAT_20005dbc * _DAT_20006e54;
            if (bVar8 == 6) {
              _DAT_20005dc0 = SQRT(_DAT_20005dbc * _DAT_20005dbc + _DAT_20005db8 * _DAT_20005db8);
            }
            else {
              FUN_080210c4(0x20007d9c,&DAT_20005db8,&DAT_20005dc0,1);
            }
            iVar12 = _DAT_20006c24 + 0xda4;
            _DAT_20006c24 = _DAT_20006c24 + 1 & 1;
            *(float *)(&DAT_20003598 + iVar12 * 4) = _DAT_20005dc0;
            uVar35 = _DAT_2000ba38;
            if (_DAT_20006c24 == 0) {
              iVar12 = local_ac + 0xa0d;
              local_ac = local_ac + 1;
              FUN_08035c88(0x20006af4,0x20006c28,&DAT_20003590 + iVar12 * 4,2);
              uVar35 = _DAT_2000ba38;
            }
          }
          uVar34 = uVar34 + 1;
          pfVar28 = pfVar28 + 2;
        } while (uVar34 < uVar35);
      }
      else {
        FUN_08034a6c(0,&DAT_20005dc4);
        uVar35 = _DAT_2000ba38;
      }
    }
    if (uVar35 >> 3 != 0) {
      uVar34 = 0;
      pfVar28 = (float *)&DAT_20005dc4;
      pfVar27 = (float *)&DAT_20005fc4;
      do {
        cVar31 = DAT_200080d2;
        if (DAT_200080d2 == '\0') {
          if (DAT_200080d0 != '\0') {
            FUN_08034a6c(0,0x20007ffc,0x32);
            _DAT_200080c4 = 0x31;
            _DAT_20007ff8 = 0.0;
            _DAT_200080e0 = 0x3f800000;
            DAT_200080d1 = cVar31;
            _DAT_200080cc = 0.0;
            _DAT_200080c8 = 0;
          }
        }
        else {
          uVar35 = (uint)DAT_20007eac;
          DAT_200080d0 = '\x01';
          uVar22 = DAT_20007fe4 + 1 & 0xff;
          *(float *)((uint)DAT_20007fe4 * 4 + 0x20007fe8) = *pfVar28;
          uVar22 = uVar22 - uVar35 * (uVar22 / uVar35);
          DAT_20007fe4 = (byte)uVar22;
          if ((uVar22 & 0xff) == 0) {
            FUN_08035c88(&DAT_20007eac,0x20007fe8,&local_54,4);
            FUN_08036000(0x20007e0c,&local_54,&local_50,1);
            local_50 = local_50 * 1000.0;
            *(float *)(_DAT_200080c4 * 4 + 0x20007ffc) = local_50;
            fVar36 = local_50 * *(float *)(_DAT_200080c8 * 4 + 0x20007ffc) * 10.0;
            fVar38 = ABS(_DAT_20007ff8 - fVar36);
            bVar30 = (byte)(((uint)(fVar38 == _DAT_200080cc) << 0x1e) >> 0x18);
            _DAT_200080c4 = (_DAT_200080c4 + 1) % 0x32;
            _DAT_200080c8 = (_DAT_200080c8 + 1) % 0x32;
            cVar31 = -((char)((byte)(((uint)(fVar38 < _DAT_200080cc) << 0x1f) >> 0x18) | bVar30) >>
                      7);
            if ((bool)(bVar30 >> 6) || (bool)cVar31 != (NAN(fVar38) || NAN(_DAT_200080cc))) {
              if (cVar31 != '\0') {
                _DAT_200080cc = _DAT_200080cc + (fVar38 - _DAT_200080cc) * 0.001;
              }
            }
            else {
              _DAT_200080cc = _DAT_200080cc + (fVar38 - _DAT_200080cc) * 0.9;
            }
            _DAT_20007ff8 = fVar36;
            if (DAT_200080d1 == '\0') {
              if ((int)((uint)(_DAT_200080cc + _DAT_200080d8 < _DAT_200080dc) << 0x1f) < 0) {
                DAT_200080d1 = '\x01';
                _DAT_200080d4 = 0x32;
              }
            }
            else if ((int)((uint)(_DAT_200080dc + _DAT_200080d8 < _DAT_200080cc) << 0x1f) < 0) {
              if (_DAT_200080d4 == 0) {
                DAT_200080d1 = '\0';
              }
              else {
                _DAT_200080d4 = _DAT_200080d4 + -1;
              }
            }
          }
        }
        FUN_08036000(0x20006fe0,pfVar28,&DAT_20008348,1);
        _DAT_20008348 = _DAT_20008348 * _DAT_20006fec;
        FUN_08036000(0x20007178,&DAT_20008348,pfVar28,1);
        fVar38 = *pfVar28 * _DAT_20007184;
        *pfVar28 = fVar38;
        fVar36 = _DAT_20008578;
        if (bVar8 != 7) {
          if (DAT_20008598 == '\0') {
            FUN_08036478(0x42480000,pfVar28,pfVar28,1);
          }
          else {
            fVar38 = fVar38 * 50.0;
            uVar35 = (uint)_DAT_2000858c;
            fVar14 = ABS(fVar38);
            bVar33 = NAN(_DAT_20008578);
            bVar30 = (byte)(((uint)(fVar14 == _DAT_20008578) << 0x1e) >> 0x18);
            cVar31 = -((char)((byte)(((uint)(fVar14 < _DAT_20008578) << 0x1f) >> 0x18) | bVar30) >>
                      7);
            *(float *)(uVar35 * 4 + 0x20008398) = fVar38;
            fVar38 = fVar14;
            fVar41 = fVar14;
            if (((bool)(bVar30 >> 6) || (bool)cVar31 != (NAN(fVar14) || bVar33)) &&
               (fVar38 = fVar36, fVar41 = _DAT_20008578, cVar31 != '\0')) {
              fVar38 = fVar36 + (fVar14 - fVar36) * 0.75;
              fVar41 = fVar38;
            }
            _DAT_20008578 = fVar41;
            fVar36 = (float)FUN_0803b57c(fVar38 + 2.3283e-10);
            fVar36 = (_DAT_20008588 - _DAT_2000857c) + -fVar36 * 20.0;
            if (fVar36 < 0.0) {
              _DAT_2000857c = _DAT_2000857c + fVar36 * _DAT_20008580;
              _DAT_20008590 = _DAT_20008594;
            }
            else if (fVar36 != 0.0) {
              if (DAT_20008599 == '\0') {
                _DAT_20008590 = 0;
              }
              else if (_DAT_20008590 != 0) {
                _DAT_20008590 = _DAT_20008590 + -1;
                goto LAB_0802508a;
              }
              _DAT_2000857c = _DAT_2000857c + fVar36 * _DAT_20008584;
            }
LAB_0802508a:
            if (10.0 < _DAT_2000857c) {
              fVar36 = 3.1622777;
              _DAT_2000857c = 10.0;
            }
            else if ((int)((uint)(_DAT_2000857c < -100.0) << 0x1f) < 0) {
              fVar36 = 1e-05;
              _DAT_2000857c = -100.0;
            }
            else {
              fVar36 = (float)FUN_0803b510(_DAT_2000857c * 0.05 * 2.3025851);
            }
            _DAT_2000858c = (short)(uVar35 + 1) + (short)((uVar35 + 1 & 0xffff) / 0x78) * -0x78;
            *pfVar28 = *(float *)(((uVar35 + 0x3c) % 0x78) * 4 + 0x20008398) * 10.0 * fVar36;
          }
        }
        FUN_08036000(0x20006f14,pfVar28,&DAT_20008348,1);
        _DAT_20008348 = _DAT_20008348 * _DAT_20006f20;
        FUN_08036000(0x200070ac,&DAT_20008348,pfVar27,1);
        _DAT_20008348 = *pfVar27 * _DAT_200070b8;
        FUN_08036000(&DAT_2000b6b8,&DAT_20008348,pfVar27,1);
        fVar36 = *pfVar27 * _DAT_2000b6c4;
        if (bVar8 == 6) {
          fVar36 = fVar36 * 5.0;
        }
        fVar38 = -_DAT_2000ba50 + _DAT_2000ba54 * 0.9 + fVar36;
        _DAT_2000ba50 = fVar36;
        _DAT_2000ba54 = fVar38;
        *pfVar27 = fVar38;
        if (DAT_2000b6b4 != '\0') {
          FUN_08036000(0x2000b674,pfVar27,&DAT_2000b6b0,1);
          fVar38 = _DAT_2000b6b0;
          *pfVar27 = _DAT_2000b6b0;
        }
        if (DAT_20008fbd == 0) {
          _DAT_20008fc0 = 0;
          _DAT_20008fc4 = 0;
          _DAT_20008fc8 = 0;
        }
        else {
          DAT_20008fbc = 1;
          iVar12 = _DAT_20008fc8 + 0x140a;
          _DAT_20008fc8 = _DAT_20008fc8 + 1 & 0x7f;
          *(float *)(&DAT_20003594 + iVar12 * 4) = fVar38;
          if (_DAT_20008fc8 == 0) {
            FUN_08022c30();
            pfVar16 = (float *)&DAT_200085bc;
            do {
              fVar36 = *pfVar16;
              pfVar16 = pfVar16 + 1;
              *(float *)(&DAT_20003594 + (_DAT_20008fc0 + 0x148a) * 4) = fVar36 * 1.414;
              _DAT_20008fc0 = _DAT_20008fc0 + 1 & 0x1ff;
            } while (pfVar16 != (float *)0x200087bc);
          }
        }
        uVar34 = uVar34 + 1;
        uVar35 = _DAT_2000ba38;
        pfVar28 = pfVar28 + 1;
        pfVar27 = pfVar27 + 1;
      } while (uVar34 < _DAT_2000ba38 >> 3);
    }
    if (DAT_20008fbd == 0) {
      if (uVar35 != 0) {
        puVar25 = &DAT_20005fc4;
        puVar20 = &DAT_200061c4;
        uVar35 = 0;
        do {
          FUN_08035364(0x20006c30,puVar25,puVar20,1);
          uVar35 = uVar35 + 8;
          puVar20 = puVar20 + 0x20;
          puVar25 = puVar25 + 4;
          uVar34 = _DAT_2000ba38;
        } while (uVar35 < _DAT_2000ba38);
        goto LAB_08026450;
      }
    }
    else if (uVar35 != 0) {
      puVar25 = &DAT_200061c4;
      uVar35 = 0;
      do {
        if (_DAT_20008fc4 < _DAT_20008fc0) {
          local_50 = *(float *)(&DAT_20003594 + (_DAT_20008fc4 + 0x148a) * 4);
          _DAT_20008fc4 = _DAT_20008fc4 + 1;
        }
        else if (_DAT_20008fc0 < _DAT_20008fc4) {
          local_50 = *(float *)(&DAT_20003594 + (_DAT_20008fc4 + 0x148a) * 4);
          _DAT_20008fc4 = _DAT_20008fc4 + 1 & 0x1ff;
        }
        else {
          local_50 = 0.0;
        }
        FUN_08035364(0x20006c30,&local_50,puVar25,1);
        uVar35 = uVar35 + 8;
        puVar25 = puVar25 + 0x20;
        uVar34 = _DAT_2000ba38;
      } while (uVar35 < _DAT_2000ba38);
      goto LAB_08026450;
    }
  }
LAB_08028866:
  uVar34 = 0;
LAB_08026450:
  _DAT_20008388 = _DAT_20008378;
  if (DAT_20008374 != '\0' || DAT_200080d1 != '\0') {
    _DAT_20008388 = 0.0;
  }
  _DAT_20008364 = _DAT_20008360;
  if (DAT_20008368 != '\0') {
    _DAT_20008364 = _DAT_20008360 * 0.05;
  }
  if (uVar34 != 0) {
    pfVar28 = (float *)&DAT_20004990;
    puVar26 = (undefined4 *)&DAT_20004190;
    uVar34 = 0;
    do {
      if (DAT_200085ad - 4 < 2) {
        _DAT_200082d8 = _DAT_200082d8 + _DAT_200082dc;
        if (6.2831855 <= _DAT_200082d8) {
          _DAT_200082d8 = _DAT_200082d8 - 6.2831855;
        }
        if (DAT_200082f5 == '\0') {
          if (_DAT_200082d4 != 0) {
            _DAT_200082d4 = _DAT_200082d4 - 1;
          }
        }
        else if (_DAT_200082d4 < _DAT_200082c8 - 1U) {
          _DAT_200082d4 = _DAT_200082d4 + 1;
        }
        _DAT_200082e0 = (float)FUN_080363f8();
        _DAT_200082e0 =
             *(float *)(&DAT_20003590 + (_DAT_200082d4 + 0x12d6) * 4) * _DAT_200082e4 *
             _DAT_200082e0;
        if ((DAT_200085af == '\x01') && (DAT_20004da8 == '\0')) {
          if (DAT_200085ad == 4) {
            fVar38 = (float)FUN_08036370(_DAT_200082d8);
            fVar36 = _DAT_200082d8;
            *(float *)(&DAT_20003590 + (_DAT_20004dac + 0x304) * 8) =
                 *(float *)(&DAT_20003590 + (_DAT_200082d4 + 0x12d6) * 4) * 0.001 * fVar38;
            fVar36 = (float)FUN_080363f8(fVar36);
            *(float *)(&DAT_20003594 + (_DAT_20004dac + 0x304) * 8) =
                 *(float *)(&DAT_20003590 + (_DAT_200082d4 + 0x12d6) * 4) * 0.001 * fVar36;
          }
          else {
            fVar38 = (float)FUN_08036370(_DAT_200082d8);
            fVar36 = _DAT_200082d8;
            *(float *)(&DAT_20003594 + (_DAT_20004dac + 0x304) * 8) =
                 *(float *)(&DAT_20003590 + (_DAT_200082d4 + 0x12d6) * 4) * 0.001 * fVar38;
            fVar36 = (float)FUN_080363f8(fVar36);
            *(float *)(&DAT_20003590 + (_DAT_20004dac + 0x304) * 8) =
                 *(float *)(&DAT_20003590 + (_DAT_200082d4 + 0x12d6) * 4) * 0.001 * fVar36;
          }
          _DAT_20004dac =
               (_DAT_20004dac + 1U) - _DAT_2000ba3c * ((_DAT_20004dac + 1U) / _DAT_2000ba3c);
          if (_DAT_20004dac == 0) {
            DAT_20004da8 = '\x01';
          }
        }
      }
      else {
        _DAT_200082e0 = 0.0;
      }
      pfVar27 = pfVar28 + 0x80;
      fVar36 = *pfVar28;
      pfVar16 = pfVar28 + 0x60d;
      pfVar28 = pfVar28 + 1;
      _DAT_20008358 = (fVar36 + *pfVar27) * _DAT_20008370 + *pfVar16 * _DAT_20008388 + _DAT_200082e0
      ;
      _DAT_2000835c = _DAT_20008358 * _DAT_20008364;
      _DAT_20008350 = VectorFloatToSignedFixed(_DAT_20008358,0x20,0x1f);
      _DAT_20008354 = VectorFloatToSignedFixed(_DAT_2000835c,0x20,0x1f);
      uVar37 = *puVar26;
      *(uint *)(_DAT_200003c8 + uVar34 * 8) = _DAT_20008350 >> 0x10 | _DAT_20008350 << 0x10;
      uVar40 = puVar26[1];
      iVar12 = VectorFloatToSignedFixed(uVar37,0x20,0x1f);
      *(uint *)((int)puVar26 + _DAT_200003c8 + -0x2000418c) =
           _DAT_20008354 >> 0x10 | _DAT_20008354 << 0x10;
      uVar35 = iVar12 + _DAT_2000b784 + _DAT_2000ba58;
      iVar12 = VectorFloatToSignedFixed(uVar40,0x20,0x1f);
      *(uint *)(_DAT_200003d0 + uVar34 * 8) = uVar35 >> 0x10 | uVar35 * 0x10000;
      _DAT_20008338 = _DAT_2000ba58 + iVar12 + _DAT_2000b788;
      *(uint *)((int)puVar26 + _DAT_200003d0 + -0x2000418c) =
           _DAT_20008338 >> 0x10 | _DAT_20008338 * 0x10000;
      uVar34 = uVar34 + 1;
      puVar26 = puVar26 + 2;
    } while (uVar34 < _DAT_2000ba38);
  }
  _DAT_40020414 = _DAT_40020414 | 4;
  _DAT_40012008 = _DAT_40012008 | 0x40000000;
  if (DAT_2000832a == '\0') {
    return;
  }
  DAT_2000832a = DAT_2000832a + -1;
  return;
}

