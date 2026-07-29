
/* WARNING: Removing unreachable block (ram,0x0802e188) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802c840(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  
  cVar1 = *(char *)(param_1 + 0x6b);
  cVar2 = *(char *)(param_1 + 0x6a);
  if (param_2 - 1500000 < 0xaae61) {
    if (cVar2 == '\x01') {
      if (2000000 < param_2) {
        if (cVar1 != '\x01') {
          *(undefined1 *)(param_1 + 0x6b) = 1;
          *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
        }
        goto LAB_0802c9dc;
      }
LAB_0802cbba:
      if (cVar1 != '\0') {
        *(undefined1 *)(param_1 + 0x6b) = 0;
        *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
      }
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x80);
      *(undefined1 *)(param_1 + 0x6a) = 1;
      *(uint *)(param_1 + 0x80) = uVar4 | 2;
      if (2000000 < param_2) {
        if (cVar1 != '\x01') {
          *(undefined1 *)(param_1 + 0x6b) = 1;
          *(uint *)(param_1 + 0x80) = uVar4 | 3;
        }
LAB_0802c9dc:
        FUN_0802e1b4(0,0x23a);
        goto LAB_0802e170;
      }
      if (cVar1 != '\0') {
        *(undefined1 *)(param_1 + 0x6b) = 0;
        *(uint *)(param_1 + 0x80) = uVar4 | 3;
      }
    }
    goto LAB_0802c954;
  }
  if (param_2 - 0x2191c1 < 1600000) {
    if (cVar2 == '\x02') {
LAB_0802cbae:
      if (cVar1 == '\x01') goto LAB_0802c9dc;
      uVar4 = *(uint *)(param_1 + 0x80);
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x80) | 2;
      *(undefined1 *)(param_1 + 0x6a) = 2;
      *(uint *)(param_1 + 0x80) = uVar4;
LAB_0802c9cc:
      if (cVar1 == '\x01') goto LAB_0802c9dc;
    }
    *(undefined1 *)(param_1 + 0x6b) = 1;
    *(uint *)(param_1 + 0x80) = uVar4 | 1;
    goto LAB_0802c9dc;
  }
  if (param_2 - 0x39fbc1 < 1700000) {
    if (cVar2 == '\x03') {
      if (param_2 < 0x3d0901) goto LAB_0802cbae;
      if (cVar1 != '\x02') {
        *(undefined1 *)(param_1 + 0x6b) = 2;
        *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x80);
      *(undefined1 *)(param_1 + 0x6a) = 3;
      uVar4 = uVar3 | 2;
      *(uint *)(param_1 + 0x80) = uVar4;
      if (param_2 < 0x3d0901) goto LAB_0802c9cc;
      if (cVar1 != '\x02') {
LAB_0802ce68:
        *(undefined1 *)(param_1 + 0x6b) = 2;
        *(uint *)(param_1 + 0x80) = uVar3 | 3;
        goto LAB_0802cb7c;
      }
    }
    if ((int)param_2 < 0x4c4b41) goto LAB_0802c9dc;
  }
  else {
    if (1999999 < param_2 - 0x53ec61) {
      if (5999999 < param_2 - 0x7270e1) {
        if (7499999 < param_2 - 0xcdfe61) {
          if (param_2 + 0xfebf90bf < 12000000) {
            if (cVar2 != '\a') {
              uVar4 = *(uint *)(param_1 + 0x80) | 2;
              *(undefined1 *)(param_1 + 0x6a) = 7;
              *(uint *)(param_1 + 0x80) = uVar4;
              if (param_2 < 0x14fb181) goto LAB_0802ca18;
              goto LAB_0802ca3e;
            }
            if (22000000 < param_2) {
              if (30000000 < param_2) goto joined_r0x0802cd4e;
              if (cVar1 != '\x05') {
                uVar4 = *(uint *)(param_1 + 0x80);
                goto LAB_0802ca52;
              }
LAB_0802cd5a:
              if (24000000 < (int)param_2) {
                if (28000000 < (int)param_2) goto LAB_0802cd72;
LAB_0802cdf4:
                FUN_0802e1b4(0,0xa08);
                goto LAB_0802e170;
              }
LAB_0802cd98:
              FUN_0802e1b4(0,0x8eb);
              goto LAB_0802e170;
            }
            if (cVar1 != '\x04') goto LAB_0802cc72;
LAB_0802ce32:
            if ((int)param_2 < 0x16e3601) goto LAB_0802cd98;
LAB_0802cc1c:
            if (50000000 < (int)param_2) {
              FUN_0802e1b4(0,0xc43);
              goto LAB_0802e170;
            }
          }
          else {
            if (16999999 < param_2 + 0xfe0875bf) {
              if (param_2 + 0xfd050f7f < 5000000) {
                if (cVar2 == '\t') {
                  if (cVar1 == '\x06') goto LAB_0802ce32;
                  goto LAB_0802cde0;
                }
                uVar4 = *(uint *)(param_1 + 0x80) | 2;
                *(undefined1 *)(param_1 + 0x6a) = 9;
                *(uint *)(param_1 + 0x80) = uVar4;
LAB_0802ca3e:
                if (param_2 < 0x1c9c381) {
                  if (cVar1 != '\x05') {
LAB_0802ca52:
                    uVar5 = 5;
                    goto LAB_0802ca58;
                  }
                  goto LAB_0802cd5a;
                }
              }
              else {
                if (cVar2 != '\0') {
                  uVar3 = *(uint *)(param_1 + 0x80);
                  uVar4 = uVar3 | 2;
                  *(undefined1 *)(param_1 + 0x6a) = 0;
                  *(uint *)(param_1 + 0x80) = uVar4;
                  if (param_2 < 0x1e8481) {
                    if (cVar1 != '\0') {
                      *(undefined1 *)(param_1 + 0x6b) = 0;
                      *(uint *)(param_1 + 0x80) = uVar3 | 3;
                    }
                    goto LAB_0802c954;
                  }
                  goto LAB_0802ca3e;
                }
                if (param_2 < 0x1e8481) goto LAB_0802cbba;
              }
joined_r0x0802cd4e:
              if (cVar1 == '\x06') {
                if (2000000 < (int)param_2) goto LAB_0802cbf2;
              }
              else {
                *(undefined1 *)(param_1 + 0x6b) = 6;
                *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
                if (2000000 < (int)param_2) goto LAB_0802cb7c;
              }
LAB_0802c954:
              FUN_0802e1b4(0,0x11d);
              goto LAB_0802e170;
            }
            if (cVar2 != '\b') {
              uVar4 = *(uint *)(param_1 + 0x80) | 2;
              *(undefined1 *)(param_1 + 0x6a) = 8;
              *(uint *)(param_1 + 0x80) = uVar4;
              goto LAB_0802ca3e;
            }
            if (cVar1 != '\x06') {
LAB_0802cde0:
              *(undefined1 *)(param_1 + 0x6b) = 6;
              *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
              goto LAB_0802ca6c;
            }
          }
LAB_0802cd72:
          FUN_0802e1b4(0,0xb26);
          goto LAB_0802e170;
        }
        if (cVar2 == '\x06') {
          if (param_2 < 0xe4e1c1) {
            if (cVar1 != '\x03') goto LAB_0802cc4a;
            goto LAB_0802ce1c;
          }
          if (cVar1 != '\x04') {
LAB_0802cc72:
            *(undefined1 *)(param_1 + 0x6b) = 4;
            *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
            goto LAB_0802ca6c;
          }
          if (18000000 < (int)param_2) {
            if (param_2 == 21000000) goto LAB_0802cd98;
            goto LAB_0802cd32;
          }
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x80) | 2;
          *(undefined1 *)(param_1 + 0x6a) = 6;
          *(uint *)(param_1 + 0x80) = uVar4;
          if (15000000 < param_2) {
LAB_0802ca18:
            if (cVar1 != '\x04') {
              uVar5 = 4;
              goto LAB_0802ca58;
            }
            if ((int)param_2 < 0x112a881) goto LAB_0802ca92;
            if (20999999 < (int)param_2) goto LAB_0802cd98;
LAB_0802cd32:
            FUN_0802e1b4(0,0x7cd);
            goto LAB_0802e170;
          }
          if (cVar1 != '\x03') goto LAB_0802cb38;
LAB_0802ce1c:
          if ((int)param_2 < 0xd59f81) goto LAB_0802cb4c;
        }
LAB_0802ca92:
        FUN_0802e1b4(0,0x6b0);
        goto LAB_0802e170;
      }
      if (cVar2 == '\x05') {
        if (param_2 < 0x7a1201) {
          if (cVar1 == '\x02') goto LAB_0802cb00;
          *(undefined1 *)(param_1 + 0x6b) = 2;
          *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
        }
        else {
          if (cVar1 == '\x03') goto LAB_0802cb40;
LAB_0802cc4a:
          *(undefined1 *)(param_1 + 0x6b) = 3;
          *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
        }
LAB_0802ca6c:
        if (10000000 < (int)param_2) {
          if (14000000 < (int)param_2) {
            if (18000000 < (int)param_2) {
LAB_0802cbf2:
              if ((int)param_2 < 21000000) goto LAB_0802cd32;
              if ((int)param_2 < 0x16e3601) goto LAB_0802cd98;
              if ((int)param_2 < 0x1ab3f01) goto LAB_0802cdf4;
              goto LAB_0802cc1c;
            }
            goto LAB_0802ca92;
          }
LAB_0802cb4c:
          FUN_0802e1b4(0,0x593);
          goto LAB_0802e170;
        }
      }
      else {
        uVar3 = *(uint *)(param_1 + 0x80);
        *(undefined1 *)(param_1 + 0x6a) = 5;
        uVar4 = uVar3 | 2;
        *(uint *)(param_1 + 0x80) = uVar4;
        if (8000000 < param_2) {
          if (cVar1 != '\x03') {
LAB_0802cb38:
            uVar5 = 3;
LAB_0802ca58:
            *(undefined1 *)(param_1 + 0x6b) = uVar5;
            *(uint *)(param_1 + 0x80) = uVar4 | 1;
            if ((int)param_2 < 0x4c4b41) goto LAB_0802c9dc;
            goto LAB_0802ca6c;
          }
LAB_0802cb40:
          if ((int)param_2 < 0x989681) goto LAB_0802cb00;
          goto LAB_0802cb4c;
        }
        if (cVar1 != '\x02') goto LAB_0802ce68;
      }
LAB_0802cb00:
      FUN_0802e1b4(0,0x475);
      goto LAB_0802e170;
    }
    if (cVar2 == '\x04') {
      if (cVar1 == '\x02') goto LAB_0802caf4;
      *(undefined1 *)(param_1 + 0x6b) = 2;
      *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 1;
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x80);
      *(undefined1 *)(param_1 + 0x6a) = 4;
      *(uint *)(param_1 + 0x80) = uVar4 | 2;
      if (cVar1 == '\x02') {
LAB_0802caf4:
        if (7000000 < (int)param_2) goto LAB_0802cb00;
        goto LAB_0802cb98;
      }
      *(undefined1 *)(param_1 + 0x6b) = 2;
      *(uint *)(param_1 + 0x80) = uVar4 | 3;
LAB_0802cb7c:
      if ((int)param_2 < 0x4c4b41) goto LAB_0802c9dc;
    }
    if (7000000 < (int)param_2) goto LAB_0802ca6c;
  }
LAB_0802cb98:
  FUN_0802e1b4(0,0x358);
LAB_0802e170:
  _DAT_40007404 = _DAT_40007404 | 2;
  return;
}

