// Lecture07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <math.h>

// These are "prototypes".  Since VS compiles one line at a time, if we got to the first GetGoodInt without these, VS would not understand what they were.
// But with these prototypes, we are saying "I promise this function exists somewhere else".

float BlertTwoNumbers(float tOne, float tOther);
int GetGoodInt(int tLow, int tHigh);
std::string PerformScience(std::string tCreatureOne, std::string tCreatureTwo);

int main()
{
	std::cout << "Enter first number between 1 and 9: ";
	int tFirst = GetGoodInt(1, 9);
	std::cout << "Enter second number between 2 and 13: ";
	int tSecond = GetGoodInt(2, 13);// Even though I am using this function twice with different arguments, there is still only on function.

	int tAnswer = BlertTwoNumbers(tFirst, tSecond);
	std::cout << tAnswer << std::endl;

	std::string tPony = "Pony";
	std::string tMonkey = "Monkey";
	std::string tMonster = tMonkey + tPony;
	for (int i = 0; i < 5; i++)
		tMonster = PerformScience(tMonster, tMonkey);// Keep adding more monkeys to the middle of the monster.
	std::cout << tMonster << std::endl;
	return 0;

}

float BlertTwoNumbers(float tOne, float tOther)
{
	// To Blert is to raise the second number to the first's power and then subtract two
	return pow(tOther, tOne) - 2;
}

int GetGoodInt(int tLow, int tHigh)
{
	// This doesn’t return until it has a good number.  It checks for incorrect range, and invalid non-number
	bool isValid = false;
	int userInput;

	while (!isValid) {
		if (!(std::cin >> userInput)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Not a Number" << std::endl;
		}
		else if (userInput < tLow) {
			std::cout << "Too Low" << std::endl;
		}
		else if (userInput > tHigh) {
			std::cout << "Too High" << std::endl;
		}
		else {
			isValid = true;
		}
	}
	return userInput;
}

std::string PerformScience(std::string tCreatureOne, std::string tCreatureTwo)
{
	// Insert creature two in to the middle of creature one.  Science!
	// Hamster and Emu make a HamEmuster
	double strLength = tCreatureOne.length();

	std::string firstHalf = tCreatureOne.substr(0, strLength / 2);
	std::string secHalf = tCreatureOne.substr(strLength / 2, strLength - 1);

	std::string newWord = firstHalf + tCreatureTwo + secHalf;
	return newWord;
}
