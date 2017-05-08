// Copyright 2017 Ivan Kiselev

#ifndef _TPolinoms_
#define _TPolinoms_

#include "THeadRing.h"
#include "TMonom.h"

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][4] = NULL, int km = 0);
	//km => kol-vo monomov
	// constructor
	//	Check ReadMe

	TPolinom (TPolinom &q);     // constructor
	~TPolinom() {};

	TMonom*  GetMonom() { return (TMonom*)GetDatValue(); }

	TPolinom& operator+(TPolinom &q); // Add Polinoms
	TPolinom& operator-(TPolinom &q); // Sub Polinoms
	TPolinom& operator*(TPolinom &q); // Mult Polinoms
	TPolinom& operator*(int);	// Mult int
	TPolinom& operator=(TPolinom &q); // 
	bool operator==(TPolinom &q);				   
	
	void AddMonom(TMonom* monom);	// + Monom
	void SubMonom(TMonom* monom);	// - Monom

	friend ostream& operator<<(ostream &os, TPolinom &q);

};

#endif

