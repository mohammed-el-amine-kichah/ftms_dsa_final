#ifndef SEASON_H
#define SEASON_H

#include <sstream>
#include <chrono>
#include "Date.h"
#include "Team.h"
#include "Player.h"
#include "Game.h"
#include "CSVreader.h"
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

class Season
{
private:
    vector<Team> teams;
    vector<Game> games;
    vector<Player> players;
    vector<Date> dates;

public:
    
    Season(){
        teams = readTeamsFromCSV("../data/teams.csv");
        players = readCSVFiles();
        games = readGamesFromFiles(this->teams,this->dates); 
        int counter = 0;
        for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 23; j++)
        {
            
            teams.at(i).addPlayer(players.at(counter));
           
            counter++;
           
        }
    }   
      
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

    void printGW(int round );
    void printgametable(BinarySearchTree<Team> &teams);
    void DisplayScorersBST(int round);
    void DisplayScorersAVL(int round);
    void DisplayBestScorersBST();
    void DisplayBestScorersBST(string TeamName);
    void DisplayBestScorersAVL();
    void showCurve(string name);

    void choice(int n, int gw);
    void printDistance(string ,int );
    vector<Date> getDates() {return dates;}

};



#endif