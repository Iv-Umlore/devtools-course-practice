//������ ������ ����������� ������� � ����������


#ifndef _THeadRing_
#define _THeadRing_

#include "TDatList.h"

class THeadRing : public TDatList 
{
protected:
	PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = NULL); // ����� ���������
												   // �������� �������
	virtual void DelFirst(void);                 // ������� ������ �����
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
}				//�������� ������

void THeadRing::DelFirst(void) // ������� ������ �����
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}

#endif

