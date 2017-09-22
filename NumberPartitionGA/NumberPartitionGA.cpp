/**
*	@file NumberPartitionGA.cpp
*	@author Steven Scholz
*	@date 9/21/17
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
*	is much higher in this algorithm than actaul biology. This is to help speed up the process. 10% probabilty is a good area to work with.
*
*	After the finite number of generations are completed, the algorithm might have found multiple solutions. All of the best solutions are then
*	shown with their respective fitness (abs(sumLeft - sumRight)), binary chromosome, and numeric partitions.
*
*   You can use the argument -h to call the help menu for the different command line arguments
*/

#include "stdafx.h"
#include <iostream>
#include <list>
#include <time.h>
#include <string>
#include <algorithm>
#include "Greedy.h"
#include "GA.h"
#include <vector>
#include <conio.h>


void check();
void helpMenu();

using namespace std;


int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(NULL)));


	vector<int> testList = {4, 5, 6, 7, 8};


	bool useRandomList = false;
	bool useGAAlgorithm = false;
	bool useGreedyAlgorithm = false;
	int popsize;
	int itterations;
	int randomListSize;
	bool showHelp = true;
	int randomListStart = 0;
	int randomListEnd = 10;


	if (argc == 6) {
		randomListStart = atoi(argv[4]);
		randomListEnd = atoi(argv[5]);
	}
	else if (argc == 8) {
		randomListStart = atoi(argv[6]);
		randomListEnd = atoi(argv[7]);
	}
	else if (argc == 9) {
		randomListStart = atoi(argv[7]);
		randomListEnd = atoi(argv[8]);
	}

	std::string showHelpString = argv[1];
	std::string help = "-h";

	if ((showHelpString.compare(help)) == 0) {
		showHelp = true;
	}

	//if only doing greedy algorithm (arguments = 4)
	if (argc == 6 || argc == 8) {

		

			std::string argv1 = argv[1];
			if (argv1 == "-greedy") {
				useGreedyAlgorithm = true;
			}
			
			// Nested if if we are doing ga algorithm
			////////////////////////////////////////////////
			if (argv1 == "-ga") {
				useGAAlgorithm = true;

				std::string argv2 = argv[2];
				if (argv2 == "-rand") {
					useRandomList = true;
				}

				randomListSize = stoi(argv[3]);
				if (randomListSize <= 0) {
					std::cout << "Invalid argument for randomListSize. Value must not be negative.\n";
					std::cout << "Use -h for help menu\n";
					check();
					return 0;
				}

				popsize = stoi(argv[4]);

				if (popsize <= 0) {
					std::cout << "Invalid argument for popsize. Value must not be negative.\n";
					std::cout << "Use -h for help menu\n";
					check();
					return 0;
				}

				itterations = stoi(argv[5]);
				if (itterations <= 0) {
					std::cout << "Invalid argument for itterations. Value must not be negative.\n";
					std::cout << "Use -h for help menu\n";
					check();
					return 0;
				}
			}

			////////////////////////////////////////

			std::string argv2 = argv[2];
			if (argv2 == "-rand"){
				useRandomList = true;
			}
		
			randomListSize = stoi(argv[3]);
			if (randomListSize <= 0) {
				std::cout << "Invalid argument for randomListSize. Value must not be negative.\n";
				std::cout << "Use -h for help menu\n";
				check();
				return 0;
			}

			//popsize = stoi(argv[4]);

			//if (popsize <= 0) {
			//	cout << "Invalid argument for popsize. Value must not be negative.\n";
			//	cout << "Use -h for help menu\n";
			//	check();
			//	return 0;
			//}

			//itterations = stoi(argv[5]);
			//if (itterations <= 0) {
			//	cout << "Invalid argument for itterations. Value must not be negative.\n";
			//	cout << "Use -h for help menu\n";
			//	check();
			//	return 0;
			//}

			showHelp = false;

	}else if (argc == 9) { //USING BOTH ALGORITHMS 

		std::string argv1 = argv[1];
		std::string argv2 = argv[2];
		if (argv1 == "-ga" || argv2 == "-ga") {
			useGAAlgorithm = true;
		}

		argv1 = argv[1];
		argv2 = argv[2];
		if (argv1 == "-greedy" || argv2 == "-greedy") {
			useGreedyAlgorithm = true;
		}

		std::string argv3 = argv[3];
		if (argv3 == "-rand") {
			useRandomList = true;
		}

		randomListSize = stoi(argv[4]);
		if (randomListSize <= 0) {
			std::cout << "Invalid argument for randomListSize. Value must not be negative.\n";
			std::cout << "Use -h for help menu\n";
			check();
			return 0;
		}

		popsize = stoi(argv[5]);

		if (popsize <= 0) {
			std::cout << "Invalid argument for popsize. Value must not be negative.\n";
			std::cout << "Use -h for help menu\n";
			check();
			return 0;
		}

		itterations = stoi(argv[6]);
		if (itterations <= 0) {
			std::cout << "Invalid argument for itterations. Value must not be negative.\n";
			std::cout << "Use -h for help menu\n";
			check();
			return 0;
		}

		showHelp = false;
		
	}
	else {
		std::cout << "\n\nEither help menu called or invalid arguments...\n\n";
		helpMenu();
		check();
		return 0;

	}



	vector <int> testRandomList;

	if (useRandomList) {
		std::cout << "\nUsing random list with a size of: " << randomListSize << endl;
		for (int i = 0; i < randomListSize; i++) {
			testRandomList.push_back(rand() % (randomListEnd - randomListStart + 1) + randomListStart);
		}
	}
	else { //if theres a problem or you want to use a random first argument. This will be
		   // generated
		std::cout << "Random command not recognized...making a random list using numbers from 0 to 10..." << endl;
		for (int i = 0; i < 10; i++) {
			testRandomList.push_back(rand() % 10);
		}

	}

	if (useGAAlgorithm) {
		std::cout << "Using genetic algorithm with a population of: " << popsize << " and the number of generations: " << itterations << endl;
		GA ga(testRandomList, popsize);
		ga.run(itterations);



		/////////////////////////////////////////
		//DISPLAY RESULTS OF GA/////////////////



		std::cout << "Optimal solution results: \n\n";
		std::cout << "Original SORTED list: \n{";

		std::sort(testRandomList.begin(), testRandomList.end());

		for (int i = 0; i < testRandomList.size(); i++) {
			std::cout << " " << testRandomList[i];
		}


		std::cout << " }\n\nFitness: " << ga.finalSolution.fitness << std::endl << std::endl;
		std::cout << "Binary Solution: ";

		for (int i = 0; i < ga.finalSolution.binarySolution.size(); i++) {
			std::cout << ga.finalSolution.binarySolution[i] << " ";
		}

		std::cout << "\n\nLeft Partition: { ";
		for (int i = 0; i < ga.finalSolution.leftPartition.size(); i++) {
			std::cout << ga.finalSolution.leftPartition[i] << " ";
		}

		std::cout << "}\n\n";

		std::cout << "\nRight Partition: { ";
		for (int i = 0; i < ga.finalSolution.rightPartition.size(); i++) {
			std::cout << ga.finalSolution.rightPartition[i] << " ";
		}

		std::cout << "}\n\n";

		//////////////////////////////////////////////////////////////



	} // END GA RUN

	if (useGreedyAlgorithm) {
		std::cout << "Using greedy algorithm..." << endl;
		Greedy greedy;
		greedy.run(testRandomList, true);

		std::cout << "\nFitness of greedy algorithm (lower is better) = " << greedy.getFitness() << endl;
		check();

	}


	//check();

    return 0;
}

/**
*	@brief Keeps the console from closing after main has finished
*	
*	@return void
*/
void  check()
{
	char chk; int j;
	std::cout << "\n\nPress any key to exit...";
	chk = _getch();
	j = chk;
	for (int i = 1; i <= 256; i++)
		if (i == j) break;
	
}

/**
*	@brief Displays the help menu to the console
*	
*	@return void
*/
void helpMenu() {

	std::cout << "\n\nNumberPartitionGA.exe -greedy -rand  <RandomListSize <INT> > <RandomListStart <INT> > <RandomListEnd <INT> >" << endl << endl;
	
	std::cout << "-greedy                     Use the greedy algorithm" << endl;
	std::cout << "-rand                       Use a randomly generated list" << endl;
	std::cout << "<randomListSize> <INT>      How many elements are in the list" << endl;
	std::cout << "<RandomListStart> <INT>     The starting range of random numbers in the original set" << endl;
	std::cout << "<RandomListEnd> <INT>       The ending range of ranom numbers in the original set. Must be greated than <RandomListStart> <INT>" << endl << endl;


	std::cout << "\n\nNumberPartitionGA.exe   -ga -rand  <RandomListSize <INT> > <PopulationSize <INT> > <Generations <INT> > <RandomListStart <INT> > <RandomListEnd <INT> >" << endl << endl;
	std::cout << "-ga                         Use genetic algorithm" << endl;
	std::cout << "-rand                       Use a randomly generated list" << endl;
	std::cout << "<randomListSize> <INT>      How many elements are in the list" << endl;
	std::cout << "<PopulationSize> <INT>      How many chromosomes are in the population" << endl << endl;
	std::cout << "<Generations> <INT>         How many generations (itterations) do you want to go through " << endl;
	std::cout << "<RandomListStart> <INT>     The starting range of random numbers in the original set" << endl;
	std::cout << "<RandomListEnd> <INT>       The ending range of ranom numbers in the original set. Must be greated than <RandomListStart> <INT>" << endl << endl;
	
	std::cout << "\n\nNumberPartitionGA.exe   -greedy -ga -rand  <RandomListSize <INT> > <PopulationSize <INT> > <Generations <INT> > <RandomListStart <INT> > <RandomListEnd <INT> >" << endl << endl;
	std::cout << "-greedy                     Use the greedy algorithm" << endl;
	std::cout << "-ga                         Use genetic algorithm" << endl;
	std::cout << "-rand                       Use a randomly generated list" << endl;
	std::cout << "<randomListSize> <INT>      How many elements are in the list" << endl;
	std::cout << "<PopulationSize> <INT>      How many chromosomes are in the population" << endl << endl;
	std::cout << "<Generations> <INT>         How many generations (itterations) do you want to go through " << endl;
	std::cout << "<RandomListStart> <INT>     The starting range of random numbers in the original set" << endl;
	std::cout << "<RandomListEnd> <INT>       The ending range of ranom numbers in the original set. Must be greated than <RandomListStart> <INT>" << endl << endl;


}