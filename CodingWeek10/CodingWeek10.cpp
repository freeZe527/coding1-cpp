// CodingWeek10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//global variables are dangerous
//global variables exist in all funtions in this source file.
bool debug = false;

//functions!
//f(x) = y
//f(input) = output
//all funtions have a return type, a name, and (input parameters)
//declaring and defining a new function named "sayHello"
//it has a return type of void, which means it returns nothing
//it has one input parameter named "greeting" with a default value of "Hello!"

void sayHello(string greeting = "Hello!") {
    cout << greeting << "\n";
}

void sayGoodbye(string farewell = "Goodbye!") {
    cout << farewell << "\n";
}

//function name is .... triple(int givenNumber)
int triple(int givenNumber) {
    if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

    return givenNumber * 3;                 //this is the output of the function.
}

//function overload
//funtion name is .... triple(double givenNumber)
double triple(double givenNumber) {
    if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

    return givenNumber * 3;
}

string triple(string givenNumber) {
    if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

    return givenNumber + givenNumber + givenNumber;
}

//creating a new function named "getPlayerName
//return type is string, with two input parameters for minSize and maxSize
string getPlayerName(int minSize = 5, int maxSize = 15) {
    string input;

    do {
        cout << "What is your name?\n";
        getline(cin, input);

        //data validation
        if (input.size() < minSize) {
            cout << "Your name needs to be at least " << minSize << " characters long.\n";
        }
        else if (input.size() > maxSize) {
            cout << "Your name cannot be longer than " << maxSize + 1 << " characters.\n";
        }
        else {
            string greeting = "Hello " + input + "!\n";             //create a greeting that includes
            sayHello(greeting);                                     //the player's name
            return input;                                           //output = player's name
        }
    } while (true);
}


int randomNumber(int minNumber = 0, int maxNumber = 10) {

    if (minNumber >= maxNumber) {
        cout << "I can't use those number.\n";
        return -1;
    }

    int range = (maxNumber - minNumber) + 1;
    return rand() % range + minNumber;
}

/*
* my attempt
    string input;

    do {
        cout << "Pick a minimum number.\n";
        getline(cin, input);
        input = minNumber;
        cout << "The minimum number you have chosen is: " << minNumber << ".\n";

        cout << "Pick a maximum number.\n";
        cout << "(Maximum number must be greater than " << minNumber << ".)\n";
        getline(cin, input);
        input = maxNumber;
        if (maxNumber <= minNumber) {
            cout << "Maximum number must be greater than " << minNumber << ".\n";
        }
        else if (maxNumber > minNumber) {
            cout << "The maximum number you have chosen is: " << maxNumber << ".\n";
            return -1;
        }

    } while (true);
}
*/


bool randomBool() {
    int number = rand() % 10;
    //50% of the time
    if (number > 4) 
        return true;
    else 
        return false;
    
}


int main() {
    if (randomBool()) {
        cout << "You've won a prize!!!\n";
    }


    srand(time(0));
    string input;
    cout << "Min = What?: \n";
    getline(cin, input);
    int minNumber = stoi(input);

    cout << "Max = What?: \n";
    getline(cin, input);
    int maxNumber = stoi(input);

    cout << "A random number between " << minNumber << " and " << maxNumber;
    cout << " is " << randomNumber(minNumber, maxNumber) << ".\n";
 
    //call the funtion
    sayHello();
    sayHello("Welcome to the thunderdome!");
    sayGoodbye();
    sayGoodbye("Here's looking at you, kid.");

    string playerName = getPlayerName();        //don't HAVE to specify min and max size

    cout << "Triple of 4 is " << triple(4) << ".\n";
    cout << "Triple of 891.13 is " << triple(891.13) << ".\n";
    cout << "Triple of 6.46 is " << triple(6.46) << ".\n";

  



    cout << "\nWhat are your top 3 favorite foods?\n";
    string favFood[11];
    //string input;

    for (int i = 0; i < 3; i++) {
        cout << "favorite food #" << i + 1 << ": ";
        getline(cin, input);
        cout << "Noted.\n";

        favFood[i] = input;
    }

    cout << "Here are your favorite foods:\n";
    for (int i = 0; i < 3; i++) {
        cout << "#" << i + 1 << ": " << favFood[i] << ".\n";
    }

    sayGoodbye();


}

