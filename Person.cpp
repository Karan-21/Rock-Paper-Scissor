#include <iostream>
#include <string>
#include "Person.h"
#include "Player.h"

using namespace std;

Person::Person()
{
    moves="";
}

string Person::move()
{
    cout<<"Enter your move: ";
    cin>>inputs;
    moves+=inputs;
    p_no_moves++;
    return inputs;
}

string Person::getMoves()
{
    return moves;
}

char Person::getMove()
{
    if(inputs.compare("r")==0 || inputs.compare("R")==0 )
        return 'r';
    else if(inputs.compare("s")==0 || inputs.compare("S")==0)
         return 's';
    else
        return 'p';
}