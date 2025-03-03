#include <iostream>
#include <string>
using namespace std;

    /*
     create a program that will

     Add a game to an array of strings
     Edit the name of the game
     Remove the game
     Show the List
     Quit
    */

    /*
     A few notes, about my notes:
     "vvv" and "^^^" are arrows pointing at the line below and above
     ^^^The amount of repeated characters may vary, but will usually be around 3
     "<<" and ">>" are also arrows I may use, however it is less likely since I'll just add notes to the end of a line
    */

int main()
{
    //intro statement
    cout << "Hello!\n"; 
    cout << "\nIn this program, you will create and be able to:\nadd to, edit, remove from, or show a list of games!\n\n";
    cout << "That being said, \n";


    string favGames[100];   //array for "favorite games" list
    int gameCount = 0;      //integer for counting games, holds the changing number of games
    string input;           //paired with "getline" and "cin" for user input

    do {
        //asking the user what should be done and getting their input every loop
        cout << "What would you like to do?\n";
        cout << "(Type \"add,\" \"edit,\" \"remove,\" \"show,\" or \"quit\")\n";
        getline(cin, input);

        //add input
        if (input == "add") {                           //if users input is "add", run this code. will be the same for "edit," "remove," "show," and "quit"
            cout << "\nWhat game would you like to add?\n";
            getline(cin, input);
            favGames[gameCount++] = input;              //adding inputted game into favGame list, amount of games in list up by 1 as well
            cout << "\n";                               //formatting for my sake
        }

        //edit input
        else if (input == "edit") {
            if (gameCount == 0) {               //if there are no games in the list, say this vvv
                cout << "\nThere are currently no games in your list.\n";
            }
            else {
                cout << "\nWhat game would you like to edit?\n";
                getline(cin, input);
                for (int i = 0; i < gameCount; i++) {       //loops through the list of games that have been inputted
                                                            //"gameCount" makes it so it only loops through the amount of games, rather than 100 times 
                    if (favGames[i] == input) {             //if game inputted matches one in the list, run this code
                        cout << "\n\"" << input << "\" has been found!\n";
                        cout << "What would you like to change it to?\n";
                        getline(cin, input);
                        favGames[i] = input;                //Chosen game has name changed 
                        cout << "\nThe game has been updated to " << favGames[i] << "!\n";
                    }
                    else if (i + 1 == gameCount) {
                        cout << "\n\"" << input << "\" was not found, therefore could not be edited.\n";
                    }
                }
            }
            cout << "\n";           //formatting, once again
        }

        //remove input
        else if (input == "remove") {
            if (gameCount == 0) {               //if there are no games in the list, say this vvv
                cout << "\nThere are currently no games in your list.\n";
            }
            else {
                cout << "\nWhat game would you like to remove?\n";
                getline(cin, input);
                for (int i = 0; i < gameCount; i++) {       //same for loop that is in "edit"
                    if (favGames[i] == input) {             //if inputted game is in the list, remove it
                        cout << "\n\"" << input << "\" has been found.\n";
                        favGames[i] = "";                   //removes inputted game
                        cout << "\"" << input << "\" has been removed.\n";
                    }
                    else if (i + 1 == gameCount) {              //Mistake clause
                        cout << "\n\"" << input << "\" was not found, therefore could not be removed.\n";
                    }
                }
            }
            cout << "\n";       //formatting for a third time.
        }

        //show input
        else if (input == "show") {
            if (gameCount == 0) {   //if there are no games in the list, say this vvv
                cout << "\nThere are currently no games in your list.\n";
            }
            else {
                cout << "\nHere are the games in your list:\n";
                for (int i = 0; i < gameCount; i++) {       //same for loop that is in "edit"
                    //if favGames does not equal nothing, display games
                    if (favGames[i] != "") {
                        cout << favGames[i] << "\n";
                    }
                }
            }
            cout << "\n";   //formatting.
        }

        //quit input
        else if (input == "quit") {
            cout << "\nThanks for your time!\n";
            cout << "Goodbye!\n";
            break;      //exits the loop
        }

        //unlisted/unknokwn input 
        else {
            cout << "\nI don't know what you want?\n";
            cout << "If there was a mistake, don't use \"quotation marks\" nor any CAPITALIZATION!\n";
            cout << "If there was not a mistake on your end, think again.\n"; 
            cout << "Please choose one of the presets listed, I am a program, not a chatting bot.\n";
            cout << "\nAnyways, ";
        }

    } while (true);

}

