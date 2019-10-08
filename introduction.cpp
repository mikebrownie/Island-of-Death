#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;


void introduction() //Welcome the player to the game, explain their situation
{
string input; //track user input
    ifstream myFile;
    myFile.open("Welcome.txt");
    
    string line;
    while(getline(myFile, line)) //print welcome text
        {
            cout<<line<<endl;
        }
User U;
getline(cin, input);
U.setUsername(input);

cout<<"Well, "<<U.getUsername()<<", you aren't much of a captain anymore. Your crew has left you. Soon, we will too."<<endl;
cout<<"Now, let us know\n"<<"What brings you to the island of death?"<<endl;
getline(cin, input);
cout<<"It's not safe here (press ENTER to continue)\n"<<endl;
getline(cin, input);
cout<<"*You see the native nod his head, and then...\n"<<endl;
getline(cin, input);
cout<<"*Darkness*"<<endl;

}
int main()
{
    introduction();
}
