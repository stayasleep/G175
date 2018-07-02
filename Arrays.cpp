
// Arrays.cpp : Defines the entry point for the console application.
// Arrays and loops and user input 

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
void printValue(int num);

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

	int index = 0;
	cout << "Please enter an interger for the index you want to change: ";
	cin >> index;

	int value; //new value for element
	cout << "Okay, what should the new int value be for the element in the"
		<< " " << index << " index position: ";
	cin >> myFirstArray[index];

	for (int i = 0; i < 9; i++) {
		printValue(myFirstArray[i]);
	}
	cout << endl;




    return 0;
}

void printValue(int num) {
	cout << num << " ";
}

