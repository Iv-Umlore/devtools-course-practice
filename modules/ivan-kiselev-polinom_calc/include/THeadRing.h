//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_
#include "TDatList.h"
class THeadRing : public TDatList{
 protected:
TDatLink* pHead;
 public:
THeadRing();
~THeadRing() {}
virtual void InsFirst(TMonom* pVal = NULL);
virtual void DelFirst(void);
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_

