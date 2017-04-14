#include <gtest/gtest.h>
#include <include\complex_number.h>

TEST(Kiselev_complex_number_test, simple_test)
{
	ComplexNumber first(2.0, 3.0);
	ComplexNumber second(2.0, 3.0);
	EXPECT_TRUE(first==second)
}