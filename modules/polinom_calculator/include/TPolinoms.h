//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TPOLINOMS_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TPOLINOMS_H_
#include "THeadRing.h"
#include "TMonom.h"
class TPolinom : public THeadRing {
 public:
    explicit TPolinom(int monoms[][4] = NULL, int km = 0);
    //  km => kol-vo monomov
    //  constructor
    //  Check ReadMe
    explicit TPolinom(TPolinom *q);  // constructor
    ~TPolinom() {}
    TMonom* GetMonom() {
        return dynamic_cast<TMonom*>(GetDatValue());
    }
    TPolinom& operator+(TPolinom *q);  //  Add Polinoms
    TPolinom& operator-(TPolinom *q);  //  Sub Polinoms
    TPolinom& operator*(TPolinom *q);  //  Mult Polinoms
    TPolinom& operator*(const int &mult);  //  Mult int
    TPolinom& operator=(TPolinom *q);
    bool operator==(TPolinom *q);
    void AddMonom(TMonom* monom);  //  + Monom
    void SubMonom(TMonom* monom);  //  - Monom
    friend std::ostream& operator<<(std::ostream &os, TPolinom &q);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TPOLINOMS_H_
