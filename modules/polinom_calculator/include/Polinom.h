//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_POLINOM_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_POLINOM_H_
#include "Head.h"
#include "Monom.h"
class Polinom : public Head {
 public:
    explicit Polinom(int monoms[][4] = NULL, int km = 0);
    //  km => kol-vo monomov
    //  constructor
    //  Check ReadMe
    explicit Polinom(Polinom *q);  // constructor
    ~Polinom() {}
    Monom* GeMonom() {
        return dynamic_cast<Monom*>(GetValue());
    }
    Polinom& operator+(Polinom *q);  //  Add Polinoms
    Polinom& operator-(Polinom *q);  //  Sub Polinoms
    Polinom& operator*(Polinom *q);  //  Mult Polinoms
    Polinom& operator*(const int &mult);  //  Mult int
    Polinom& operator=(Polinom *q);
    bool operator==(Polinom *q);
    void AddMonom(Monom* monom);  //  + Monom
    void SubMonom(Monom* monom);  //  - Monom
    friend std::ostream& operator<<(std::ostream &os, Polinom &q);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_POLINOM_H_
