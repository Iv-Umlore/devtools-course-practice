//Модуль класса моном

#ifndef _TMonom_
#define _TMonon_

#include "TDatValue.h"


class TMonom : public TDatValue {
protected:
	int Coeff; // коэффициент монома
	int XInd; // индекс X
	int YInd; // индекс Y
	int ZInd; // индекс Z
public:
	TMonom(int cval = 1, int x = 0 , int y = 0, int z = 0) 
	{
		Coeff = cval;
		XInd = x;
		YInd = y;
		ZInd = z;
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

	void SetIndexX(int ival) 
	{ 
		XInd = ival; 
	}

	void SetIndexY(int ival)
	{
		YInd = ival;
	}

	void SetIndexZ(int ival)
	{
		ZInd = ival;
	}

	int  GetIndexX(void) 
	{ 
		return XInd; 
	}

	int  GetIndexY(void)
	{
		return YInd;
	}

	int  GetIndexZ(void)
	{
		return ZInd;
	}

	TMonom& operator=(const TMonom &tm) 
	{
		Coeff = tm.Coeff;
		XInd = tm.XInd;
		YInd = tm.YInd;
		ZInd = tm.ZInd;
		return *this;
	}
	friend ostream& operator<<(ostream &os, TMonom * tm) 
	{
		if (tm->Coeff > 0)
			os << " + " << tm->Coeff;
		else
			os << " - " << -tm->Coeff;
		if (tm->XInd != 0) os << " * x^" << tm->XInd;
		if (tm->YInd != 0) os << " * y^" << tm->YInd;
		if (tm->ZInd != 0) os << " * z^" << tm->ZInd;
		return os;
	}

	TMonom operator*(TMonom &mon)
	{
		TMonom* that = new TMonom(0, 0, 0, 0);
		that->Coeff = this->Coeff * mon.Coeff;
		that->SetIndexX(this->GetIndexX() + mon.GetIndexX());
		that->SetIndexY(this->GetIndexY() + mon.GetIndexY());
		that->SetIndexZ(this->GetIndexZ() + mon.GetIndexZ());
		return *that;
	}

	bool operator==(const TMonom &tm) 
	{
		return ((Coeff == tm.Coeff) && (XInd == tm.XInd) && (YInd == tm.YInd) && (ZInd == tm.ZInd));
	}

	bool EqualityExponent(TMonom &tm)
	{
		return (XInd == tm.XInd) && (YInd == tm.YInd) && (ZInd == tm.ZInd);
	}

	bool operator<(TMonom &tm) // prioritet x > y > z
	{
		if (EqualityExponent(tm)) return false;
		if (XInd > tm.XInd)
			return false;
		else if (XInd < tm.XInd)
			return true;
		// XInd == tm.XInd
		if (YInd > tm.YInd)
			return false;
		else if (YInd < tm.YInd)
			return true;
		// & YInd == tm.YInd
		if (ZInd > tm.ZInd)
			return false;
		else if (ZInd < tm.ZInd)
			return true;

		return false;
	}

	bool operator>(TMonom &tm) // prioritet x > y > z
	{
		if (EqualityExponent(tm)) return false;
		if (XInd < tm.XInd)
			return false;
		else if (XInd > tm.XInd)
			return true;
		// XInd == tm.XInd
		if (YInd < tm.YInd)
			return false;
		else if (YInd > tm.YInd)
			return true;
		// & YInd == tm.YInd
		if (ZInd < tm.ZInd)
			return false;
		else if (ZInd > tm.ZInd)
			return true;

		return false;
	}

	friend class TPolinom;

};

TDatValue* TMonom::GetCopy()
{
	return new TMonom(Coeff, XInd, YInd, ZInd);
}

#endif

