#pragma once
#include <list>
#include <string>

class Greedy
{
public:
	Greedy();
	~Greedy();




	void run(std::list<int>& L, bool displayTwoLists);

	int getFitness() { return fitness; };

private:
	int fitness;
	std::string binarySolution;
	int listSize;
};

