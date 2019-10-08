#include <iostream>
#include <fstream>
#include <string>
#include <limits> //for getline
#include "User.h"
#include "Game.h"
#include "Map.h"
#include "Inventory.h"

using namespace std;
int main(int argc, char** argv) //for taking console inputs
{
//Objects
Game G; 
User U;
Map M;

G.introduction(); //introduce player to gameS


string choice; //store user input
bool move; //can the user move or not?
while (choice != "9") 
{
            G.displayMenu();
            M.printMap(U.getPosY(), U.getPosX());
            
            if(U.getPosX() == 51 && U.getPosY() == 2) //end game once cannon is reached
            {
                cout<<"You use the cannon to shoot your old ship with one well placed shot."<<endl;
                cout<<"As you watch your old ship sink, 20 tribesmen approach you, commanding you to drop your weapons."<<endl;
                cout<<"TO BE CONTINUED"<<endl;
                return 0;
            }
            if(!G.checkAlive()) //if dead
                return 0;

        int choice =0;
        while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
        {
		cin.clear(); //clear input
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
		cout << "Invalid input.  Try again: ";
        }
        
            switch (choice) 
            {
                case 1: //quit
                return 0;
                break;
                
                case 2: //travel north
                    move = U.move(choice);
                    if (move == false)
                        cout<<"You ran into the edge of the map!"<<endl;
                    else
                    {
                        G.printDay();
                        G.changeDay();
                    }
                break;
                
                case 3: //travel south
                    move  = U.move(choice);
                    if (move == false)
                    cout<<"You ran into the edge of the map!"<<endl;
                    else
                    {
                        G.printDay();
                        G.changeDay();
                    }
                break;
                
                case 4: //travel east
                    move  = U.move(choice);
                    if (!move )
                    cout<<"You ran into the edge of the map!"<<endl;
                    else
                    {
                        G.printDay();
                        G.changeDay();
                    }
                break;
                
                case 5: //travel west
                    move  = U.move(choice);
                    if (move == false)
                    cout<<"You ran into the edge of the map!"<<endl;
                    else
                    {
                        G.printDay();
                        G.changeDay();
                    }
                break;
                
                case 6: //rest
                    G.printDay();
                    G.changeDay();
                break;
                
                case 7: //checkinv
                    G.displayInventory();
                break;
                
                default:
                cout<<"invalid input"<<endl;
            }
}
}