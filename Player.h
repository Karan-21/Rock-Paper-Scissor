#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
        string winner;
        virtual string move()=0;
        virtual string getMoves()=0;
        virtual char getMove()=0;
        bool win(Player * opponent);

};
#endif