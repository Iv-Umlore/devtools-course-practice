//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
#include "Value.h"
#include <iostream>

class Monom : public Value {
 public:
    explicit Monom(int cval = 1, int x = 0, int y = 0, int z = 0);
    ~Monom();
    virtual Value * GetCopy();
    void SetCoeff(int cval);
    int  GetCoeff(void);
    void SetIndexX(int ival);
    void SetIndexY(int ival);
    void SetIndexZ(int ival);
    int GetIndexX(void);
    int GetIndexY(void);
    int GetIndexZ(void);
    Monom& operator=(const Monom &tm);
    Monom operator*(Monom mon);
    bool operator==(const Monom &tm);
    bool EqualityExponent(Monom tm);
    bool operator<(Monom tm);  //  prioritet x > y > z
    bool operator>(Monom tm);  //  prioritet x > y > z
    friend std::ostream& operator<<(std::ostream &os, Monom * tm);
    friend class Polinom;

 protected:
    int coeff_;  //  monom's coeff_
    int x_ind_;  //  index X
    int y_ind_;  //  index Y
    int z_ind_;  //  index Z
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
