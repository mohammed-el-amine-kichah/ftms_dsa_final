#include "../include/Team.h"
#include <iostream>
#include <vector>
#include <map>

Team::Team( std::string name1, double xG1, double xGA1, std::map<double, int> scoringDistribution1 )
{
    name = name1;
    xG = xG1;
    xGA = xGA1;
    totalGoalsFor = 0;
    totalGoalsAgainst = 0;
    totalPoints = 0;
    goalDifference = 0;
    totalWins = 0;
    totalDraws = 0;
    totalLosses = 0;
    totalGamesPlayed = 0;
    scoringDistribution = scoringDistribution1;
}

void Team::goalScored( int amount )
{
    totalGoalsFor += amount;
    goalDifference = totalGoalsFor - totalGoalsAgainst;
}

void Team::goalAgainstScored( int amount )
{
    totalGoalsAgainst += amount;
    goalDifference = totalGoalsFor - totalGoalsAgainst;
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

bool Team::compareTo( Team t )
{
    // Check if this -> team has more points.
    if ( totalPoints > t.getTotalPoints() )
    {
        return true;
    }
    else if ( totalPoints < t.getTotalPoints() )
    {
        return false;
    }
    // If points are equal check if this -> team has higher goal difference.
    else
    {
        if ( goalDifference > t.getGoalDifference() )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Team::toString()
{
    std::cout << "Team name:     " << name << "\n"
              << "xG:            " << xG << "\n"
              << "xGA:           " << xGA << "\n";
}

void Team::addPlayer(const Player& player) {
    players.push_back(player);
}
void Team::addCoach(const Coach& coach1) {
    coach = coach1;
}
void Team::addPresident(const President& president1) {
    president = president1;
}
void Team::printTeamPlayers() {
    for (const Player& player : players) {
        std::cout << player.getName() << "\n";
    }
}
bool Team::operator<(const Team& team) const { 
        if (totalPoints != team.totalPoints)
        {
            return totalPoints < team.totalPoints; 
        }

        else if (goalDifference != team.goalDifference)
        {
            return goalDifference < team.goalDifference;
        }

        else if (totalGoalsFor != team.totalGoalsFor)
        {
            return totalGoalsFor < team.totalGoalsFor;
        }

        else if (totalWins != team.totalWins)
        {
            return totalWins < team.totalWins;
   }
    return name < team.name;
}