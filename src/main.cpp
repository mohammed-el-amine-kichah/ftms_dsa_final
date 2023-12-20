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


using namespace std;


int main(){

    Season s;
    
    // s.printTeams();
    // s.printPlayers();
    //s.printGames();

    // vector<Team> teams = s.getTeams();
    // for(auto team : teams){
    //     cout<<team.getName()<<endl;
    //     cout << team.getTotalPoints()<<endl;
    //     cout << team.getPoints(36) << endl;
    // }
    //s.DisplayScorersBST(22);
    //s.DisplayScorersAVL(24);
        //s.showCurve("Sadio Mané");
        
    //s.DisplayBestScorersAVL();
    //s.DisplayBestScorersBST();
    cout << "\n";
    cout << "* ----------------------------------------------------- *\n";
    cout << "* Welcome to the Football Touranment Management System! *\n";
    cout << "* ----------------------------------------------------- *\n";
    
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
    s.choice(n);

}
    system("clear");
    cout << "\n";
    cout << "* ----------------------------------------------------------- *\n";
    cout << "* Thanks for using the Football Touranment Management System! *\n";
    cout << "* ----------------------------------------------------------- *\n";
    cout << "\n";
    return 0;
}