//  Copyright 2017 Ivan Kiselev
#include "../include/TDatLink.h"

TDatLink::TDatLink(PTDatValue pVal, PTRootLink pN) : TRootLink(pN) {
    pValue_ = pVal;
}

TDatLink::TDatLink(const TDatLink &Link) : TRootLink(Link.pNext_) {
    pValue_ = Link.pValue_;
}

TDatLink::~TDatLink() {}

void TDatLink::SetDatValue(PTDatValue pVal) {
    pValue_ = pVal;
}

PTDatValue TDatLink::GetDatValue() {
    return pValue_;
}

TDatLink* TDatLink::GetNextDatLink() {
    return reinterpret_cast<TDatLink*>(pNext_);
}
