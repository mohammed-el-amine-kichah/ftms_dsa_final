#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <string>
#include <map>

class Team
{
private:

    string name;              // Team name.
    vector<Player> players;   // Team players.
    
    int totalGoalsFor;        // Total goals scored during season.
    int totalGoalsAgainst;    // Total goals scored against during season.
    int totalPoints;          // Total points for current season.
    int goalDifference;       // Goals for - goals against
    int totalWins;            // Total games won.
    int totalDraws;           // Total games drawn.
    int totalLosses;          // Total games lost.
    int totalGamesPlayed;     // Total games played;

public:

    ~Team() {}


    Team( string name1);

    string getName() { return name; }
    vector<Player> getPlayers() { return players; }
    int getTotalGoalsfor() { return totalGoalsFor; }
    int getTotalGoalsAgainst() { return totalGoalsAgainst; }
    int getTotalPoints() { return totalPoints; }
    int getGoalDifference() { return goalDifference; }
    int getTotalWins() { return totalWins; }
    int getTotalLosses() { return totalLosses; }
    int getTotalDraws() { return totalDraws; }
    int getTotalGamesPlayed() { return totalGamesPlayed; }

    bool operator<(const Team& team) const ;

    /**
        Mutator methods.
    */

    void incrementPoints( int amount ) { totalPoints += amount; }

    /**
        Methods for incrementing overall goals for and against.
        Used during the lifetime of a game.
    */
    void goalScored( int amount );
    void goalAgainstScored( int amount );


    /**
        Methods for logging wins, draws and losses. Will also update
        total points for this team based on results.
    */
    void logWin();
    void logDraw();
    void logLoss();

    /**
        Method which compares this -> team to another team.

        Returns true if this -> team has higher total points.
        If this -> team has equal points returns true if this -> team
        has a higher goal difference.

        Used when sorted league table.
    */
    bool compareTo( Team t );

    /**
        Prints team name and statistics.
    */
    void toString();

    // methode to populate the team players from csv file
    //void populateTeamPlayers(string teamName);
    void addPlayer(const Player& player);
    void printTeamPlayers();
};

#endif