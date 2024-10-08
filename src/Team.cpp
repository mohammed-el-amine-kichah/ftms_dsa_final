#include "../include/Team.h"
#include "../include/Player.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

Team::Team( string name1,string coachName1,string PresidentName1)
{
    name = name1;
    coachName = coachName1;
    PresidentName = PresidentName1;

    totalGoalsFor = 0;
    totalGoalsAgainst = 0;
    totalPoints = 0;
    totalGoalDifference = 0;
    totalWins = 0;
    totalDraws = 0;
    totalLosses = 0;
    totalGamesPlayed = 0;
    Cpoints = 0;
    CgoalDifference = 0;
    CgoalsFor = 0;
    Cwins = 0;
    points = {0};
    goalsFor = {0};
    goalsAgainst = {0};
    goalDifference = {0};
    Wins = {0};
    MP = {0};
    Draws = {0};
    Loses = {0};
    players.clear();
}

void Team::goalScored( int amount )
{
    totalGoalsFor += amount;
    totalGoalDifference = totalGoalsFor - totalGoalsAgainst;
}

void Team::goalAgainstScored( int amount )
{
    totalGoalsAgainst += amount;
    totalGoalDifference = totalGoalsFor - totalGoalsAgainst;
}

void Team::logWin()
{
    totalWins += 1;
    totalPoints += 3;
    totalGamesPlayed++;
}

void Team::logDraw()
{
    totalDraws += 1;
    totalPoints += 1;
    totalGamesPlayed++;
}

void Team::logLoss()
{
    totalLosses += 1;
    totalPoints += 0; // Added for completeness.
    totalGamesPlayed++;
}


void Team::toString()
{
    std::cout << "Team name:     " << name << "\n";
}

void Team::addPlayer(const Player& player) {
    players.push_back(player);
}

void Team::printTeamPlayers() {
    for (const Player& player : players) {
        std::cout << player.getName() << "\n";
    }
}
bool Team::operator<(const Team& team) const { 
        if (Cpoints != team.getCpoints())
        {
            return Cpoints < team.getCpoints(); 
        }

        else if (CgoalDifference != team.getCgoalDifference())
        {
            return CgoalDifference < team.getCgoalDifference();
        }

        else if (CgoalsFor != team.getCgoalsFor())
        {
            return CgoalsFor < team.getCgoalsFor();
        }

        else if (Cwins != team.getCwins())
        {
            return Cwins < team.getCwins();
   }
    return name < team.name;
}
void Team::InfoAt(int round)  // derafa khalil
{
    Cpoints = points[round];
    CgoalDifference = goalDifference[round];
    CgoalsFor = goalsFor[round];
    Cwins = Wins[round];
    CMP = MP[round];
    CDraws = Draws[round];
    CLoses = Loses[round];
}

