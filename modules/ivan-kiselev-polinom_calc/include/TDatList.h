//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLIST_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLIST_H_
#include "TDatLink.h"
#include "TMonom.h"
class TDatList{
 protected:
TDatLink* pFirst;
TDatLink* pLast;
TDatLink* pCurrLink;
TDatLink* pPrevLink;
TDatLink* pStop;
int CurrPos;
int ListLen;
TDatLink* GetLink(TMonom pVal, TDatLink* pNext);
 public:
TDatList();
~TDatList() {
DelList();
}
TMonom* GeTMonom();
virtual int IsEmpty() const {
return pFirst == pLast;
}
int GetListLength() const {
return ListLen;
}
virtual void Reset(void);
virtual bool IsListEnded(void) const;
int GoNext(void);
virtual void InsFirst(TMonom* pVal = NULL);
virtual void InsLast(TMonom* pVal = NULL);
virtual void InsCurrent(TMonom* pVal = NULL);
virtual void DelFirst(void);
virtual void DelCurrent(void);
virtual void DelList(void);
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLIST_H_

