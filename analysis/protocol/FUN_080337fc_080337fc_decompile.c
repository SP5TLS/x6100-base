
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080337fc(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = DAT_2000e7e2;
  cVar1 = DAT_2000e7e0;
  if (DAT_2000e7e2 == '\0') {
    if (DAT_2000e7e0 == '\0') {
      FUN_08023c88(0x200003fc);
      _DAT_200013fc = _DAT_20001420;
      DAT_20001424 = cVar1;
      _DAT_20001400 =
           CONCAT13(DAT_20001427,CONCAT12(DAT_20001426,CONCAT11(DAT_20001425,DAT_20001400)));
      _DAT_20001408 =
           _DAT_20001408 & 0xff000000 | (uint)DAT_2000142e | (uint)DAT_2000142f << 8 |
           (uint)DAT_2000142d << 0x10;
      _DAT_20001404 = CONCAT13(DAT_2000142b,_DAT_20001428);
      FUN_0802e0bc();
      _DAT_2000141c = FUN_0802e0cc(0x200003f8,0x409);
      FUN_08032fc8(0x200003f8,0x1028);
      DAT_2000e7e0 = 1;
      return;
    }
    if (DAT_2000e7e0 == '\x01') {
      iVar3 = FUN_0802e1dc(&DAT_400264a0,0x20200000);
      if (iVar3 != 1) {
        return;
      }
      FUN_0802e214(&DAT_400264a0,0x20200000);
      FUN_0802e214(&DAT_400264a0,0x20100000);
      DAT_2000e7e1 = cVar2;
      DAT_2000e7e0 = 2;
      return;
    }
    if ((DAT_2000e7e0 == '\x02') && (DAT_2000e7e1 = DAT_2000e7e1 + 1, DAT_2000e7e1 < 10)) {
      return;
    }
  }
  DAT_2000e7e0 = 0;
  return;
}

