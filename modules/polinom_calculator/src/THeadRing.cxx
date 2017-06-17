//  Copyright 2017 Ivan Kiselev
#include "../include/THeadRing.h"
THeadRing::THeadRing() {
    pHead_ = new TDatLink();
    pHead_->SetNextLink(pFirst);
    pStop = pHead_;
    pLast->SetNextLink(pHead_);
}

void THeadRing::InsFirst(PTDatValue pVal) {
    TDatList::InsFirst(pVal);
    pHead_->SetNextLink(pFirst);
    if (pCurrLink == pFirst->GetNextDatLink()) {
        pPrevLink = pFirst;
        CurrPos = 1;
    }
}

void THeadRing::DelFirst(void) {
    TDatList::DelFirst();
    pHead_->SetNextLink(pFirst);
}
