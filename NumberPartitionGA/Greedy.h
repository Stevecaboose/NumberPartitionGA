#pragma once
#include <list>
#include <string>
#include <vector>

class Greedy
{
public:
	Greedy();
	~Greedy();




	void run(std::vector<int>& L, bool displayTwoLists);

	int getFitness() { return fitness; };

private:
	int fitness;
	std::string binarySolution;
	int listSize;
};

