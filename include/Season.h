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
        for (int j = 0; j < 22; j++)
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
    
    void printGW(int round , vector<Team> &teams);
    void printgametable(BinarySearchTree<Team> &teams);

    void DisplayBestScorersBST() {
        auto start = chrono::high_resolution_clock::now();

        BinarySearchTree<Player> bestScorers;
        BinarySearchTree<Player> bestScorer;
        for (auto team : teams)
        {
            for (auto player : team.getPlayers())
            {
                if (player.getGoals() > 0) 
                    bestScorer.insert(player); 
            }
            Player best = bestScorer.findMax();
            bestScorers.insert(best);
            bestScorer.makeEmpty();
        }

        cout << "TEAM    Name           GOALS" << endl;
        bestScorers.printTree();

        cout << "the best scorer among all teams is: " << bestScorers.findMax() << endl;
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "BST display time: " << duration.count() << " microseconds" << endl;
    }
    void DisplayBestScorersAVL() {
        auto start = chrono::high_resolution_clock::now();

        AvlTree<Player> bestScorers;
        AvlTree<Player> bestScorer;
        for (auto& team : teams)
        {   
           
            
            vector<Player> players = team.getPlayers();
           
           
             for (auto player : players)
            { 
                 if (player.getGoals() > 0) {
                  
                     bestScorer.insert(player);} 
            }
            Player best = bestScorer.findMax();
            //cout << best << endl;
            bestScorers.insert(best);
        
        bestScorer.makeEmpty();
        }
        cout << "TEAM    Name           GOALS" << endl;
     bestScorers.printTree();

        cout << "the best scorer among all teams is: " << bestScorers.findMax() << endl;
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "AVL display time: " << duration.count() << " microseconds" << endl;
    }

    void showCurve(string name){
        ofstream myfile;
        myfile.open ("../draw/goalDistribution.csv");
        myfile <<name<<"\n";

        myfile <<"GameweekNumber,Goals\n";
        
        for (auto player : players) {
            if (player.getName() == name)
            for (int i = 0; i < player.getNumberOfGoals().size(); i++)
            {   if (i == 0)
                myfile << i+1 << "," << player.getNumberOfGoals()[i] << "\n";
                else 
                myfile << i+1 << "," << player.getNumberOfGoals()[i] - player.getNumberOfGoals()[i-1] << "\n";
            }
        }
        myfile.close();
        system("python3  ../draw/draw.py ");

    }
    
    void DisplayScorersBST(int gw = 37){
        auto start = chrono::high_resolution_clock::now();
        BinarySearchTree<Player> bstScorers;
       
        for (auto player : players)
        {   
            player.setGoals(player.getNumberOfGoals()[gw]);
            player.setTimePlayed(player.getTimePlayedI(gw));
            if (player.getGoals() > 0) 
                bstScorers.insert(player); 
                
        }
        bstScorers.printTree();
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "BST display time: " << duration.count() << " microseconds" << endl;
    }
    void DisplayScorersAVL(int gw = 37){
        auto start = chrono::high_resolution_clock::now();

        AvlTree<Player> avlScorers;
       
        for (auto player : players)
        {   
            player.setGoals(player.getNumberOfGoals()[gw]);
            player.setTimePlayed(player.getTimePlayedI(gw));
            if (player.getGoals() > 0) 
                avlScorers.insert(player); 
                
        }
        avlScorers.printTree();
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "AVL display time: " << duration.count() << " microseconds" << endl;
    }
    vector<Date> getDates() {return dates;}

};



#endif