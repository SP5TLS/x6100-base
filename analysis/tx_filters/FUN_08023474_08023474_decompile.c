
void FUN_08023474(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 0x69;
  *param_1 = 0;
  FUN_08034a6c(0,puVar2,0x65);
  puVar1 = param_1 + 4;
  FUN_08034a6c(0,param_1 + 0xce,100);
  FUN_08034aa8(param_2,puVar1,0x65);
  param_1[2] = puVar2;
  param_1[3] = puVar1;
  *(undefined2 *)(param_1 + 1) = 0x65;
  FUN_0803579c(param_1 + 1,0x65,puVar1,puVar2,1);
  return;
}

