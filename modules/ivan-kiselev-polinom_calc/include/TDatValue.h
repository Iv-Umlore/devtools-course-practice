//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATVALUE_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATVALUE_H_
class TDatValue {
 public:
virtual TDatValue * GetCopy() = 0;  //  copia
~TDatValue() {}
};

#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATVALUE_H_
