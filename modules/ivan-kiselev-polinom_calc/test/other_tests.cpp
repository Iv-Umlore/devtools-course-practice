// Copyright 2017 Ivan Kiselev
#include "../3rdparty/gtest/gtest.h"
#include "../include/TPolinoms.h"
TEST(TMonom, Equal) {
	TMonom first(10, 20);
	TMonom second(10, 20);

	EXPECT_TRUE(first == second);
}

TEST(TMonom, Not_equal) {
	TMonom first(10, 20);
	TMonom second(10, 25);

	EXPECT_TRUE(!(first == second));
}

TEST(TMonom, EqualityExponent_1) {
	TMonom* first = new TMonom(5, 1, 4, 3);
	TMonom* second = new TMonom(7, 1, 4, 3);

	EXPECT_TRUE(first->EqualityExponent(*second));
}

TEST(TMonom, EqualityExponent_2) {
	TMonom* first = new TMonom(5, 1, 4, 3);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(first->EqualityExponent(*second));
}

TEST(TMonom, Comparison_of_monomials_1) {
	TMonom* first = new TMonom(5, 1, 4, 3);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_TRUE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_2) {
	TMonom* first = new TMonom(5, 1, 3, 3);
	TMonom* second = new TMonom(7, 1, 4, 4);

	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_3) {
	TMonom* first = new TMonom(5, 1, 3, 3);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_4) {
	TMonom* first = new TMonom(5, 1, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 3);

	EXPECT_TRUE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_5) {
	TMonom* first = new TMonom(5, 2, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_TRUE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_6) {
	TMonom* first = new TMonom(5, 0, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_7) {
	TMonom* first = new TMonom(5, 1, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_21) {
	TMonom* first = new TMonom(5, 1, 4, 3);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_22) {
	TMonom* first = new TMonom(5, 1, 3, 3);
	TMonom* second = new TMonom(7, 1, 4, 4);

	EXPECT_TRUE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_23) {
	TMonom* first = new TMonom(5, 1, 3, 3);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_TRUE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_24) {
	TMonom* first = new TMonom(5, 1, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 3);

	EXPECT_FALSE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_25) {
	TMonom* first = new TMonom(5, 2, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_26) {
	TMonom* first = new TMonom(5, 0, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_TRUE(*second > *first);
}

TEST(TMonom, Comparison_of_monomials_27) {
	TMonom* first = new TMonom(5, 1, 3, 4);
	TMonom* second = new TMonom(7, 1, 3, 4);

	EXPECT_FALSE(*second > *first);
}

TEST(TMonom, multiplication_Monom) {
	TMonom first(3, 1, 3, 5);
	TMonom second(4, 0, -3, 1);
	TMonom result(12, 1, 0, 6);

	first = first * second;

	EXPECT_TRUE(result == first);
}

TEST(TDatLink, Get_DatValue) {
TMonom* pdv = new TMonom(1, 0, 0, 0);
TDatLink dl;

dl.SetValue(*pdv);

EXPECT_TRUE(dl.GetValue() == *pdv);
}

TEST(TDatLink, Get_Next_DatLink) {
TDatLink dl1;
TDatLink dl2;

dl1.SetNextLink(&dl2);

EXPECT_TRUE(&dl2 == dl1.GetNextLink());
}



TEST(THeadRing, Ins_First) {
int size = 1;
int res_size = 2;
int mon[][4] = { { 1, 0, 0, 3 } };
int resmon[][4] = { { 2, 1, 0, 0} , { 1, 0, 0, 3 } };
TMonom Mon(2, 1, 0, 0);
TPolinom old(mon, size);
TPolinom res(resmon, res_size);
old.InsFirst(&Mon);

EXPECT_TRUE(old == res);
}

TEST(THeadRing, Del_First) {
int size = 2;
int res_size = 1;
int mon[][4] = { { 2, 1, 0, 0 } , { 1, 0, 0, 3 } };
int resmon[][4] = { { 1, 0, 0, 3 } };
TPolinom old(mon, size);
TPolinom res(resmon, res_size);
old.DelFirst();

EXPECT_TRUE(old == res);
}

TEST(TPolinom, Auto_Equal) {
int size = 1;
int mon[][4] = { { 1, 0, 0, 3 } };
TPolinom old(mon, size);

EXPECT_TRUE(old == old);
}

TEST(TPolinom, can_compare_the_polynoms) {
int size = 3;
int mon[][4] = { { 2, 1, 0, 0 } , { 2, 0, 0, 4 } , { 1, 0, 0, 3 } };
TPolinom Pol1(mon, size);
TPolinom Pol2(mon, size);

EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_copy_polinoms) {
const int size = 2;
int mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
TPolinom Pol1(mon, size);
TPolinom Pol2(Pol1);

EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_polynoms) {
const int size = 2;
int mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
TPolinom Pol1(mon, size);
TPolinom Pol2;

Pol2 = Pol1;

EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_empty_polynom) {
TPolinom Pol1;
TPolinom Pol2;

Pol2 = Pol1;

EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_add_Monom_1) {
const int Size = 2;
const int resSize = 3;
int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
int resMon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } , { 10, 0, 0, 2 } };
TPolinom Pol(Mon, Size);
TMonom monom(10, 0, 0, 2);
TPolinom res(resMon, resSize);

Pol.AddMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_2) {
const int Size = 2;
const int resSize = 1;
int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
int resMon[][4] = { { 2, 0, 0, 4 } };
TPolinom Pol(Mon, Size);
TMonom monom(-5, 0, 0, 3);
TPolinom res(resMon, resSize);

Pol.AddMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_3) {
const int Size = 2;
const int resSize = 2;
int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
int resMon[][4] = { { 6, 0, 0, 4 } , { 5, 0, 0, 3 } };
TPolinom Pol(Mon, Size);
TMonom monom(4, 0, 0, 4);
TPolinom res(resMon, resSize);

Pol.AddMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_4) {
const int Size = 2;
const int resSize = 3;
int Mon[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } , { 1, 0, 0, 1 } };
int resMon[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
TPolinom Pol(Mon, Size);
TMonom monom(5, 0, 0, 2);
TPolinom res(resMon, resSize);

Pol.AddMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_1) {
const int Size = 2;
const int resSize = 2;
int Mon[][4] = { { 4, 0, 0, 5 } , { 5, 0, 0, 4 } };
int resMon[][4] = { { 4, 0, 0, 5 } , { 2, 0, 0, 4 } };
TPolinom Pol(Mon, Size);
TMonom monom(3, 0, 0, 4);
TPolinom res(resMon, resSize);

Pol.SubMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_2) {
const int Size = 2;
const int resSize = 2;
int Mon[][4] = { { 4, 0, 0, 5 } , { 3, 0, 0, 4 } };
int resMon[][4] = { { 1, 0, 0, 5 } , { 3, 0, 0, 4 } };
TPolinom Pol(Mon, Size);
TMonom monom(3, 0, 0, 5);
TPolinom res(resMon, resSize);

Pol.SubMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_3) {
const int Size = 3;
const int resSize = 2;
int Mon[][4] = { { 4, 0, 0, 5 } , { 3, 0, 0, 4 } , {2 , 0 , 0 , 2} };
int resMon[][4] = { { 4, 0, 0, 5 } , { 2, 0, 0, 2 } };
TPolinom Pol(Mon, Size);
TMonom monom(3, 0, 0, 4);
TPolinom res(resMon, resSize);

Pol.SubMonom(&monom);

EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_up_linear_polynoms) {
const int size = 1;
const int expected_size = 1;
int mon1[][4] = { { 2, 0, 0, 1 } };
int mon2[][4] = { { 1, 0, 0, 1 } };
int expected_mon[][4] = { { 3, 0, 0, 1 } };
TPolinom Pol1(mon1, size);
TPolinom Pol2(mon2, size);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol1 + Pol2;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_simple_polynoms_A_plus_B) {
const int size1 = 3;
const int size2 = 4;
const int expected_size = 4;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int expected_mon[][4] = { { 2, 0, 0, 5 } , { 10, 0, 0, 4 } ,
{ 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol1 + Pol2;

EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_add_up_simple_polynoms_B_plus_A) {
const int size1 = 3;
const int size2 = 4;
const int expected_size = 4;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int expected_mon[][4] = { { 2, 0, 0, 5 } , { 10, 0, 0, 4 } ,
{ 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol2 + Pol1;

EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_add_up_polynoms) {
const int size1 = 5;
const int size2 = 4;
const int expected_size = 6;
int mon1[][4] = { { 10, 9, 9, 9 } , { -21, 5, 0, 0 } ,
{ 10, 4, 3, 2 } , { 8, 3, 2, 1 } , { 5, 2, 1, 3 } };
int mon2[][4] = { { 20, 7, 0, 2 } , { 1, 5, 0, 0 } ,
{ -8, 3, 2, 1 } , { 15, 0 } };
int expected_mon[][4] = { { 10, 9, 9, 9 } , { 20, 7, 0, 2 } ,
{ -20, 5, 0, 0 } , { 10, 4, 3, 2 } , { 5, 2, 1, 3 } ,
{ 15, 0, 0, 0 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol1 + Pol2;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_1) {
const int size1 = 3;
const int size2 = 4;
const int size3 = 3;
const int expected_size = 6;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
{ 10, 0, 0, 0 } };
int expected_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
{ 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom Pol3(mon3, size3);
TPolinom Pol;
TPolinom expected_Pol(expected_mon, expected_size);

Pol = Pol1 + Pol2 + Pol3;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_2) {
const int size1 = 3;
const int size2 = 4;
const int size3 = 3;
const int expected_size = 6;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
{ 10, 0, 0, 0 } };
int expected_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
{ 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom Pol3(mon3, size3);
TPolinom Pol;
TPolinom expected_Pol(expected_mon, expected_size);

Pol = Pol2 + Pol3 + Pol1;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_3) {
const int size1 = 3;
const int size2 = 4;
const int size3 = 3;
const int expected_size = 6;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
{ -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
{ 10, 0, 0, 0 } };
int expected_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
{ 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom Pol3(mon3, size3);
TPolinom Pol;
TPolinom expected_Pol(expected_mon, expected_size);

Pol = Pol2 + Pol1 + Pol3;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_subtract_simple_polinom) {
int size1 = 3;
int size2 = 1;
int res_size = 3;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 7, 0, 0, 4 } };
int resmon[][4] = { { 2, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
TPolinom first(mon1, size1);
TPolinom second(mon2, size2);
TPolinom third(mon1, size1);
TPolinom res(resmon, res_size);

first = first - second;

EXPECT_TRUE(res == first);
}


TEST(TPolinom, can_subtract_polinom) {
int size1 = 3;
int res_size = 2;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 7, 0, 0, 4} , { 8, 0, 0, 3} ,
{ -2, 0, 0, 2} };
int resmon[][4] = { {2, 0, 0, 4} , { 7, 0, 0, 2} };
TPolinom first(mon1, size1);
TPolinom second(mon2, size1);
TPolinom res(resmon, res_size);

first = first - second;

EXPECT_TRUE(res == first);
}

TEST(TPolinom, can_subtract_up_simple_polynoms_A_minus_B) {
const int size1 = 3;
const int size2 = 4;
const int expected_size = 4;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 7, 0, 0, 4 } ,
{ 8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int expected_mon[][4] = { { -2, 0, 0, 5 } , { 2, 0, 0, 4 } ,
{ 5, 0, 0, 2 } , { -1, 0, 0, 1 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol1 - Pol2;

EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_subtract_up_simple_polynoms_B_minus_A) {
const int size1 = 3;
const int size2 = 4;
const int expected_size = 4;
int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
{ 5, 0, 0, 2 } };
int mon2[][4] = { { 2, 0, 0, 5 } , { 7, 0, 0, 4 } ,
{ 8, 0, 0, 3 } , { 1, 0, 0, 1 } };
int expected_mon[][4] = { { 2, 0, 0, 5 } , { -2, 0, 0, 4 } ,
{ -5, 0, 0, 2 } , { 1, 0, 0, 1 } };
TPolinom Pol1(mon1, size1);
TPolinom Pol2(mon2, size2);
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol2 - Pol1;

EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_subtract_up_polynoms) {
const int size1 = 5;
const int size2 = 4;
const int expected_size = 6;
int mon1[][4] = { { 10, 9, 9, 9 } , { -21, 5, 0, 0 } ,
{ 10, 4, 3, 2 } , { 8, 3, 2, 1 } , { 5, 2, 1, 3 } };
int mon2[][4] = { { 20, 7, 0, 2 } , { 1, 5, 0, 0 } ,
{ 8, 3, 2, 1 } , { 15, 0, 0, 0 } };
int expected_mon[][4] = { { 10, 9, 9, 9 } , { -20, 7, 0, 2 } ,
{ -22, 5, 0, 0 } , { 10, 4, 3, 2 } , { 5, 2, 1, 3 } , { -15, 0, 0, 0 } };
// 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
TPolinom Pol1(mon1, size1);
// 15-8x^3y^2z+x^5+20x^7z^2
TPolinom Pol2(mon2, size2);
// 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
TPolinom expected_Pol(expected_mon, expected_size);

TPolinom Pol = Pol1 - Pol2;

EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, multiplication_with_simple_polinom) {
int size1 = 4;
int size2 = 1;
int mon1[][4] = { { 5, 3, 0, 6 } , { 4, 2, 4, 3 } ,
{ 10, 2, 3, 5 } , { 10, 0, 0, 0 } };
int mon2[][4] = { {2, 1, 1, 1} };
// 5*x^3*z^6 + 4*x^2*y^4*z^4 + 10*x^2*y^3*z^5 + 10
int resMon[][4] = { { 10, 4, 1, 7 } , { 8, 3, 5, 4 } ,
{ 20, 3, 4, 6 } , { 20, 1, 1, 1 } };
TPolinom first(mon1, size1);
// (2*x*y*z)
TPolinom second(mon2, size2);
TPolinom result(resMon, size1);
EXPECT_TRUE(result == (first * second));
}

TEST(TPolinom, multiplication_with_big_polinom_4x4) {
int size = 4;
int res_size = 16;
int mon1[][4] = { { 5, 3, 0, 6 } , { 5, 2, 4, 3 } ,
{ 10, 2, 3, 5 } , { 10, 0, 0, 0 } };
int mon2[][4] = { { 2, 7, 5, 6} , { 7, 5, 3, 8} ,
{ 12, 4, 6, 1} , { 3, 4, 2, 0} };
int res_Mon[][4] = {
{ 10, 10, 5, 12 } , { 10, 9, 9, 9 } ,
{ 20, 9, 8, 11 } , { 35, 8, 3, 14 } ,
{ 35, 7, 7, 11 } , { 70, 7, 6, 13 } ,
{ 60, 7, 6, 7 } , { 20, 7, 5, 6 } ,
{ 15, 7, 2, 6 } , { 60, 6, 10, 4 } ,
{ 120, 6, 9, 6 } , { 15, 6, 6, 3 } ,
{ 30, 6, 5, 5 } , { 70, 5, 3, 8 } ,
{ 120, 4, 6, 1 } , { 30, 4, 2, 0 }
};
// 5*x^3*z^6 + 5*x^2*y^4*z^3 + 10*x^2*y^3*z^5 + 10
TPolinom first(mon1, size);
// 2*x^7*y^5*z^6 + 7*x^5*y^3*z^8 + 12*x^4*y^6*z + 3*x^4*y^2
TPolinom second(mon2, size);
TPolinom result(res_Mon, res_size);

EXPECT_TRUE(result == (first * second));
}
