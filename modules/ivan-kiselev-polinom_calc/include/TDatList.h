// Copyright 2017 Ivan Kiselev
#ifndef _TDatList_
#define _TDatList_
#include "TDatLink.h"
class TDatList
{
protected:
PTDatLink pFirst;
PTDatLink pLast;
PTDatLink pCurrLink;
PTDatLink pPrevLink;
PTDatLink pStop;
int CurrPos;
int ListLen;
protected:
PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL)
{
	return new TDatLink(pVal, pLink);
}
void DelLink(PTDatLink pLink);
public:
TDatList();
~TDatList() {
	DelList();
};
PTDatValue GetDatValue();
virtual int IsEmpty()  const
{
	return pFirst == pLast;
}
int GetListLength()    const { return ListLen; };
void SetCurrentPos(int pos);         
int GetCurrentPos(void) const;      
virtual void Reset(void);           
virtual bool IsListEnded(void) const; 
int GoNext(void);                 
virtual void InsFirst(PTDatValue pVal = NULL);
virtual void InsLast(PTDatValue pVal = NULL);  
virtual void InsCurrent(PTDatValue pVal = NULL);  
virtual void DelFirst(void);  
virtual void DelCurrent(void); 
virtual void DelList(void);   
};

#endif

