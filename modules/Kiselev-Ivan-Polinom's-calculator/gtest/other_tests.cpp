#include "../gtest/gtest.h"
#include "../lib/TPolinoms.h"

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

TEST(TMonom, EqualityExponent_1)
{
	PTMonom first = new TMonom(5, 1, 4, 3);
	PTMonom second = new TMonom(7, 1, 4, 3);
	EXPECT_TRUE(first->EqualityExponent(*second));
}

TEST(TMonom, EqualityExponent_2)
{
	PTMonom first = new TMonom(5, 1, 4, 3);
	PTMonom second = new TMonom(7, 1, 3, 4);
	EXPECT_FALSE(first->EqualityExponent(*second));
}

TEST(TMonom, Comparison_of_monomials_1)
{
	PTMonom first = new TMonom(5, 1, 4, 3);
	PTMonom second = new TMonom(7, 1, 3, 4);
	EXPECT_TRUE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_2)
{
	PTMonom first = new TMonom(5, 1, 4, 3);
	PTMonom second = new TMonom(7, 1, 3, 4);
	EXPECT_TRUE( *second < *first);
}

TEST(TMonom, Comparison_of_monomials_3)
{
	PTMonom first = new TMonom(5, 1, 3, 4);
	PTMonom second = new TMonom(7, 1, 3, 4);
	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_4)
{
	PTMonom first = new TMonom(1, 0, 0, 1);
	PTMonom second = new TMonom(5, 0, 0, 2);
	EXPECT_FALSE(*second < *first);
}

TEST(TMonom, Comparison_of_monomials_5)
{
	PTMonom first = new TMonom(5, 1, 4, 3);
	PTMonom second = new TMonom(7, 0, 6, 4);
	EXPECT_FALSE(*first < *second);
}

TEST(TPolinom, Auto_Equal)
{
	int mon[][4] = { { 1, 0, 0, 3 }};
	TPolinom old(mon , 1);
	EXPECT_TRUE(old == old);
}

TEST(TPolinom, can_compare_the_polynoms)
{
	int size = 3;
	int mon[][4] = { { 2, 1, 0, 0 }, { 2, 0, 0, 4 },{ 1, 0, 0, 3 } };
	
	TPolinom Pol1(mon, size);

	TPolinom Pol2(mon, size);
	bool res = (Pol1 == Pol2);
	EXPECT_TRUE(res);
}

TEST(TPolinom, can_copy_polinoms)
{
	const int size = 2;
	int mon[][4] = { { 2, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
	TPolinom Pol1(mon, size);

	TPolinom Pol2(Pol1);
	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_polynoms)
{
	const int size = 2;
	int mon[][4] = { { 2, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
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

TEST(TPolinom, can_add_Monom_1)
{
	const int Size = 2;
	const int resSize = 3;
	int Mon[][4] = { { 2, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
	int resMon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } , { 10, 0, 0, 2 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(10, 0, 0, 2);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_2)
{
	const int Size = 2;
	const int resSize = 1;
	int Mon[][4] = { { 2, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
	int resMon[][4] = { { 2, 0, 0, 4 }};
	TPolinom Pol(Mon, Size);
	TMonom monom(-5, 0, 0, 3);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_3)
{
	const int Size = 2;
	const int resSize = 2;
	int Mon[][4] = { { 2, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
	int resMon[][4] = { { 6, 0, 0, 4 } ,{ 5, 0, 0, 3 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(4, 0, 0, 4);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_add_Monom_4)
{
	const int Size = 2;
	const int resSize = 3;
	int Mon[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 } ,{ 1, 0, 0, 1 } };
	int resMon[][4] = { { 2, 0, 0, 5 }, { 1, 0, 0, 4 }, { 5, 0, 0, 2 }, { 1, 0, 0, 1 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(5, 0, 0, 2);
	Pol.AddMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_1)
{
	const int Size = 2;
	const int resSize = 2;
	int Mon[][4] = { { 4, 0, 0, 5 },{ 5, 0, 0, 4 } };
	int resMon[][4] = { { 4, 0, 0, 5 },{ 2, 0, 0, 4 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(3, 0, 0, 4);
	Pol.SubMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_2)
{
	const int Size = 2;
	const int resSize = 2;
	int Mon[][4] = { { 4, 0, 0, 5 },{ 3, 0, 0, 4 } };
	int resMon[][4] = { { 1, 0, 0, 5 },{ 3, 0, 0, 4 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(3, 0, 0, 5);
	Pol.SubMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}

TEST(TPolinom, can_subtract_Monom_3)
{
	const int Size = 3;
	const int resSize = 2;
	int Mon[][4] = { { 4, 0, 0, 5 },{ 3, 0, 0, 4 }, {2 , 0 , 0 , 2} };
	int resMon[][4] = { { 4, 0, 0, 5 },{ 2, 0, 0, 2 } };
	TPolinom Pol(Mon, Size);
	TMonom monom(3, 0, 0, 4);
	Pol.SubMonom(&monom);
	TPolinom res(resMon, resSize);
	EXPECT_TRUE(res == Pol);
}


TEST(TPolinom, can_add_up_linear_polynoms)
{
	const int size = 1;
	int mon1[][4] = { { 2, 0, 0, 1 } };
	int mon2[][4] = { { 1, 0, 0, 1 } };
	// 2z
	TPolinom Pol1(mon1, size);
	// z
	TPolinom Pol2(mon2, size);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 1;
	int expected_mon[][4] = { { 3, 0, 0, 1 } };
	// 3z
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_simple_polynoms_A_plus_B)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][4] = { { 9, 0, 0, 4 } ,{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	TPolinom Pol = Pol1 + Pol2;						// A + B

	const int expected_size = 4;
	int expected_mon[][4] = { { 2, 0, 0, 5 },{ 10, 0, 0, 4 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_add_up_simple_polynoms_B_plus_A)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][4] = { { 9, 0, 0, 4 } ,{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	TPolinom Pol = Pol2 + Pol1;					// B + A

	const int expected_size = 4;
	int expected_mon[][4] = { { 2, 0, 0, 5 },{ 10, 0, 0, 4 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_add_up_polynoms)
{
	const int size1 = 5;
	const int size2 = 4;
	int mon1[][4] = { { 10, 9, 9, 9 },{ -21, 5, 0, 0 },{ 10, 4, 3, 2 },{ 8, 3, 2, 1 },{ 5, 2, 1, 3 } };
	int mon2[][4] = { { 20, 7, 0, 2 },{ 1, 5, 0, 0 },{ -8, 3, 2, 1 },{ 15, 0 } };
	// 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
	TPolinom Pol1(mon1, size1);
	// 15-8x^3y^2z+x^5+20x^7z^2
	TPolinom Pol2(mon2, size2);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 6;
	int expected_mon[][4] = { { 10, 9 ,9 ,9 },{ 20, 7, 0, 2 },{ -20, 5, 0, 0 },{ 10, 4, 3, 2 },{ 5, 2, 1, 3 },{ 15, 0, 0, 0 } };
	// 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_1)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][4] = { { 9, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	int mon3[][4] = { { 8, 0, 0, 5 },{ 2, 0, 0, 3 },{ 10, 0, 0, 0 } };
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
	int expected_mon[][4] = { { 10, 0, 0, 5 },{ 10, 0, 0, 4 },{ 2, 0, 0, 3 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 },{ 10, 0, 0, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_2)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][4] = { { 9, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	int mon3[][4] = { { 8, 0, 0, 5 },{ 2, 0, 0, 3 },{ 10, 0, 0, 0 } };
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
	int expected_mon[][4] = { { 10, 0, 0, 5 },{ 10, 0, 0, 4 },{ 2, 0, 0, 3 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 },{ 10, 0, 0, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms_3)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][4] = { { 9, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	int mon3[][4] = { { 8, 0, 0, 5 },{ 2, 0, 0, 3 },{ 10, 0, 0, 0 } };
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
	int expected_mon[][4] = { { 10, 0, 0, 5 },{ 10, 0, 0, 4 },{ 2, 0, 0, 3 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 },{ 10, 0, 0, 0 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_subtract_simple_polinom)
{
	int size1 = 3;
	int size2 = 1;
	int res_size = 3;
	int mon1[][4] = { { 9, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 7, 0, 0, 4 } };
	int resmon[][4] = { { 2, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	TPolinom first(mon1, size1);
	TPolinom second(mon2, size2);
	TPolinom third(mon1, size1);
	TPolinom res(resmon, res_size);
	first = first - second;
	cout << endl << endl << first << endl << endl;
	bool expect = (res == first);
	EXPECT_TRUE(expect);
}


TEST(TPolinom, can_subtract_polinom)
{
	int size1 = 3;
	int res_size = 2;
	int mon1[][4] = { { 9, 0, 0, 4 },{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 7, 0, 0, 4},{ 8, 0, 0, 3}, { -2, 0, 0, 2} };
	int resmon[][4] = { {2, 0, 0, 4},{ 7, 0, 0, 2} };
	TPolinom first(mon1, size1);
	TPolinom second(mon2, size1);
	TPolinom res(resmon, res_size);
	first = first - second;
	cout << endl << endl << first << endl << endl;
	EXPECT_TRUE(res == first);

}

/*TEST(TPolinom, can_subtract_up_linear_polynoms)
{
	const int size = 1;
	int mon1[][4] = { { 2, 0, 0, 1 } };
	int mon2[][4] = { { 1, 0, 0, 1 } };
	// 2z
	TPolinom Pol1(mon1, size);
	// z
	TPolinom Pol2(mon2, size);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 1;
	int expected_mon[][4] = { { 3, 0, 0, 1 } };
	// 3z
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_subtract_up_simple_polynoms_A_plus_B)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][4] = { { 9, 0, 0, 4 } ,{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	TPolinom Pol = Pol1 + Pol2;			

	const int expected_size = 4;
	int expected_mon[][4] = { { 2, 0, 0, 5 },{ 10, 0, 0, 4 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_subtract_up_simple_polynoms_B_plus_A)
{
	// Arrange
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][4] = { { 9, 0, 0, 4 } ,{ 8, 0, 0, 3 },{ 5, 0, 0, 2 } };
	int mon2[][4] = { { 2, 0, 0, 5 },{ 1, 0, 0, 4 },{ -8, 0, 0, 3 },{ 1, 0, 0, 1 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	TPolinom Pol = Pol2 + Pol1;		

	const int expected_size = 4;
	int expected_mon[][4] = { { 2, 0, 0, 5 },{ 10, 0, 0, 4 },{ 5, 0, 0, 2 },{ 1, 0, 0, 1 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(expected_Pol == Pol);
}

TEST(TPolinom, can_subtract_up_polynoms)
{
	const int size1 = 5;
	const int size2 = 4;
	int mon1[][4] = { { 10, 9, 9, 9 },{ -21, 5, 0, 0 },{ 10, 4, 3, 2 },{ 8, 3, 2, 1 },{ 5, 2, 1, 3 } };
	int mon2[][4] = { { 20, 7, 0, 2 },{ 1, 5, 0, 0 },{ -8, 3, 2, 1 },{ 15, 0 } };
	// 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
	TPolinom Pol1(mon1, size1);
	// 15-8x^3y^2z+x^5+20x^7z^2
	TPolinom Pol2(mon2, size2);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 6;
	int expected_mon[][4] = { { 10, 9 ,9 ,9 },{ 20, 7, 0, 2 },{ -20, 5, 0, 0 },{ 10, 4, 3, 2 },{ 5, 2, 1, 3 },{ 15, 0, 0, 0 } };
	// 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
	TPolinom expected_Pol(expected_mon, expected_size);

	EXPECT_TRUE(Pol == expected_Pol);
}*/