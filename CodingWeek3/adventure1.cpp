#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	
	string name;
	int pHealth = 10;
	int pAttack;
	int block;
	int turns = 0;
	string die;
	int eHealth = rand() % 5 + 2;
	int damagePerTurn;
	int nam;
	string eName[6];

	eName[0] = "Troll";
	eName[1] = "Frank";
	eName[2] = "Goblin";
	eName[3] = "Zombie";
	eName[4] = "Skeleton";
	eName[5] = "Orc";

	//Intro to game
	cout << "WELCOME BRAVE TRAVELER.\n";
	cout << "WHO MAY I HAVE THE PLEASURE SPEAKING WITH?\n\n";
	getline(cin, name);
	cout << "\nWELL NICE TO MEET YOU, " << name << "! LET'S GET THIS STARTED.\n";
	cout << "DO YOU KNOW WHAT YOU'RE DOING HERE?\n(Y/N)\n";

	//Explains the concept/rules, starting the game
	string answer;
	
	cin >> answer;
	if (answer == "y") {
		cout << "\nDo you dare enter?\n(Y/N)\n";
	}

	if (answer == "n") {
		cout << "You will go through a series of rooms, battling the denizens of THIS PLACE!\n";
		cout << "Equiped with a mighty sword and sheild, you will make your way through THIS PLACE and claim your reward at the end.\n";
		cout << "\nor DIE TRYING!\n";
		cout << "\nDo you dare enter?\n(Y/N)\n";
	}

	cin >> answer;
	if (answer == "n") {
		cout << "\nBye Bye!";
		return 0;
	}

	if (answer == "y") {
		cout << "\nHere we go!\n";
	}

	//Game Start
	while (turns < 5) {

		//beginning of floor
		nam = rand() % 6;

		cout << "\nWelcome to floor " << turns + 1 << "!\n";
		cout << "This time, you are facing a wild " << eName[nam] << "!\n";
		cout << "The " << eName[nam] << " has " << eHealth << " health!\n";


		//Gameplay
		int attack;
		int block;
		damagePerTurn = rand() % 5
			
			+ 1;
		while (eHealth > 0) {

			attack = rand() % 4;
			block = rand() % 3;

			//Player choice
			cout << "Get ready to ATTACK!\n";
			system("pause");	//wait for input
			eHealth -= attack;
			if (eHealth < 0) {
				eHealth = 0;
			}
			cout << "\nYou did " << attack << " damage!\n";
			cout << "the " << eName[nam] << " has " << eHealth << " health remaining!\n";

			if (eHealth > 0) {
				cout << "Get ready to block the " << eName[nam] << "\'s ATTACK!\n";
				system("pause");
				//Block damage
				damagePerTurn -= block;
				if (damagePerTurn < 0) {
					damagePerTurn = 0;
				}
				pHealth -= damagePerTurn;
				if (pHealth < 0) {
					pHealth = 0;
				}
				cout << "\nYou blocked " << block << " damage of the " << eName[nam] << "\'s attack!\n";
				cout << "The " << eName[nam] << " did " << damagePerTurn << " damage!\n\n";
				cout << name << " has " << pHealth << " health remaining!\n";
				cout << eName[nam] << " has " << eHealth << " health remaining!\n";

				//Player death
				if (pHealth <= 0) {
					cout << "You were defeated! Better luck next time.\n";
					return 0;
				}
			}
			else
			{
				//end of floor
				cout << "\nGreat Job " << name << ", you defeated the " << eName[nam] << "!\n";
				cout << "Would you like to continue?\n(Y/N)\n";
				cin >> answer;
				if (answer == "y" && turns < 4) {
					cout << "\nOnto the next floor!\n";
					turns += 1;
				}
				else if (answer == "n") {		//Quit if wanted
					cout << "Bye Bye!";
					return 0;
				}
				//Win
				else if (turns == 4) {
					cout << "\nCongrats! Your reward is a pat on the back!\n";
					cout << "Would you like to try again?\n(Y/N)\n";
					cin >> answer;
					if (answer == "y") {
						turns = 0;
					}
					else if (answer == "n") {
						cout << "\nAw man :(\n";
						cout << "Frick off then >:(\n";
						return 0;
					}
				}
			}
		}
		eHealth = rand() % 5 + 3;
	}
}