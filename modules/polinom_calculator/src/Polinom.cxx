//  Copyright 2017 Ivan Kiselev
#include "../include/Polinom.h"
Polinom::Polinom(int monoms[][4], int km) {
    Monom* mon = new Monom(0, 0, 0, 0);
    phead_->SetValue(mon);
    for (int i = 0; i < km; i++) {
        mon = new Monom(monoms[i][0], monoms[i][1],
        monoms[i][2], monoms[i][3]);
        InsLast(mon);
    }
    Reset();
}

Polinom::Polinom(Polinom * q) {
    Monom* mon = new Monom(0, 0, 0, 0);
    phead_->SetValue(mon);
    for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
        InsLast(q->GetValue());
    }
    phead_->SetNextLink(pfirst_);
    Reset();
    q->Reset();
}

Polinom & Polinom::operator+(Polinom *q) {
    Polinom* old = new Polinom(q);
    Reset();
    while (!IsListEnded()) {
        old->AddMonom(GeMonom());
        GoNext();
    }
    Reset();
    q->Reset();
    old->Reset();
    return *old;
}

Polinom & Polinom::operator-(Polinom *q) {
    Reset();
    while (!q->IsListEnded()) {
        SubMonom(q->GeMonom());
        q->GoNext();
    }
    Reset();
    q->Reset();
    return *this;
}

Polinom & Polinom::operator*(const int &mult) {
    Reset();
    while (!IsListEnded()) {
        GeMonom()->SetCoeff(GeMonom()->coeff_ * mult);
        GoNext();
    }
    return *this;
}

Polinom & Polinom::operator*(Polinom *q) {
    Polinom* old = new Polinom();
    for (Reset(); !IsListEnded(); GoNext())
        for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
            Monom* result = new Monom(((*GeMonom()) * (*q->GeMonom())));
            old->AddMonom(result);
        }
    return *old;
}

Polinom & Polinom::operator=(Polinom *q) {
        for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
            InsLast(q->GetValue());
        }
        phead_->SetNextLink(pfirst_);
        Reset();
        q->Reset();
        return *this;
}

bool Polinom::operator==(Polinom *q) {
    if (pfirst_ == q->pfirst_) return true;
    if (this->listlen_ != q->listlen_) {
        return false;
    } else {
        Reset();
        q->Reset();
        while (!IsListEnded()) {
            Monom* pMon;
            Monom* qMon;
            pMon = GeMonom();
            qMon = q->GeMonom();
            if (*pMon == *qMon) {
                GoNext();
                q->GoNext();
            } else {
                return false;
            }
        }
        return true;
    }
}

void Polinom::AddMonom(Monom * monom) {
    Reset();
    while ((!IsListEnded() && !(GeMonom()->EqualityExponent(*monom))
        && (*monom < *GeMonom()))) {
        GoNext();
    }
    if (!IsListEnded()) {
        if (GeMonom()->EqualityExponent(*monom)) {
            GeMonom()->SetCoeff(monom->GetCoeff() + GeMonom()->GetCoeff());
            if (GeMonom()->GetCoeff() == 0)
                DelCurrent();
        } else {
            InsCurrent(monom->GetCopy());
        }
    } else {
        InsLast(monom->GetCopy());
    }
    Reset();
}

void Polinom::SubMonom(Monom * monom) {
    Reset();
    while ((!IsListEnded() && !(GeMonom()->EqualityExponent(*monom))
        && (*monom < *GeMonom()))) {
        GoNext();
    }
    if (!IsListEnded()) {
        if (GeMonom()->EqualityExponent(*monom)) {
            GeMonom()->SetCoeff(GeMonom()->GetCoeff() - monom->GetCoeff());
            if (GeMonom()->GetCoeff() == 0)
                DelCurrent();
        } else {
            monom->coeff_ = -monom->coeff_;
            InsCurrent(monom->GetCopy());
        }
    } else {
        monom->coeff_ = -monom->coeff_;
        InsLast(monom->GetCopy());
    }
}

std::ostream& operator<<(std::ostream &os, Polinom &q) {
    Monom* old = new Monom();
    for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
        old = q.GeMonom();
        os << old;
    }
    return os;
}
