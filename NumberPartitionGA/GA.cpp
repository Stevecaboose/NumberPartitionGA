#include "stdafx.h"
#include "GA.h"
#include <list>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

GA::GA()
{
	srand(static_cast<unsigned int>(time(NULL)));
	popSize = 0;
}

GA::GA(std::vector<int> startingList) {

	srand(static_cast<unsigned int>(time(NULL)));
	popSize = 0;
	std::sort(startingList.begin(), startingList.end());
	sortedList = startingList;
	solution_size = startingList.size();
}

GA::~GA()
{
}

void GA::run() {

	// make a test vector
	

	std::vector <std::vector<std::string>> populationVector;
	std::vector<std::string> temp;

	for (int i = 0; i < INIT_POP_SIZE; i++) {
		for (int j = 0; j < solution_size; j++) {
			if (rand() % 2 == 0) {
				temp.push_back("0");
			}
			else {
				temp.push_back("1");
			}
		}
		populationVector.push_back(temp);
		popSize++;
		temp.clear();
		
	} //end for

	displayPopulation(populationVector);

	//now that the inital population is created we need to select 2 parents using tournament selection

	tournament(populationVector, popSize);
	
}


void GA::tournament(std::vector<std::vector<std::string>>& L, int& popSize){

	std::cout << "Randomly selecting first contender...\n\n";
	
	int firstIndex = rand() % popSize;
	

	std::vector<string> temp;
	std::vector<std::vector<std::string>> tournamentVector;
	
	temp = L[firstIndex]; //store vector in temp
	//erase chosen vector
	L.erase(L.begin() + firstIndex);
	//store the chromosome in the tournament vector 
	tournamentVector.push_back(temp);
	popSize--;

	//now we need to get another chromosome 
	temp.clear(); 

	firstIndex = rand() % popSize;
	temp = L[firstIndex]; //store vector in temp
	//erase chosen vector
	L.erase(L.begin() + firstIndex);
	//store the chromosome in the tournament vector
	tournamentVector.push_back(temp);

	//now our tournament vector has 2 potention parents
	//we need to compare their fitnesses and pick the better of the two

	int fitness1 = getFitness(tournamentVector[0]);
	int fitness2 = getFitness(tournamentVector[1]);
}

void GA::displayPopulation(const std::vector<std::vector<std::string>> vector_const) {

	for (int i = 0; i < vector_const.size(); i++) {
		std::cout << "\nChromosome " << i+1 << " : ";
		for (int j = 0; j < solution_size; j++) {
			std::cout << vector_const[i][j] << " ";
		}
	}

	std::cout << std::endl << std::endl;

}

int GA::getFitness(std::vector<std::string> chromosome) {

	std::vector<int> left, right;
	int leftSum = 0;
	int rightSum = 0;

	for (int i = 0; i < chromosome.size(); i++) {
		if (chromosome[i] == "1") {
			leftSum =+ sortedList[i];
		}
		else {
			rightSum =+ sortedList[i];
		}
	}

	return abs(leftSum - rightSum);

}

std::vector<int> GA::getSortedList() {

	cout << "\n\nSorted List:\n\n";

	for (int i = 0; i < sortedList.size(); i++) {
		std::cout << sortedList[i] << ' ';
	}

	cout << endl << endl << endl;

	return sortedList;
}