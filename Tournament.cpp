#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include "Tournament.h"

using namespace std;

Tournament::Tournament()
{

}

void Tournament::match_size(int n)
{
    int size;
    int i=0;

    bool loop = true;
    while(loop == true)
    {
        i++;

        size = pow (2, i);

        if (size>=n)
        {
            loop = false;
        }
    }
    tournament_size = size;
    number_of_players=n;
}

void Tournament::match_making()
{
    number_of_AI=tournament_size-number_of_players;
    cout<<"We are adding "<<number_of_AI<<" AIs to the tournament Match Making."<<endl;

    int player_array[tournament_size];
    int ordered_array[tournament_size];

    //creting an ordered array of the players
    for (int i=1; i<(tournament_size+1); i++)
    {
        player_array[i-1]=i;

    }

    //Shuffling the elements by randomly exchanging each with one other.-----------------
    srand(time(NULL));
    int n = (rand() % 10) + 1;

    for (int j=0; j<n; j++)
    {
        for (int i=0; i<(tournament_size-1); i++)
        {
            int r = i + (rand() % (tournament_size-i)); // Random remaining position.
            int temp = player_array[i];
            player_array[i] = player_array[r];
            player_array[r] = temp;
        }

    }
    //-----------------------------------------------------------------------------------

    vector<int> playerArray;

    for (int i=0; i<tournament_size; i++)
    {
        playerArray.push_back(player_array[i]);
    }

    //-----------------------------------------------------------------------------------

    string *names = new string[tournament_size];

    for (int j=0; j<number_of_players; j++)
    {
        cout<<"Enter the name of player "<<(j+1)<<": ";
        cin>>names[j];
    }

    for (int j=number_of_players; j<(number_of_AI+number_of_players); j++)
    {
        cout<<"Enter the name of AI "<<(j+1-number_of_players)<<": ";
        cin>>names[j];
    }

    //-----------------------------------------------------------------------------------
    cout<<endl;

    Person player1, player2;
    Computer AI1, AI2;

    string a;
    string b;

    int matchCNTR=0;
    bool winner=false;
    while (playerArray.size()>1)
    {
        cout<<names[playerArray.at(0)-1]<<" "<<playerArray.at(0)<<" vs "<<names[playerArray.at(1)-1]<<" "<<playerArray.at(1)<<endl;

        bool loop=true;
        while (loop==true)
        {

            if (playerArray.at(0)>=(number_of_players+1))
            {
                cout<<"taking player 1 move"<<endl;
                a = AI1.move();
            }

            else
            {
                cout<<"taking player 1 move"<<endl;
                a = player1.move();
            }

            if (playerArray.at(1)>=(number_of_players+1))
            {
                cout<<"taking player 2 move"<<endl;
                b = AI2.move();
            }

            else
            {
                cout<<"taking player 2 move"<<endl;
                b = player2.move();
            }


            cout<<endl<<"Move of "<<names[playerArray.at(0)-1]<<" is: "<<a<<" and Move of "<<names[playerArray.at(1)-1]<<" is "<<b<<endl;
            string winning_move = check_winner(a,b);

            if (winning_move == a)
            {
                cout<<names[playerArray.at(0)-1]<<" wins"<<endl<<endl;
                playerArray.push_back(playerArray.at(0));
                loop=false;
            }
            else if (winning_move == b)
            {
                cout<<names[playerArray.at(1)-1]<<" wins"<<endl<<endl;
                playerArray.push_back(playerArray.at(1));
                loop=false;
            }
            else
            {
                cout<<"Draw, try again!"<<endl<<endl;;
                break;
            }

            playerArray.erase(playerArray.begin());
            playerArray.erase(playerArray.begin());
        }

    }
    
    delete[] names;

    //-----------------------------------------------------------------------------------

}

string Tournament::check_winner(string a, string b)
{
    if((a.compare("r")==0 && b.compare("s")==0) ||
        (a.compare("s")==0 && b.compare("p")==0)||
        (a.compare("p")==0 && b.compare("r")==0))
        {
            return a;
        }

    else if ((a.compare("s")==0 && b.compare("r")==0) ||
            (a.compare("p")==0 && b.compare("s")==0) ||
            (a.compare("r")==0 && b.compare("p")==0))
            {
                return b;
            }
    else
    {
        return "x";
    }

}
