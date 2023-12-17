// #include <iostream>
// using namespace std;

// int main() {
    
//     system("python3  ../draw/draw.py ");
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/Team.h"
#include "../include/Player.h"


using namespace std;


vector<Team> readTeamsFromCSV(const string& filename) {
    ifstream inputFile(filename);
    vector<Team> teams;
    string line;

    // Check if file was opened successfully
    if (!inputFile.is_open()) {
        throw runtime_error("Could not open file");
    }

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string name;

        // Parse team name
        getline(inputString, name, ',');

        // Add to teams vector.
        Team team(name);
        teams.push_back(team);
    }

    inputFile.close();
    return teams;
}


// vector<Player> readCSVFiles() {
//     vector<Player> players;

//     for (int i = 1; i <= 38; ++i) {
//         ifstream file("../data/data-final/match_details_week_" + to_string(i) + ".csv");
//         if (!file.is_open()) {
//             cerr << "Unable to open file" << to_string(i) << ".csv" << endl;
//             continue;
//         }

//         string line;
//         getline(file, line); // Skip the header line
//         while (getline(file, line)) {
//             istringstream iss(line);
//             string teamName, playerName, position;
//             int number, goals, onPitch, yellow, red, dist, start, end, played;

//             if (getline(iss, teamName, ',') &&
//                 getline(iss, playerName, ',') &&
//                 iss >> number >> ws >> position >> ws >> goals >> onPitch >> yellow >> red >> dist >> start >> end >> played) {
                
//                 bool playerExists = false;
//                 for(auto& player : players) {
//                     if (player.getTeam() == teamName && player.getName() == playerName) {
//                         playerExists = true;
//                         player.numberOfGoals.push_back(goals);
//                         player.isOnPitch.push_back(onPitch);
//                         player.isYellow.push_back(yellow);
//                         player.isRed.push_back(red);
//                         player.distancea.push_back(dist);
//                         player.startTimea.push_back(start);
//                         player.endTime.push_back(end);
//                         player.timePlayeda.push_back(played);
//                         break;
//                     }
//                 }

//                 if (!playerExists) {
//                     Player newPlayer(teamName, number, playerName, 0, position);
//                     players.push_back(newPlayer);
//                 }
//             } else {
//                 cerr << "Error reading line in file" << to_string(i) << ".csv" << endl;
//             }
//         }

//         file.close();
//     }

//     return players;
// }

vector<Player> readCSVFiles() {
    vector<Player> players;

    for (int i = 1; i <= 38; ++i) {
        ifstream file("../data/data-final/player_details_week_" + to_string(i) + ".csv");
        if (!file.is_open()) {
            cerr << "Unable to open file" << to_string(i) << ".csv" << endl;
            continue;
        }

        string line;
        getline(file, line); // Skip the header line

        while (getline(file, line)) {
            istringstream iss(line);
            string teamName, playerName, position;
            int number, goals, onPitch, yellow, red, dist, start, end, played;
             string numberStr, positionStr, goalsStr, onPitchStr, yellowStr, redStr, distStr, startStr, endStr, playedStr;

    // Read the rest of the comma-separated values as strings

            if (getline(iss, teamName, ',') &&
                getline(iss, playerName, ',')  &&
                getline(iss, numberStr, ',') &&
                getline(iss, positionStr, ',') &&
                getline(iss, goalsStr, ',') &&
                getline(iss, onPitchStr, ',') &&
                getline(iss, yellowStr, ',') &&
                getline(iss, redStr, ',') &&
                getline(iss, distStr, ',') &&
                getline(iss, startStr, ',') &&
                getline(iss, endStr, ',') &&
                getline(iss, playedStr)) {

                // Convert the strings to the appropriate data types if needed
                int number = stoi(numberStr);
                int goals = stoi(goalsStr);
                int onPitch = stoi(onPitchStr);
                int yellow = stoi(yellowStr);
                int red = stoi(redStr);
                int dist = stoi(distStr);
                int start = stoi(startStr);
                int end = stoi(endStr);
                int played = stoi(playedStr);
                bool playerExists = false;
                for (auto& player : players) {
                    if (player.getTeam() == teamName && player.getName() == playerName) {
                        playerExists = true;
                        player.numberOfGoals.push_back(goals);
                        player.isOnPitch.push_back(onPitch);
                        player.isYellow.push_back(yellow);
                        player.isRed.push_back(red);
                        player.distancea.push_back(dist);
                        player.startTimea.push_back(start);
                        player.endTime.push_back(end);
                        player.timePlayeda.push_back(played);
                        break;
                    }
                }

                if (!playerExists) {
                    Player newPlayer(teamName, number, playerName, 0, position);
                    newPlayer.numberOfGoals.push_back(goals);
                    newPlayer.isOnPitch.push_back(onPitch);
                    newPlayer.isYellow.push_back(yellow);
                    newPlayer.isRed.push_back(red);
                    newPlayer.distancea.push_back(dist);
                    newPlayer.startTimea.push_back(start);
                    newPlayer.endTime.push_back(end);
                    newPlayer.timePlayeda.push_back(played);

                    players.push_back(newPlayer);
                }
            } else {
                cerr << "Error reading line in file" << to_string(i) << ".csv" << endl;
            }
        }

        file.close();
    }

    return players;
}


int main() {

    vector<Team> teams = readTeamsFromCSV("../data/teams.csv");
    for (auto team : teams)
    {
        cout<<team.getName()<<endl;
    }
    vector<Player> players = readCSVFiles();
    for (auto team : players)
    {   if (team.getTeam() == "Arsenal"){
        cout<<team.getName()<<endl;
        cout<<team.distancea[37]<<endl;
        cout<<team.numberOfGoals[37]<<endl;
}



    }
    //system("python3  ../draw/draw.py ");
    return 0;
}