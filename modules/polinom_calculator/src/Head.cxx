//  Copyright 2017 Ivan Kiselev
#include "../include/Head.h"
Head::Head() {
    phead_ = new Link();
    phead_->SetNextLink(pfirst_);
    pstop_ = phead_;
    plast_->SetNextLink(phead_);
}

void Head::InsFirst(PValue pval) {
    List::InsFirst(pval);
    phead_->SetNextLink(pfirst_);
    if (pcurrlink_ == pfirst_->GetNexLink()) {
        pprevlink_ = pfirst_;
        currpos_ = 1;
    }
}

void Head::DelFirst(void) {
    List::DelFirst();
    phead_->SetNextLink(pfirst_);
}
