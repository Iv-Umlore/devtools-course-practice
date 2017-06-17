//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
#include "TRootLink.h"
class TDatLink : public TRootLink {
 public:
     explicit TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL);
     TDatLink(const TDatLink &Link);
     ~TDatLink();
     virtual void SetDatValue(PTDatValue pVal);
     virtual PTDatValue GetDatValue();
     TDatLink* GetNextDatLink();
    friend class TDatList;

 protected:
    PTDatValue pValue_;  //  Value
};
typedef TDatLink *PTDatLink;
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
