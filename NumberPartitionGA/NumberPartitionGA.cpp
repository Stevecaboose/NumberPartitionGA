// NumberPartitionGA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

int greedy(list<int> L, bool displayTwoLists);

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
	srand(time(NULL));

	list<int> testRadnomList;
	for (int i = 0; i < 300000; i++) {
		testRadnomList.push_back(rand() % 10000);
	}

	cout << "\nFitness of greedy algorithm (lower is better) = " << greedy(testList, true) << endl;
	
    return 0;
}

int greedy(list<int> L, bool displayTwoLists) {

	cout << endl << "Size of list to start: " << L.size() << endl;
	int listSize = L.size();

	L.sort(); //ascending order
	list<int> left, right;
	//take largest value and put it in the left list
	int temp = L.back(); //grab last value
	L.pop_back(); //remove last value

	//store it in left
	left.push_front(temp);

	//Now we have to make it loop to push the most right ele in L to the left or right list.

	int leftSum = temp;
	int rightSum = 0;

	for (int i = 0; i < listSize - 1; i++) {
		if (leftSum > rightSum) { //need to put it in the right list
			temp = L.back();
			L.pop_back();
			right.push_front(temp);
			rightSum += temp;

		}else{ //need to put it in the left list
			temp = L.back();
			L.pop_back();
			left.push_front(temp);
			leftSum += temp;
		}

	} //end for
	
	cout << endl << "Size of list after (lower is better (0 is a perfect solution): " << L.size() << endl;

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

	int fitness = abs(leftSum - rightSum);

	return fitness;
}
