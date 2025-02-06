//Aurora Garacia Coding 1 Spring 2025 Week 3
//Variables, Logic, and Randomness
// HOMEWORK INFO VVVVVV!!!!
//to work on hw, right click CodingWeek3, Exclude from project, work on adventure1

#include <iostream>		//in out stream sends text to and from the console
#include <string>		//allows us to use stringe variables
#include <cstdlib>
#include <ctime>

using namespace std;	//so we don't have to type std:: all the time

//this is where the program starts running
//it's a function that returns an integer
int main() {
	srand(time(0));
	cout << "Here's a random number for you: " << rand() << ".\n";
	cout << "Here's a random number for you: " << rand() << ".\n";
	cout << "Here's a random number for you: " << rand() << ".\n";
	cout << "Here's a random number for you: " << rand() << ".\n";

	//modulus gives remainder of long division
	cout << "7 divided by 2 = " << 7 / 2 << " with a remainder of " << 7 % 2 << ".\n";

	cout << "A random number between 1 and 10 (inclusive): " << (rand() % 10) + 1 << ".\n";

	//1-10 inclusive could be 1 or 10
	//1-10 exclusive could NOT be 1 or 10, but only 2 to 9

	cout << "here are this week's grades for the class. (50 and 100).\n";
	int counter = 0;
	//while the test is true, keep looking
	//while (test) { code block }
	while (counter < 10) {
		counter += 1;
		cout << (rand() % 50) + 50 << "\n";
	}

	cout << "Hello! What is your name?\n";
	string input;			//create a variable to hold player's input
	cin >> input;			//assign input from console to input variable

	if (input == "Aurora") {
		cout << "What is the pasword?\n";
		cin >> input;
		if (input == "Pizza") {			//nested if statement
			cout << "Hello creator!\n";
		}
		else {
			cout << "Imposter!!! ALERT ALERT ALERT\n";
			return 0;				//quites out of the program early
		}
	}
	//default statement
	else {
		cout << "Hello " << input << ".\n";
	}

	cout << "Are you ready to play a game?\n";
	//a character is a single character, anything you could type on your keyboard
	char playerCharInput = 'n';
	//a string is an ordered list of characters. you could say it's an array of characters
	string name = "aurora";

	int totalTurns = 0;
	do {
		cout << "Press 'y' to keep playing.\n";		//Ask the player for input
		cin >> playerCharInput;						//get input
		totalTurns += 1;

		//totalTurns++;		//increment operator is ++

	} while (playerCharInput == 'y');				//test the input

	//todo: use a switch statement
	cout << "You played for " << totalTurns << " turns!\n";





	//all code inside a code block should be indented
	cout << "\tWelcome to Week 3!\n";
	cout << "We're talking about Variables, Logic, and Randomness today.\n";

	//variables are nicknames for data
	//creating a variable of the type integer named "age" with the declared value of 19.
	int age = 19;
	int score = 0;		//declaring the variable, but not defining the variable

	cout << "Always initialize your variables.\n";
	
	//let's talk about camelCase
	//capitalize each new word after the first one
	int playerOneFuelAmount = 43;

	//an integer is a whole number, positive or negative, between -2bil and +2bil
	int oceanDepth = -234;

	//floats are floating-point numbers. they have a decimal point!
	//they're accurate to 7-digits
	//creating a constant float named "pi" with the value of "3.1415"
	const float pi = 3.1415f;

	//doubles are double-precision floating point numbers. accurate to 22-digits.
	double someNumberWithDecimalPlaces = 3456.789012323;

	cout << "\nPlayer 1's fuel amount is " << playerOneFuelAmount << ".\n";
	cout << "Your current Depth is " << oceanDepth << " meters.\n";
	cout << "The value of 'pi' is " << pi << ".\n";
	cout << "Hey, look at this number " << someNumberWithDecimalPlaces << "!\n";

	//when using random numbers, don't forget to
	//#include <cstdlib>	for rand() and srand()
	//#include <ctime>		for time()



}	//end of main()