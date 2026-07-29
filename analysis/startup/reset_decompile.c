
void FUN_08034a18(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar3 = DAT_08034a5c;
  uVar2 = DAT_08034a58;
  iVar1 = DAT_08034a54;
  for (iVar6 = 0; puVar4 = DAT_08034a64, puVar5 = DAT_08034a60, (uint)(iVar1 + iVar6) < uVar2;
      iVar6 = iVar6 + 4) {
    *(undefined4 *)(iVar1 + iVar6) = *(undefined4 *)(iVar3 + iVar6);
  }
  for (; puVar5 < puVar4; puVar5 = puVar5 + 1) {
    *puVar5 = 0;
  }
  FUN_0803485c();
  FUN_08037ed0();
  FUN_08034178();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

