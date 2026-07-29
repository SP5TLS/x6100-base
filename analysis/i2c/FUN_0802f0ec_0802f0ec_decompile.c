
undefined4 FUN_0802f0ec(int *param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_54;
  byte local_53;
  byte local_52;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_48;
  undefined1 local_47;
  byte local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined2 local_40 [2];
  uint local_3c;
  float local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  if (param_2 < 0x84851) {
    local_28 = 0x80;
  }
  else if (param_2 < 0x19a29) {
    local_28 = 0x40;
  }
  else {
    local_28 = 0x20;
  }
  local_2c = local_28 * param_2;
  fVar4 = (float)VectorSignedToFloat(local_2c,(byte)(in_fpscr >> 0x16) & 3);
  local_14 = (uint)(5.5296e+07 / fVar4);
  if ((1 < (int)local_14) && ((local_14 & 1) != 0)) {
    local_14 = local_14 - 1;
  }
  local_30 = local_14 * local_2c;
  if (local_30 < 0x34bc001) {
    fVar4 = (float)VectorSignedToFloat(local_30,(byte)(in_fpscr >> 0x16) & 3);
    local_10 = (uint)(1.37e+08 / fVar4);
    if ((1 < (int)local_10) && ((local_10 & 1) != 0)) {
      local_10 = local_10 - 1;
    }
    if ((int)local_10 < 0x81) {
      local_34 = local_10 * local_30;
      if (local_34 < 92000000) {
        uVar3 = 0;
      }
      else if (local_34 < 0x82a7441) {
        local_38 = (float)VectorSignedToFloat(local_34,(byte)(in_fpscr >> 0x16) & 3);
        local_38 = local_38 / 2.6e+07;
        if ((63.9996 < local_38) || (local_38 < 1.0)) {
          uVar3 = 0;
        }
        else {
          uVar1 = in_fpscr & 0xfffffff | (uint)(local_38 < 1.0) << 0x1f |
                  (uint)(local_38 == 1.0) << 0x1e;
          bVar2 = (byte)(uVar1 >> 0x18);
          if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(local_38)) {
            local_24 = 4;
            local_1c = 4;
            local_20 = 0;
          }
          else {
            local_3c = (uint)local_38;
            fVar4 = (float)VectorSignedToFloat(local_3c,(byte)(uVar1 >> 0x16) & 3);
            fVar4 = local_38 - fVar4;
            if ((int)local_3c < 5) {
              local_24 = 4;
              local_38 = local_38 * 4.0;
              local_3c = (uint)local_38;
              fVar4 = (float)VectorSignedToFloat(local_3c,(byte)(uVar1 >> 0x16) & 3);
              fVar4 = local_38 - fVar4;
              local_1c = local_3c;
            }
            else {
              local_1c = local_3c & 0x3f;
              local_24 = 1;
            }
            local_c = (int)(fVar4 * 10000.0);
            if (9999 < local_c) {
              local_c = 9999;
            }
            local_20 = local_c;
          }
          local_18 = 1;
          param_1[6] = param_2;
          *param_1 = local_28;
          param_1[1] = param_2 * param_1[8] * param_1[7];
          param_1[4] = local_34;
          param_1[3] = local_34 / (int)local_10;
          param_1[2] = param_1[3] / (int)local_14;
          param_1[9] = param_1[3] / (param_1[7] * param_1[8] * param_1[6]);
          local_40[0] = 0;
          FUN_08031890(0x40005800,0x30,local_40,2,10000);
          local_48 = 4;
          local_47 = 0x40;
          local_46 = (byte)local_18 | (byte)(local_24 << 4) | 0x80;
          local_45 = (undefined1)local_1c;
          local_44 = (undefined1)((uint)local_20 >> 8);
          local_43 = 8;
          local_42 = (undefined1)local_20;
          FUN_08031890(0x40005800,0x30,&local_48,7,10000);
          local_4c = 0xd;
          local_4b = 0;
          local_4a = (undefined1)local_28;
          FUN_08031890(0x40005800,0x30,&local_4c,3,10000);
          local_50 = 0x14;
          local_4f = (undefined1)local_28;
          FUN_08031890(0x40005800,0x30,&local_50,2,10000);
          local_54 = 0xb;
          local_53 = (byte)local_10 | 0x80;
          local_52 = (byte)local_14 | 0x80;
          FUN_08031890(0x40005800,0x30,&local_54,3,10000);
          local_58 = 0x12;
          local_57 = (undefined1)local_10;
          local_56 = (undefined1)local_14;
          FUN_08031890(0x40005800,0x30,&local_58,3,10000);
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

