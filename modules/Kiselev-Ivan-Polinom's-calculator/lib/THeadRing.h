//Модуль класса циклических списков с заголовком


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


THeadRing::THeadRing()
{
	pHead = new TDatLink();
	pHead->SetNextLink(pFirst);
	pStop = pHead;
	pLast->SetNextLink(pHead);
}

/*-------------------------------------------*/

THeadRing::~THeadRing()
{
	delete pHead;
}

void THeadRing::InsFirst(PTDatValue pVal)	//+
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
	if (pCurrLink == pFirst->GetNextDatLink())
	{
		pPrevLink = pFirst;
		CurrPos = 1;
	}
}				//добавить первым

void THeadRing::DelFirst(void) // удалить первое звено
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}

#endif

