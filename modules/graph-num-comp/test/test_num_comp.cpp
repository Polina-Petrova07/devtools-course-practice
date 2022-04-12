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
TEST(graphTest, can_copy_graph_from_given_matrix_0)
{
	//  Arrenge 
	std::vector<std::vector<int>> Graph;
	const int NUMVERTEX = 3;
	int matrix[NUMVERTEX][NUMVERTEX] = {
		{0,1,1},
		{1,0,1},
		{1,1,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = matrix[i][j];
		}
	}
	// Act & Assert
	ASSERT_NO_THROW(matrixType G(Graph, NUMVERTEX));
}

TEST(graphTest, can_copy_graph_from_given_matrix_1)
{
	//  Arrenge 
	std::vector<std::vector<int>> Graph;
	const int NUMVERTEX = 3;
	int matrix[NUMVERTEX][NUMVERTEX] = {
		{0,1,1},
		{1,0,1},
		{1,1,0}
	};
	for (int i = 0; i < NUMVERTEX; i++)
	{
		Graph.push_back(std::vector <int>());
		for (int j = 0; j < NUMVERTEX; j++)
		{
			Graph[i].push_back(0);
			Graph[i][j] = matrix[i][j];
		}
	}
	//  Act
	matrixType G(Graph, NUMVERTEX);

	//  Assert
	EXPECT_EQ(3, G.getNumVert());
}
TEST(graphTest, operator_work_correct)
{
	//  Arrenge
	matrixType G(3);
	int k;

	// Act & Assert
	ASSERT_NO_THROW(k = G(1, 1));
}
TEST(graphTest, can_do_right_matrix_0)  //  we need matrix without loop
{ 
	//  Arrenge & Act
	matrixType G(3);
	std::vector<int> check;
	for (int i = 0; i < G.getNumVert(); i++)
	{
		for (int j = 0; j < G.getNumVert(); j++)
		{
			if (i == j)
				check.push_back(G(i,j));
		}
	}

	//  Assert
	for (int i = 0; i < G.getNumVert(); i++)
		EXPECT_EQ(0, check[i]);
}
TEST(graphTest, can_do_right_matrix_1)
{
	//  Arrenge & Act
	matrixType G(7);

	//  Assert
	for (int i = 0; i < G.getNumVert(); i++)
	{
		for (int j = 0; j < G.getNumVert(); j++)
		{
			if (i != j)
				EXPECT_EQ(G(i, j), G(j, i));
		}
	}
}