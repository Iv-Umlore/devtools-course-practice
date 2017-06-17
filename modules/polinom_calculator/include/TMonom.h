//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TMONOM_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TMONOM_H_
#include "TDatValue.h"
#include <iostream>
class TMonom : public TDatValue {
 public:
    explicit TMonom(int cval = 1, int x = 0, int y = 0, int z = 0);
    ~TMonom();
    virtual TDatValue * GetCopy();
    void SetCoeff_(int cval);
    int  GetCoeff_(void);
    void SetIndexX(int ival);
    void SetIndexY(int ival);
    void SetIndexZ(int ival);
    int GetIndexX(void);
    int GetIndexY(void);
    int GetIndexZ(void);
    TMonom& operator=(const TMonom &tm);
    TMonom operator*(TMonom mon);
    bool operator==(const TMonom &tm);
    bool EqualityExponent(TMonom tm);
    bool operator<(TMonom tm);  //  prioritet x > y > z
    bool operator>(TMonom tm);  //  prioritet x > y > z
    friend std::ostream& operator<<(std::ostream &os, TMonom * tm);
    friend class TPolinom;

 protected:
    int Coeff_;  //  monom's Coeff_
    int XInd_;  //  index X
    int YInd_;  //  index Y
    int ZInd_;  //  index Z
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TMONOM_H_
