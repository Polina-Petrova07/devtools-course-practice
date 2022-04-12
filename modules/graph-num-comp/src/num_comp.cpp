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
	return 7;
}

