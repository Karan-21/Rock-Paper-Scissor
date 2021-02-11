#include <iostream>
#include <string>
#include "Computer.h"
#include "Person.h"
#include "Player.h"

using namespace std;

Computer::Computer()
{
        moves="";
}

string Computer::getMoves()
{
        return moves;
}

string Computer::move()
{
    srand(time(NULL));

    int randNum = (rand() % 3) + 1;

    string Move;
    if (randNum==1)
        Move="r";
        
    else if (randNum==2)
        Move="p";

    else if (randNum==3)
        Move="s";
    
    
    string letter = Move;
    if(letter.compare("s")==0 || letter.compare("S")==0)
        move1="s";

    else if(letter.compare("p")==0 || letter.compare("P")==0)
        move1="p";

    else
        move1="r";



    cout<<"Computer's Move is: "<<move1<<endl;
    c_no_of_move++;
        
    return move1;

}

char Computer::getMove()
{
    if(move1.compare("r")==0 || move1.compare("R")==0 )
        return 'r';
    else if(move1.compare("s")==0 || move1.compare("S")==0)
        return 's';
    else
        return 'p';
}
