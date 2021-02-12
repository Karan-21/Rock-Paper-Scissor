#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

bool Player::win(Player * opponent)
{
    if(opponent->winner.compare("Person")==0)return true;
    else return false;
}