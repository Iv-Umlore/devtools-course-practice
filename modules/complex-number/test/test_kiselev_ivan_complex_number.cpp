// Copyright 2017 Kiselev Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kornyakov_Kirill_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kiselev_complex_number_test, simple_test) {
	//Act
	ComplexNumber first(2.0, 3.0);
	ComplexNumber second(2.0, 3.0);

	//Assert
	EXPECT_TRUE(first == second);
}

TEST(Kiselev_complex_number_test, Add_test) {
	//Act
	ComplexNumber first(3.0, 2.5);
	ComplexNumber second(2.0, 3.0);
	ComplexNumber result(1.0, -0.5);

	//Assert
	EXPECT_TRUE(result == first - second);
}

TEST(Kiselev_complex_number_test, multiplication_test) {
	//Act
	ComplexNumber first(3.0, 2.0);
	ComplexNumber second(2.0, 3.0);
	ComplexNumber result(0, 13.0);

	//Assert
	EXPECT_TRUE(result == first * second);
}

TEST(Kiselev_complex_number_test, division_test) {
	//Act
	ComplexNumber first(2.0, 2.0);
	ComplexNumber second(2.0, 2.0);
	ComplexNumber result(1.0, 0.0);

	//Assert
	EXPECT_TRUE(result == first / second);
}