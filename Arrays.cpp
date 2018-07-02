// Arrays.cpp : Defines the entry point for the console application.
// Arrays and loops and user input 

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
void printValue(int num);
void showValues(int nums[], int size);

int main()
{
	srand(time(NULL));
	const int ARR_SIZE = 9;
	int myFirstArray[ARR_SIZE] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };

	cout << "Let\'s loop through our first array: " << endl;

	for (int i = 0; i < 9; i++) {
		myFirstArray[i] = rand() % 7 + 1;
		printValue(myFirstArray[i]);
	}
	cout << endl;

	int index = 0,
		value;

	while (index != -1 && index < ARR_SIZE) {
		cout << "Please enter an interger for the index you want to change "
			<< "or enter -1 to exit the loop instead." << endl;

		if (!(cin >> index)) {
			cout << "You entered a non interger value, shame!  Let\'s try this again..." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}

		if (index >= ARR_SIZE) {
			cout << "You entered an out of bounds index!  Exiting the loop so "
				<< "something unintended does not happen instead." << endl;
			cin.ignore(10000, '\n');
			break;
		}
		else if (index == -1) {
			cout << "Exiting menu options." << endl;
			break;
		}
		else if (index < 0) {
			cout << "That\'s not a valid index position.  Please try again." << endl;
			continue;
		}

		cout << "Please enter the new integer value for the element in the " << index
			<< " index position." << endl;

		if (!(cin >> value)) {
			cout << "Invalid data type, cannot assign it to element in the index position " << index
				<< ", exiting the loop instead." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		myFirstArray[index] = value;

		showValues(myFirstArray, ARR_SIZE);

	};

    return 0;
}

void showValues(int nums[], int size) {
	for (int i= 0; i < size; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void printValue(int num) {
	cout << num << " ";
}
