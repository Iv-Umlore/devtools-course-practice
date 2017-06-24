// Copyright 2017 Ivan Kiselev
#include "../3rdparty/gtest/gtest.h"
#include "../include/Polinom.h"

TEST(RootLink, Set_Next_Link_test) {
    Link sec(NULL);
    PLink pdv1 = &sec;
    Link first(NULL);

    GTEST_TEST_NO_FATAL_FAILURE_(first.SetNextLink(pdv1) ,
        GTEST_NONFATAL_FAILURE_);
}

TEST(RootLink, Set_Next_Link) {
    Link sec(NULL);
    PLink pdv1 = &sec;

    Link first(NULL, pdv1);

    ASSERT_EQ(&sec, first.GetNextLink());
}

TEST(RootLink, Get_Next_Link) {
    Link sec(NULL);
    PLink pdv1 = &sec;
    Link first(NULL, pdv1);

    ASSERT_EQ(&sec, first.GetNextLink());
}

TEST(RootLink, Ins_Next_Link) {
    Link sec(NULL);
    PLink pdv1 = &sec;
    Link first(NULL, pdv1);
    Link third(NULL);

    first.InsNextLink(&third);

    ASSERT_EQ(&third, first.GetNextLink());
}

TEST(Link, create_DatLink_with_parametr) {
    ASSERT_NO_FATAL_FAILURE(Link sec(NULL, NULL));
}

TEST(Link, create_DatLink) {
    Link sec(NULL);

    ASSERT_NO_FATAL_FAILURE(Link first(NULL, &sec));
}

TEST(Link, Set_DatLalue) {
    PValue pdv = NULL;
    Link dl(NULL, NULL);

    ASSERT_NO_FATAL_FAILURE(dl.SetValue(pdv));
}

TEST(Link, Get_DatValue) {
    PValue pdv = NULL;
    Link dl;

    dl.SetValue(pdv);

    ASSERT_EQ(dl.GetValue(), pdv);
}

TEST(Link, Get_Next_DatLink) {
    Link dl1;
    Link dl2;

    dl1.SetNextLink(&dl2);

    ASSERT_EQ(&dl2, dl1.GetNexLink());
}

TEST(Monom, Equal) {
    Monom first(10, 20);
    Monom second(10, 20);

    ASSERT_TRUE(first == second);
}

TEST(Monom, Not_equal) {
    Monom first(10, 20);
    Monom second(10, 25);

    ASSERT_TRUE(!(first == second));
}

TEST(Monom, EqualityExponent_1) {
    Monom* first = new Monom(5, 1, 4, 3);
    Monom* second = new Monom(7, 1, 4, 3);

    ASSERT_TRUE(first->EqualityExponent(*second));
}

TEST(Monom, EqualityExponent_2) {
    Monom* first = new Monom(5, 1, 4, 3);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(first->EqualityExponent(*second));
}

TEST(Monom, Comparison_of_monomials_1) {
    Monom* first = new Monom(5, 1, 4, 3);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_TRUE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_2) {
    Monom* first = new Monom(5, 1, 3, 3);
    Monom* second = new Monom(7, 1, 4, 4);

    ASSERT_FALSE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_3) {
    Monom* first = new Monom(5, 1, 3, 3);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_4) {
    Monom* first = new Monom(5, 1, 3, 4);
    Monom* second = new Monom(7, 1, 3, 3);

    ASSERT_TRUE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_5) {
    Monom* first = new Monom(5, 2, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_TRUE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_6) {
    Monom* first = new Monom(5, 0, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_7) {
    Monom* first = new Monom(5, 1, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second < *first);
}

TEST(Monom, Comparison_of_monomials_21) {
    Monom* first = new Monom(5, 1, 4, 3);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_22) {
    Monom* first = new Monom(5, 1, 3, 3);
    Monom* second = new Monom(7, 1, 4, 4);

    ASSERT_TRUE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_23) {
    Monom* first = new Monom(5, 1, 3, 3);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_TRUE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_24) {
    Monom* first = new Monom(5, 1, 3, 4);
    Monom* second = new Monom(7, 1, 3, 3);

    ASSERT_FALSE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_25) {
    Monom* first = new Monom(5, 2, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_26) {
    Monom* first = new Monom(5, 0, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_TRUE(*second > *first);
}

TEST(Monom, Comparison_of_monomials_27) {
    Monom* first = new Monom(5, 1, 3, 4);
    Monom* second = new Monom(7, 1, 3, 4);

    ASSERT_FALSE(*second > *first);
}

TEST(Monom, multiplication_Monom) {
    Monom first(3, 1, 3, 5);
    Monom second(4, 0, -3, 1);
    Monom result(12, 1, 0, 6);

    first = first * second;

    ASSERT_TRUE(result == first);
}

TEST(Head, Ins_First) {
    int size = 1;
    int res_size = 2;
    int mon[][4] = { { 1, 0, 0, 3 } };
    int resmon[][4] = { { 2, 1, 0, 0 } , { 1, 0, 0, 3 } };
    Monom Mon(2, 1, 0, 0);
    Polinom old(mon, size);
    Polinom res(resmon, res_size);
    old.InsFirst(dynamic_cast<PValue> (&Mon));

    ASSERT_TRUE(old == &res);
}

TEST(Head, Del_First) {
    int size = 2;
    int res_size = 1;
    int mon[][4] = { { 2, 1, 0, 0 } , { 1, 0, 0, 3 } };
    int resmon[][4] = { { 1, 0, 0, 3 } };
    Polinom old(mon, size);
    Polinom res(resmon, res_size);
    old.DelFirst();

    ASSERT_TRUE(old == &res);
}

TEST(Polinom, Auto_Equal) {
    int size = 1;
    int mon[][4] = { { 1, 0, 0, 3 } };
    Polinom old(mon, size);

    ASSERT_TRUE(old == &old);
}

TEST(Polinom, can_compare_the_polynoms) {
    int size = 3;
    int mon[][4] = { { 2, 1, 0, 0 } , { 2, 0, 0, 4 } , { 1, 0, 0, 3 } };
    Polinom Pol1(mon, size);
    Polinom Pol2(mon, size);

    ASSERT_TRUE(Pol1 == &Pol2);
}

TEST(Polinom, can_copy_polinoms) {
    const int size = 2;
    int mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
    Polinom Pol1(mon, size);
    Polinom Pol2(Pol1);

    ASSERT_TRUE(Pol1 == &Pol2);
}

TEST(Polinom, can_assign_polynoms) {
    const int size = 2;
    int mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
    Polinom Pol1(mon, size);
    Polinom Pol2;

    Pol2 = &Pol1;

    ASSERT_TRUE(Pol1 == &Pol2);
}

TEST(Polinom, can_assign_empty_polynom) {
    Polinom Pol1;
    Polinom Pol2;

    Pol2 = &Pol1;

    ASSERT_TRUE(Pol1 == &Pol2);
}

TEST(Polinom, can_add_Monom_1) {
    const int Size = 2;
    const int resSize = 3;
    int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
    int resMon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } , { 10, 0, 0, 2 } };
    Polinom Pol(Mon, Size);
    Monom monom(10, 0, 0, 2);
    Polinom res(resMon, resSize);

    Pol.AddMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_add_Monom_2) {
    const int Size = 2;
    const int resSize = 1;
    int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
    int resMon[][4] = { { 2, 0, 0, 4 } };
    Polinom Pol(Mon, Size);
    Monom monom(-5, 0, 0, 3);
    Polinom res(resMon, resSize);

    Pol.AddMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_add_Monom_3) {
    const int Size = 2;
    const int resSize = 2;
    int Mon[][4] = { { 2, 0, 0, 4 } , { 5, 0, 0, 3 } };
    int resMon[][4] = { { 6, 0, 0, 4 } , { 5, 0, 0, 3 } };
    Polinom Pol(Mon, Size);
    Monom monom(4, 0, 0, 4);
    Polinom res(resMon, resSize);

    Pol.AddMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_add_Monom_4) {
    const int Size = 2;
    const int resSize = 3;
    int Mon[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } , { 1, 0, 0, 1 } };
    int resMon[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
    Polinom Pol(Mon, Size);
    Monom monom(5, 0, 0, 2);
    Polinom res(resMon, resSize);

    Pol.AddMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_subtract_Monom_1) {
    const int Size = 2;
    const int resSize = 2;
    int Mon[][4] = { { 4, 0, 0, 5 } , { 5, 0, 0, 4 } };
    int resMon[][4] = { { 4, 0, 0, 5 } , { 2, 0, 0, 4 } };
    Polinom Pol(Mon, Size);
    Monom monom(3, 0, 0, 4);
    Polinom res(resMon, resSize);

    Pol.SubMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_subtract_Monom_2) {
    const int Size = 2;
    const int resSize = 2;
    int Mon[][4] = { { 4, 0, 0, 5 } , { 3, 0, 0, 4 } };
    int resMon[][4] = { { 1, 0, 0, 5 } , { 3, 0, 0, 4 } };
    Polinom Pol(Mon, Size);
    Monom monom(3, 0, 0, 5);
    Polinom res(resMon, resSize);

    Pol.SubMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_subtract_Monom_3) {
    const int Size = 3;
    const int resSize = 2;
    int Mon[][4] = { { 4, 0, 0, 5 } , { 3, 0, 0, 4 } , { 2 , 0 , 0 , 2 } };
    int resMon[][4] = { { 4, 0, 0, 5 } , { 2, 0, 0, 2 } };
    Polinom Pol(Mon, Size);
    Monom monom(3, 0, 0, 4);
    Polinom res(resMon, resSize);

    Pol.SubMonom(&monom);

    ASSERT_TRUE(res == &Pol);
}

TEST(Polinom, can_add_up_linear_polynoms) {
    const int size = 1;
    const int ASSERTed_size = 1;
    int mon1[][4] = { { 2, 0, 0, 1 } };
    int mon2[][4] = { { 1, 0, 0, 1 } };
    int ASSERTed_mon[][4] = { { 3, 0, 0, 1 } };
    Polinom Pol1(mon1, size);
    Polinom Pol2(mon2, size);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol1 + &Pol2;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, can_add_up_simple_polynoms_A_plus_B) {
    const int size1 = 3;
    const int size2 = 4;
    const int ASSERTed_size = 4;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int ASSERTed_mon[][4] = { { 2, 0, 0, 5 } , { 10, 0, 0, 4 } ,
    { 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol1 + &Pol2;

    ASSERT_TRUE(ASSERTed_Pol == &Pol);
}

TEST(Polinom, can_add_up_simple_polynoms_B_plus_A) {
    const int size1 = 3;
    const int size2 = 4;
    const int ASSERTed_size = 4;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int ASSERTed_mon[][4] = { { 2, 0, 0, 5 } , { 10, 0, 0, 4 } ,
    { 5, 0, 0, 2 } , { 1, 0, 0, 1 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol2 + &Pol1;

    ASSERT_TRUE(ASSERTed_Pol == &Pol);
}

TEST(Polinom, can_add_up_polynoms) {
    const int size1 = 5;
    const int size2 = 4;
    const int ASSERTed_size = 6;
    int mon1[][4] = { { 10, 9, 9, 9 } , { -21, 5, 0, 0 } ,
    { 10, 4, 3, 2 } , { 8, 3, 2, 1 } , { 5, 2, 1, 3 } };
    int mon2[][4] = { { 20, 7, 0, 2 } , { 1, 5, 0, 0 } ,
    { -8, 3, 2, 1 } , { 15, 0 } };
    int ASSERTed_mon[][4] = { { 10, 9, 9, 9 } , { 20, 7, 0, 2 } ,
    { -20, 5, 0, 0 } , { 10, 4, 3, 2 } , { 5, 2, 1, 3 } ,
    { 15, 0, 0, 0 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol1 + &Pol2;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, can_add_up_many_polynoms_1) {
    const int size1 = 3;
    const int size2 = 4;
    const int size3 = 3;
    const int ASSERTed_size = 6;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
    { 10, 0, 0, 0 } };
    int ASSERTed_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
    { 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom Pol3(mon3, size3);
    Polinom Pol;
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Pol = Pol1 + &Pol2 + &Pol3;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, can_add_up_many_polynoms_2) {
    const int size1 = 3;
    const int size2 = 4;
    const int size3 = 3;
    const int ASSERTed_size = 6;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
    { 10, 0, 0, 0 } };
    int ASSERTed_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
    { 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom Pol3(mon3, size3);
    Polinom Pol;
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Pol = Pol2 + &Pol3 + &Pol1;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, can_add_up_many_polynoms_3) {
    const int size1 = 3;
    const int size2 = 4;
    const int size3 = 3;
    const int ASSERTed_size = 6;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 1, 0, 0, 4 } ,
    { -8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int mon3[][4] = { { 8, 0, 0, 5 } , { 2, 0, 0, 3 } ,
    { 10, 0, 0, 0 } };
    int ASSERTed_mon[][4] = { { 10, 0, 0, 5 } , { 10, 0, 0, 4 } ,
    { 2, 0, 0, 3 } , { 5, 0, 0, 2 } , { 1, 0, 0, 1 } , { 10, 0, 0, 0 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom Pol3(mon3, size3);
    Polinom Pol;
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Pol = Pol2 + &Pol1 + &Pol3;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, can_subtract_simple_polinom) {
    int size1 = 3;
    int size2 = 1;
    int res_size = 3;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 7, 0, 0, 4 } };
    int resmon[][4] = { { 2, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    Polinom first(mon1, size1);
    Polinom second(mon2, size2);
    Polinom third(mon1, size1);
    Polinom res(resmon, res_size);

    first = first - &second;

    ASSERT_TRUE(res == &first);
}


TEST(Polinom, can_subtract_polinom) {
    int size1 = 3;
    int res_size = 2;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 7, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { -2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 4 } , { 7, 0, 0, 2 } };
    Polinom first(mon1, size1);
    Polinom second(mon2, size1);
    Polinom res(resmon, res_size);

    first = first - &second;

    ASSERT_TRUE(res == &first);
}

TEST(Polinom, can_subtract_up_simple_polynoms_A_minus_B) {
    const int size1 = 3;
    const int size2 = 4;
    const int ASSERTed_size = 4;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 7, 0, 0, 4 } ,
    { 8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int ASSERTed_mon[][4] = { { -2, 0, 0, 5 } , { 2, 0, 0, 4 } ,
    { 5, 0, 0, 2 } , { -1, 0, 0, 1 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol1 - &Pol2;

    ASSERT_TRUE(ASSERTed_Pol == &Pol);
}

TEST(Polinom, can_subtract_up_simple_polynoms_B_minus_A) {
    const int size1 = 3;
    const int size2 = 4;
    const int ASSERTed_size = 4;
    int mon1[][4] = { { 9, 0, 0, 4 } , { 8, 0, 0, 3 } ,
    { 5, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 5 } , { 7, 0, 0, 4 } ,
    { 8, 0, 0, 3 } , { 1, 0, 0, 1 } };
    int ASSERTed_mon[][4] = { { 2, 0, 0, 5 } , { -2, 0, 0, 4 } ,
    { -5, 0, 0, 2 } , { 1, 0, 0, 1 } };
    Polinom Pol1(mon1, size1);
    Polinom Pol2(mon2, size2);
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol2 - &Pol1;

    ASSERT_TRUE(ASSERTed_Pol == &Pol);
}

TEST(Polinom, can_subtract_up_polynoms) {
    const int size1 = 5;
    const int size2 = 4;
    const int ASSERTed_size = 6;
    int mon1[][4] = { { 10, 9, 9, 9 } , { -21, 5, 0, 0 } ,
    { 10, 4, 3, 2 } , { 8, 3, 2, 1 } , { 5, 2, 1, 3 } };
    int mon2[][4] = { { 20, 7, 0, 2 } , { 1, 5, 0, 0 } ,
    { 8, 3, 2, 1 } , { 15, 0, 0, 0 } };
    int ASSERTed_mon[][4] = { { 10, 9, 9, 9 } , { -20, 7, 0, 2 } ,
    { -22, 5, 0, 0 } , { 10, 4, 3, 2 } , { 5, 2, 1, 3 } , { -15, 0, 0, 0 } };
    // 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
    Polinom Pol1(mon1, size1);
    // 15-8x^3y^2z+x^5+20x^7z^2
    Polinom Pol2(mon2, size2);
    // 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
    Polinom ASSERTed_Pol(ASSERTed_mon, ASSERTed_size);

    Polinom Pol = Pol1 - &Pol2;

    ASSERT_TRUE(Pol == &ASSERTed_Pol);
}

TEST(Polinom, multiplication_with_simple_polinom) {
    int size1 = 4;
    int size2 = 1;
    int mon1[][4] = { { 5, 3, 0, 6 } , { 4, 2, 4, 3 } ,
    { 10, 2, 3, 5 } , { 10, 0, 0, 0 } };
    int mon2[][4] = { { 2, 1, 1, 1 } };
    // 5*x^3*z^6 + 4*x^2*y^4*z^4 + 10*x^2*y^3*z^5 + 10
    int resMon[][4] = { { 10, 4, 1, 7 } , { 8, 3, 5, 4 } ,
    { 20, 3, 4, 6 } , { 20, 1, 1, 1 } };
    Polinom first(mon1, size1);
    // (2*x*y*z)
    Polinom second(mon2, size2);
    Polinom result(resMon, size1);
    Polinom answer;

    answer = (first * &second);

    ASSERT_TRUE(result == &answer);
}

TEST(Polinom, multiplication_with_big_polinom_4x4) {
    int size = 4;
    int res_size = 16;
    int mon1[][4] = { { 5, 3, 0, 6 } , { 5, 2, 4, 3 } ,
    { 10, 2, 3, 5 } , { 10, 0, 0, 0 } };
    int mon2[][4] = { { 2, 7, 5, 6 } , { 7, 5, 3, 8 } ,
    { 12, 4, 6, 1 } , { 3, 4, 2, 0 } };
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
    Polinom first(mon1, size);
    // 2*x^7*y^5*z^6 + 7*x^5*y^3*z^8 + 12*x^4*y^6*z + 3*x^4*y^2
    Polinom second(mon2, size);
    Polinom result(res_Mon, res_size);

    ASSERT_TRUE(result == &(first * &second));
}

//  Additional tests

TEST(List, DelCurrent) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 2 } };
    int size = 2;
    int ressize = 1;
    Polinom pol(mon, size);
    Polinom res(resmon, ressize);

    pol.Reset();
    pol.DelCurrent();

    ASSERT_TRUE(pol == &res);
}

TEST(Monom, cout_test1) {
    Monom* mon = new Monom(2, 1, 1, 1);
    GTEST_TEST_NO_FATAL_FAILURE_(std::cout << mon, GTEST_NONFATAL_FAILURE_);
}

TEST(Monom, cout_test2) {
    Monom* mon = new Monom(-2, 1, 1, 1);
    GTEST_TEST_NO_FATAL_FAILURE_(std::cout << mon, GTEST_NONFATAL_FAILURE_);
}

TEST(Monom, Equality1) {
    Monom* mon1 = new Monom(2, 1, 1, 1);
    Monom* mon2 = new Monom(3, 1, 1, 5);

    bool res = (*mon2 < *mon1);

    ASSERT_FALSE(res);
}

TEST(Monom, Equality2) {
    Monom* mon1 = new Monom(2, 1, 1, 1);
    Monom* mon2 = new Monom(3, 1, 1, 5);

    bool res = (*mon1 > *mon2);

    ASSERT_FALSE(res);
}

TEST(Polinom, Assignment_to_a_nonzero_polynom) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int mon2[][4] = { { 1, 0, 1, 0 } , { 3, 0, 0, 2 } };
    int size = 2;
    Polinom pol(mon, size);
    Polinom pol2(mon2, size);

    pol2 = pol;

    ASSERT_TRUE(pol == &pol2);
}

TEST(Polinom, Not_Equal_polinoms1) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int resmon[][4] = { { 2, 0, 0, 2 } };
    int size = 2;
    int ressize = 1;
    Polinom pol(mon, size);
    Polinom pol2(resmon, ressize);

    ASSERT_FALSE(pol == &pol2);
}

TEST(Polinom, Not_Equal_polinoms2) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 0, 2 } , { 10, 0, 0, 1 } };
    int size = 2;
    Polinom pol(mon, size);
    Polinom pol2(mon2, size);
    bool result;

    result = (pol == &pol2);

    ASSERT_FALSE(result);
}

TEST(Polinom, cout_polinom) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int size = 2;
    Polinom pol(mon, size);

    GTEST_TEST_NO_FATAL_FAILURE_(std::cout << pol, GTEST_NONFATAL_FAILURE_);
}

TEST(Head, can_create_Head) {
    GTEST_TEST_NO_FATAL_FAILURE_(Head thead, GTEST_NONFATAL_FAILURE_);
}

TEST(RootLink, can_create_RootLink) {
    List list;

    GTEST_TEST_NO_FATAL_FAILURE_(list.~List(), GTEST_NONFATAL_FAILURE_);
}

TEST(RootLink, can_set_next_link) {
    Link* link = new Link();
    Link* TDL = new Link();


    TDL->SetNextLink(reinterpret_cast<RootLink*> (link));
    RootLink* reslink = TDL->GetNextLink();

    ASSERT_TRUE(reslink == link);
}

TEST(List, list_ended) {
    List list;

    int i = list.IsEmpty();

    ASSERT_EQ(1, i);
}

TEST(Link, SetValue_and_GetValue_and_GetNexLink) {
    Link MyLink;
    Link MyLink2(NULL, &MyLink);
    Monom mon(1, 0, 0, 0);

    MyLink.SetValue(reinterpret_cast<Value*> (&mon));

    ASSERT_TRUE(mon == *(reinterpret_cast<Monom*> (MyLink.GetValue())));
    ASSERT_TRUE(&MyLink == MyLink2.GetNexLink());
}

TEST(Polinom, mylt_on_int) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int mon2[][4] = { { 2, 0, 1, 0 } , { 4, 0, 0, 2 } };
    int size = 2;
    Polinom pol(mon, size);
    Polinom res(mon2, size);

    pol = pol * size;

    ASSERT_TRUE(pol == &res);
}

TEST(Head, Head_destructor) {
    Head THR;

    GTEST_TEST_NO_FATAL_FAILURE_(THR.~Head(), GTEST_NONFATAL_FAILURE_);
}

TEST(List, List_IsEmpty) {
    List list;
    int i;

    i = list.IsEmpty();

    ASSERT_EQ(1, i);
}

TEST(List, List_destructor) {
    List list;

    GTEST_TEST_NO_FATAL_FAILURE_(list.~List(), GTEST_NONFATAL_FAILURE_);
}

TEST(Monom, Monom_destructor) {
    Monom monom(1, 0, 0, 0);

    GTEST_TEST_NO_FATAL_FAILURE_(monom.~Monom(), GTEST_NONFATAL_FAILURE_);
}

TEST(Link, Link_functional) {
    Link link2;
    Link link(NULL, &link2);
    Monom monom(1, 0, 0, 0);
    PValue pVal = reinterpret_cast<PValue> (&monom);

    link.SetValue(pVal);

    ASSERT_TRUE(link.GetValue() == pVal);
}

TEST(List, GetLength) {
    int mon[][4] = { { 1, 0, 1, 0 } , { 2, 0, 0, 2 } };
    int size = 2;
    Polinom pol(mon, size);

    ASSERT_EQ(pol.GetListLength() , 2);
}

TEST(Fake, Fake_Test) {
    EXPECT_TRUE(true);
}
