#ifndef GAME_H
#define GAME_H

#include "Team.h"
#include "Date.h"
#include <string>

class Game
{
private:

    Team homeTeam;      // Pointer to team playing at home during this game.
    Team awayTeam;      // Pointer to team playing away during this game.
    int homeTeamGoals;   // Amount of goals score by home team.
    int awayTeamGoals;   // Amount of goals score by away team.
    Date match;
    int duration;
    int gameWeek;

    vector<Player*> activeHomePlayers;
    vector<Player*> activeAwayPlayers;
    vector<Player*> PlayersScoredGame;
public:

    Game() : homeTeam(NULL,"",""), awayTeam(NULL,"",""), homeTeamGoals(0), awayTeamGoals(0), duration(0) {}

     Game(Team& home,Team& away, int homeGoals, int awayGoals, const Date matchDate, int gameDuration, int Gw) 
    : homeTeam(home), awayTeam(away), homeTeamGoals(homeGoals), awayTeamGoals(awayGoals), match(matchDate), duration(gameDuration),gameWeek(Gw) {}
    ~Game() {}

    Team getHomeTeam() const { return homeTeam; }
    Team getAwayTeam() const { return awayTeam; }
    vector<Player*> getPlayersScoredGame() const {return PlayersScoredGame;};
    Date getday() const {return match;}
    int gethomeGoal() const {return homeTeamGoals;}
    int getawayGoal() const {return awayTeamGoals;}
    int getGameWeek() const {return gameWeek;}
    void printTableat(int round, vector<Team> &teams);
    void printGameInfo() const;
};

#endif