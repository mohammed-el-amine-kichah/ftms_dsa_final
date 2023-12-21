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



//1-        g++ -std=c++17 main.cpp Player.cpp
//2 -     ./a.out

using namespace std;


int main(){
    Season s;
    
    int selection = 1;
    int gw = -1;
   
    cout << "\n";
    cout << "* ----------------------------------------------------- *\n";
    cout << "* Welcome to the Football Touranment Management System! *\n";
    cout << "* ----------------------------------------------------- *\n";
    
    while (selection != 0){
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
            cout << " 1 display best scorers using BST " << endl;
            cout << " 2 display best scorers using AVL " << endl;
            cout << " 3 display best scorer in every team " << endl;
            cout << " 4 draw the curve of a given player " << endl;
            cout << " 5 display gameweek details " << endl;
            cout << " 6 display the standing table  " << endl;
            cout << " 7 display the distance runing of a given team  " << endl;
            cout << " 8 display best scorer for a given team " << endl;
            cout << " 0 exit " << endl;
            cout << "\n\n";
            gw = 37;

            cout << "Enter your choice: ";
            cin >> n;
            s.choice(n,gw);
            }
    }
    else if (selection == 2) {
        Date d;
        cout <<  endl << " Enter the date: dd-mm-yyyy " << endl;
        cin >> d;
        gw = d.DateToGameWeek(d, s.getDates());
        while (gw == -1) {
            cout << " Enter a valid date: dd-mm-yyyy " << endl;
            cin >> d;
            gw = d.DateToGameWeek(d, s.getDates());
        }
        int n = 1; 
            while ( n != 0){
            cout << "\n\n";
            cout << "  please choose one of the following options:" << endl;
            cout << "\n";
            cout << " 1 display best scorers using BST " << endl;
            cout << " 2 display best scorers using AVL " << endl;
            cout << " 3 display best scorer in every team " << endl;
            cout << " 4 draw the curve of a given player " << endl;
            cout << " 5 display gameweek details " << endl;
            cout << " 6 display the standing table  " << endl;
            cout << " 7 display the distance runing of a given team  " << endl;
            cout << " 8 display best scorer for a given team " << endl;
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

