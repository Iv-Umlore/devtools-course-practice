//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_LINK_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_LINK_H_
#include "RootLink.h"
class Link : public RootLink {
 public:
     explicit Link(PValue pval = NULL, PRootLink pn = NULL);
     Link(const Link &Link);
     ~Link();
     virtual void SetValue(PValue pval);
     virtual PValue GetValue();
     Link* GetNexLink();
    friend class List;

 protected:
    PValue pvalue_;  //  Value
};
typedef Link *PLink;
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_LINK_H_
