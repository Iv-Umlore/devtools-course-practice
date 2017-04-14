#include <gtest\gtest.h>

#include <include\complex_number.h>

TEST(complex_number, First_test)
{
	double real = 2.0;
	double imaginary = 3.0;
	ComplexNumber first(real, imaginary),second(real,imaginary);
	EXPECT_TRUE(first==second);
}