
void phase_6(char *szInput)

{
  int *piVar1;
  Node *pSuccNode;
  Node *pPrevNode;
  Node *pNodeToRecord;
  Node *pNode;
  int iVar2;
  long nAddrOffset;
  int nCounter;
  int *piVar3;
  int pnInputNums [6];
  int local_60 [2];
  Node *ppNodes [6];
  Node *pTemp;
  
  piVar3 = pnInputNums;
  piVar1 = pnInputNums;
  read_six_numbers(szInput,pnInputNums);
  nCounter = 0;
  while( true ) {
    if (5 < *piVar3 - 1U) {
      explode_bomb();
    }
    nCounter = nCounter + 1;
    iVar2 = nCounter;
    if (nCounter == 6) break;
    do {
      if (*piVar3 == pnInputNums[iVar2]) {
        explode_bomb();
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
    piVar3 = piVar3 + 1;
  }
  do {
    *piVar1 = 7 - *piVar1;
    piVar1 = piVar1 + 1;
  } while (piVar1 != local_60);
  nAddrOffset = 0;
  do {
    if (*(int *)((long)pnInputNums + nAddrOffset) < 2) {
      pNodeToRecord = &g_FirstNode;
    }
    else {
      nCounter = 1;
      pNode = &g_FirstNode;
      do {
        pNode = pNode->next;
        nCounter = nCounter + 1;
        pNodeToRecord = pNode;
      } while (nCounter != *(int *)((long)pnInputNums + nAddrOffset));
    }
    *(Node **)((long)ppNodes + nAddrOffset * 2) = pNodeToRecord;
    nAddrOffset = nAddrOffset + 4;
  } while (nAddrOffset != 0x18);
  pSuccNode = ppNodes[1];
  pPrevNode = ppNodes[0];
  do {
    pTemp = pSuccNode;
    pPrevNode->next = pTemp;
    pSuccNode = pSuccNode->next;
    pPrevNode = pTemp;
  } while (pSuccNode != (Node *)&stack0xffffffffffffffd8);
  pTemp->next = (Node *)0x0;
  nCounter = 5;
  do {
    if (*(int *)&ppNodes[0]->val < *(int *)&ppNodes[0]->next->val) {
      explode_bomb();
    }
    ppNodes[0] = ppNodes[0]->next;
    nCounter = nCounter + -1;
  } while (nCounter != 0);
  return;
}

