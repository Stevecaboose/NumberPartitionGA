// NumberPartitionGA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <time.h>
#include <string>
#include <algorithm>
#include "Greedy.h"
#include "GA.h"
#include <vector>
#include<conio.h>


void  check();

using namespace std;


int main()
{

	/**
	*
	*	Test instance
	**/

	vector<int> testList = {4, 5, 6, 7, 8};

	/**
	*
	*	Generate random test list
	**/
	srand(static_cast<unsigned int>(time(NULL)));

	vector <int> testRandomList;
	for (int i = 0; i < 10; i++) {
		testRandomList.push_back(rand() % 10);
	}

	//Greedy greedy;
	//greedy.run(testList, true);

	//cout << "\nFitness of greedy algorithm (lower is better) = " << greedy.getFitness() << endl;



	/////////////////////////////////////////
	//DISPLAY RESULTS OF GA/////////////////


	GA ga(testRandomList);
	ga.run(50);
	
	std::cout << "Optimal solution results: \n\n";
	std::cout << "Fitness: " << ga.finalSolution.fitness << std::endl;
	std::cout << "Binary Solution: ";

	for (int i = 0; i < ga.finalSolution.binarySolution.size(); i++) {
		std::cout << ga.finalSolution.binarySolution[i] << " ";
	}

	std::cout << "\nLeft Partition: {";
	for (int i = 0; i < ga.finalSolution.leftPartition.size(); i++) {
		std::cout << ga.finalSolution.leftPartition[i] << " ";
	}

	std::cout << " }\n";

	std::cout << "\nRight Partition: {";
	for (int i = 0; i < ga.finalSolution.rightPartition.size(); i++) {
		std::cout << ga.finalSolution.rightPartition[i] << " ";
	}

	std::cout << " }\n";

	//////////////////////////////////////////////////////////////

	check();

    return 0;
}

void  check()
{
	char chk; int j;
	cout << "\n\nPress any key to continue...";
	chk = _getch();
	j = chk;
	for (int i = 1; i <= 256; i++)
		if (i == j) break;
	
}