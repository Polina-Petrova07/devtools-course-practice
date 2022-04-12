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
			Graph[i][j] = 0;
		}
	}
}
int matrixType::getNumVert()
{
	return this->Graph.size();
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

