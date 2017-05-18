//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#include "TRootLink.h"
class TDatLink : public TRootLink {
 protected:
    PTDatValue pValue_;  //  Value
 public:
     explicit TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL);
     TDatLink(const TDatLink &Link);
     ~TDatLink();
     virtual void SetDatValue(PTDatValue pVal);
     virtual PTDatValue GetDatValue();
     TDatLink* GetNextDatLink();
    friend class TDatList;
};
typedef TDatLink *PTDatLink;
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
