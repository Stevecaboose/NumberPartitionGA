/**
*	@file NumberPartitionGA.cpp
*	@author Steven Scholz
*	@date 4/23/18
*	@version 1.0
*
*	@brief Use a greedy algorithm and genetic algorithm to solve the number partition problem
*
*	@section DESCRIPTION
*
*	
*	This is a program to run two algorithms to solve the well-known Number Partition Problem (NPP)
*	The NPP is taking a set of numbers and partition that set. Each element in the original set may be placed in either of the two sub partitions.
*	The goal is to find a solution where the sum of the numbers in each partition is equal. For this particular algorithm, a fitness is represented
*	by an integer. A perfect solution will have a value of 0. As this number increases, the solution is further from a perfect solution. For a
*	particular set, there might not be a perfect solution. A "chromosome" is the term I will use for a particular solution. A chromosome is
*	represented as a binary string of 1's and 0's. A 1 represents a value in one of the two partitions and a 0 represents a value in the other
*	partition. Each position of the bits corresponds to the position of the SORTED ascending original list.
*
*	These two algorithms are as follows:
*	A greedy algorithm called the longest processing time heuristic. This algorithm first takes the largest element in the original set and places
*	it in the "left" partition. The sum for that partition is then calculated (one value at this point). The element is then removed from the
*	original set. The repetitive process at this point is to take the highest value element in the original set and place it in the partition
*	with the smaller sum. This is repeated until there are no longer any elements left in the original set.
*
*	The genetic algorithm (GA) is an algorithm that takes elements from biological evolution and mimics them to alter chromosomes that have a
*	better fitness than their respective parents. The general steps I take for this algorithm are:
*
*	* Creating a finite set of randomly generated chromosomes (initial population)
*
*	* Using 2-tournament selection to choose two parents from the population
*
*	* Use 2-point crossover to splice the chromosomes from the two parents to create an offspring chromosome
*
*	* Simulate genetic mutation by making the probability of each bit in an offspring chromosome be the opposite of what it was. This probability
*	is much higher in this algorithm than actaul biology. This is to help speed up the process. 5% probabilty is a good area to work with.
*
*	After the finite number of generations are completed, the algorithm might have found multiple solutions. All of the best solutions are then
*	shown with their respective fitness (abs(sumLeft - sumRight)), binary chromosome, and numeric partitions.
*
*   You can use the argument -h to call the help menu for the different command line arguments
*/


#include <iostream>
#include <list>
#include <ctime>
#include <string>
#include <algorithm>
#include "Greedy.h"
#include "GA.h"
#include <vector>
#include <conio.h>
#include "InputData.h"
#include <fstream>

const std::string INPUTFILE = "InputData.csv";


void check();
void intToASCII(const int n);



int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(NULL)));


	std::vector<int> testList = {4, 5, 6, 7, 8};


	bool useRandomList = false;
	bool useGAAlgorithm = true;
	bool useGreedyAlgorithm = false;
	int popsize;
	int itterations;
	int randomListSize;
	bool showHelp = true;
	int randomListStart = 0;
	int randomListEnd = 10;		
	
	//load in file
	//make file loader

	InputData data(INPUTFILE);

	std::vector<int> dataList = data.getdataSet();


	if (useGAAlgorithm) {
		std::cout << "How many itterations would you like to use?";
		std::cin >> itterations;

		popsize = dataList.size();
		std::cout << "Using genetic algorithm with a population of: " << popsize << " and the number of generations: " << itterations << std::endl;
		GA ga(dataList, popsize);
		ga.run(itterations);



		/////////////////////////////////////////
		//DISPLAY RESULTS OF GA/////////////////



		std::cout << "Optimal solution results: \n\n";
		std::cout << "Original SORTED list: \n{";

		std::sort(dataList.begin(), dataList.end());

		for (int i = 0; i < dataList.size(); i++) {
			std::cout << " " << dataList[i];
		}


		std::cout << " }\n\nFitness: " << ga.finalSolution.fitness << std::endl << std::endl;
		std::cout << "Binary Solution: ";

		for (int i = 0; i < ga.finalSolution.binarySolution.size(); i++) {
			std::cout << ga.finalSolution.binarySolution[i] << " ";
		}

		std::cout << "\n\nLeft Partition: { ";
		for (int i = 0; i < ga.finalSolution.leftPartition.size(); i++) {
			std::cout << ga.finalSolution.leftPartition[i] << " ";
			intToASCII(ga.finalSolution.leftPartition[i]);
		}

		std::cout << "}\n\n";

		std::cout << "\nRight Partition: { ";
		for (int i = 0; i < ga.finalSolution.rightPartition.size(); i++) {
			std::cout << ga.finalSolution.rightPartition[i] << " ";
			intToASCII(ga.finalSolution.rightPartition[i]);
		}

		std::cout << "}\n\n";

		//////////////////////////////////////////////////////////////



	} // END GA RUN

	

	if (useGreedyAlgorithm) {
		std::cout << "Using greedy algorithm..." << std::endl;
		Greedy greedy;
		greedy.run(dataList, true, data);

		std::cout << "\nFitness of greedy algorithm (lower is better) = " << greedy.getFitness() << std::endl;
		check();

	}


	check();
	

	getchar();
    return 0;
}

/**
*	@brief Keeps the console from closing after main has finished
*	
*	@return void
*/
void  check()
{
	std::cout << "\n\nPress any key to exit...";
	const char chk = _getch();
	int j = chk;
	for (auto i = 1; i <= 256; i++)
		if (i == j) break;
	
}

void intToASCII(const int n)
{
	char buffer = n;
	std::cout << buffer << " ";
} 