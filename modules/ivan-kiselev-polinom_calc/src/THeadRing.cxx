//  Copyright 2017 Ivan Kiselev
#include "../include/THeadRing.h"
THeadRing::THeadRing() {
pHead = new TDatLink<TMonom>();
pHead->SetNextLink(*pFirst);
pStop = pHead;
pLast->SetNextLink(*pHead);
}

void THeadRing::InsFirst(TMonom* pVal) {
TDatList::InsFirst(pVal);
pHead->SetNextLink(*pFirst);
if (pCurrLink == pFirst->GetNextLink()) {
pPrevLink = pFirst;
CurrPos = 1;
}
}

void THeadRing::DelFirst(void) {
TDatList::DelFirst();
pHead->SetNextLink(*pFirst);
}
