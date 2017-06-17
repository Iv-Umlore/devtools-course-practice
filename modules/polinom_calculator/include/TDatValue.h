//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TDATVALUE_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TDATVALUE_H_
class TDatValue {
 protected:
    virtual TDatValue * GetCopy() = 0;  //  copia
};

#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TDATVALUE_H_
