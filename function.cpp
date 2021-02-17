#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <limits>
#include "Computer.h"
#include "Player.h"
#include "Tournament.h"

using namespace std;

int mainMenu()
{
    bool loop = true;
    cout << string(100, '\n');
    while(loop == true)
    {
        int option;
        cout<<"********************************************************************"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                   Let's Play Rock Paper Scicors                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"********************************************************************"<<endl<<endl;

        cout<<"[1] Begin Tournament"<<endl;
        cout<<"[2] Exit"<<endl;

        cout<<"[?] Pick your option: ";
        cin>>option;
        
        while (cin.fail() || option < 1 || option > 2) {
            cout<<"Incorrect option please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cin >> option;
        }
        cout<<endl<<endl;


        switch (option)
        {
            case 1:
                loop = false;
                break;

            case 2:
                cout<<"Bye Bye!"<<endl;
                return -1;
                loop = false;
                
                break;
        }
    }
    return 0;
}


