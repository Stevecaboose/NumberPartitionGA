/**
*	@file Greedy.cpp
*	@author Steven Scholz
*	@date 4/23/18
*	@version 1.0
*	
*	@breif This file performs the greedy algorithm for the parition problem
*/

#include "Greedy.h"
#include <list>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include "InputData.h"


/**
*	@breif Default constructor for Greedy.
*/
Greedy::Greedy()
{
	binarySolution = "";
	fitness = -1;
	listSize = 0;
}

/**
*	@brief Default deconstructor for Greedy
*/
Greedy::~Greedy()
= default;

/**
*	@brief Starts the main algorithm for the greedy algorithm
*	
*	@param L is a vector containing the origonal number set
*	@param displayTwoLists <bool> Displays extra information about the final results
*	@return void
*/
void Greedy::run(std::vector<int>& L, bool displayTwoLists, InputData in) {

	listSize = L.size();
	std::cout << std::endl << "Size of list to start: " << listSize << std::endl;
	
	std::cout << "\n\nOriginal List:\n\n";
	in.displayList();

	std::sort(L.begin(), L.end());

	std::cout << "\n\nSorted List:\n\n";

	for (auto i = L.begin(); i != L.end(); ++i)
		std::cout << *i << ' ';
	
	std::cout << std::endl << std::endl << std::endl;

	std::vector<int> left, right;
	//take largest value and put it in the left list
	int temp = L.back(); //grab last value
	L.pop_back(); //remove last value

				  
	left.push_back(temp);//store it in left at the end (easier to do for vectors)

	binarySolution += '1';

	//Now we have to make it loop to push the most right ele in L to the left or right list.

	int leftSum = temp;
	int rightSum = 0;

	for (int i = 0; i < listSize - 1; i++) {
		if (leftSum > rightSum) { //need to put it in the right list
			temp = L.back(); //grab last value
			L.pop_back(); //remove last value
			right.push_back(temp); //store it in right last position (right side)
			rightSum += temp;

			binarySolution += '0';
			std::cout << "\nPercent done: " << (i*1.0 / listSize) * 100 << "%";

		}
		else { //need to put it in the left list
			temp = L.back(); //grab last value
			L.pop_back(); //remove last value
			left.push_back(temp); // store it in the last position (left side) 
			leftSum += temp;

			binarySolution += '1';
			std::cout << "\nPercent done: " << (i*1.0 / listSize) * 100 << "%";
		}

	} //end for

	std::reverse(std::begin(binarySolution), std::end(binarySolution));

	std::cout << std::endl << "Size of list after (expected 0): " << L.size() << std::endl;

	if (displayTwoLists) {
		std::cout << "Left list:\n";
		for (auto i : left) {
			std::cout << i << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Right list:\n";

		for (auto i : right) {
			std::cout << i << std::endl;
		}
	}

	std::cout << "\nLeft sum = " << leftSum << std::endl;
	std::cout << "Right sum = " << rightSum << std::endl;

	std::cout << std::endl << std::endl << "Binary Solution: " << binarySolution << std::endl;
	fitness = abs(leftSum - rightSum);

} // end run


