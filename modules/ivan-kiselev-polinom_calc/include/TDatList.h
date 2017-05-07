// Copyright 2017 Ivan Kiselev

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
		return pFirst == pLast; 
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

#endif

