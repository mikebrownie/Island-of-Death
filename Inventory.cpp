#include <iostream>
#include <cctype> //for tolower()
#include <limits>
#include "Inventory.h"
#include "Shop.h"
using namespace std;



void Inventory::setBullets(int x) //adds input to bullets
{
    bullets += x;
}
void Inventory::setMedKits(int x) //adds input to medKits
{
    medKits += x;
}
void Inventory::setGold(int x) //adds input to gold
{
    gold += x;
}
void Inventory::setInvisibilityPot(int x) //adds input to bullets
{
    invisibilityPots += x;
}

bool Inventory::heal() //use medkit to restore 3 hitpoints
{
    string input;
    cout<<"Are you sure? (Y/N)\n"<<"You currently have "<<hitpoints<<"/10"<<" hitpoints."<<endl;
    while(getline(cin, input))
    {
        if(input == "y" || "Y")
            {
                if (medKits == 0) //if they don't have any med kits
                {
                    return false;
                }
                if (hitpoints == 10)
                {
                    cout<<"You already have full health!"<<endl;
                    return false;
                }
                medKits--;
                if (hitpoints == 9) //don't let them heal over 10
                {
                    hitpoints = hitpoints + 1;
                }
                else
                {
                    hitpoints = hitpoints + 2;
                }
                return true;
        }
        if(input == "n"||"N")
        {
            break;
        }
        else
        {
            cout<<"Please enter valid input(Y/N)"<<endl;
        }
    }
}
bool Inventory::damage(int a) //subract input from health
{
    hitpoints = hitpoints - a;
}
bool Inventory::drinkInvisibilityPot() //drink pot to become invisibe for 3
{
    string input;
    cout<<"Are you sure? (Y/N)"<<endl;
    while(getline(cin, input))
    {
        if(input == "y"|| "Y")
        {
            if (invisibilityPots>0)
            {
                invisibilityPots--;
                invisible = true;
                cout<<"You are invisibe for the next few days!"<<endl;
                return true;
            }
            else
            {
                cout<<"You don't have any potions!"<<endl;
                return false;
            }
        }
        if(input == "n"||"N")
        {
            break;
        }
        else
        {
            cout<<"Please enter valid input(Y/N)"<<endl;
        }
    }
}

void Inventory::displayInventory() //shows all items in inventory
{
cout<<"  Health: "<< hitpoints<<"/10"<<endl;
cout<<"+--------------------+"<<endl;
cout<<"|BULLETS             |"<<bullets<<endl;
cout<<"+--------------------+"<<endl;
cout<<"|GOLD                |"<<gold<<endl;
cout<<"+--------------------+"<<endl;
cout<<"|MEDKITS             |"<<medKits<< "   [Enter 1 to use]"<<endl;
cout<<"+--------------------+"<<endl;
cout<<"|INVISIBILITY POTIONS|"<<invisibilityPots << "   [Enter 2 to use]" <<endl;
cout<<"+--------------------+"<<endl; 
cout<<"|--Enter 0 to learn--|"<<"    [Enter 3 to exit]"<<endl;
cout<<"|-----about items----|"<<endl;
cout<<"+--------------------+"<<endl;
int choice = 0;
while(1)
{
    while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
        {
            cin.clear(); //clear input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
            cout << "Invalid input.  Try again: ";
        }
    switch(choice)
    {
        case 0: //tell user about items
        cout<<"Gold is used to trade with islanders "<<endl;
        cout<<"Bullets are used to fight foes encountered on the Island of Death."<<endl;
        cout<<"Medkits are used to heal 2 points."<<endl;
        cout<<"Invisibility potions make you invisible for a random amount of turns"<<endl;
        return;

        case 1:
        heal();
        return;

        case 2:
        drinkInvisibilityPot();
        return;

        case 3:
        return;

        default:
            cout<< "Please enter valid input"<<endl;
    }
}
}

void Inventory::limitInvisibility()
{
    if (invisible)
    {
        cout<<"You are no longer invisible!"<<endl;
        invisible = false;
    }
}


///NOW FOR MISFORTUNES

void Inventory::sneakAttack() //sneak attack by native
{
    cout<<"You were raided by an invisible foe. While you were able to fend him off, you were sliced with a dagger[-1 health]."<<endl;
    damage(1);
}

void Inventory::thieves() //theves steal random items
{
    cout<<"You awake to find your bag opened, with your items spread across the ground."<<endl;
    
    bool goldC = (rand() % 100) < 20; //-gold- what item did they take?
    bool medKitsC = (rand() % 100) < 20; //-medkits-
    bool invisibilityPotsC = (rand() % 100) < 20; //-pots-
    bool bulletsC = (rand() % 100) < 20; //-bullets-
    
    if (goldC)
    {
        setGold(-3);
        cout<<"Some gold is missing."<<endl;
    }
    else if (medKitsC)
    {
       setMedKits(-1);
       cout<<"A medKit is missing."<<endl;
    }
    else if (invisibilityPotsC)
    {
        setInvisibilityPot(-1);
        cout<<"An invisibility Potion is missing."<<endl;
    }
    else if (bulletsC)
    {
        setBullets(-2);
        cout<<"Some bullets are missing."<<endl;
    }
    else
    cout<<"Luckily, they found none of your items as valuable and nothing is missing."<<endl;
}




void Inventory::nativeEncounter()
{

    cout<<"While traveling, you run into a native islander. Will you...\n"<<endl;
    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"|FIGHT!   |[chance of winning and stealing items]|1|USE   BULLETS|"<<endl;
    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"|RUN!     |[chance of getting away]              |2|USE NOTHING  |"<<endl;
    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"|BEFRIEND!|[chance of being able to trade]       |3|USE GOLD     |"<<endl;
    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"Enter numerical input:"<<endl;
    int choice = 0;

while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
    {
		cin.clear(); //clear input
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
		cout << "Invalid input.  Try again: ";
    }
    switch(choice)
    {
        case 1: //fight option, 50% chance to win
        {//brackets to allow decleration of variables
            bool Win = (rand() % 100) < 50;
            if(Win && bullets >=5)
            {
                cout<<"You won the fight!"<<endl;
                int bullets_used= -(rand() % (6)); //random number between 0-5
                setBullets(bullets_used);
                cout<<"You used "<<bullets_used<<" bullets.\n"<<endl;
                
                int gold_found = (rand() % (11)); //random number between 0-10
                setGold(gold_found);
                int medKits_found = (rand() % (6)); //random number between 0-5
                setMedKits(medKits_found);
                int invisibilityPots_found = (rand() % (3)); //random number 0-2
                setInvisibilityPot(invisibilityPots_found);
                
                cout<<"You looted: "<<medKits_found<<" medKits, "<<gold_found<<" gold, and "<<invisibilityPots_found<<" invisibility potions."<<endl;
                
            }
            else
            {
                cout<<"You lost the fight and were badly injured[-2hp]"<<endl; 
                damage(2);
            }
        break;
        }
        
        case 2:
        {
            bool getAway = (rand() % 100) < 80; //80% chance of getting away
            if (getAway)
                cout<<"You successfully escaped!"<<endl;
            else
            {
                cout<<"While you managed to escape, you took some damage.[-1hp]"<<endl; //possibility of taking damage
                damage(1);
            }
        break;
        }
        case 3:
        {
            bool befriend = (rand() % 100) < 60; //60% chance of getting to trade
            if(befriend)
            {
                int choice = 0;
                string input;
                                S.generateShop(); //only one shop
                while(choice != 4)
                {
                S.displayShop();
                while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
                {
            		cin.clear(); //clear input
            		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
            		cout << "Invalid input.  Try again: ";
                }
                    switch(choice)
                    {
                        case 1:
                        {
                            cout<<"How many?"<<endl;
                            while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
                            {
                        		cin.clear(); //clear input
                        		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
                        		cout << "Invalid input.  Try again: ";
                            }
                            if (choice*3 > gold) //medkits cost 3 gold each
                            {
                                cout<<"You don't have enough gold."<<endl;
                            }
                            else if (choice <= S.medKitsShop && choice >= 0 )
                            {
                                medKits += choice; //change user medkits
                                S.medKitsShop -= choice; //change medkits in shop
                                cout<<"You bought "<<choice<<" medKits."<<endl;
                                cout<<"You have "<<gold<<" gold left."<<endl;
                                break;
                                
                            }
                            else
                            {
                            cout<<"Please enter valid input"<<endl;
                            }
                            
                        }
                        case 2:
                        {
                            cout<<"How many?"<<endl;
                            while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
                            {
                        		cin.clear(); //clear input
                        		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
                        		cout << "Invalid input.  Try again: ";
                            }
                            if (choice*2 > gold) //bullets cost 2 gold each
                            {
                                cout<<"You don't have enough gold."<<endl;
                            }
                            else if (choice <= S.bulletsShop && choice >= 0 )
                            {
                                bullets += choice; //change user medkits
                                S.bulletsShop -= choice; //change medkits in shop
                                cout<<"You bought "<<choice<<" bullets."<<endl;
                                cout<<"You have "<<gold<<" gold left."<<endl;
                                break;
                                
                            }
                            else
                            {
                            cout<<"Please enter valid input"<<endl;
                            }
                            
                        }
                        case 3:
                        {
                            cout<<"How many?"<<endl;
                            while(!(cin >> choice)) //HANDLING ERROR STATE FOR CIN SOURCE: https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
                            {
                        		cin.clear(); //clear input
                        		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore limit
                        		cout << "Invalid input.  Try again: ";
                            }
                            if (choice*7 > gold) //pots cosy 7 gold each
                            {
                                cout<<"You don't have enough gold."<<endl;
                            }
                            else if (choice <= S.invisibilityPotsShop && choice >= 0 )
                            {
                                bullets += choice; //change user medkits
                                S.invisibilityPotsShop -= choice; //change medkits in shop
                                cout<<"You bought "<<choice<<" Invisibility Potions."<<endl;
                                cout<<"You have "<<gold<<" gold left."<<endl;
                                break;
                                
                            }
                            else
                            {
                            cout<<"Please enter valid input"<<endl;
                            }
                            
                        }
                        case 4://EXIT SHOP
                            return;
                        default:
                            cout<<"Please enter valid input"<<endl;
                        break;
                    }
                }
            }
            else
            {
            cout<<"Your attempt to befriend failed[-2hp]"<<endl;
            }
        }
        default:
            cout<<"Please make valid input"<<endl;
            break;
    }
}


void Inventory::scurvy() //player gets sick, must use medkit.
{
    cout<<"The taste of vitamin-C deficient blood coats yourt gums. You remember you haven't had an orange in months."<<endl;
    cout<<"You could use a medKit to negate the ill-effects of scurvy, or you could suffer through [up to -4hp].\n"<<endl;
    cout<<"Would you like to use a medKit?[Y/N]"<<endl;
    
    string input;
    while(getline(cin, input))
    {
        if(input == "y" || input == "Y")
        {
            cout<<"You feel much better now."<<endl;
            if (medKits > 0)
            {
                setMedKits(-1);
                return;
            }
            else
            {
                cout<<"You don't have any medKits!"<<endl;
                int hurt = (rand() % (5));
                damage(hurt); //up to 4 damage
                cout<<"-"<<hurt<<"hp"<<endl;;
                return;
            }
        }
        if(input == "n" || input == "N")
        {
            cout<<"That ones gonna hurt you"<<endl;
            int hurt = (rand() % (5));
            damage(hurt); //up to 4 damage
            cout<<"-"<<hurt<<"hp"<<endl;;
            return;
        }
        else
        cout<<"Please make valid input: [Y/N]"<<endl;
    }
}
