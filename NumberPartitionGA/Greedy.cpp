#include "stdafx.h"
#include "Greedy.h"
#include <list>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

/**
*	@breif Default constructor for Greedy.
*/
Greedy::Greedy()
{
	binarySolution = "";
	fitness = -1;
}

/**
*	@brief Default deconstructor for Greedy
*/
Greedy::~Greedy()
{
}

/**
*	@brief Starts the main algorithm for the greedy algorithm
*	
*	@param L is a vector containing the origonal number set
*	@param displayTwoLists <bool> Displays extra information about the final results
*	@return void
*/
void Greedy::run(std::vector<int>& L, bool displayTwoLists) {

	listSize = L.size();
	cout << endl << "Size of list to start: " << listSize << endl;
	
	cout << "\n\nOriginal List:\n\n";
	for (auto i = L.begin(); i != L.end(); ++i)
		std::cout << *i << ' ';

	std::sort(L.begin(), L.end());

	cout << "\n\nSorted List:\n\n";

	for (auto i = L.begin(); i != L.end(); ++i)
		std::cout << *i << ' ';
	
	cout << endl << endl << endl;

	vector<int> left, right;
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
			cout << "\nPercent done: " << (i*1.0 / listSize) * 100 << "%";

		}
		else { //need to put it in the left list
			temp = L.back(); //grab last value
			L.pop_back(); //remove last value
			left.push_back(temp); // store it in the last position (left side) 
			leftSum += temp;

			binarySolution += '1';
			cout << "\nPercent done: " << (i*1.0 / listSize) * 100 << "%";
		}

	} //end for

	std::reverse(std::begin(binarySolution), std::end(binarySolution));

	cout << endl << "Size of list after (expected 0): " << L.size() << endl;

	if (displayTwoLists) {
		cout << "Left list:\n";
		for (int i : left) {
			cout << i << endl;
		}

		cout << endl;
		cout << "Right list:\n";

		for (int i : right) {
			cout << i << endl;
		}
	}

	cout << "\nLeft sum = " << leftSum << endl;
	cout << "Right sum = " << rightSum << endl;

	cout << endl << endl << "Binary Solution: " << binarySolution << endl;
	fitness = abs(leftSum - rightSum);

} // end run


