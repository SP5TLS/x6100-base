
void FUN_08023d4c(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 100;
  bVar1 = false;
  do {
    if (bVar1) {
      if (DAT_2000832a == '\0') {
        return;
      }
    }
    else if (DAT_2000832a == '\0') {
      DAT_2000832a = '\x04';
      bVar1 = true;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

