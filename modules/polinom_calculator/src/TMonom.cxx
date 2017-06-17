//  Copyright 2017 Ivan Kiselev
#include "../include/TMonom.h"
#include <iostream>
TMonom::TMonom(int cval, int x, int y, int z) {
    Coeff_ = cval;
    XInd_ = x;
    YInd_ = y;
    ZInd_ = z;
}

TMonom::~TMonom() {}

void TMonom::SetCoeff_(int cval) {
    Coeff_ = cval;
}

int TMonom::GetCoeff_(void) {
    return Coeff_;
}

void TMonom::SetIndexX(int ival) {
    XInd_ = ival;
}

void TMonom::SetIndexY(int ival) {
    YInd_ = ival;
}

void TMonom::SetIndexZ(int ival) {
    ZInd_ = ival;
}

int TMonom::GetIndexX(void) {
    return XInd_;
}

int TMonom::GetIndexY(void) {
    return YInd_;
}

int TMonom::GetIndexZ(void) {
    return ZInd_;
}

TMonom& TMonom::operator=(const TMonom &tm) {
    Coeff_ = tm.Coeff_;
    XInd_ = tm.XInd_;
    YInd_ = tm.YInd_;
    ZInd_ = tm.ZInd_;
    return *this;
}

std::ostream& operator<<(std::ostream &os, TMonom * tm) {
    if (tm->GetCoeff_() > 0)
        os << " + " << tm->GetCoeff_();
    else
        os << " - " << -tm->GetCoeff_();
    if (tm->GetIndexX() != 0) os << " * x^" << tm->GetIndexX();
    if (tm->GetIndexY() != 0) os << " * y^" << tm->GetIndexY();
    if (tm->GetIndexZ() != 0) os << " * z^" << tm->GetIndexZ();
    return os;
}

TMonom TMonom::operator*(TMonom mon) {
    TMonom* that = new TMonom(0, 0, 0, 0);
    that->Coeff_ = this->Coeff_ * mon.Coeff_;
    that->SetIndexX(this->GetIndexX() + mon.GetIndexX());
    that->SetIndexY(this->GetIndexY() + mon.GetIndexY());
    that->SetIndexZ(this->GetIndexZ() + mon.GetIndexZ());
    return *that;
}

bool TMonom::operator==(const TMonom &tm) {
    return ((Coeff_ == tm.Coeff_) && (XInd_ == tm.XInd_)
        && (YInd_ == tm.YInd_) && (ZInd_ == tm.ZInd_));
}

bool TMonom::EqualityExponent(TMonom tm) {
    return (XInd_ == tm.XInd_) && (YInd_ == tm.YInd_)
        && (ZInd_ == tm.ZInd_);
}

bool TMonom::operator<(TMonom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (XInd_ > tm.XInd_)
        return false;
    else if (XInd_ < tm.XInd_)
        return true;
    // XInd_ == tm.XInd_
    if (YInd_ > tm.YInd_)
        return false;
    else if (YInd_ < tm.YInd_)
        return true;
    // & YInd_ == tm.YInd_
    if (ZInd_ > tm.ZInd_)
        return false;
    return true;
}

bool TMonom::operator>(TMonom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (XInd_ < tm.XInd_)
        return false;
    else if (XInd_ > tm.XInd_)
        return true;
    // XInd_ == tm.XInd_
    if (YInd_ < tm.YInd_)
        return false;
    else if (YInd_ > tm.YInd_)
        return true;
    // & YInd_ == tm.YInd_
    if (ZInd_ < tm.ZInd_)
        return false;
    return true;
}

TDatValue* TMonom::GetCopy() {
    return new TMonom(Coeff_, XInd_, YInd_, ZInd_);
}
