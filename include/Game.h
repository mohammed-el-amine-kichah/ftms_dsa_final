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
    void activePlayers(Team *team, vector<Player*> &players);
    vector<Player*> PlayersScoredGame;
public:

    Game() : homeTeam(NULL,"",""), awayTeam(NULL,"",""), homeTeamGoals(0), awayTeamGoals(0), duration(0) {}

     Game(Team& home,Team& away, int homeGoals, int awayGoals, const Date matchDate, int gameDuration, int Gw) 
    : homeTeam(home), awayTeam(away), homeTeamGoals(homeGoals), awayTeamGoals(awayGoals), match(matchDate), duration(gameDuration),gameWeek(Gw) {}
    ~Game() {}

    /**
        Constructor for season simulations where teams are determined in terms
        of home and away. Accepts pointers to teams within the simulation.
    */
    Game( Team *homeTeam, Team *awayTeam );

    /**
        Starts game between two teams within the simulation. The current
        model iteration uses a combination of each teams xG and xGA as
        an estimate for the teams ability to score goals.

        The amount of goals scored by each team is deteremined by a Poisson
        random variable with a weighted average of xG and xGA as it's lambda
        parameter. This is randomly seeded to create varying results for use
        in multiple season simulations.
    */
    void startGame();

    /**
        Methods which log home and away goals. Will also log goals against
        for opposite team.
    */
    void homeGoal( int amount );
    void awayGoal( int amount );

    //Prints score of game to terminal.
    void getScore();
    Team getHomeTeam() const { return homeTeam; }
    Team getAwayTeam() const { return awayTeam; }
    void printActivePlayers(const vector<Player*> &players) const;
    vector<Player*> getPlayersScoredGame() const {return PlayersScoredGame;};
    //vector<Game> readGamesFromFiles();
    void printGameInfo() const;
    Date getday() const {return match;}
    int gethomeGoal() const {return homeTeamGoals;}
    int getawayGoal() const {return awayTeamGoals;}
    int getGameWeek() const {return gameWeek;}
    void printTableat(int round, vector<Team> &teams);
};

#endif