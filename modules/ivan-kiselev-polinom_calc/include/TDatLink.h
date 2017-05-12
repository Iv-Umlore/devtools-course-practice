//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#include "TMonom.h"
class TDatLink
{
 protected:
TMonom Value;
TMonom* that;
TDatLink* pNext;
 public:
TDatLink(TMonom* mon = new TMonom(0, 0, 0, 0) ,TDatLink* link = nullptr );
TDatLink(TDatLink &Link);
~TDatLink();
void SetValue(TMonom value);
TMonom GetValue();
//  Work with the pointer
TDatLink* GetNextLink();
void SetNextLink(TDatLink* pLink);
TMonom* GetLinkMonom();
bool operator==(TDatLink* Link);
friend class TDatList;
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
