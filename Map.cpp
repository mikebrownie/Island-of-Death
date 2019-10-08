#include <fstream>
#include <iostream>
#include "User.h"
#include "Map.h"
using namespace std;

void Map::setMapWidth(int x)
{
    mapWidth = x;
}
void Map::setMapHeight(int y)
{
    mapHeight = y;
}
Map::Map()
{
    ifstream myFile;
    myFile.open("map.txt");
    
    string line;
    int count = 0;
    int maxMapWidth = 200;
    int width = 0;
    while(getline(myFile, line)) //transer map file to maparray
    {
        string temp; //temp store info
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i]=='C')
                temp+=" ";
            else if(line[i] == ' ')
                temp+=" ";
            else if(line[i] != ' ')
                temp+="1";
        }
        compMapArr[count] = temp;
        //cout<<temp<<endl
        
        mapArr[count] = line;;//store user map array
        count++;
        width = line.length();
        if (width <= maxMapWidth) //Store max width of map
        {
            setMapWidth(width);
        }
        //cout<<line<<endl;
        setMapHeight(count); //store height of map
    }
}

void Map::printMap(int PosY, int PosX)
{
    int count = 0;
    
    for (string s: mapArr) //for each loop:  create new string s. format : for (datatype x : what every x makes up)
    {
        if (count < mapHeight)
        { 
            if (count == PosY)
            {
                cout<<s.substr(0, PosX)<<'X'<<s.substr((PosX+1), mapWidth)<<endl;
            }
            else
            {
                cout<<s<<endl;
            }
                count++; //track line
        }
    }
}
string Map::getMapArrAt(int Y, int X) //returns comp map at X Y coordinate
{
    cout<<"<=>==================<=>==================<=>"<<endl;
    cout<<"X Co-ordinate: "<<X<<endl;
    cout<<"Y Co-ordinate: "<<Y<<endl;
    
    string line = compMapArr[Y];
    return line.substr(X, 1);
}