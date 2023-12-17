#include "../include/Team.h"
#include <iostream>
#include <vector>
#include <map>

Team::Team( std::string name, double xG, double xGA, std::map<double, int> scoringDistribution )
{
    m_name = name;
    m_xG = xG;
    m_xGA = xGA;
    m_totalGoalsFor = 0;
    m_totalGoalsAgainst = 0;
    m_totalPoints = 0;
    m_goalDifference = 0;
    m_totalWins = 0;
    m_totalDraws = 0;
    m_totalLosses = 0;
    m_totalGamesPlayed = 0;
    m_scoringDistribution = scoringDistribution;
}

void Team::goalScored( int amount )
{
    m_totalGoalsFor += amount;
    m_goalDifference = m_totalGoalsFor - m_totalGoalsAgainst;
}

void Team::goalAgainstScored( int amount )
{
    m_totalGoalsAgainst += amount;
    m_goalDifference = m_totalGoalsFor - m_totalGoalsAgainst;
}

void Team::logWin()
{
    m_totalWins += 1;
    m_totalPoints += 3;
    m_totalGamesPlayed++;
}

void Team::logDraw()
{
    m_totalDraws += 1;
    m_totalPoints += 1;
    m_totalGamesPlayed++;
}

void Team::logLoss()
{
    m_totalLosses += 1;
    m_totalPoints += 0; // Added for completeness.
    m_totalGamesPlayed++;
}

bool Team::compareTo( Team t )
{
    // Check if this -> team has more points.
    if ( m_totalPoints > t.getTotalPoints() )
    {
        return true;
    }
    else if ( m_totalPoints < t.getTotalPoints() )
    {
        return false;
    }
    // If points are equal check if this -> team has higher goal difference.
    else
    {
        if ( m_goalDifference > t.getGoalDifference() )
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
    std::cout << "Team name:     " << m_name << "\n"
              << "xG:            " << m_xG << "\n"
              << "xGA:           " << m_xGA << "\n";
}

void Team::addPlayer(const Player& player) {
    m_players.push_back(player);
}
void Team::addCoach(const Coach& coach) {
    m_coach = coach;
}
void Team::addPresident(const President& president) {
    m_president = president;
}
void Team::printTeamPlayers() {
    for (const Player& player : m_players) {
        std::cout << player.getName() << "\n";
    }
}
bool Team::operator<(const Team& team) const { 
        if (m_totalPoints != team.m_totalPoints)
        {
            return m_totalPoints < team.m_totalPoints; 
        }

        else if (m_goalDifference != team.m_goalDifference)
        {
            return m_goalDifference < team.m_goalDifference;
        }

        else if (m_totalGoalsFor != team.m_totalGoalsFor)
        {
            return m_totalGoalsFor < team.m_totalGoalsFor;
        }

        else if (m_totalWins != team.m_totalWins)
        {
            return m_totalWins < team.m_totalWins;
   }
    return m_name < team.m_name;
}