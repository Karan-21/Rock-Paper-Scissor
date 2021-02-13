#ifndef PERSON_H
#define PERSON_H
#include "Player.h"
#include <string>

using namespace std;

class Person : public Player
{
    public:
        string inputs,moves;
        int p_no_moves=0;
        Person();
        string move();
        string getMoves();
        char getMove();
};
#endif