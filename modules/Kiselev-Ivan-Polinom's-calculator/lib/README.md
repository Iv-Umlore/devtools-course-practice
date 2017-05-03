﻿# Лабораторная работа №5: Полиномы

## Цели и задачи

В рамках лабораторной работы ставится задача создания программных средств, поддерживающих эффективное представление полиномов и выполнение следующих операций над ними:
* ввод полинома 
* организация хранения полинома
* удаление введенного ранее полинома;
* копирование полинома;
* сложение двух полиномов;
* вычисление значения полинома при заданных значениях переменных;
* вывод.

В качестве структуры хранения используются списки. В качестве дополнительной цели в лабораторной работе ставится также задача разработки общего представления списков и операций по их обработке. В числе операций над списками реализованы следующие действия:
* поддержка понятия текущего звена;
* вставка звеньев в начало, после текущей позиции и в конец списков;
* удаление звеньев в начале и в текущей позиции списков;
* организация последовательного доступа к звеньям списка (итератор).

### Условия и ограничения
При выполнении лабораторной работы использовались следующие основные предположения:
1.	Разработка структуры хранения должна быть ориентирована на представление полиномов от трех неизвестных.
2.	Степени переменных полиномов не могут превышать значения 9.
3.	Число мономов в полиномах существенно меньше максимально возможного количества (тем самым, в структуре хранения должны находиться только мономы с ненулевыми коэффициентами).

### План работы
1. Разработка структуры хранения списков.
2. Разработка структуры хранения полиномов.
3. Проверка работоспособности написанных классов с помощью Google Test Framework.


### Используемые инструменты
- Система контроля версий **Git**.
- Фреймворк для написания автоматических тестов **Google Test**.
- Среда разработки **Microsoft Visual Studio 2015 Community Edition**.


## Абстрактный класс TDatValue.

DatValue.h:

	class TDatValue {
	public:
		virtual TDatValue * GetCopy() = 0; // создание копии
		~TDatValue() {};
	};


## Класс TMonom позволяющий работать с частями полинома

	Monom.h:
		class TMonom : public TDatValue {
		protected:
			int Coeff; // коэффициент монома
			int Index; // индекс (свертка степеней)
		public:
			TMonom(int cval = 1, int ival = 0) 
			{
				Coeff = cval; 
				Index = ival;
			};

			~TMonom() {};

			virtual TDatValue * GetCopy(); // изготовить копию
			void SetCoeff(int cval) 
			{ 
				Coeff = cval; 
			}

			int  GetCoeff(void) 
			{ 
				return Coeff; 
			}

			void SetIndex(int ival) 
			{ 
				Index = ival; 
			}

			int  GetIndex(void) 
			{ 
				return Index; 
			}

			TMonom& operator=(const TMonom &tm) 
			{
				Coeff = tm.Coeff;
				Index = tm.Index;
				return *this;
			}
			friend ostream& operator<<(ostream &os, TMonom * tm) 
			{
				int x, y, z;
				x = (tm->Index / 100);
				y = ((tm->Index % 100) / 10);
				z = (tm->Index % 10);
				if (tm->Coeff > 0)
					os << " + " << tm->Coeff;
				else
					os << " - " << -tm->Coeff;
				if (x > 0) os << " * x^" << x;
				if (y > 0) os << " * y^" << y;
				if (z > 0) os << " * z^" << z;
				//os << tm.Coeff << " " << tm.Index;
				return os;
			}


			bool TMonom::operator==(const TMonom &tm) 
			{
				return ((Coeff == tm.Coeff) && (Index == tm.Index));
			}

			bool operator<(const TMonom &tm) 
			{
				return Index < tm.Index;
			}

			friend class TPolinom;

		};

		TDatValue* TMonom::GetCopy()
		{
			return new TMonom(Coeff, Index);
		}

##TRootLink хранящий адрес на следущий элемент

RootLink.h:

	class TRootLink;
	typedef TRootLink *PTRootLink;
	typedef TDatValue *PTDatValue;

	class TRootLink {
	protected:
		PTRootLink  pNext;  // указатель на следующее звено
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

##TDatLink отвечающий за хранение значения монома и работы с этим значением

DatLink.h:

	class TDatLink;
	typedef TDatLink *PTDatLink;

	class TDatLink : public TRootLink {
	protected:
	PTDatValue pValue;  // указатель на объект значения
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

## TDatList отвечающий за сбор всех TDatLink в общее целое(управление списком)

DatList.h:

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


## THeadRing содержащий указатель на сам список

HeadRing.h:

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

		void THeadRing::InsFirst(PTDatValue pVal)	
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

## TPolinom который преобразует список в полноценный Полином и позволяет работать с ним

Polinom.h:

		typedef TMonom* PTMonom;

		class TPolinom : public THeadRing {
		public:
			TPolinom(int monoms[][2] = NULL, int km = 0);
			 //km => количесво мономом, ну и дерьмо
			 // конструктор
			 // полинома из массива «коэффициент-индекс»

			TPolinom (TPolinom &q);     // конструктор копирования
			~TPolinom() {};
			PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }

			TPolinom& operator+(TPolinom &q); // сложение полиномов
			TPolinom& operator=(TPolinom &q); // присваивание
			bool operator==(TPolinom &q);				   //дополнительные функции
		
			friend ostream& operator<<(ostream &os, TPolinom &q);
			void AddMonom(TMonom* monom);
		};

		TPolinom::TPolinom(int monoms[][2], int km)
		{
	
			PTMonom Monom = new TMonom(0, 0);
			pHead->SetDatValue(Monom);
			for (int i = 0; i < km; i++)
			{
				Monom = new TMonom(monoms[i][0], monoms[i][1]);
				InsLast(Monom);
			}
			Reset();
		}

		TPolinom::TPolinom(TPolinom & q)
		{
				PTMonom Monom = new TMonom(0, 0);
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
				q.Reset();
				old->AddMonom(GetMonom());
				GoNext();
			}	
			Reset();
			q.Reset();
			return *old;
		}

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
			while (!IsListEnded() && (GetMonom()->GetIndex() > monom->GetIndex()))
			{
				GoNext();
			}
			if (!IsListEnded())
				if (GetMonom()->GetIndex() == monom->GetIndex())
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


	
Демонстрационная программа сложения двух полиномов:

	int main()
	{
		const int size = 3;
		int mon1[][2] = { { 1, 3 },{ 2, 4 },{ 2, 100 } };
		int mon2[][2] = { { 3, 3 },{ -2, 4 },{ 2, 100 } };
		TPolinom Pol1(mon1, size);
		TPolinom Pol2(mon2, size);
		cout << endl << Pol1 << endl << Pol2 << endl;
		TPolinom ResPol(Pol1 + Pol2);
		cout << ResPol << endl;
		return 0;
	}
	
Результат запуска демонстрационной программы:

![](picture_2.png)


### 3. Проверка работоспособности при помощи Google Test Framework

Данные классы были протестированы с помощью фреймворка **Google Test**.

#other_tests.cpp

	TEST(TRootLink, Set_Next_Link)
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL);
	first.SetNextLink(pdv1);
	EXPECT_EQ(&sec, first.GetNextLink());
}

TEST(TRootLink, Get_Next_Link)
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL, pdv1);
	EXPECT_EQ(&sec, first.GetNextLink());
}

TEST(TRootLink, Ins_Next_Link)
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL, pdv1);
	TDatLink third(NULL);
	first.InsNextLink(&third);
	EXPECT_EQ(&third, first.GetNextLink());
}


TEST(TDatLink, create_DatLink)
{
	TDatLink sec(NULL);
	EXPECT_NO_FATAL_FAILURE(TDatLink first(NULL, &sec));
}

TEST(TDatLink, Set_DatLalue)
{
	PTDatValue pdv = NULL;
	TDatLink dl(NULL, NULL);
	EXPECT_NO_FATAL_FAILURE(dl.SetDatValue(pdv));
}

TEST(TDatLink, Get_DatValue)
{
	PTDatValue pdv = NULL;
	TDatLink dl;
	dl.SetDatValue(pdv);
	EXPECT_EQ(dl.GetDatValue(), pdv);
}

TEST(TDatLink, Get_Next_DatLink)
{
	TDatLink dl1;
	TDatLink dl2;
	dl1.SetNextLink(&dl2);
	EXPECT_EQ(&dl2, dl1.GetNextDatLink());
}

TEST(TMonom, Equal)
{
	TMonom first(10, 20);
	TMonom second(10, 20);
	EXPECT_TRUE(first == second);
}

TEST(TMonom, Not_equal)
{
	TMonom first(10, 20);
	TMonom second(10, 25);

	EXPECT_TRUE(!(first == second));
}

TEST(TPolinom, Auto_Equal)
{
	int mon[][2] = { { 1, 3 }};
	TPolinom old(mon , 1);
	EXPECT_TRUE(old == old);
}

TEST(TPolinom, can_compare_the_polynoms)
{
	int size = 3;
	int mon[][2] = { { 2, 100 }, { 2, 4 },{ 1, 3 } };
	
	TPolinom Pol1(mon, size);

	TPolinom Pol2(mon, size);
	bool res = (Pol1 == Pol2);
	EXPECT_TRUE(res);
}

TEST(TPolinom, can_copy_polinoms)
{
	const int size = 2;
	int mon[][2] = { { 2, 4 } ,{ 5, 3 } };
	TPolinom Pol1(mon, size);

	TPolinom Pol2(Pol1);
	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_polynoms)
{
	const int size = 2;
	int mon[][2] = { { 2, 4 } ,{ 5, 3 } };
	TPolinom Pol1(mon, size);
	TPolinom Pol2;

	Pol2 = Pol1;

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_empty_polynom)
{
	TPolinom Pol1;
	TPolinom Pol2;

	Pol2 = Pol1;

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_add_Monom1)
{
	const int Size = 2;
	const int resSize = 3;
	int Mon[][2] = { { 2, 4 } ,{ 5, 3 } };
	int resMon[][2] = { { 2, 4 } , { 5, 3 } , { 10, 2 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(10, 2);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom2)
{
	const int Size = 2;
	const int resSize = 1;
	int Mon[][2] = { { 2, 4 } ,{ 5, 3 } };
	int resMon[][2] = { { 2, 4 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(-5, 3);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom3)
{
	const int Size = 2;
	const int resSize = 2;
	int Mon[][2] = { { 2, 4 } ,{ 5, 3 } };
	int resMon[][2] = { { 6, 4 } ,{ 5, 3 }};
	TPolinom Pol(Mon, Size);
	TMonom monom(4, 4);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}


TEST(TPolinom, can_add_up_linear_polynoms)
{
	const int size = 1;
	int mon1[][2] = { { 2, 1 } };
	int mon2[][2] = { { 1, 1 } };
	// 2z
	TPolinom Pol1(mon1, size);
	// z
	TPolinom Pol2(mon2, size);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 1;
	int expected_mon[][2] = { { 3, 1 } };
	// 3z
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_simple_polynoms)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][2] = { { 9, 4 } ,{ 8, 3 },{ 5, 2 } };
	int mon2[][2] = { { 2, 5 },{ 1, 4 },{ -8, 3 },{ 1, 1 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 4;
	int expected_mon[][2] = { { 2, 5 },{ 10, 4 },{ 5, 2 },{ 1, 1 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_add_up_polynoms)
{
	const int size1 = 5;
	const int size2 = 4;
	int mon1[][2] = { { 10, 999 },{ -21, 500 },{ 10, 432 },{ 8, 321 },{ 5, 213 } };
	int mon2[][2] = { { 20, 702 },{ 1, 500 },{ -8, 321 },{ 15, 0 } };
	// 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
	TPolinom Pol1(mon1, size1);
	// 15-8x^3y^2z+x^5+20x^7z^2
	TPolinom Pol2(mon2, size2);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 6;
	int expected_mon[][2] = { { 10, 999 },{ 20, 702 },{ -20, 500 },{ 10, 432 },{ 5, 213 },{ 15, 0 } };
	// 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms1)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][2] = { { 9, 4 },{ 8, 3 },{ 5, 2 } };
	int mon2[][2] = { { 2, 5 },{ 1, 4 },{ -8, 3 },{ 1, 1 } };
	int mon3[][2] = { { 8, 5 },{ 2, 3 },{ 10, 0 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	// 10+2z^3+8z^5
	TPolinom Pol3(mon3, size3);
	// { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 }
	TPolinom Pol;
	Pol = Pol1 + Pol2 + Pol3;
	const int expected_size = 6;
	int expected_mon[][2] = { { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms2)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][2] = { { 9, 4 },{ 8, 3 },{ 5, 2 } };
	int mon2[][2] = { { 2, 5 },{ 1, 4 },{ -8, 3 },{ 1, 1 } };
	int mon3[][2] = { { 8, 5 },{ 2, 3 },{ 10, 0 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	// 10+2z^3+8z^5
	TPolinom Pol3(mon3, size3);
	// { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 }
	TPolinom Pol;
	Pol = Pol2 + Pol3 + Pol1;
	const int expected_size = 6;
	int expected_mon[][2] = { { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][2] = { { 9, 4 },{ 8, 3 },{ 5, 2 } };
	int mon2[][2] = { { 2, 5 },{ 1, 4 },{ -8, 3 },{ 1, 1 } };
	int mon3[][2] = { { 8, 5 },{ 2, 3 },{ 10, 0 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	// 10+2z^3+8z^5
	TPolinom Pol3(mon3, size3);
	// { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 }
	TPolinom Pol;
	Pol = Pol2 + Pol1 + Pol3;
	const int expected_size = 6;
	int expected_mon[][2] = { { 10, 5 },{ 10, 4 },{ 2, 3 },{ 5, 2 },{ 1, 1 },{ 10, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}




**Результат**

![](picture_1.png)


	
## Выводы

В ходе выполнения данной работы были получены навыки создания структуры данных список (TDatList) и организации работы с полиномами на основе списков (TPolinom). 

Функциональность написанной системы была протестирована при помощи Google Test Framework. Тесты показали, что разработанная программа успешно решает поставленную в начале работы задачу.