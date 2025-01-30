// Coding1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// comment!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
using namespace std;

int main()
{
   //string name;

    //cout << "Whats your name?\n";
    //cin >> name;

    //if (name == "Aurora", "Addison") (cout << "Hello creator!");
    //else {
        //cout << "Hello " << name << "!! nice to meet you\n";
  //  }
    
    string names[6];

    names[0] = "Jeff Bezos";
    names[1] = "Ryan";
    names[2] = "Matsune Miku";
    names[3] = "Hatsune Hiku";
    names[4] = "Tyler the Creator";
    names[5] = "bob";

    for (int i = 0; i < 6; i++) {
        cout << names[i] << ", ";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
