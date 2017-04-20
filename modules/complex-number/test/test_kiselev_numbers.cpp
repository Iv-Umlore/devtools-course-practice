// Copyright 2017 Korniakov Kirill
#include <gtest/gtest.h>
#include <include\complex_number.h>
TEST(Kiselev_complex_number_test, simple_test){
ComplexNumber first(2.0, 3.0);
ComplexNumber second(2.0, 3.0);
EXPECT_TRUE(first == second);
}
TEST(Kiselev_complex_number_test, Add_test){
ComplexNumber first(3.0, 2.5);
ComplexNumber second(2.0, 3.0);
ComplexNumber result(1.0, -0.5);
EXPECT_TRUE(result == first - second);
}
TEST(Kiselev_complex_number_test, multiplication_test){
ComplexNumber first(3.0, 2.0);
ComplexNumber second(2.0, 3.0);
ComplexNumber result(0, 13.0);
EXPECT_TRUE(result == first * second);
}
TEST(Kiselev_complex_number_test, division_test){
ComplexNumber first(2.0, 2.0);
ComplexNumber second(2.0, 2.0);
ComplexNumber result(1.0,0.0);
EXPECT_TRUE(result == first / second);
}