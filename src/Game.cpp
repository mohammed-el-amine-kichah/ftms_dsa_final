#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../include/Game.h"
#include "../include/Team.h"
#include "../include/BinarySearchTree.h"

using namespace std;

void Game::printGameInfo() const {
    cout  << homeTeam.getName()<< " " << homeTeamGoals << " - "<< awayTeamGoals<< " " << awayTeam.getName()
              << ", Date: " << match << ", Duration: " << duration << " minutes" << endl;
}
void Game::printTableat(int round, vector<Team> &teams)
{
    BinarySearchTree <Team> TeamBST; 
    for(const Team team:teams)
    {
        TeamBST.insert(team);
    }
}