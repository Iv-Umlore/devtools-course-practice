// Copyright 2017 Kiselev Ivan

#include <gtest/gtest.h>
#include "../include/Application.h"

TEST(Application, first_simple_test) {
    EXPECT_TRUE(true);
}

TEST(Application, Open_File) {
    Salary* sal = new Salary();

    sal->CalculateSalary();

    EXPECT_EQ(sal->GetSalary() , 3200);
}
