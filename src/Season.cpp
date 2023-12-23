#include <iostream>
#include <vector>
#include "../include/Season.h"
using namespace std;


void Season::printGW(int round)
{
    BinarySearchTree <Team> TeamBST; 
    for(Team team:teams)
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
    Counter::reset();
}
vector<Player> Season::getTeamPlayers(string teamName){
    for (auto team : teams)
    {
        if (team.getName() == teamName)
        {
            return team.getPlayers();
        }
    }
    cout << "Team not found" << endl;
    return {};
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
void Season::DisplayBestScorersBST(string TeamName) {
        auto start = chrono::high_resolution_clock::now();
        bool found = false;

        BinarySearchTree<Player> bestScorers;
        BinarySearchTree<Player> bestScorer;
        for (auto team : teams)
        {
            if (team.getName() == TeamName){
                found = true;
                for (auto player : team.getPlayers())
                {
                    if (player.getGoals() > 0) {
                        bestScorer.insert(player);
                    } 
                }
                bestScorer.printTree();
                auto end = chrono::high_resolution_clock::now();

                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "BST display time: " << duration.count() << " microseconds" << endl;
                break;
            }
        }
        if (!found) cout << "Team not found" << endl;
    }
void Season::DisplayScorersBST(int gw = 37){
    auto start = chrono::high_resolution_clock::now();
    BinarySearchTree<Player> bstScorers;
    BinarySearchTree<Player> bstScorer;
   
    for(auto& team : teams){
        vector<Player> players = team.getPlayers();
        int gameWeek = gw;  // Create a copy of gw for each team
        for (auto player : players)
        {   
            player.setGoals(player.getNumberOfGoals()[gw]);
            player.setTimePlayed(player.getTimePlayedI(gw));
            if (player.getGoals() > 0 && gameWeek-- > 0) 
                bstScorers.insert(player); 
        }
        bstScorer.insert(bstScorers.findMax());
        bstScorers.makeEmpty();
    }
    bstScorer.printTree();
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
void Season::DisplayScorersAVL(int gw = 37){
        auto start = chrono::high_resolution_clock::now();

        AvlTree<Player> avlScorers;
       
        for (auto& team : teams)
        {      
            vector<Player> players = team.getPlayers();
            int gameWeek = gw;  // Create a copy of gw for each team
            for (auto player : players)
            { 
                player.setGoals(player.getNumberOfGoals()[gw]);
                player.setTimePlayed(player.getTimePlayedI(gw));
                if (player.getGoals() > 0 && gameWeek-- > 0) 
                    avlScorers.insert(player); 
            }
        }
        
        avlScorers.printTree();
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "AVL display time: " << duration.count() << " microseconds" << endl;
    }

    void Season::showCurve(string name){
        ofstream myfile;
        bool found = false;
        myfile.open ("../draw/goalDistribution.csv");
        myfile <<name<<"\n";

        myfile <<"GameweekNumber,Goals\n";
        
        for (auto player : players) {
            if (player.getName() == name){
            found = true;
                for (int i = 0; i < player.getNumberOfGoals().size(); i++)
                {   if (i == 0)
                    myfile << i+1 << "," << player.getNumberOfGoals()[i] << "\n";
                    else 
                    myfile << i+1 << "," << player.getNumberOfGoals()[i] - player.getNumberOfGoals()[i-1] << "\n";
                }
                myfile.close();
                system("python3  ../draw/draw.py ");
            }
        }
        if(!found) cout <<endl<< "Player not found" << endl;
    }
    
    void Season::printgametable(BinarySearchTree<Team> &teams)
    {
            cout << endl;
            cout<< setw(20) << left <<
            "TeamName" << setw(16) << left <<
            "MP" << setw(16) << left <<
            "Wins" << setw(16) << left << 
            "Draws" << setw(16) << left << 
            "Loses" << setw(16) << left << 
            "Points" << endl;
            cout << endl;
        teams.printTree();
        Counter::reset();
    }
    void Season::printDistance(string teamName,int i = 38){
        double distance = 0;
        bool TeamFound = false;
        for (auto team : teams)
        {
            if (team.getName() == teamName)
            {
                TeamFound = true;
                for(auto& player : team.getPlayers())
                {
                    if (i == 1)
                    {
                        cout<<player.getName() << " Runs : " << player.getDistanceI(i-1)<< " KM in Gameweek number "<< i << endl;
                        distance += player.getDistanceI(i-1);
                    }
                    else if (i != 1)
                    {
                        cout<<player.getName()<<" "<<player.getDistanceI(i-1) - player.getDistanceI(i-2)<< " KM in Gameweek number "<< i <<endl;
                        distance += player.getDistanceI(i-1) - player.getDistanceI(i-2);
                    }
                    cout << "The average distance covered by the player is : " << distance / i << " KM" << endl;
                    cout << endl;                 
                }
            }
        }
        if (!TeamFound)
        {
            cout << "Team not found" << endl;
        }
    }
    void Season::teamInformation(string TeamName,int i = 38){
        bool found = false;
        int counter = 1;
        for(auto & team : teams)
        {
            if(team.getName() == TeamName)
            {
                found = true;
                cout <<endl<< "Team Name : "<< team.getName() << endl;
                cout << "Coach Name : "<< team.getCoachName() << endl;
                cout << "President Name : " << team.getPresidentName() << endl;

                cout << "Team Players : " << endl;
                for(auto & player : team.getPlayers())
                {
                    cout <<counter << " - "<< player.getName() << endl;
                    counter++;
                }
                cout << endl;
                break;
            }
        }
        if (found == false)
        {
            cout <<endl<< "Team Not Found Please ENter A Valid Team Name" << endl;
        }
        
    }
void Season::printGameWeekDetails(int gw){
        bool found = false;
        for (auto game : games)
        {
            if (game.getGameWeek() == gw)
            {
                cout << "Game Week : " << gw << endl;
                found = true;
                game.printGameInfo();
                cout << endl;
            }
        }
        if (!found)
        {
            cout << "Game Week Not Found" << endl;
        }
    
}
void Season::printPlayersDetails(int gw){
    bool found = false;
    int gameweek = gw + 1;

    // Iterate over all games
    for (auto game : games)
    {
        // If the current game's week is greater than the specified week, break the loop
        if(game.getGameWeek() > gameweek) break;

        // If the current game's week matches the specified week
        if (game.getGameWeek() == gameweek){
            cout << "* ----------------------------------------------------- *\n";

            // Get the players of the home and away teams
            vector<Player> homePlayers = this->getTeamPlayers(game.getHomeTeam().getName());
            vector<Player> awayPlayers = this->getTeamPlayers(game.getAwayTeam().getName());

            found = true;

            // Print game info
            game.printGameInfo();

            // Print home team players' details
            cout << (game.getHomeTeam()).getName()<<" Players : " << endl;
            for (auto& player : homePlayers)
            {
                // Skip players who didn't play in the specified week
                if(player.getTimePlayedI(gw) == 0) continue;

                // Print player details
                cout << player.getName() << endl;
                if (gw == 0) {
                    cout << "Goals : " << player.getNumberOfGoals()[gw] << endl;
                    cout << "Yellow Cards : " << player.getIsYellowI(gw) << endl;
                    cout << "Red Cards : " << player.getIsRedI(gw) << endl;
                    cout << "Distance : " << player.getDistanceI(gw) << endl;
                } else {
                    cout << "Goals : " << player.getNumberOfGoals()[gw] - player.getNumberOfGoals()[gw-1] << endl;
                    cout << "Yellow Cards : " << player.getIsYellowI(gw) - player.getIsYellowI(gw-1) << endl;
                    cout << "Red Cards : " << player.getIsRedI(gw) - player.getIsRedI(gw-1) << endl;
                    cout << "Distance : " << player.getDistanceI(gw) - player.getDistanceI(gw-1) << endl;
                }
                cout << endl;
            }

            // Print away team players' details
            cout << (game.getAwayTeam()).getName()<<" Players : " << endl;
            for (auto& player : awayPlayers)
            {
                // Skip players who didn't play in the specified week
                if(player.getTimePlayedI(gw) == 0) continue;

                // Print player details
                cout << player.getName() << endl;
                if (gw == 0) {
                    cout << "Goals : " << player.getNumberOfGoals()[gw] << endl;
                    cout << "Yellow Cards : " << player.getIsYellowI(gw) << endl;
                    cout << "Red Cards : " << player.getIsRedI(gw) << endl;
                    cout << "Distance : " << player.getDistanceI(gw) << endl;
                } else {
                    cout << "Goals : " << player.getNumberOfGoals()[gw] - player.getNumberOfGoals()[gw-1] << endl;
                    cout << "Yellow Cards : " << player.getIsYellowI(gw) - player.getIsYellowI(gw-1) << endl;
                    cout << "Red Cards : " << player.getIsRedI(gw) - player.getIsRedI(gw-1) << endl;
                    cout << "Distance : " << player.getDistanceI(gw) - player.getDistanceI(gw-1) << endl;
                }
                cout << endl;
            }

            cout << "* ----------------------------------------------------- *\n";
        }
    }

    // If no game was found for the specified week
    if (!found)
    {
        cout << "Game Week Not Found" << endl;
    }
}


void Season::choice(int n,int gw) {
        string name,teamName;
        BinarySearchTree<Team> myteams;
        int r = gw;


        switch (n)
        {   
            case 1:
                system("cls");
                DisplayBestScorersAVL();
                break;
            case 2:
                system("cls");
                DisplayScorersBST(gw);
                break;
            case 3:
                system("cls");
                DisplayScorersAVL(gw);
                break;
            case 4: 
                cout << "Enter the name of the player: ";
                getline(cin>>ws, name);
                showCurve(name);
                break;
            case 5:
                system("cls");
                printGameWeekDetails(gw++);
                break;
            case 6:
                system("cls");
                cout << "Game week : " << ++gw << endl << endl;
                printPlayersDetails(--gw);
                break;
            case 7:
                for (auto team : teams)
                {
                    team.InfoAt(gw);
                    myteams.insert(team);
                }
                system("cls");
                printgametable(myteams);
                break;
            case 8:
                cout << "Enter Team Name : ";
                getline(cin>>ws, teamName);
                cout << endl;
                printDistance(teamName,gw);
                break;
            
            case 9:
                cout << "Enter Team name :";
                getline(cin>>ws, teamName);
                system("cls");
                cout << teamName << endl;
                DisplayBestScorersBST(teamName);
                break;
            case 10:
                cout << "Enter Team name :";
                getline(cin>>ws, teamName);
                system("cls");
                teamInformation(teamName,gw);
                break;

            default:
                break;
                
            }
    }