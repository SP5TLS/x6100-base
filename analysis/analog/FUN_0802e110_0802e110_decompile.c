
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802e110(uint param_1,uint *param_2)

{
  _DAT_40007400 =
       (*param_2 | param_2[1] | param_2[2] | param_2[3]) << (param_1 & 0xff) |
       _DAT_40007400 & ~(0xffe << (param_1 & 0xff));
  return;
}

