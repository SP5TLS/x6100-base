
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08033990(void)

{
  ushort uVar1;
  undefined1 uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = _DAT_20001464[10];
  _DAT_20001434 = _DAT_20001464[0xc];
  uVar6 = (uint)uVar1;
  _DAT_20001432 = uVar1;
  if ((_DAT_20001434 & 1) != 0) {
    return;
  }
  _DAT_20001432 = uVar1 & 2;
  if ((uVar1 & 2) == 0) {
    if ((int)(uVar6 << 0x19) < 0) {
      _DAT_20001448 = _DAT_20001464[8];
      _DAT_20001434 = 0;
      uVar6 = (uint)_DAT_20001448;
      if (_DAT_2000143c == 0) {
        _DAT_20001434 = 0;
        _DAT_2000143c = 1;
        _DAT_20001440 = uVar6;
        return;
      }
      if (_DAT_2000143c == 1) {
        _DAT_20001434 = 0;
        _DAT_20001438 = uVar6 | _DAT_20001440 << 8;
        _DAT_2000143c = 2;
        _DAT_20001444 = uVar6;
        return;
      }
      uVar2 = (undefined1)_DAT_20001448;
      if (_DAT_20001438 < 0xfffe) {
        uVar6 = _DAT_20001438 - 0xf000;
        if (uVar6 < 0xffe) {
          _DAT_2000147c = uVar6 - _DAT_20001480 * (uVar6 / _DAT_20001480);
          *(undefined1 *)(_DAT_20001478 + _DAT_2000147c) = uVar2;
          uVar6 = (uint)_DAT_20001432;
          _DAT_20001438 = _DAT_20001438 + 1;
          uVar5 = uVar6 & 0x10;
        }
        else {
LAB_08033b36:
          if (*_DAT_20001454 == 0) {
            _DAT_20001450 = _DAT_20001452;
            _DAT_20001454[2] = 0;
            _DAT_2000144a = CONCAT22(DAT_2000144a_2,1);
            goto LAB_080339be;
          }
          *(undefined1 *)
           (*_DAT_20001454 +
           (_DAT_20001438 - _DAT_20001454[1] * (_DAT_20001438 / (uint)_DAT_20001454[1]))) = uVar2;
          _DAT_20001438 =
               (_DAT_20001438 + 1) -
               _DAT_20001454[1] * ((_DAT_20001438 + 1) / (uint)_DAT_20001454[1]);
          if (_DAT_20001438 == 0) {
            uVar6 = (uint)_DAT_20001432;
            if (DAT_2000144e == '\0') {
              DAT_2000144e = '\x01';
            }
            uVar5 = uVar6 & 0x10;
          }
          else {
            uVar6 = (uint)_DAT_20001432;
            uVar5 = uVar6 & 0x10;
          }
        }
      }
      else {
        if (_DAT_20001468 == 0) goto LAB_08033b36;
        *(undefined1 *)(_DAT_20001468 + _DAT_2000146c) = uVar2;
        uVar6 = (uint)_DAT_20001432;
        _DAT_2000146c =
             (_DAT_2000146c + 1U) - _DAT_20001474 * ((_DAT_2000146c + 1U) / _DAT_20001474);
        uVar5 = uVar6 & 0x10;
      }
      _DAT_20001454[2] = 0;
      _DAT_20001450 = _DAT_20001452;
      _DAT_2000144a = CONCAT22(DAT_2000144a_2,1);
    }
    else {
      uVar5 = uVar6 & 0x10;
      _DAT_20001432 = uVar1;
    }
    uVar4 = _DAT_2000145c;
    if (uVar5 != 0) {
      sVar3 = _DAT_2000144a;
      *_DAT_20001464 = *_DAT_20001464 | 1;
      _DAT_20001432 = 0;
      _DAT_20001434 = 0;
      _DAT_2000143c = 0;
      if (sVar3 == 0) {
        _DAT_20001432 = 0;
        _DAT_20001434 = 0;
        _DAT_2000143c = 0;
        return;
      }
      _DAT_2000144a = 0x10000;
      return;
    }
    if ((int)(uVar6 << 0x18) < 0) {
      _DAT_20001432 = 0;
      _DAT_20001434 = 0;
      if (_DAT_20001438 < 0x80) {
        if (_DAT_20001460 != 0) {
          _DAT_20001464[8] =
               (ushort)*(byte *)(_DAT_20001460 +
                                (_DAT_20001438 - _DAT_2000145c * (_DAT_20001438 / _DAT_2000145c)));
          _DAT_20001438 = (_DAT_20001438 + 1) - uVar4 * ((_DAT_20001438 + 1) / uVar4);
          _DAT_20001450 = _DAT_20001452;
          return;
        }
      }
      else if (0x7f < _DAT_20001438 - 0x80) {
        uVar6 = _DAT_20001438 - 0x100;
        if (uVar6 < 0xf00) {
          _DAT_2000147c = uVar6 - _DAT_20001480 * (uVar6 / _DAT_20001480);
          _DAT_20001464[8] = (ushort)*(byte *)(_DAT_20001478 + _DAT_2000147c);
          _DAT_20001438 = _DAT_20001438 + 1;
          _DAT_20001450 = _DAT_20001452;
          return;
        }
        if (0xdfff < _DAT_20001438 - 0x1000) {
          uVar6 = _DAT_20001438 - 0xf000;
          if (uVar6 < 0xffe) {
            _DAT_2000147c = uVar6 - _DAT_20001480 * (uVar6 / _DAT_20001480);
            _DAT_20001464[8] = (ushort)*(byte *)(_DAT_20001478 + _DAT_2000147c);
            _DAT_20001438 = _DAT_20001438 + 1;
            _DAT_20001450 = _DAT_20001452;
            return;
          }
          _DAT_20001464[8] = 0x61;
          _DAT_20001450 = _DAT_20001452;
          return;
        }
      }
      _DAT_20001464[8] = 0;
      _DAT_20001450 = _DAT_20001452;
      return;
    }
  }
  else {
    _DAT_20001432 = 0;
    _DAT_20001430 = _DAT_20001434 & 1;
    _DAT_20001434 = _DAT_20001434 & 1;
    _DAT_20001454[3] = 1;
LAB_080339be:
    uVar6 = 0;
  }
  if (-1 < (int)(uVar6 << 0x15)) {
    return;
  }
  _DAT_20001432 = 0;
  _DAT_20001434 = 0;
  _DAT_20001464[10] = _DAT_20001464[10] & 0xfdff;
  _DAT_2000143c = 0;
  return;
}

