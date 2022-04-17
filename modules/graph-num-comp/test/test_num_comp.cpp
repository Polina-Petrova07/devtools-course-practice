// Copyright 2022 Petrova Polina

#include <gtest/gtest.h>
#include "../include/num_comp.h"

TEST(randTest, do_without_any_throw)
{
	ASSERT_NO_THROW(int n = generateRandEdge());
}
TEST(randTest, do_number_less_two)
{
	//  Arrange & Act
	int n = generateRandEdge();
	EXPECT_GT(3, n);
}