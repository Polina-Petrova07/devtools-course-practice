// Copyright 2022 Petrova Polina

#include <gtest/gtest.h>
#include "../include/num_comp.h"

TEST(graphTest, can_do_graph_without_parametrs)
{
	ASSERT_NO_THROW(matrixType matrix (5));
}
TEST(graphTest, can_do_matrix_with_a_given_size_0)
{
	// Arrange & Act
	matrixType matrix(7);

	// Assert
	EXPECT_EQ(7, matrix.getNumVert());
}
TEST(graphTest, can_do_matrix_with_a_given_size_1)
{
	// Arrange & Act
	matrixType matrix(33);

	// Assert
	EXPECT_EQ(33, matrix.getNumVert());
}