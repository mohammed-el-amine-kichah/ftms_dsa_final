#include <iostream>
#include <vector>
#include "../include/Season.h"



void Season::printGW(int round)
{
    BinarySearchTree <Team> TeamBST; 
    for( Team team:teams)
    {
        team.InfoAt(round);
        TeamBST.insert(team);
    }
    cout << endl;
    cout<< setw(20) << left <<
    "TeamName" << setw(16) << left <<
    "MP" << setw(16) << left <<
    "Wins" << setw(16) << left << 
    "Draws" << setw(16) << left << 
    "Loses" << setw(16) << left << 
    "Points" << endl;
    cout << endl;
    TeamBST.printTree();
}
       
    void Season::DisplayBestScorersBST() {
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
    void Season::DisplayBestScorersAVL() {
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
        cout << "TEAM          Name           GOALS" << endl;
        cout << "\n";

        bestScorers.printTree();
        cout << "\n";
        cout << "the best scorer among all teams is: " << bestScorers.findMax() << endl << endl;
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "AVL display time: " << duration.count() << " microseconds" << endl << endl;
    }

    void Season::showCurve(string name){
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
    
    void Season::DisplayScorersBST(int gw = 37){
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
    void Season::DisplayScorersAVL(int gw = 37){
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
    
    void Season::printgametable(BinarySearchTree<Team> &teams)
    {
        teams.printTree();
    }
    void Season::choice(int n,int gw) {
        string name;
        BinarySearchTree<Team> myteams;


        switch (n)
        {   
            cout << n;
            case 1:
                system("clear");
                DisplayBestScorersBST();
                break;
            case 2:
                system("clear");
                DisplayBestScorersAVL();
                break;
            case 3:
                system("clear");
                DisplayScorersBST(gw);
                break;
            case 4:
                system("clear");
                DisplayScorersAVL(gw);
                break;
            case 5: 
                cout << "Enter the name of the player: ";
                getline(cin>>ws, name);
                showCurve(name);
                break;
            case 6:
                
                system("clear");
                printGW(gw);
                

                break;
            case 7:
                for (auto team : teams)
                {
                    team.InfoAt(gw); // derafa 3shan el gameweek bta3 el standing table
                    myteams.insert(team);
                  
                }
                system("clear");
                printgametable(myteams);
                break;

            default:
                break;
                
            }
    }

    void Season::printDistance(string teamName,int i = 38){
        double distance = 0;
        for (auto team : teams)
        {
            if (team.getName() == teamName)
            {
                for(auto& player : team.getPlayers())
                {
                    if (i == 1)
                    {
                        cout<<player.getName() << " Runs : " << player.getDistanceI(i-1)<< " KM in Gameweek number "<< i << endl;
                    }
                    else if (i != 1)
                    {
                        cout<<player.getName()<<" "<<player.getDistanceI(i-1) - player.getDistanceI(i-2)<< " KM in Gameweek number "<< i <<endl;
                    }
                    cout << "The average distance covered by the player is : " << distance / i << " KM" << endl;
                    cout << endl;
                    distance = player.getDistanceI(i-1);                   
                }
            }
        }
    }