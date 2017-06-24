//  Copyright 2017 Ivan Kiselev
#include "../include/Monom.h"
#include <iostream>
Monom::Monom(int cval, int x, int y, int z) {
    coeff_ = cval;
    x_ind_ = x;
    y_ind_ = y;
    z_ind_ = z;
}

Monom::~Monom() {}

void Monom::SetCoeff(int cval) {
    coeff_ = cval;
}

int Monom::GetCoeff(void) {
    return coeff_;
}

void Monom::SetIndexX(int ival) {
    x_ind_ = ival;
}

void Monom::SetIndexY(int ival) {
    y_ind_ = ival;
}

void Monom::SetIndexZ(int ival) {
    z_ind_ = ival;
}

int Monom::GetIndexX(void) {
    return x_ind_;
}

int Monom::GetIndexY(void) {
    return y_ind_;
}

int Monom::GetIndexZ(void) {
    return z_ind_;
}

Monom& Monom::operator=(const Monom &tm) {
    coeff_ = tm.coeff_;
    x_ind_ = tm.x_ind_;
    y_ind_ = tm.y_ind_;
    z_ind_ = tm.z_ind_;
    return *this;
}

std::ostream& operator<<(std::ostream &os, Monom * tm) {
    if (tm->GetCoeff() > 0)
        os << " + " << tm->GetCoeff();
    else
        os << " - " << -tm->GetCoeff();
    if (tm->GetIndexX() != 0) os << " * x^" << tm->GetIndexX();
    if (tm->GetIndexY() != 0) os << " * y^" << tm->GetIndexY();
    if (tm->GetIndexZ() != 0) os << " * z^" << tm->GetIndexZ();
    return os;
}

Monom Monom::operator*(Monom mon) {
    Monom* that = new Monom(0, 0, 0, 0);
    that->coeff_ = this->coeff_ * mon.coeff_;
    that->SetIndexX(this->GetIndexX() + mon.GetIndexX());
    that->SetIndexY(this->GetIndexY() + mon.GetIndexY());
    that->SetIndexZ(this->GetIndexZ() + mon.GetIndexZ());
    return *that;
}

bool Monom::operator==(const Monom &tm) {
    return ((coeff_ == tm.coeff_) && (x_ind_ == tm.x_ind_)
        && (y_ind_ == tm.y_ind_) && (z_ind_ == tm.z_ind_));
}

bool Monom::EqualityExponent(Monom tm) {
    return (x_ind_ == tm.x_ind_) && (y_ind_ == tm.y_ind_)
        && (z_ind_ == tm.z_ind_);
}

bool Monom::operator<(Monom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (x_ind_ > tm.x_ind_)
        return false;
    else if (x_ind_ < tm.x_ind_)
        return true;
    // x_ind_ == tm.x_ind_
    if (y_ind_ > tm.y_ind_)
        return false;
    else if (y_ind_ < tm.y_ind_)
        return true;
    // & y_ind__ == tm.y_ind__
    if (z_ind_ > tm.z_ind_)
        return false;
    return true;
}

bool Monom::operator>(Monom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (x_ind_ < tm.x_ind_)
        return false;
    else if (x_ind_ > tm.x_ind_)
        return true;
    // x_ind_ == tm.x_ind_
    if (y_ind_ < tm.y_ind_)
        return false;
    else if (y_ind_ > tm.y_ind_)
        return true;
    // & y_ind__ == tm.y_ind__
    if (z_ind_ < tm.z_ind_)
        return false;
    return true;
}

Value* Monom::GetCopy() {
    return new Monom(coeff_, x_ind_, y_ind_, z_ind_);
}
