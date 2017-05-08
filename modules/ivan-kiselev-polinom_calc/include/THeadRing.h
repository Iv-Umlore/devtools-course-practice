// Copyright 2017 Ivan Kiselev
#ifndef _THeadRing_
#define _THeadRing_
#include "TDatList.h"
class THeadRing : public TDatList
{
protected:
PTDatLink pHead;
public:
THeadRing();
~THeadRing();
virtual void InsFirst(PTDatValue pVal = NULL);
virtual void DelFirst(void);
};
#endif

