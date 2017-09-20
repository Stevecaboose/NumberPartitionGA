#include "stdafx.h"
#include "GA.h"
#include <list>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <random>

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

void GA::run(int itterations) {

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
	std::cout << "Origonal population (generation 0): " << std::endl;
	displayPopulation(populationVector);



	//THIS IS WHERE THE MAIN LOOP STARTS. THIS IS THE NUMBER OF GENERATIONS THAT ARE PUT INTO THE POPULATION



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	for (int x = 0; x < itterations; x++) {





		//now that the inital population is created we need to select 2 parents using tournament selection

		firstParent = tournament(populationVector, popSize);
		secondParent = tournament(populationVector, popSize);

		//because from the above 2 lines, we loose 1 population size per call to tournament() we need to put the better of the 2 parents back in the population
		
		firstParentFitness = getFitness(firstParent);
		secondParentFitness = getFitness(secondParent);

		if (firstParentFitness >= secondParentFitness) {
			populationVector.push_back(firstParent);
		}
		else {
			populationVector.push_back(secondParent);
		}

		popSize++;

		//next we need to create an offspring using 2-point crossover. These positions will be fixed (for now) 



		firstCross = rand() % solution_size; // position from 0 to X1
		secondCross = rand() % (solution_size + 1 - firstCross) + firstCross; //position fro

		//taking the bits from the first parent up to the first cross
		for (int i = 0; i < firstCross; i++) {
			offspring.push_back(firstParent[i]);
		}
		//taking the bits from the second parent up to the second cross
		for (int i = firstCross; i < secondCross; i++) {
			offspring.push_back(secondParent[i]);
		}
		//taking the bits from the first parent up to the end
		for (int i = secondCross; i < solution_size; i++) {
			offspring.push_back(firstParent[i]);
		}

		//clear parent variables
		firstParent.clear();
		secondParent.clear();

		std::cout << "\n\nSize of offspring: " << offspring.size() << " Which should be equal to the solution size which is: " << solution_size << std::endl;

		//OFFSPRING HAS BEEN CREATED

		//Now the offspring needs to be mutated
		// There is a 10% chance that the bit will be switched

		for (int i = 0; i < solution_size; i++) {
			if (rand() % 100 < 10) {
				if (offspring[i] == "0") {
					offspring[i] = "1";
				}
				else {
					offspring[i] = "0";
				}
			}
		} // end for

		//MUTATION COMPLETE

		// Insert the new offspring back into the population




		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		populationVector.push_back(offspring);
		popSize++;
		//clear offspring variable for place of a new offspring
		offspring.clear();

		std::cout << "Generation: " << x + 1 << std::endl;
		displayPopulation(populationVector);
	} // END MAIN FOR LOOP

	//after our itterations is complete, we need to find the best fitness, the coorisponding binary solution and numeric solution

	//for (int i = 0; i < popSize; i++) {

	//}
}


std::vector<std::string> GA::tournament(std::vector<std::vector<std::string>>& L, int& popSize){

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

	std::cout << "Randomly selecting second contender...\n\n";

	firstIndex = rand() % popSize;
	temp = L[firstIndex]; //store vector in temp
	//erase chosen vector
	L.erase(L.begin() + firstIndex);
	//store the chromosome in the tournament vector
	tournamentVector.push_back(temp);
	popSize--;

	//now our tournament vector has 2 potention parents
	//we need to compare their fitnesses and pick the better of the two

	int fitness1 = getFitness(tournamentVector[0]);
	int fitness2 = getFitness(tournamentVector[1]);

	if (fitness1 <= fitness2) { //fitness needs to be lower for a winner
		//put the winner back into the population
		L.push_back(tournamentVector[0]);
		popSize++;
		return tournamentVector[0];
	}
	else {
		//put the winner back into the population
		L.push_back(tournamentVector[1]);
		popSize++;
		return tournamentVector[1];
	}
}

void GA::displayPopulation(const std::vector<std::vector<std::string>> vector_const) {

	for (int i = 0; i < vector_const.size(); i++) {
		std::cout << "\nChromosome " << i+1 << " : ";
		for (int j = 0; j < solution_size; j++) {
			std::cout << vector_const[i][j] << " ";
		}
		std::cout << "Fitness: " << getFitness(vector_const[i]);
	}

	std::cout << std::endl << std::endl;

}

int GA::getFitness(std::vector<std::string> chromosome) {

	std::vector<int> left, right;
	int leftSum = 0;
	int rightSum = 0;

	for (int i = 0; i < chromosome.size(); i++) {
		if (chromosome[i] == "1") {
			leftSum += sortedList[i];
		}
		else {
			rightSum += sortedList[i];
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