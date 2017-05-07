// Copyright 2017 Ivan Kiselev

#ifndef _THeadRing_
#define _THeadRing_

#include "TDatList.h"

class THeadRing : public TDatList 
{
protected:
	PTDatLink pHead;     // заголовок, pFirst - звено за pHead
public:
	THeadRing();
	~THeadRing();
	// вставка звеньев
	virtual void InsFirst(PTDatValue pVal = NULL); // после заголовка
												   // удаление звеньев
	virtual void DelFirst(void);                 // удалить первое звено
};

#endif

