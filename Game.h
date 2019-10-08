#include "User.h"
#include "Map.h"
#include "Inventory.h"
#ifndef GAME_H
#define GAME_H

class Game
{
    public:
    
    void introduction(); //introduce player to game
        
    void displayMenu(); //show player main menu
    
    void displayInventory(); //show player inventory
    
    void changeDay(); //changes day
    
    void printDay(); //prints to user the date.
    
    void rollMisfortune(); //roll misfortune, to be used each day

    bool checkAlive(); //check if hitpoint are >= 0
    
    private:
    
    int day = 1; //date, increases with each move.
    
    int month = 0; //month, increases at 31 days then resets days
    
    int timer = 0; //limit invisibility to 5 days
    
    User U;
    
    Inventory I;
    
};

#endif