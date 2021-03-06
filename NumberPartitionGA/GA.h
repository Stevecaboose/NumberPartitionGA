#pragma once
#include <vector>
class GA
{
public:
	GA();
	GA(std::vector<int> startingList, int popsize);
	~GA();

	void run(int itterations); //no input data. Data is randomly generated
	std::vector<std::string> tournament(std::vector<std::vector<std::string>>& L, int& popSize);
	void displayPopulation(const std::vector<std::vector<std::string>>& vector_const);
	int getFitness(std::vector<std::string> chromosome);
	std::vector<int> getSortedList();
	void setBestSolution(std::vector<std::vector<std::string>>& L);


	struct finalSolutionStruct
	{
		int fitness;
		std::vector<std::string> binarySolution;
		std::vector<int> leftPartition;
		std::vector<int> rightPartition;
	} finalSolution;

private:
	std::vector<std::string> testVector;
	int INIT_POP_SIZE; //starting number of potential parents in the population (population size)
	int solution_size; //size of a chromosome which must equal the size of the instance
	int popSize;
	std::vector<int> sortedList;
	std::vector<std::string> firstParent;
	std::vector<std::string> secondParent;
	std::vector<std::string> offspring;
	int firstParentFitness;
	int secondParentFitness;
	int firstCross; 
	int secondCross;
	int bestSolutionIndex;

};

