// Copyright 2017 Ivan Kiselev

#ifndef _TPolinoms_
#define _TPolinoms_


#include "THeadRing.h"
#include "TMonom.h"

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][4] = NULL, int km = 0);
	 //km => ��������� �������, �� � ������
	 // �����������
	 // �������� �� ������� ������������-������

	TPolinom (TPolinom &q);     // ����������� �����������
	~TPolinom() {};
	TMonom*  GetMonom() { return (TMonom*)GetDatValue(); }

	TPolinom& operator+(TPolinom &q); // �������� ���������
	TPolinom& operator-(TPolinom &q); // ��������� ���������
	TPolinom& operator*(TPolinom &q); // ��������� ���������
	TPolinom& operator*(int);	// ��������� �� �����
	TPolinom& operator=(TPolinom &q); // ������������
	bool operator==(TPolinom &q);				   //�������������� �������

	friend ostream& operator<<(ostream &os, TPolinom &q);
	void AddMonom(TMonom* monom);		// �������� � �������� �����
	void SubMonom(TMonom* monom);		// ������� �� �������� �����
};

#endif

