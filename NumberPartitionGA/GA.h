#pragma once
#include <vector>
class GA
{
public:
	GA();
	GA(std::vector<int> startingList);
	~GA();

	void run(); //no input data. Data is randomly generated
	void tournament(std::vector<std::vector<std::string>>& L, int& popSize);
	void displayPopulation(const std::vector<std::vector<std::string>> vector_const);
	int getFitness(std::vector<std::string> chromosome);
	std::vector<int> getSortedList();

private:
	std::vector<std::string> testVector;
	const int INIT_POP_SIZE = 10; //starting number of potential parents in the population (population size)
	int solution_size; //size of a chromosome which must equal the size of the instance
	int popSize;
	std::vector<int> sortedList;
};

