//������ ������ �����

#ifndef _TMonom_
#define _TMonon_

#include "TDatValue.h"


class TMonom : public TDatValue {
protected:
	int Coeff; // ����������� ������
	int XInd; // ������ X
	int YInd; // ������ Y
	int ZInd; // ������ Z
public:
	TMonom(int cval = 1, int x = 0 , int y = 0, int z = 0) 
	{
		Coeff = cval;
		XInd = x;
		YInd = y;
		ZInd = z;
	};

	~TMonom() {};

	virtual TDatValue * GetCopy(); // ���������� �����
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
		os << " * x^" << tm->XInd;
		os << " * y^" << tm->YInd;
		os << " * z^" << tm->ZInd;
		return os;
	}


	bool TMonom::operator==(const TMonom &tm) 
	{
		return ((Coeff == tm.Coeff) && (XInd == tm.XInd) && (YInd == tm.YInd) && (ZInd == tm.ZInd));
	}

	bool operator<(const TMonom &tm) // prioritet x > y > z
	{
		if (*this == tm) return false;
		
		if (XInd > tm.XInd)
			return false;
		else if (XInd < tm.XInd)
			return true;
		//XInd == tm.XInd
		if (YInd > tm.YInd)
			return false;
		else if (YInd < tm.YInd)
			return true;
		// & YInd == tm.YInd
		if (ZInd > tm.ZInd)
			return false;
		else if (ZInd < tm.ZInd)
			return true;
	}

	friend class TPolinom;

};

TDatValue* TMonom::GetCopy()
{
	return new TMonom(Coeff, XInd, YInd, ZInd);
}

#endif

