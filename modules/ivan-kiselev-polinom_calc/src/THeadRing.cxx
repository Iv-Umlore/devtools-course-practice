#include "../include/THeadRing.h"

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
