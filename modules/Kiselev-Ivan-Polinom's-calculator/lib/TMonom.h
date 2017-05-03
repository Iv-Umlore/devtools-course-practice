//Модуль класса моном

#ifndef _TMonom_
#define _TMonon_

#include "TDatValue.h"


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

#endif

