//  Copyright 2017 Ivan Kiselev
#include "../include/RootLink.h"
RootLink::RootLink(PRootLink pn) {
    pnext_ = pn;
}

void RootLink::SetNextLink(PRootLink plink) {
    pnext_ = plink;
}

RootLink::~RootLink() {}

PRootLink RootLink::GetNextLink() {
    return pnext_;
}

void RootLink::InsNextLink(PRootLink plink) {
    PRootLink p = pnext_;
    pnext_ = plink;
    if (plink != NULL) plink->pnext_ = p;
}
