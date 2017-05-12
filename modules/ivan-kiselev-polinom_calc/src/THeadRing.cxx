//  Copyright 2017 Ivan Kiselev
#include "../include/THeadRing.h"
THeadRing::THeadRing() {
TMonom* Monom = new TMonom(0, 0, 0, 0);
pHead = new TDatLink(Monom,nullptr);
SetHeadPoint(*pFirst);
pStop = pHead;
pLast->SetNextLink(pHead);
}
void THeadRing::SetHeadPoint(TDatLink &link) {
	pHead->SetNextLink(&link);
}
void THeadRing::InsFirst(TMonom* pVal) {
TDatList::InsFirst(pVal);
SetHeadPoint(*pFirst);
if (pCurrLink == pFirst->GetNextLink()) {
pPrevLink = pFirst;
CurrPos = 1;
}
}

void THeadRing::DelFirst(void) {
TDatList::DelFirst();
SetHeadPoint(*pFirst);
}
