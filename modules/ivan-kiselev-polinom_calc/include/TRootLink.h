//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TROOTLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TROOTLINK_H_
#include "TDatValue.h"
#include <iostream>
class TRootLink;
typedef TRootLink *PTRootLink;
typedef TDatValue *PTDatValue;
class TRootLink {
 protected:
    PTRootLink pNext_;  //  next point
    explicit TRootLink(PTRootLink pN = NULL);

 public:
    ~TRootLink();
    PTRootLink GetNextLink();
    void SetNextLink(PTRootLink pLink);
    void InsNextLink(PTRootLink pLink);
    virtual void SetDatValue(PTDatValue pVal) = 0;
    virtual PTDatValue GetDatValue() = 0;
    friend class TDatList;
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TROOTLINK_H_
