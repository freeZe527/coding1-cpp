#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//GLOBAL VARIABLES VVV
string name;
int health = 100;
int totalTreasure = 0;
bool temp;
bool temp2;
//GLOBAL VARIABLES ^^^

/*Notes VVV

(Notes about my notes)
"vvv" and "^^^" are arrows pointing at the line below and above
 ^^^The amount of repeated characters may vary, but will usually be around 3
 "<<" and ">>" are also arrows I may use, however it is less likely since I'll just add notes to the end of a line

I liked a lot of the dialogue I had written in Adventure 1.0 so I kept quite a bit of it.
Some concepts are also very similar 

*/

//Intro to Game
void introStory() {
	cout << "WELCOME BRAVE TRAVELER.\n";
	cout << "WHO MAY I HAVE THE PLEASURE SPEAKING WITH?\n\n";
	getline(cin, name);
	cout << "\nWELL NICE TO MEET YOU, " << name << "! LET'S GET THIS STARTED.\n";
}

//Explaination of Game
void explainStory() {
	cout << "\nYou will wander through Strawberry Sunset Land where glorious treasure awaits. . .\n";
	system("pause");
	cout << "That treasure being STRAWBERRIES!!\n";
	system("pause");
	cout << "But beware, as creatures may be roaming and protecting said Strawberries!\n";
	cout << "Equiped with a mighty sword and shield,\nYou will make your way through Strawberry Sunset Land and gather as many Strawberries as you can hold!\n";
	system("pause");
	cout << "\nor DIE TRYING!\n\n";
	system("pause");
}


//Yes or No function
bool AskYesNo() {
	string input;

	//pretty sure this works, for the longest time I thought the while loop wouldn't work so I didn't even consider it
	while (true) {
		cout << "(Type \"Yes\" or \"No\")\n";
		getline(cin, input);

		if (input == "Yes") {
			return true;
			break;
		}
		else if (input == "No") {
			return false;
			break;
		}
		else {
			cout << "\nCheck spelling and capitalization, make sure there are no spaces or symbols, and try again.\n";
		}
	}
	
}

//50/50 chance
bool FlipCoin() {
	int number = rand() % 2; 
	if (number == 1)
		return true;
	else
		return false;
}

//Chance to Crit, 3* damage
int rollD12() {
	int number = (rand() % 12) + 1;
	return number;
}

//General Rolling
int rollD6() {
	int number = (rand() % 6) + 1;
	return number;
}

//Small Treasure Roll
int rollD50() {
	int number = (rand() % 50) + 2;
	return number;
}

//Treasure Roll
int rollD100() {
	int range = (rand() % 25) + 26;
	int number = (rand() % 100) + range;
	return number;
}

//A bit of prior knowledge from a prior class and a bit of help from a friend vvv
class enemy {
public:
	int eHealth = 0;
	int eAttack = 0;
	string eName = "";
	enemy(string x, float y, int z) 
	{
		eName = x;
		eHealth = y;
		eAttack = z;
	}
};

enemy FuncEnemy() {
	enemy Troll("Troll", 15, 8);
	enemy Goblin("Goblin", 6, 4);
	enemy Zombie("Zombie", 6, 6);
	enemy Skeleton("Skeleton", 4, 5);
	enemy Demon("Demon", 12, 12);
	enemy meanBird("Mean Bird", 1, 1);
	enemy Gnome("Gnome", 3, 4);
	enemy Slime("Slime", 7, 5);
	enemy giantRat("Giant Rat", 5, 4);
	enemy Squirrel("Squirrel", 1, 2);
	enemy Lizard("Large Lizard that Occasionally Coughs Up Fire", 20, 10);
	enemy Joe("Joe", 8, 2);		//he doesn't go to the gym

	enemy enemies[12] = {Troll, Goblin, Zombie, Skeleton, Demon, meanBird, Gnome, Slime, giantRat, Squirrel, Lizard, Joe};

	return enemies[rand() % 12];
}

void chanceDialogue() {
	int chance = rollD6();
	if (chance == 1) {
		cout << "\nCrossing a stream, you spot what looks like a pile of Strawberries. . .\n";
		cout << "Approaching the pile, you notice ";
	}
	else if (chance == 2) {
		cout << "\nAcross a clearing, you spot what looks like a mound of Strawberries. . .\n";
		cout << "Approaching the mound, you notice ";
	}
	else if (chance == 3) {
		cout << "\nIn a small cave, you spot what looks like a stack of Strawberries. . .\n";
		cout << "Approaching the stack, you notice ";
	}
	else if (chance == 4) {
		cout << "\nNext to a tree, you spot what looks like a heap of Strawberries. . .\n";
		cout << "Approaching the heap, you notice ";
	}
	else if (chance == 5) {
		cout << "\nAlong a path, you spot what looks like a clump of Strawberries. . .\n";
		cout << "Approaching the clump, you notice ";
	}
	else if (chance == 6) {
		cout << "\nBehind a large rock, you spot what looks like a lump of Strawberries. . .\n";
		cout << "Approaching the lump, you notice ";
	}
}

//Secret Boss fight
void SecretBoss() {
	enemy Narrator("Narrator", 75, 12);
	system("pause");
	cout << "\nI'll make this a bit more fair and heal you up a bit\n";
	health += 30;
	cout << "You gained 30 health and now have " << health << " health.\n";
	cout << "Compared to you, I have 75 health, and I can whittle your lame " << health << " health down in a matter of turns!\n";
	cout << "(You feel a surge of power in you, you now do more damage per hit!)\n";
	cout << "However, I won't go too easy!\n";

	while (health > 0 && Narrator.eHealth > 0) {
		int critChance = rollD12();
		int attack = rollD6();
		int block = rollD6();
		attack *= 2;
		if (critChance == 12) {
			attack *= 3;
			block *= 2;
		}
		if (Narrator.eHealth > 0) {
			cout << "\nIt's MY turn!\n";
			system("pause");
			cout << "\nYou raise your shield and block " << block << " of MY " << Narrator.eAttack << " attack damage!\n";
			if ((Narrator.eAttack - block) == 0) {
				cout << "Lucky b*tch\n";
				cout << "You took 0 damage and have " << health << " health!\n";
			}
			else {
				health -= (Narrator.eAttack - block);
				if (health <= 0) {
					health = 0;
				}
				cout << "I did " << (Narrator.eAttack - block) << " damage and you have " << health << " health left!\n";
			}
			if (health > 0 && Narrator.eHealth > 0) {
				cout << "It's your turn now loser!\n";
				system("pause");
				cout << "\nYou swing your sword and do " << attack << " damage!\n";
				if (critChance == 12) {
					cout << "It's a critical hit!\n";
				}
				Narrator.eHealth -= attack;
				if (Narrator.eHealth < 0) {
					Narrator.eHealth = 0;
				}
				cout << "I have " << Narrator.eHealth << " health remaining!\n";
				system("pause");
				if (Narrator.eHealth == 0) {
					cout << "\nF*CK!\n";
					system("pause");
					cout << "\nYou got me.\n";
					system("pause");
					cout << "\nI guess you can keep your " << totalTreasure << " Strawberries!\n";
					system("pause");
					cout << "\nGet out of my sight\n";
					system("pause");
					cout << "\n . . .\n\n";
					system("pause");
					cout << "\n(The Narrator has died)\n";
					system("pause");
					cout << "\n(You leave Strawberry Sunset Land with " << health << " health, and " << totalTreasure << " Strawberries)\n";
					break;
				}
				else {
					
				}
			}
			else if (health == 0) {
				cout << "\nThanks for all " << totalTreasure << " of your Strawberries!\n";
				system("pause");
				cout << "\nLoser\n";
			}
			else if (Narrator.eHealth == 0) {
				cout << "\nF*CK!\n";
				system("pause");
				cout << "\nYou got me.\n";
				system("pause");
				cout << "\nI guess you can keep your " << totalTreasure << " Strawberries!\n";
				system("pause");
				cout << "\nGet out of my sight\n";
				system("pause");
				cout << "\n . . .\n\n";
				system("pause");
				cout << "\n(The Narrator has died)\n";
				system("pause");
				cout << "\n(You leave Strawberry Sunset Land with " << health << " health, and " << totalTreasure << " Strawberries)\n";
				break;
			}
		}
	}
	
	//make really hard but not impossible
	//goofy ending, probably no narration if won
}

//End Treasure Counter
void endingTreasure() {
	if (totalTreasure >= 0 && totalTreasure <= 50) {
		cout << "\nThat is such a pitiful amount of Strawberries. . .\n";
		cout << "You should actually try next time. . .\n";
	}
	else if (totalTreasure > 50 && totalTreasure <= 200) {
		cout << "\nThat is quite a bit of Strawberries!\n";
		cout << "Good Job!\n";
	}
	else if (totalTreasure > 200 && totalTreasure <= 500) {
		cout << "\nWow! That is a lot of Strawberries!\n";
		cout << "Great Job!\n";
	}
	else if (totalTreasure > 500 && totalTreasure < 1000) {
		cout << "\nWOW!! That is so A LOT of Strawberries!!\n";
		cout << "Amazing Job, " << name << "!\n";
	}
	else if (totalTreasure >= 1000) {
		cout << "\n . . .\n\n";
		system("pause");
		cout << "\nScratch that, you're not leaving just yet " << name << "!\n";
		cout << "That is such a large amount of Strawberries! I need them from you!!\n";
		cout << "(The narrator is fighting you for your Strawberries)\n";
		SecretBoss();
	}
}

//Ending
void Ending() {
	if (health > 0) {
		cout << "\nYou leave Strawberry Sunset Land with " << health << " health, and " << totalTreasure << " Strawberries!\n";
		system("pause");
		endingTreasure();
	}
	else {
		system("pause");
		cout << "\nDespite your best attempts, you DIED on your journey through Strawberry Sunset Land!\n";
		cout << "Better luck next time!\n";
	}
}

//Gameplay
void Adventure() {
	chanceDialogue();
	temp = FlipCoin();
	temp2 = FlipCoin();
	enemy tempEnemy = FuncEnemy();
	//safe treasure	1/4 chance
	if (temp == true && temp2 == true) {
		cout << "that there is nothing guarding the Strawberries!\n";
		int treasure = rollD50();
		cout << "You found " << treasure << " Strawberries!\n";
		totalTreasure += treasure;
		cout << "You now have " << totalTreasure << " Strawberries!\n";
		cout << "Would you like to continue?\n";
	}
	//dangerous treasure	3/4 chance
	else {
		cout << "a wild " << tempEnemy.eName << " is guarding the Strawberries!\n";
		cout << "The " << tempEnemy.eName << " has " << tempEnemy.eHealth << " health, and does " << tempEnemy.eAttack << " damage per hit!\n";
		cout << "You're up first!\n";
		while (health > 0 && tempEnemy.eHealth > 0) {
			system("pause");							//pause for player input
			int critChance = rollD12();
			int attack = rollD6();
			int block = rollD6();
			if (critChance == 12) {
				attack *= 3;
			}
			cout << "\nYou swing your sword and do " << attack << " damage!\n";
			if (critChance == 12) {
				cout << "It's a critical hit!\n";
			}
			tempEnemy.eHealth -= attack;
			if (tempEnemy.eHealth < 0) {
				tempEnemy.eHealth = 0;
			}
			cout << "The " << tempEnemy.eName << " has " << tempEnemy.eHealth << " health remaining!\n";
			system("pause");
			if (tempEnemy.eHealth == 0) {
				int treasure = rollD100();
				cout << "\nThe " << tempEnemy.eName << " has died!\n";
				cout << "You earned " << treasure << " Strawberries!\n";
				totalTreasure += treasure;
				cout << "You now have " << totalTreasure << " Strawberries!\n";
				cout << "Would you like to continue?\n";
			}
			else {
				cout << "\nIt's the " << tempEnemy.eName << "'s turn!\n";
				system("pause");
				cout << "\nYou raise your shield and block " << block << " of the " << tempEnemy.eName << "'s " << tempEnemy.eAttack << " attack damage!\n";
				if ((tempEnemy.eAttack - block) < 0) {
					cout << "You took 0 damage and have " << health << " health!\n";
				}
				else {
					health -= (tempEnemy.eAttack - block);
					if (health <= 0) {
						health = 0;
					}
					cout << "You took " << (tempEnemy.eAttack - block) << " damage and have " << health << " health left!\n";
				}
				if (health > 0 && tempEnemy.eHealth > 0) {
					cout << "It's your turn again!\n";
				}
				else if (health == 0) {
					Ending();
				}
				else if (tempEnemy.eHealth == 0) {
					int treasure = rollD100();
					cout << "The " << tempEnemy.eName << " has died!\n";
					cout << "You earned " << treasure << " Strawberries!\n";
					totalTreasure += treasure;
					cout << "You now have " << totalTreasure << " Strawberries!\n";
					cout << "Would you like to continue?\n";
				}
			}
		}
	}
}


int main() {
	srand(time(0));

	introStory();
	cout << "DO YOU KNOW WHAT YOU'RE DOING HERE?\n";
	temp = AskYesNo();
	if (temp == false) {
		explainStory();
	}
	else if (temp == true) {
		cout << "\nThat is good to hear!\n";
	}

	cout << "\nDo you dare continue?\n";
	temp = AskYesNo();
	if (temp == true) {
		cout << "\n" << name << "'s Adventure through Strawberry Sunset Land begins!\n";
	}
	else if (temp == false) {
		Ending();
		return 0;
	}

	if (health <= 0) {
		Ending();
		return 0;
	}

	while (health > 0) {
		Adventure();
		if (health == 0) {
			break;
		}
		temp = AskYesNo();
		if (temp == true) {
			cout << "\n" << name << "'s Adventure through Strawberry Sunset Land continues!\n";
		}
		else if (temp == false) {
			Ending();
			return 0;
		}
	}
	return 0;
}