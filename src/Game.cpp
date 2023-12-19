#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../include/Game.h"
#include "../include/Team.h"

using namespace std;

void Game::printGameInfo() const {
    cout << "Home Team: " << homeTeam.getName() << ", Away Team: " << awayTeam.getName()
              << ", Home Goals: " << homeTeamGoals << ", Away Goals: " << awayTeamGoals
              << ", Date: " << match << ", Duration: " << duration << " minutes" << endl;
    // Add more details as needed
}