// Copyright 2017 Ivan Kiselev

#ifndef _TDatLink_
#define _TDatLink_
#include "TRootLink.h"
class TDatLink;
typedef TDatLink *PTDatLink;
class TDatLink : public TRootLink {
protected:
PTDatValue pValue;  // Value
public:
TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :TRootLink(pN)
{
	pValue = pVal;
}
~TDatLink() { };
void  SetDatValue(PTDatValue pVal)
{
	pValue = pVal;
}
PTDatValue GetDatValue()
{
	return  pValue;
}
PTDatLink GetNextDatLink()
{
	return (PTDatLink)pNext;
}
friend class TDatList;
};
#endif
