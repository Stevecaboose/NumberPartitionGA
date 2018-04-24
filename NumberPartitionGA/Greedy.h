#pragma once
#include <list>
#include <string>
#include <vector>
#include "InputData.h"

class Greedy
{
public:
	Greedy();
	~Greedy();

	void run(std::vector<int>& L, bool displayTwoLists, InputData in);

	int getFitness() const { return fitness; };

private:
	int fitness;
	std::string binarySolution;
	int listSize;
};

