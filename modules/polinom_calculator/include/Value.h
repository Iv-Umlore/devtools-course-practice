//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_VALUE_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_VALUE_H_

class Value {
 protected:
    virtual Value * GetCopy() = 0;
};

#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_VALUE_H_
