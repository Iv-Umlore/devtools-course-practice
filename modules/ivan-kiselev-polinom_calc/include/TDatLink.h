//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
template <class CL>
class TDatLink
{
 protected:
CL* pValue;  //  Value
CL Value;
TDatLink<CL>* pNext;
 public:
TDatLink(CL value = nullptr,TDatLink<CL>* link = nullptr );
TDatLink(TDatLink<CL> &Link);
~TDatLink() {}
void SetValue(CL value);
CL* GetValue();
//  Work with the pointer
TDatLink<CL>* GetNextLink();
void SetNextLink(TDatLink<CL> pLink);
friend class TDatList;
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
