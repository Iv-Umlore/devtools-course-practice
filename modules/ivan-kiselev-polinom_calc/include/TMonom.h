//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TMONOM_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TMONOM_H_
#include "TMonom.h"
#include <iostream>
class TMonom {
 protected:
int Coeff;  //  monom's coeff
int XInd;  //  index X
int YInd;  //  index Y
int ZInd;  //  index Z

 public:
TMonom(int cval = 1, int x = 0, int y = 0, int z = 0) {
Coeff = cval;
XInd = x;
YInd = y;
ZInd = z;
}
~TMonom() {}
void SetCoeff(int cval);
int  GetCoeff(void) const;
void SetIndexX(int ival);
void SetIndexY(int ival);
void SetIndexZ(int ival);
int GetIndexX(void) const;
int GetIndexY(void) const;
int GetIndexZ(void) const;
TMonom& operator=(const TMonom &tm);
TMonom operator*(const TMonom &mon);
bool operator==(const TMonom &tm) const;
bool EqualityExponent(const TMonom &tm) const;
bool operator<(const TMonom &tm) const;  //  prioritet x > y > z
bool operator>(const TMonom &tm) const;  //  prioritet x > y > z
friend std::ostream& operator<<(std::ostream &os, TMonom * tm);
friend class TPolinom;
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TMONOM_H_
