//  Copyright 2017 Ivan Kiselev
#include "../include/TMonom.h"
#include <iostream>
void TMonom::SetCoeff(int cval) {
Coeff = cval;
}

int TMonom::GetCoeff(void) {
return Coeff;
}

void TMonom::SetIndexX(int ival) {
XInd = ival;
}

void TMonom::SetIndexY(int ival) {
YInd = ival;
}

void TMonom::SetIndexZ(int ival) {
ZInd = ival;
}

int TMonom::GetIndexX(void) {
return XInd;
}

int TMonom::GetIndexY(void) {
return YInd;
}

int TMonom::GetIndexZ(void) {
return ZInd;
}

TMonom& TMonom::operator=(const TMonom &tm) {
Coeff = tm.Coeff;
XInd = tm.XInd;
YInd = tm.YInd;
ZInd = tm.ZInd;
return *this;
}

std::ostream& operator<<(std::ostream &os, TMonom * tm) {
if (tm->GetCoeff() > 0)
os << " + " << tm->GetCoeff();
else
os << " - " << -tm->GetCoeff();
if (tm->GetIndexX() != 0) os << " * x^" << tm->GetIndexX();
if (tm->GetIndexY() != 0) os << " * y^" << tm->GetIndexY();
if (tm->GetIndexZ() != 0) os << " * z^" << tm->GetIndexZ();
return os;
}

TMonom TMonom::operator*(TMonom mon) {
TMonom* that = new TMonom(0, 0, 0, 0);
that->Coeff = this->Coeff * mon.Coeff;
that->SetIndexX(this->GetIndexX() + mon.GetIndexX());
that->SetIndexY(this->GetIndexY() + mon.GetIndexY());
that->SetIndexZ(this->GetIndexZ() + mon.GetIndexZ());
return *that;
}

bool TMonom::operator==(const TMonom &tm) {
return ((Coeff == tm.Coeff) && (XInd == tm.XInd)
&& (YInd == tm.YInd) && (ZInd == tm.ZInd));
}

bool TMonom::EqualityExponent(TMonom tm) {
return (XInd == tm.XInd) && (YInd == tm.YInd)
&& (ZInd == tm.ZInd);
}

bool TMonom::operator<(TMonom tm) {  //  prioritet x > y > z
if (EqualityExponent(tm)) return false;
if (XInd > tm.XInd)
return false;
else if (XInd < tm.XInd)
return true;
// XInd == tm.XInd
if (YInd > tm.YInd)
return false;
else if (YInd < tm.YInd)
return true;
// & YInd == tm.YInd
if (ZInd > tm.ZInd)
return false;
else if (ZInd < tm.ZInd)
return true;
return false;
}

bool TMonom::operator>(TMonom tm) {  //  prioritet x > y > z
if (EqualityExponent(tm)) return false;
if (XInd < tm.XInd)
return false;
else if (XInd > tm.XInd)
return true;
// XInd == tm.XInd
if (YInd < tm.YInd)
return false;
else if (YInd > tm.YInd)
return true;
// & YInd == tm.YInd
if (ZInd < tm.ZInd)
return false;
else if (ZInd > tm.ZInd)
return true;
return false;
}

TMonom* TMonom::GetCopy() {
return new TMonom(Coeff, XInd, YInd, ZInd);
}
