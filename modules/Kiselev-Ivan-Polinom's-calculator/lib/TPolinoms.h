//Модуль класса полиномов
#ifndef _TPolinoms_
#define _TPolinoms_


#include "THeadRing.h"
#include "TMonom.h"

typedef TMonom* PTMonom;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][4] = NULL, int km = 0);
	 //km => количесво мономом, ну и дерьмо
	 // конструктор
	 // полинома из массива «коэффициент-индекс»

	TPolinom (TPolinom &q);     // конструктор копирования
	~TPolinom() {};
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }

	TPolinom& operator+(TPolinom &q); // сложение полиномов
	TPolinom& operator-(TPolinom &q); // вычитание полиномов
	TPolinom& operator*(TPolinom &q); // умножение полиномов
	TPolinom& operator=(TPolinom &q); // присваивание
	bool operator==(TPolinom &q);				   //дополнительные функции

	friend ostream& operator<<(ostream &os, TPolinom &q);
	void AddMonom(TMonom* monom);		// добавить к полиному Моном
	void SubMonom(TMonom* monom);		// вычесть из Полинома Моном
};

TPolinom::TPolinom(int monoms[][4], int km)
{
	
	PTMonom Monom = new TMonom(0, 0, 0, 0);
	pHead->SetDatValue(Monom);
	for (int i = 0; i < km; i++)
	{
		Monom = new TMonom(monoms[i][0], monoms[i][1], monoms[i][2] , monoms[i][3]);
		InsLast(Monom);
	}
	Reset();
}

TPolinom::TPolinom(TPolinom & q)
{
		PTMonom Monom = new TMonom(0, 0, 0, 0);
		pHead->SetDatValue(Monom);
		for (q.Reset();!q.IsListEnded(); q.GoNext())
		{
			InsLast(q.GetDatValue());
		}
		pHead->SetNextLink(pFirst);
		Reset();
		q.Reset();
}

TPolinom & TPolinom::operator+(TPolinom & q)
{
	TPolinom* old = new TPolinom(q);
	Reset();
	while (!IsListEnded())
	{
		old->AddMonom(GetMonom());
		GoNext();
	}
	Reset();
	q.Reset();
	old->Reset();
	return *old;
}

TPolinom & TPolinom::operator-(TPolinom & q)
{
	TPolinom* old = new TPolinom(q);
	Reset();
	while (!IsListEnded())
	{
		old->SubMonom(GetMonom());
		GoNext();
	}
	Reset();
	q.Reset();
	old->Reset();
	return *old;
}

/*TPolinom & TPolinom::operator*(TPolinom & q)
{
	TPolinom* old = new TPolinom(q);
	Reset();
	while (!IsListEnded())
	{
		old->AddMonom(GetMonom());
		GoNext();
	}
	Reset();
	q.Reset();
	old->Reset();
	return *old;
}*/

TPolinom & TPolinom::operator=(TPolinom & q)
{
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		InsLast(q.GetDatValue());
	}
	pHead->SetNextLink(pFirst);
	Reset();
	q.Reset();
	return *this;
}

bool TPolinom::operator==( TPolinom &q)
{
	if (pFirst == q.pFirst) return true;
	if (this->ListLen != q.ListLen)
		return false;
	else
	{
		PTMonom pMon, qMon;
		Reset(); 
		q.Reset();
		while (!IsListEnded())
		{
			pMon = GetMonom();				
			qMon = q.GetMonom();			
			if (*pMon == *qMon)
			{
				GoNext(); 
				q.GoNext();
			}
			else
				return false;
		}
		return true;
	}
}

void TPolinom::AddMonom(TMonom * monom)		
{
 	Reset();
	while ((!IsListEnded() && !(GetMonom()->EqualityExponent(*monom)) && (*monom < *GetMonom())) )
	{
		GoNext();
	}

	if (!IsListEnded())
		if (GetMonom()->EqualityExponent(*monom))
		{
			GetMonom()->SetCoeff(monom->GetCoeff() + GetMonom()->GetCoeff());
			if (GetMonom()->GetCoeff() == 0) 
				DelCurrent();
		}
		else
		{
			InsCurrent(monom->GetCopy());
		}
	else InsLast(monom->GetCopy());
}

void TPolinom::SubMonom(TMonom * monom)
{
	Reset();
	while ((!IsListEnded() && !(GetMonom()->EqualityExponent(*monom)) && (*monom < *GetMonom())))
	{
		GoNext();
	}

	if (!IsListEnded())
		if (GetMonom()->EqualityExponent(*monom))
		{
			GetMonom()->SetCoeff(GetMonom()->GetCoeff() - monom->GetCoeff());
			if (GetMonom()->GetCoeff() == 0)
				DelCurrent();
		}
		else
		{
			InsCurrent(monom->GetCopy());
		}
	else InsLast(monom->GetCopy());
}
ostream& operator<<(ostream &os, TPolinom &q)
{
	TMonom* old = new TMonom();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		old = q.GetMonom();
		cout << old;
	}

	return os;
}

#endif

