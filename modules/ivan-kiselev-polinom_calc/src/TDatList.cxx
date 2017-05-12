//  Copyright 2017 Ivan Kiselev
#include "../include/TDatList.h"
TMonom* TDatList::GeTMonom() {
return pCurrLink->GetLinkMonom();
}

TDatLink* TDatList::GetLink(TMonom &pVal, TDatLink* pNext) {
	TDatLink* that = new TDatLink(&pVal, pNext);
	return that;
}

TDatList::TDatList() {
pFirst = new TDatLink();
pLast = pFirst;
pCurrLink = pFirst;
pPrevLink = NULL;
pStop = pFirst;
CurrPos = 0;
ListLen = 0;
}

void TDatList::Reset(void) {
pCurrLink = pFirst;
pPrevLink = NULL;
CurrPos = 0;
}

bool TDatList::IsListEnded(void) const {
return ((CurrPos >= ListLen) || (pCurrLink == pLast));
}

int TDatList::GoNext(void) {
if (IsListEnded()) return 1;
pPrevLink = pCurrLink;
pCurrLink = pCurrLink->GetNextLink();
CurrPos++;
return 0;
}

void TDatList::InsFirst(TMonom* pVal) {
pFirst = GetLink(*pVal, pFirst);
ListLen++;
}

void TDatList::InsLast(TMonom* pVal) {
TMonom zero(0, 0, 0, 0);
if (pFirst->GetValue() == zero) {
InsFirst(pVal);
} else {
while (GoNext() != 1) {}
pPrevLink->SetNextLink(GetLink(*pVal, pLast));
pCurrLink = pPrevLink->GetNextLink();
ListLen++;
}
}

void TDatList::InsCurrent(TMonom* pVal) {
if (pPrevLink != NULL) {
pPrevLink->SetNextLink(GetLink(*pVal, pCurrLink));
pCurrLink = pPrevLink->GetNextLink();
ListLen++;
} else {
InsFirst(pVal);
}
}

void TDatList::DelFirst(void) {
TDatLink* old = pFirst;
pFirst = pFirst->GetNextLink();
ListLen--;
old->~TDatLink();
}

void TDatList::DelCurrent(void) {
if (pCurrLink == pFirst) {
DelFirst();
} else {
TDatLink* old = pCurrLink;
pPrevLink->SetNextLink(pCurrLink->GetNextLink());
pCurrLink = pCurrLink->GetNextLink();
old->~TDatLink();
ListLen--;
}
}

void TDatList::DelList(void) {
while (ListLen > 0) DelFirst();
}
