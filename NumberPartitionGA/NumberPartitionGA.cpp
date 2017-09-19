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


using namespace std;


int main()
{

	/**
	*
	*	Test instance
	**/

	vector<int> testList = {8, 5, 2, 3, 5 };

	/**
	*
	*	Generate random test list
	**/
	srand(static_cast<unsigned int>(time(NULL)));

	vector <int> testRandomList;
	for (int i = 0; i < 300000; i++) {
		testRandomList.push_back(rand() % 10000);
	}

	//Greedy greedy;
	//greedy.run(testList, true);

	//cout << "\nFitness of greedy algorithm (lower is better) = " << greedy.getFitness() << endl;

	GA ga(testList);
	ga.run();
	
    return 0;
}
