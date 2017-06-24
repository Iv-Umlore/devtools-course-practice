//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_
#include "Link.h"
class List {
 public:
    List();
    List(const List &list);
    ~List();
    PValue GetValue();
    virtual int IsEmpty() const;
    int GetListLength() const;
    virtual void Reset(void);
    virtual bool IsListEnded(void) const;
    int GoNext(void);
    virtual void InsFirst(PValue pval = NULL);
    virtual void InsLast(PValue pval = NULL);
    virtual void InsCurrent(PValue pval = NULL);
    virtual void DelFirst(void);
    virtual void DelCurrent(void);
    virtual void DelList(void);

 protected:
    PLink pfirst_;
    PLink plast_;
    PLink pcurrlink_;
    PLink pprevlink_;
    PLink pstop_;
    int currpos_;
    int listlen_;
    PLink GetLink(PValue pval = NULL, PLink plink = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_

