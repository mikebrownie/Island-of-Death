#include <iostream>
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Shop.h"

using namespace std;


class Inventory
{
    private:
    
        int bullets = 15; //used for protection
        int medKits = 5; //healing
        int gold = 20; //buying stuff
        int invisibilityPots = 1; //5 moves without misfortunes
        Shop S;
        
    public:
        int hitpoints = 10; //between 0 and 10, if reaches 0, game over

        void displayInventory(); //shows all items in inventory
    
        void setBullets(int); //adds input to bullets
        void setMedKits(int); //adds input to medKits
        void setGold(int); //adds input to gold
        void setInvisibilityPot(int); //adds invisibility pot
        bool invisible = false; //true if user is invisible

        bool heal(); //use medkit to restore 3 hitpoints
        bool damage(int); //subtract input from hitpoints
        bool drinkInvisibilityPot(); //drink pot to become invisibe for 5 days
        
        void limitInvisibility(); //make sure you stay invisible for only 5 days
        
        //Misfortunes: put here because they directly impact inventory
        void sneakAttack();  //sneak attaack does damage
        void thieves(); //thieves steal random items
        void nativeEncounter(); //prompt user to fight, flee, or befriend
        void scurvy(); //Bruising, bleeding gums, weakness, fatigue, and rash are among scurvy symptoms. -1 hp
        
};

#endif