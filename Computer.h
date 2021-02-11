#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include "Person.h"
#include <string>

using namespace std;

class Computer : public Player
{
    public:
        string move1;
        string moves;
        int c_no_of_move=0;
        Computer();
        string getMoves();
        string move();
        char getMove();
};
#endif