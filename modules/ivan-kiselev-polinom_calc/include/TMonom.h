// Copyright 2017 Ivan Kiselev
#ifndef _TMonom_
#define _TMonon_
#include "TDatValue.h"
class TMonom : public TDatValue {
protected:
int Coeff; // monom's coeff
int XInd; // index X
int YInd; // index Y
int ZInd; // index Z
public:
TMonom(int cval = 1, int x = 0, int y = 0, int z = 0)
{
	Coeff = cval;
	XInd = x;
	YInd = y;
	ZInd = z;
};
~TMonom() {};
virtual TDatValue * GetCopy();
void SetCoeff(int cval);
int  GetCoeff(void);
void SetIndexX(int ival);
void SetIndexY(int ival);
void SetIndexZ(int ival);
int  GetIndexX(void);
int  GetIndexY(void);
int  GetIndexZ(void);
TMonom& operator=(const TMonom &tm);	
TMonom operator*(TMonom &mon);
bool operator==(const TMonom &tm);
bool EqualityExponent(TMonom &tm);
bool operator<(TMonom &tm); // prioritet x > y > z
bool operator>(TMonom &tm); // prioritet x > y > z
friend ostream& operator<<(ostream &os, TMonom * tm);
friend class TPolinom;
};

#endif
