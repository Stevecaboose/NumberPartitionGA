// NumberPartitionGA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <time.h>
#include <string>
#include <algorithm>
#include "Greedy.h"


using namespace std;


int main()
{

	/**
	*
	*	Test instance
	**/

	list<int> testList = { 4, 5, 6, 7, 8 };

	/**
	*
	*	Generate random test list
	**/
	srand(static_cast<unsigned int>(time(NULL)));

	list<int> testRandomList;
	for (int i = 0; i < 300000; i++) {
		testRandomList.push_back(rand() % 10000);
	}

	Greedy greedy;
	greedy.run(testList, true);

	cout << "\nFitness of greedy algorithm (lower is better) = " << greedy.getFitness() << endl;
	
    return 0;
}
