// Copyright 2022 Petrova Polina

#include <random>
#include "../include/num_comp.h"


// NOLINTNEXTLINE
matrixType::matrixType(int n)
{
	matrixType::numVert = n;
	for (int i = 0; i < numVert; i++)
	{
		matrixType::Graph.push_back(std::vector<int>());
		for (int j = 0; j < numVert; j++)
		{
			Graph[i].push_back(0);
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = generateRandEdge();
		}
	}
	for (int i = 0; i < numVert; i++)
		for (int j = 0; j < numVert; j++)
			Graph[i][j] = Graph[j][i];
}
int matrixType::getNumVert()
{
	return this->Graph.size();
}
int& matrixType::operator()(int i, int j)
{
	return this->Graph[i][j];
}
matrixType::matrixType(std::vector<std::vector<int>> G, int numvert)
{
	matrixType::numVert = numvert;
	matrixType::Graph = G;
}
int generateRandEdge()
{
	int k;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);
	k = dist(gen);
	return k;
}

