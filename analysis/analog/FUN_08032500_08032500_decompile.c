
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08032500(void)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  int local_1c;
  
  FUN_0802e900(1,1);
  FUN_0802e900(8,1);
  FUN_0802e900(0x10,1);
  FUN_0802e900(0x20,1);
  FUN_0802e900(0x40,1);
  FUN_0802e938(0x200,1);
  local_44 = 0;
  local_4c = 0;
  local_48 = 0x30000;
  local_40 = 0;
  FUN_0802dfa8(&local_4c);
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_3c = 0;
  local_38 = 0;
  local_28 = 1;
  local_37 = 0;
  FUN_0802df54(0x40012100,&local_3c);
  FUN_0802dfec(0x40012100,6,1,7);
  FUN_0802dfd8(0x40012100,1);
  _DAT_40012108 = _DAT_40012108 | 0x40000000;
  FUN_0802e57c(0x40021400,0x800);
  FUN_0802e580(0x40021400,0x1000);
  FUN_0802e580(0x40021000,0x800);
  local_1f = 0;
  local_1e = 0;
  local_20 = 1;
  local_1d = 1;
  local_24 = 0x18;
  FUN_0802e580(0x40020c00,0x18);
  FUN_0802e4e8(0x40020c00,&local_24);
  local_1f = 0;
  local_1e = 0;
  local_20 = 1;
  local_1d = 1;
  local_24 = 0x4c00;
  _DAT_40021014 = _DAT_40021014 & 0xffffbfff | 0x400;
  FUN_0802e4e8(0x40021000,&local_24);
  local_24 = 0x1800;
  FUN_0802e4e8(0x40021400,&local_24);
  local_20 = 0;
  local_1d = 1;
  local_24 = 0x2000;
  FUN_0802e4e8(0x40021000,&local_24);
  local_24 = 0x10;
  FUN_0802e4e8(0x40021800,&local_24);
  local_20 = 3;
  local_24 = 0x40;
  FUN_0802e4e8(0x40020000,&local_24);
  FUN_08033094();
  FUN_08032cf4();
  FUN_080301b0(&DAT_2000c6e0);
  iVar3 = FUN_08032c5c(0x8008000,&DAT_2000e984);
  if (iVar3 == 0) {
    DAT_2000e6f4 = FUN_08032c54(&DAT_2000e984,0,1);
  }
  else {
    DAT_2000e6f4 = '\x01';
  }
  if (DAT_2000e6f4 != '\0') {
    FUN_0803131c();
    FUN_080305ac(&DAT_20000334);
    uVar2 = FUN_08032c54(&DAT_2000e984,0,1);
    FUN_08032ce0(0x40021400,0x1000,uVar2);
    pcVar1 = DAT_2000c6c8;
    uVar2 = FUN_08032c54(&DAT_2000e984,0,1);
    (*pcVar1)(uVar2);
    uVar2 = FUN_08032c54(&DAT_2000e984,0,1);
    FUN_08030140(&DAT_200002ac,uVar2);
  }
  FUN_0802e91c(0x10000000,1);
  FUN_0802e900(0x40000,1);
  FUN_0802e838(1);
  FUN_08032470();
  FUN_08033d64();
  while (_DAT_40024000 != -0x55aaaa56) {
    if ((_DAT_40021810 & 0x10) == 0) {
      DAT_2000e6fc = DAT_2000e6fc + 1;
      if (-1 < DAT_2000e6fc) break;
    }
    else {
      DAT_2000e6fc = 0;
    }
    uVar4 = FUN_0802d7e8();
    if ((uVar4 & 0x100000) != 0) break;
    if ((DAT_2000e6f4 != '\0') && (DAT_2000e6f8 = (DAT_2000e6f8 + 1) % 0x4e2, DAT_2000e6f8 == 0)) {
      local_1c = FUN_080304c0(&DAT_200002d0,&DAT_2000e70c);
      if (local_1c == 0) {
        local_1c = FUN_08030478(&DAT_200002d0,&DAT_2000e710);
        if (local_1c == 0) {
          DAT_2000e714 = (DAT_2000e710 * 100.0) / 1800.0;
          if ((int)((uint)(DAT_2000e714 < 0.0) << 0x1f) < 0) {
            DAT_2000e714 = 0.0;
          }
          else if (100.0 < DAT_2000e714) {
            DAT_2000e714 = 100.0;
          }
          uVar6 = FUN_08020628(DAT_2000e70c);
          uVar7 = FUN_08020628(DAT_2000e710);
          uVar8 = FUN_08020628(DAT_2000e714);
          if (DAT_2000e6f7 == '\0') {
            pcVar5 = s_CHARGING_0803d184;
          }
          else {
            pcVar5 = s_FULL_0803d190;
          }
          FUN_08037970(s_bv___4_1fmV__bc___4_1fmAh___3_1f_0803d19c,(int)((ulonglong)uVar8 >> 0x20),
                       (int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar7,uVar8,pcVar5);
        }
        else {
          FUN_08030528(&DAT_200002d0);
          FUN_08037970(s_error__get_battery_capacity__rec_0803d150);
        }
      }
      else {
        FUN_08030528(&DAT_200002d0);
        FUN_08037970(s_error__get_battery_voltage__reco_0803d120);
      }
      if ((1800.0 <= DAT_2000e710) || ((_DAT_40021010 & 0x2000) == 0)) {
        DAT_2000e6f7 = '\x01';
      }
      else {
        DAT_2000e6f7 = '\0';
      }
      if (DAT_2000e6f7 == '\0') {
        FUN_08032ce0(0x40020c00,8,DAT_2000e6f5);
      }
      else {
        FUN_08032ce0(0x40020c00,8,1);
      }
      DAT_2000e6f5 = ~DAT_2000e6f5;
    }
    DAT_2000e700 = (DAT_2000e700 + 1) % 500;
    if (DAT_2000e700 == 0) {
      DAT_2000e704 = _DAT_4001214c;
      if (_DAT_4001214c < 0x610) {
        DAT_2000e6fc = DAT_2000e6fc + 1;
      }
      else {
        DAT_2000e6fc = 0;
        DAT_2000e6f6 = 1;
      }
      if (10 < DAT_2000e6fc) {
        DAT_2000e6fc = 0;
        DAT_2000e6f6 = 0;
        _DAT_40021014 = _DAT_40021014 & 0xfffff7ff;
      }
      _DAT_40012108 = _DAT_40012108 | 0x40000000;
    }
    FUN_080324c8(1);
  }
  _DAT_40021014 = _DAT_40021014 | 0x800;
  if (DAT_2000e6f4 == '\0') {
    FUN_0803131c();
    FUN_080305ac(&DAT_20000334);
  }
  FUN_0802dfd8(0x40012100,0);
  _DAT_40024000 = 0;
  FUN_080349e4(10);
  FUN_0802e838(0);
  FUN_080331c4();
  FUN_0803249c();
  FUN_08033d0c();
  return;
}

