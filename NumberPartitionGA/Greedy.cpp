#include "stdafx.h"
#include "Greedy.h"
#include <list>
#include <iostream>
#include <string>
#include <functional>

using namespace std;


Greedy::Greedy()
{
	binarySolution = "";
	fitness = -1;
}


Greedy::~Greedy()
{
}


void Greedy::run(std::list<int>& L, bool displayTwoLists) {

	listSize = L.size();
	cout << endl << "Size of list to start: " << listSize << endl;
	

	L.sort();

	list<int> left, right;
	//take largest value and put it in the left list
	int temp = L.back(); //grab last value
	L.pop_back(); //remove last value

				  
	left.push_front(temp);//store it in left

	binarySolution += '1';

	//Now we have to make it loop to push the most right ele in L to the left or right list.

	int leftSum = temp;
	int rightSum = 0;

	for (int i = 0; i < listSize - 1; i++) {
		if (leftSum > rightSum) { //need to put it in the right list
			temp = L.back();
			L.pop_back();
			right.push_front(temp);
			rightSum += temp;

			binarySolution += '0';
			cout << "\nPercent done: " << (i*1.0 / listSize) * 100;

		}
		else { //need to put it in the left list
			temp = L.back();
			L.pop_back();
			left.push_front(temp);
			leftSum += temp;

			binarySolution += '1';
			cout << "\nPercent done: " << (i*1.0 / listSize) * 100;
		}

	} //end for

	std::reverse(std::begin(binarySolution), std::end(binarySolution));

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

	cout << endl << endl << "Binary Solution: " << binarySolution << endl;
	fitness = abs(leftSum - rightSum);

} // end run


