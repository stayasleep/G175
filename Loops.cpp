
// Loops.cpp : Defines the entry point for the console application.
/*
  A game of rock, paper, and scissors! Built in game statistics and basic user
  interaction .
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	//declare game variables
	int won = 0,
		lost = 0;
	char userInput;
	char playGame = 'y';
	char legalMoves[3] = { 'R', 'P', 'S' };

	do {
		//seed the random number sequence
		srand(time(NULL));

		cout << "Please enter \"R\" for rock, \"P\" for paper,  "
			<< "and \"S\" for scissors." << endl;
		//cin >> userInput;

		if (!(cin >> userInput)) {
			cout << "You entered invalid input! Please play again.";
			continue;
		}

		//check againt invalid input 
		if (!isalpha(userInput)) {
			cout << "You entered a number! Please play again with the allowed characters instead." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		bool isLegal = false;
		for (int j = 0; j < 3; j++) {
			//uppercase in order to allow sneaky players to play either form of a letter
			if (legalMoves[j] == toupper(userInput)) {
				userInput = toupper(userInput);
				isLegal = true;
				break;
			}
		}

		if (!isLegal) {
			cout << "You played an incorrect move! Please play again." << endl;
			//clear cin buffer for next use
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		//super cool AI
		//each outcome has equal probability of being chosen
		int random = rand() % 3;

		char aiMove = legalMoves[random];
		cout << "I picked " << aiMove << endl;

		//biz logic
		if (userInput == 'R') {
			if (aiMove == 'P') {
				lost += 1;
				cout << "You lose!" << endl;
			}
			else if (aiMove == 'S') {
				won += 1;
				cout << "You win!" << endl;
			}
			else {
				cout << "Tie! Try again!!!" << endl;
				continue;
			}
		}
		else if (userInput == 'S') {
			if (aiMove == 'P') {
				won += 1;
				cout << "You win!" << endl;
			}
			else if (aiMove == 'R') {
				lost += 1;
				cout << "You lose!" << endl;
			}
			else {
				cout << "Tie! Try again!!!" << endl;
				continue;
			}
		}
		else {
			if (aiMove == 'R') {
				won += 1;
				cout << "You win!" << endl;
			}
			else if (aiMove == 'S') {
				lost += 1;
				cout << "You lose!" << endl;
			}
			else {
				cout << "Tie! Try again!!!" << endl;
				continue;
			}
		}

		cout << "Would you like to play again? (y/n)" << endl;
		cin >> playGame;
		if (isalpha(playGame)) {
			playGame = tolower(playGame);
			if (playGame != 'y' && playGame != 'n') {
				cout << "That was not a valid option.  Defaulting to \"no\" instead." << endl;
				playGame = 'n';
			}
		}
		else {
			cout << "Only letters should be entered.  Defaulting to \"no\" instead." << endl;
			playGame = 'n';
		}

	} while (playGame == 'y');
	cout << "Thanks for playing user!" << endl;

	double totalPlayed = won + lost;
	double winRate = won / totalPlayed * 100;

	cout << "You won " << won << " and lost " << lost << " games." << endl;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "That\'s a win rate of " << winRate <<"%" << endl;

    return 0;
}

