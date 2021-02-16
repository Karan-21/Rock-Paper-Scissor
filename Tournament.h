#ifndef Tournament_h
#define Tournament_h
#include <string>
#include"Computer.h"
#include"Person.h"

using namespace std;

class Tournament : public Person,public Computer
{
    private:
        int number_of_players;
        int tournament_size;
        int number_of_AI;
        
    public:
        Tournament();
        void match_size(int number_of_players);
        void match_making();
        void name_players();
        void begin_tournament();
        string check_winner(string a, string b);
};
#endif