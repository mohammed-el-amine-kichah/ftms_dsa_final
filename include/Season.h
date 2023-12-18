#ifndef SEASON_H
#define SEASON_H

#include <sstream>
#include "Team.h"
#include "Player.h"
#include "Game.h"
#include "CSVreader.h"
using namespace std;

class Season
{
private:
    vector<Team> teams;
    vector<Game> games;
    vector<Player> players;

public:
    
    Season(){
        teams = readTeamsFromCSV("../data/teams.csv");
        players = readCSVFiles();
        games = readGamesFromFiles();
    };
    vector<Team> getTeams() { return teams; }
    vector<Game> getGames() { return games; }
    vector<Player> getPlayers() { return players; }
    void printTeams(){
        for (auto team : teams)
        {
            cout<<team.getName()<<endl;
        }
    }
    void printPlayers(){
        for (auto player : players)
        {
            cout<<player.getName()<<endl;
        }
    }
    void printGames(){
        for (auto game : games)
        {
            cout<<game.getHomeTeam()<<" " << game.gethomeGoal() <<" - "<< game.getawayGoal()<<" "<<game.getAwayTeam()<<endl;
        }
    }

    ~Season(){};
};



#endif