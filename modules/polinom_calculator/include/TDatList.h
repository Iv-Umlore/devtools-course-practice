//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_
#include "TDatLink.h"
class TDatList {
 public:
    TDatList();
    TDatList(const TDatList &list);
    ~TDatList();
    PTDatValue GetDatValue();
    virtual int IsEmpty() const;
    int GetListLength() const;
    virtual void Reset(void);
    virtual bool IsListEnded(void) const;
    int GoNext(void);
    virtual void InsFirst(PTDatValue pVal = NULL);
    virtual void InsLast(PTDatValue pVal = NULL);
    virtual void InsCurrent(PTDatValue pVal = NULL);
    virtual void DelFirst(void);
    virtual void DelCurrent(void);
    virtual void DelList(void);

 protected:
    PTDatLink pFirst;
    PTDatLink pLast;
    PTDatLink pCurrLink;
    PTDatLink pPrevLink;
    PTDatLink pStop;
    int CurrPos;
    int ListLen;
    PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_

