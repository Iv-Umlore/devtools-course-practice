//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_HEAD_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_HEAD_H_
#include "List.h"

class Head : public List {
 public:
    Head();
    virtual void InsFirst(PValue pval = NULL);
    virtual void DelFirst(void);

 protected:
    PLink phead_;
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_HEAD_H_

