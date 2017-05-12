//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TPOLINOMS_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TPOLINOMS_H_
#include "THeadRing.h"
#include "TMonom.h"
class TPolinom : public THeadRing {
 public:
TPolinom(int monoms[][4] = NULL, int km = 0);
//  km => kol-vo monomov
//  constructor
//  Check ReadMe
TPolinom(TPolinom *q);  // constructor
~TPolinom() {}
TMonom* GetMonom() const {		//гдеяэ
return pCurrLink->GetLinkMonom();
}
TPolinom& operator+(TPolinom q);  //  Add Polinoms
TPolinom& operator-(TPolinom q);  //  Sub Polinoms
TPolinom& operator*(TPolinom q);  //  Mult Polinoms
TPolinom& operator*(int mult);  //  Mult int
TPolinom& operator=(TPolinom q);
bool operator==(TPolinom q);
void AddMonom(TMonom* monom);  //  + Monom
void SubMonom(TMonom* monom);  //  - Monom
friend std::ostream& operator<<(std::ostream &os, TPolinom &q);
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TPOLINOMS_H_
