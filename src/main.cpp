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
    s.printGames();

    
    //system("python3  ../draw/draw.py ");
    return 0;
}