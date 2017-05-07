// Copyright 2017 Ivan Kiselev

#ifndef _TPolinoms_
#define _TPolinoms_


#include "THeadRing.h"
#include "TMonom.h"

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][4] = NULL, int km = 0);
	 //km => количесво мономом, ну и дерьмо
	 // конструктор
	 // полинома из массива «коэффициент-индекс»

	TPolinom (TPolinom &q);     // конструктор копирования
	~TPolinom() {};
	TMonom*  GetMonom() { return (TMonom*)GetDatValue(); }

	TPolinom& operator+(TPolinom &q); // сложение полиномов
	TPolinom& operator-(TPolinom &q); // вычитание полиномов
	TPolinom& operator*(TPolinom &q); // умножение полиномов
	TPolinom& operator*(int);	// умножение на число
	TPolinom& operator=(TPolinom &q); // присваивание
	bool operator==(TPolinom &q);				   //дополнительные функции

	friend ostream& operator<<(ostream &os, TPolinom &q);
	void AddMonom(TMonom* monom);		// добавить к полиному Моном
	void SubMonom(TMonom* monom);		// вычесть из Полинома Моном
};

#endif

