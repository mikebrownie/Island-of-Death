#include "Game.h"
#include "User.h"
#include "Inventory.h"
#include <fstream>

void Game::introduction() //Welcome the player to the game, explain their situation
{
    string input; //track user input
    
        ifstream myFile;
        myFile.open("Welcome.txt");
        
        string line;
        while(getline(myFile, line)) //print welcome text
            {
                cout<<line<<endl;
            }
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
    getline(cin, input);
    cout<<"You wake up to the sun rising, alone, on the beach. You see your crew leaving with your ship on the horizon."<<endl;
    getline(cin, input);
    cout<<"Next to you, there is a map..."<<endl;
    

}

void Game::displayMenu()
{
    cout << "Select a numerical option:"<< endl;
    cout << "<=>Choose Your Poison<=>" << endl;
    cout << "<1> I don't wanna do this anymore..." << endl;
    cout << "<2> Travel north" << endl;
    cout << "<3> Travel south" << endl;
    cout << "<4> Travel east" << endl;
    cout << "<5> Travel west" << endl;
    cout << "<6> Rest" << endl;
    cout << "<7> Check inventory" <<endl;
}

void Game::displayInventory()
{
    I.displayInventory();
}
    
void Game::rollMisfortune() //roll misfortune, to be used each day
{
    bool Yes = (rand() % 100) < 50; //50 percent chance of misfortune
    if (Yes)
    {
        bool sneakProb = (rand() % 100) < 25; //25% chance of each misfortune
        bool thievesProb = (rand() % 100) < 25;
        bool nativeEncounterProb = (rand() % 100) < 50;
        bool scurvyProb = (rand() % 100) < 25;
    if (nativeEncounterProb)
    {
        I.nativeEncounter();
    }
    if (scurvyProb)
    {
        I.scurvy();
    }
    else if (thievesProb)
    {
        I.thieves();
    }
    else
    {
        I.sneakAttack();
    }

    }
}
void Game::changeDay() //increase day by 1.
{
    day++;
    if (day == 32)
    {
        month++; //add one to month
        day = 1;
    }
    if (!I.invisible) //only roll misfortunes if user is not invisible
    {
        rollMisfortune();
    }
    
    timer++; //limit invisibility on unknown
    if (timer % 5 == 0 && I.invisible)
    {
        I.limitInvisibility();
    }
}

void Game::printDay() //prints day to user
{
    string monthName; //for converting month number to name
    switch(month) //get month name
        {
            case 0:
                monthName = "May";
            break;
            case 1:
                monthName = "June";
            break;
            case 2:
                monthName = "July";
            break;
            case 3:
                monthName = "August";
            break;
            case 5:
                monthName = "October";
            break;
        }
    cout<<"<=>==================<=>==================<=>"<<endl;
    cout<<"It is the " <<day<<" of "<<monthName<<", 1892."<<endl; //print to user
    cout<<"<=>==================<=>==================<=>"<<endl;
}

bool Game::checkAlive()
{
    if(I.hitpoints <= 0) //or if you run out of hitpoints
    {
        cout<<"You have died a sad, lonely death."<<endl;
        return false;
    }
    else
    return true;
}