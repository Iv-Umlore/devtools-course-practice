//  Copyright 2017 Ivan Kiselev
#include "../include/TRootLink.h"
TRootLink::TRootLink(PTRootLink pN) {
    pNext_ = pN;
}

void TRootLink::SetNextLink(PTRootLink pLink) {
    pNext_ = pLink;
}

TRootLink::~TRootLink() {}

PTRootLink TRootLink::GetNextLink() {
    return pNext_;
}

void TRootLink::InsNextLink(PTRootLink pLink) {
    PTRootLink p = pNext_;
    pNext_ = pLink;
    if (pLink != NULL) pLink->pNext_ = p;
}
