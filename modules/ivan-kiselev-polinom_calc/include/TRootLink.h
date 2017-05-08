// Copyright 2017 Ivan Kiselev

#ifndef _TRootLink_
#define _TRootLink_

#include "TDatValue.h"

class TRootLink;
typedef TRootLink *PTRootLink;
typedef TDatValue *PTDatValue;

class TRootLink {
protected:
	PTRootLink  pNext;  // next point
public:
	TRootLink(PTRootLink pN = NULL) 
	{
		pNext = pN; 
	}
	
	~TRootLink() { };

	PTRootLink  GetNextLink() 
	{
		return  pNext; 
	}

	void SetNextLink(PTRootLink pLink) {
		pNext = pLink; 
	}

	void InsNextLink(PTRootLink  pLink) 
	{
		PTRootLink p = pNext;
		pNext = pLink;
		if (pLink != NULL) pLink->pNext = p;
	}
	virtual void       SetDatValue(PTDatValue pVal) = 0;
	virtual PTDatValue GetDatValue() = 0;

	friend class TDatList;
};

#endif
