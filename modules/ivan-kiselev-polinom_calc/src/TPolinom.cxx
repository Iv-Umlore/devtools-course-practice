//  Copyright 2017 Ivan Kiselev
#include "../include/TPolinoms.h"
TPolinom::TPolinom(int monoms[][4], int km) {
    TMonom* Monom = new TMonom(0, 0, 0, 0);
    pHead_->SetDatValue(Monom);
    for (int i = 0; i < km; i++) {
        Monom = new TMonom(monoms[i][0], monoms[i][1],
        monoms[i][2], monoms[i][3]);
        InsLast(Monom);
    }
    Reset();
}

TPolinom::TPolinom(TPolinom * q) {
    TMonom* Monom = new TMonom(0, 0, 0, 0);
    pHead_->SetDatValue(Monom);
    for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
        InsLast(q->GetDatValue());
    }
    pHead_->SetNextLink(pFirst);
    Reset();
    q->Reset();
}

TPolinom & TPolinom::operator+(TPolinom *q) {
    TPolinom* old = new TPolinom(q);
    Reset();
    while (!IsListEnded()) {
        old->AddMonom(GetMonom());
        GoNext();
    }
    Reset();
    q->Reset();
    old->Reset();
    return *old;
}

TPolinom & TPolinom::operator-(TPolinom *q) {
    Reset();
    while (!q->IsListEnded()) {
        SubMonom(q->GetMonom());
        q->GoNext();
    }
    Reset();
    q->Reset();
    return *this;
}

TPolinom & TPolinom::operator*(const int &mult) {
    Reset();
    while (!IsListEnded()) {
        GetMonom()->SetCoeff_(GetMonom()->Coeff_ * mult);
        GoNext();
    }
    return *this;
}

TPolinom & TPolinom::operator*(TPolinom *q) {
    TPolinom* old = new TPolinom();
    for (Reset(); !IsListEnded(); GoNext())
        for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
            TMonom* result = new TMonom(((*GetMonom()) * (*q->GetMonom())));
            old->AddMonom(result);
        }
    return *old;
}

TPolinom & TPolinom::operator=(TPolinom *q) {
        for (q->Reset(); !q->IsListEnded(); q->GoNext()) {
            InsLast(q->GetDatValue());
        }
        pHead_->SetNextLink(pFirst);
        Reset();
        q->Reset();
        return *this;
}

bool TPolinom::operator==(TPolinom *q) {
    if (pFirst == q->pFirst) return true;
    if (this->ListLen != q->ListLen) {
        return false;
    } else {
        Reset();
        q->Reset();
        while (!IsListEnded()) {
            TMonom* pMon;
            TMonom* qMon;
            pMon = GetMonom();
            qMon = q->GetMonom();
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

void TPolinom::AddMonom(TMonom * monom) {
    Reset();
    while ((!IsListEnded() && !(GetMonom()->EqualityExponent(*monom))
        && (*monom < *GetMonom()))) {
        GoNext();
    }
    if (!IsListEnded()) {
        if (GetMonom()->EqualityExponent(*monom)) {
            GetMonom()->SetCoeff_(monom->GetCoeff_() + GetMonom()->GetCoeff_());
            if (GetMonom()->GetCoeff_() == 0)
                DelCurrent();
        } else {
            InsCurrent(monom->GetCopy());
        }
    } else {
        InsLast(monom->GetCopy());
    }
    Reset();
}

void TPolinom::SubMonom(TMonom * monom) {
    Reset();
    while ((!IsListEnded() && !(GetMonom()->EqualityExponent(*monom))
        && (*monom < *GetMonom()))) {
        GoNext();
    }
    if (!IsListEnded()) {
        if (GetMonom()->EqualityExponent(*monom)) {
            GetMonom()->SetCoeff_(GetMonom()->GetCoeff_() - monom->GetCoeff_());
            if (GetMonom()->GetCoeff_() == 0)
                DelCurrent();
        } else {
            monom->Coeff_ = -monom->Coeff_;
            InsCurrent(monom->GetCopy());
        }
    } else {
        monom->Coeff_ = -monom->Coeff_;
        InsLast(monom->GetCopy());
    }
}

std::ostream& operator<<(std::ostream &os, TPolinom &q) {
    TMonom* old = new TMonom();
    for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
        old = q.GetMonom();
        os << old;
    }
    return os;
}
