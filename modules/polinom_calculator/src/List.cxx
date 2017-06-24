//  Copyright 2017 Ivan Kiselev
#include "../include/List.h"
PLink List::GetLink(PValue pval, PLink plink) {
    return new Link(pval, plink);
}

PValue List::GetValue() {
    return pcurrlink_->pvalue_;
}

List::List() {
    pfirst_ = new Link(NULL, NULL);
    plast_ = pfirst_;
    pcurrlink_ = pfirst_;
    pprevlink_ = NULL;
    pstop_ = pfirst_;
    currpos_ = 0;
    listlen_ = 0;
}

List::List(const List &list) {
    int k = 1;
    pfirst_ = new Link(*list.pfirst_);
    plast_ = pfirst_;
    pcurrlink_ = pfirst_;
    pprevlink_ = NULL;
    pstop_ = pfirst_;
    currpos_ = 0;
    listlen_ = 0;
    Link * that = list.pfirst_;
    while (k < list.listlen_) {
        pcurrlink_ = new Link(*that);
        k++;
        that = that->GetNexLink();
        GoNext();
    }
    plast_ = new Link(that->GetValue(), that->pnext_);
    listlen_ = k;
}

List::~List() {
    DelList();
}

int List::IsEmpty() const {
    return pfirst_ == plast_;
}

int List::GetListLength() const {
    return listlen_;
}

void List::Reset(void) {
    pcurrlink_ = pfirst_;
    pprevlink_ = NULL;
    currpos_ = 0;
}

bool List::IsListEnded(void) const {
    return ((currpos_ >= listlen_) || (pcurrlink_ == plast_));
}

int List::GoNext(void) {
    if (IsListEnded()) return 1;
    pprevlink_ = pcurrlink_;
    pcurrlink_ = pcurrlink_->GetNexLink();
    currpos_++;
    return 0;
}

void List::InsFirst(PValue pval) {
    pfirst_ = GetLink(pval, pfirst_);
    listlen_++;
}

void List::InsLast(PValue pval) {
    if (pfirst_->pvalue_ == NULL) {
        InsFirst(pval);
    } else {
        while (GoNext() != 1) {}
        pprevlink_->SetNextLink(GetLink(pval, plast_));
        pcurrlink_ = pprevlink_->GetNexLink();
        listlen_++;
    }
}

void List::InsCurrent(PValue pval) {
    if (pprevlink_ != NULL) {
        pprevlink_->SetNextLink(GetLink(pval, pcurrlink_));
        pcurrlink_ = pprevlink_->GetNexLink();
        listlen_++;
    } else {
        InsFirst(pval);
    }
}

void List::DelFirst(void) {
    PLink old = pfirst_;
    pfirst_ = pfirst_->GetNexLink();
    listlen_--;
    old->~Link();
}

void List::DelCurrent(void) {
    if (pcurrlink_ == pfirst_) {
        DelFirst();
    } else {
        PLink old = pcurrlink_;
        pprevlink_->SetNextLink(pcurrlink_->GetNextLink());
        pcurrlink_ = pcurrlink_->GetNexLink();
        old->~Link();
        listlen_--;
    }
}

void List::DelList(void) {
    while (listlen_ > 0) DelFirst();
}
