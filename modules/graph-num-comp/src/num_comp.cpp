// Copyright 2022 Petrova Polina

#include"../include/num_comp.h"

int generateRandEdge()
{
	int k;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);  //  can do graph with weight
	k = dist(gen);
	return k;
}