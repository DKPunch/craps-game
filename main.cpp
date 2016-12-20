// A simple craps simulation
// Date: April 11, 2016
// Author: Joe Schell
// Sources: None.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//Global Constants
const int CHIPS = 500;

// Function Prototypes
bool playGame();
int  rollDice();
void welcomeMessage();
void closeProgram();

int main()
{
	int currentStack;
	char reply;
	string line;

	srand((unsigned)time(NULL));

	welcomeMessage();
	currentStack = CHIPS;
	cout << "You have $" << currentStack << " to play with." << endl;
	cout << "Your wager is $10 per game" << endl;

	do {
		if (currentStack >= 10) {
			if (playGame() == true) {
				currentStack += 10;
			}
			else {
				currentStack -= 10;
			}
		}
		else {
			cout << "Sorry, you are bankrupt!!!" << endl;
			break;
		}
		cout << "You have $" << currentStack << " available." << endl;
		cout << "Would you like to play again (y/n) ";
		getline(cin, line);
		if (line.length() == 0) {
			reply = 'y';
		}
		else {
			reply = line.at(0);
		}
	} while (reply == 'y' || reply == 'Y');
	cout << "Thank you for playing craps!!!" << endl;
	cout << "Please press <Enter> to quit:";
	getline(cin, line);
	return 0;
}

bool playGame()
{
	int die1, die2;
	int point;
	int total;
	string reply;
	die1 = rollDice();
	die2 = rollDice();
	point = die1 + die2;
	cout << "The point is set at: " << point << endl;
	if (point == 7 || point == 11) {
		cout << "Player wins!!!" << endl;
		return true;
	}
	else if (point == 2 || point == 3 || point == 12) {
		cout << "Player loses!!!" << endl;
		return false;
	}
	else {
		do {
			cout << "Press enter to roll the dice:";
			getline(cin, reply);
			die1 = rollDice();
			die2 = rollDice();
			total = die1 + die2;
			cout << "The total is " << total << endl;
		} while (!(total == point || total == 7));
		if (total == point) {
			cout << "Player wins!!!" << endl;
			return true;
		}
		else {
			cout << "Player loses!!!" << endl;
			return false;
		}
	}
}

int rollDice()
{
	int die;
	// Generate a random number between 1 and 6.
	die = 1 + rand() % 6;
	switch (die) {
	case 1:
		cout << "You rolled a 1" << endl;
		break;
	case 2:
		cout << "You rolled a 2" << endl;
		break;
	case 3:
		cout << "You rolled a 3" << endl;
		break;
	case 4:
		cout << "You rolled a 4" << endl;
		break;
	case 5:
		cout << "You rolled a 5" << endl;
		break;
	default:
		cout << "You rolled a 6" << endl;
	}
	return die;
}

void welcomeMessage()
{
	string line;
	char reply;
	cout << "Would you like to play craps? (y/n) ";
	getline(cin, line);
	if (line.length() == 0) {
		reply = 'y';
	}
	else {
		reply = line.at(0);   
	}
	switch (reply) {
	case 'n':
	case 'N':
		cout << "Thanks for playing." << endl;
		closeProgram();
	case 'y':
	case 'Y':
		cout << "Welcome to the craps table!!!" << endl;
		return;
	default:
		cout << "Sorry, I didn't understand." << endl;
		closeProgram();
	}
}

void closeProgram()
{
	string line;
	cout << "Please press <Enter> to quit:";
	getline(cin, line);
	exit(1);
}
