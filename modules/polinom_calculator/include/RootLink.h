//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_ROOTLINK_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_ROOTLINK_H_
#include "Value.h"
#include <iostream>
class RootLink;
typedef RootLink *PRootLink;
typedef Value *PValue;
class RootLink {
 public:
    ~RootLink();
    PRootLink GetNextLink();
    void SetNextLink(PRootLink plink);
    void InsNextLink(PRootLink plink);
    virtual void SetValue(PValue pval) = 0;
    virtual PValue GetValue() = 0;
    friend class List;

 protected:
    PRootLink pnext_;  //  next point
    explicit RootLink(PRootLink pn = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_ROOTLINK_H_
