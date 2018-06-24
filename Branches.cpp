
// Branches.cpp : Defines the entry point for the console application.
// Display the value of a die of a particular size

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//declare and initialize some variables;
	int sides = 0, 
		value = 0;
	string stars;
	
	//Prompt user for the size of die
	cout << "Please enter the size of the die you wish to play with: ";

	//Implementing some crude validation
	if(!(cin >> sides)){			
		cout << "That was not a numerical value! Defaulting to a 6 sided die." << endl;
		//clear cin stream so we can use it again
		cin.clear();
		//ignore amount x from cin or until new line
		cin.ignore(1000, '\n');
		//assign sides to default
		sides = 6;
	}

	//validate size of die against permitted sizes
	int legalSizes[6] = { 4,6,8,10,12,20 };
	bool isLegalSize = false;

	for (int j = 0; j < 6; j++) {
		if (legalSizes[j] == sides) {
			isLegalSize = true;
			break;
		}
	}

	//Set allowed size if validation failed
	if (!isLegalSize) {
		cout << "You entered an invalid size!  Defaulting to a 6 sided die." << endl;
		sides = 6;
	}
	
	//Prompt user for desired value
	cout << "Please enter the value of the face of the die: ";
	do {
		
		if (!(cin >> value)) {
			cout << "That\'s not a numerical value! Please enter a positive integer instead: ";
			cin.clear(); 
			cin.ignore(10000, '\n');
			//skip rest of logic but stay inside the loop for next iteration
			continue;
		}

		if (value <= 0) {
			cout << "Value must be greater than or equal to 1.  Defaulting to a value of 1 instead." << endl;
			value = 1;
			break;
		}
	} while (value < 1 );

	//value must be less than or equal to the highest # on die
	if (value > sides) {
		cout << "The value provided is too high! Let\'s use a value of 1 instead." << endl;
		value = 1;
	}

	if (sides == 4 || sides == 8 || sides == 20) {
		cout << "    *" << endl;
		cout << "   * * " << endl;
		cout << "  *   *  " << endl;
		cout << " *" << setw(3) << value << "  * " << endl;
		cout << stars.assign(9, '*') << endl;
	}
	else if (sides == 10) {
		cout << "      *     " << endl;
		cout << "    *   *   " << endl;
		cout << "   *" << setw(3) << value << "  *" << endl;
		cout << "  *       *" << endl;
		cout << "   *     *" << endl;
		cout << "    *   *" << endl;
		cout << "      *" << endl;
	}
	else if (sides == 12) {
		//formatting helps when value takes 1 or 2 spaces when outputting
		cout << "      *" << endl;
		cout << "  *      *" << endl; 
		cout << "*          *" << endl;
		cout << " *" << setw(5) << value << "   *" << endl;
		cout << "  *      *" << endl;
		cout << "   ******" << endl;
	}
	else {
		cout << stars.assign(7, '*') << endl;
		cout << "*     *" << endl;
		cout << "*  " << value << "  *" << endl;
		cout << "*     *" << endl;
		cout << stars.assign(7, '*') << endl;
	}
    return 0;
}
