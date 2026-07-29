
void FUN_0802145c(int *param_1)

{
  int iVar1;
  
  if ((char)param_1[2] != '\0') {
    *(undefined1 *)(param_1 + 2) = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[0xe] = 0;
    *(undefined1 *)((int)param_1 + 0xe) = 0;
    *(undefined1 *)((int)param_1 + 9) = 0;
    *(undefined1 *)((int)param_1 + 10) = 0;
    param_1[8] = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    param_1[0xd] = 0;
  }
  if (*param_1 == 0) {
    param_1[0xe] = 0;
  }
  else {
    iVar1 = (*(code *)*param_1)();
    param_1[0xe] = iVar1;
    if ((char)param_1[3] == '\x02') {
      param_1[0xe] = (param_1[0xe] & 1U) << 1 | (uint)param_1[0xe] >> 1 & 1 | param_1[0xe] & 4U;
    }
  }
  if ((param_1[0xe] & 4U) == 0) {
    if (((param_1[0xe] & 1U) != 0) || ((param_1[0xe] & 2U) != 0)) {
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 4) = 1;
  }
  if (((char)param_1[3] == '\0') || ((char)param_1[4] != '\0')) {
    param_1[5] = 0;
    param_1[6] = 0;
    if ((((param_1[0xe] & 4U) == 0) && ((param_1[0xe] & 1U) == 0)) && ((param_1[0xe] & 2U) == 0)) {
      *(undefined1 *)((int)param_1 + 9) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 9) = 1;
    }
  }
  else {
    if ((*(char *)((int)param_1 + 0xd) == '\x01') &&
       (((param_1[5] != 0 && (param_1[0xe] != 0)) && (*(char *)((int)param_1 + 0xe) == '\0')))) {
      if ((param_1[0xd] == 1) && ((param_1[0xe] & 2U) != 0)) {
        *(undefined1 *)((int)param_1 + 0xe) = 1;
        param_1[0xd] = 2;
      }
      else if ((param_1[0xd] == 2) && ((param_1[0xe] & 1U) != 0)) {
        *(undefined1 *)((int)param_1 + 0xe) = 1;
        param_1[0xd] = 1;
      }
    }
    if ((param_1[5] == 0) && (param_1[6] == 0)) {
      if (*(char *)((int)param_1 + 0xe) == '\0') {
        if (param_1[0xe] == 3) {
          if (param_1[0xd] == 1) {
            param_1[0xd] = 2;
          }
          else {
            param_1[0xd] = 1;
          }
        }
        else if (param_1[0xe] == 1) {
          param_1[0xd] = 1;
        }
        else if (param_1[0xe] == 2) {
          param_1[0xd] = 2;
        }
        else {
          param_1[0xd] = 0;
        }
      }
      if (param_1[0xd] == 1) {
        param_1[6] = (int)(float)param_1[9];
        param_1[5] = param_1[6];
      }
      else if (param_1[0xd] == 2) {
        param_1[6] = (int)(float)param_1[9];
        param_1[5] = (int)((float)param_1[9] * (float)param_1[10]);
      }
      *(undefined1 *)((int)param_1 + 0xe) = 0;
    }
    if (param_1[5] < 1) {
      if (0 < param_1[6]) {
        *(undefined1 *)((int)param_1 + 9) = 0;
        param_1[6] = param_1[6] + -1;
      }
    }
    else {
      *(undefined1 *)((int)param_1 + 9) = 1;
      param_1[5] = param_1[5] + -1;
    }
  }
  if (*(char *)((int)param_1 + 9) == '\x01') {
    param_1[8] = param_1[7];
    if (*(char *)((int)param_1 + 0xb) != '\0') {
      *(undefined1 *)((int)param_1 + 10) = 1;
    }
  }
  else if (((param_1[5] == 0) && (param_1[6] == 0)) && (param_1[0xe] == 0)) {
    if (param_1[8] < 1) {
      *(undefined1 *)((int)param_1 + 10) = 0;
    }
    else {
      param_1[8] = param_1[8] + -1;
    }
  }
  if (*(char *)((int)param_1 + 0xf) != '\0') {
    *(undefined1 *)((int)param_1 + 10) = 0;
  }
  if (param_1[1] != 0) {
    (*(code *)param_1[1])(*(undefined1 *)((int)param_1 + 9),*(undefined1 *)((int)param_1 + 10));
  }
  return;
}

