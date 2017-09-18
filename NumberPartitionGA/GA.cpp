#include "stdafx.h"
#include "GA.h"
#include <list>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

GA::GA()
{
	srand(static_cast<unsigned int>(time(NULL)));
}


GA::~GA()
{
}

void GA::run() {

	std::list<int> testList = { 4, 5, 6, 7, 8 };
	const int numberOfInitialParents = 10;
	const int listSize = testList.size();

	//generate candidate solutions

	std::list<std::list<std::string>> candidateSolutions;
	std::list<std::string> tempList;
	std::list<std::string>::iterator itr_inner;
	std::list< std::list<std::string> >::iterator itr_outer;

	for (int i = 0; i < numberOfInitialParents; i++) {

		for (int j = 0; j < listSize; j++) {

			if ((rand() % 2) + 1 == 2) {
				tempList.push_back("1");
			}
			else {
				tempList.push_back("0");
			}
		}

		candidateSolutions.push_back(tempList);
		tempList.clear();
	}

	std::cout << "List of candidate solutions are now generated\n";

	for (itr_outer = candidateSolutions.begin(); itr_outer != candidateSolutions.end(); ++itr_outer) {
		std::list<std::string> current_selection = *itr_outer;

		for (itr_inner = current_selection.begin(); itr_inner != current_selection.end(); ++itr_inner){
			std::cout << "\t" << *itr_inner << "\n";
		}

		std::cout << std::endl;

	}
}


std::list<std::string> GA::tournament(std::list<std::string>& L, int size){

//pick 2 random candidates from the population

	int randIndex = rand() % size; //generates a random index to pick from the list

	//find the nth element using std::advance()

	//find randIndex index

	//create iterator pointing to the first element
	std::list<std::string>::iterator it = L.begin();

	//advance the iterator by randIndex number of positions
	std::advance(it, randIndex);

	std::cout << "Tournament pick starting...\n\n";
	std::cout << "Picking first contender...\n\n";
	std::cout << "First random candidate solution selected is: " << *it << "\nWith an index position of " << randIndex << std::endl;
	

	std::cout << "Picking second contender";

	std::list<std::string> test = { "" };
	return test;

}