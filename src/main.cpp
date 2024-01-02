#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/Date.h"
#include "../include/Season.h"
#include "../include/Team.h"
#include "../include/Player.h"
#include "../include/Game.h"
#include "../include/CSVreader.h"
#include "Game.cpp"
#include "Season.cpp"
#include "Date.cpp"
#include "Team.cpp"
#include <cstdlib> 



using namespace std;


int main() {
    Season s;

    int selection = 1;
    int gw = -1;
   
    cout << "\n";
    cout << "* ----------------------------------------------------- *\n";
    cout << "* Welcome to the Football Touranment Management System! *\n";
    cout << "* ----------------------------------------------------- *\n";
    
    while (selection != 0)
    {
        cout << "\n";
        cout << "  please choose one of the following options:" << endl;
        cout << "\n";
        cout << " 1 display details at end of season " << endl;
        cout << " 2 display details at a given date " << endl;
        cout << " 0 exit " << endl;

        cout << "enter your choice : ";
        cin >> selection;
        if (selection == 1)
        {
                int n = 1; 
                while ( n != 0){
                cout << "\n\n";
                 cout << "  please choose one of the following options:" << endl;
                cout << "\n";
                cout << " 1 display best scorers using AVL " << endl;
                cout << " 2 display best scorers using BST " << endl;
                cout << " 3 display All scorers during the season" << endl;
                cout << " 4 draw the curve of goals for a given player " << endl;
                cout << " 5 display gameweek resaults " << endl;
                cout << " 6 display gameweek player's details " << endl;
                cout << " 7 display the current standing table  " << endl;
                cout << " 8 display the distance runing of a given team  " << endl;
                cout << " 9 display all scorers for a given team " << endl;
                cout << " 10 display all information about a given team " << endl;
                cout << " 0 exit " << endl;
                cout << "\n\n";
                gw = 37;

                cout << "Enter your choice: ";
                cin >> n;
                s.choice(n,gw);
                }
        }

            int n = 1; 
            while ( n != 0){
            cout << "\n\n";
            cout << "  please choose one of the following options:" << endl;
            cout << "\n";
            cout << " 2 display best scorers using BST " << endl;
            cout << " 3 display best scorers using AVL " << endl;
            cout << " 4 display best scorer in every team " << endl;
            cout << " 5 draw the curve of a given player " << endl;
            cout << " 6 display gameweek details " << endl;
            cout << " 7 display the standing table  " << endl;
            cout << " 0 exit " << endl;
            cout << "\n\n";

            cout << "Enter your choice: ";
            cin >> n;
            s.choice(n,gw); 

            }
        else if (selection == 2)
        {
            Date d, start(13,8,2022), end(29,04,2023);
            cout <<  endl << " Enter the date: yyyy-mm-dd \n";
            do{
                cout<<"between (2022-08-13 and 2023-04-29)" << endl;
                cin >> d;
            }while(d>end && d<start);
            gw = d.DateToGameWeek(d, s.getDates());
            while (gw == -1)
            {
                cout << " Enter a valid date: yyyy-mm-dd " << endl;
                cin >> d;
                gw = d.DateToGameWeek(d, s.getDates());

            }
            int n = 1; 
                while ( n != 0)
                {
                cout << "\n\n";
                cout << "  please choose one of the following options:" << endl;
                cout << "\n";
                cout << " 1 display best scorers using AVL " << endl;
                cout << " 2 display best scorers using BST " << endl;
                cout << " 3 display All scorers during the season" << endl;
                cout << " 4 draw the curve of goals for a given player " << endl;
                cout << " 5 display gameweek resaults " << endl;
                cout << " 6 display gameweek player's details " << endl;
                cout << " 7 display the current standing table  " << endl;
                cout << " 8 display the distance runing of a given team  " << endl;
                cout << " 9 display all scorers for a given team " << endl;
                cout << " 10 display all information about a given team " << endl;
                cout << " 0 exit " << endl;
                cout << "\n\n";

                cout << "Enter your choice: ";
                cin >> n;
                s.choice(n,gw);
                }
        }
    }
    
    

    system("clear");
    cout << "\n";
    cout << "* ----------------------------------------------------------- *\n";
    cout << "* Thanks for using the Football Touranment Management System! *\n";
    cout << "* ----------------------------------------------------------- *\n";
    cout << "\n";

    
    return 0;

    
}

