//Модуль класса линейных списков

#ifndef _TDatList_
#define _TDatList_

#include "TDatLink.h"

class TDatList
{
protected:
	PTDatLink pFirst;    // первое звено
	PTDatLink pLast;     // последнее звено
	PTDatLink pCurrLink; // текущее звено
	PTDatLink pPrevLink; // звено перед текущим
	PTDatLink pStop;     // значение указателя, означающего конец списка 
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке
protected:  // методы
	PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL)
	{
		return new TDatLink(pVal, pLink);
	}

	void DelLink(PTDatLink pLink);   // удаление звена
public:
	TDatList();
	~TDatList() { 
		DelList();
	};
	// доступ
	PTDatValue GetDatValue(); // значение
	virtual int IsEmpty()  const 
	{ 
		return pFirst == pStop; 
	} // список пуст ?
	int GetListLength()    const { return ListLen; }       // к-во звеньев
	// навигация
	void SetCurrentPos(int pos);          // установить текущее звено
	int GetCurrentPos(void) const;       // получить номер тек. звена
	virtual void Reset(void);             // установить на начало списка
	virtual bool IsListEnded(void) const; // список завершен ?
	int GoNext(void);                    // сдвиг вправо текущего звена
										 // (=1 после применения GoNext для последнего звена списка)
	// вставка звеньев
	virtual void InsFirst(PTDatValue pVal = NULL); // перед первым
	virtual void InsLast(PTDatValue pVal = NULL); // вставить последним 
	virtual void InsCurrent(PTDatValue pVal = NULL); // перед текущим 
	// удаление звеньев
	virtual void DelFirst(void);    // удалить первое звено 
	virtual void DelCurrent(void);    // удалить текущее звено 
	virtual void DelList(void);    // удалить весь список


};


void TDatList::DelLink(PTDatLink pLink)		
{
	PTDatLink that = pCurrLink;
	pPrevLink->SetNextLink(pCurrLink->pNext);
	pCurrLink = pCurrLink->GetNextDatLink();
	that->~TDatLink();
	ListLen--;
}

PTDatValue TDatList::GetDatValue()
{
	return pCurrLink->pValue;
}

TDatList::TDatList()			//конструктор
{
	pFirst = new TDatLink(NULL, NULL);// первое звено
	pLast=pFirst;     // последнее звено
	pCurrLink=pFirst; // текущее звено
	pPrevLink=NULL; // звено перед текущим
	pStop=pFirst;     // значение указателя, означающего конец списка 
	CurrPos=0;         // номер текущего звена (нумерация от 0)
	ListLen=0;         // количество звеньев в списке
}

void TDatList::SetCurrentPos(int pos) 
{
	if ((pos-1 < 0) || (pos-1 > ListLen)) throw 2;	
	Reset();
	while (CurrPos < pos-1)
	{
		GoNext();
	}
}  // установить текущее звено

int TDatList::GetCurrentPos(void) const 
{
	return CurrPos;
}     // получить номер тек. звена

void TDatList::Reset(void) 
{
	pCurrLink = pFirst;
	pPrevLink = NULL;
	CurrPos = 0;
}     // установить на начало списка

bool TDatList::IsListEnded(void) const 
{
	return ((CurrPos >= ListLen) || (pCurrLink == pLast));
} // список завершен ?

int TDatList::GoNext(void) 
{	
	if (IsListEnded()) return 1;
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;	
	return 0;
}                    // сдвиг вправо текущего звена
// (=1 после применения GoNext для последнего звена списка)


void TDatList::InsFirst(PTDatValue pVal) 
{
	pFirst = GetLink(pVal,pFirst);
	ListLen++;
} // перед первым

void TDatList::InsLast(PTDatValue pVal)		// в пизду
{
	if (pFirst->pValue == NULL)
	{
		InsFirst(pVal);
	}
	else
	{
		while (GoNext() != 1);
		pPrevLink->SetNextLink(GetLink(pVal, pLast));
		pCurrLink = pPrevLink->GetNextDatLink();
		ListLen++;
	}
	
} // вставить последним

void TDatList::InsCurrent(PTDatValue pVal) 
{
	if (pPrevLink != NULL)
	{
		pPrevLink->SetNextLink(GetLink(pVal, pCurrLink));
		pCurrLink = pPrevLink->GetNextDatLink();
		ListLen++;
	}
	else InsFirst(pVal);
} // перед текущим 

void TDatList::DelFirst(void)
{
	while (ListLen>0)
	{
	PTDatLink old = pFirst;
	pFirst = pFirst->GetNextDatLink();
	ListLen--;
	}
}    // удалить первое звено 

void TDatList::DelCurrent(void)
{
	if (pCurrLink == pFirst)
	{
		DelFirst();
	}
	else {
		PTDatLink old = pCurrLink;
		pPrevLink->SetNextLink(pCurrLink->GetNextLink());
		pCurrLink = pCurrLink->GetNextDatLink();
		old->~TDatLink();
		ListLen--;
	}
}	// удалить текущее звено 

void TDatList::DelList(void)   
{
	while (ListLen > 0) DelFirst();
}	 // удалить весь список


#endif

