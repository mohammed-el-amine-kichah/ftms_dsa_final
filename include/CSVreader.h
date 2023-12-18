#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <sstream>
#include "Team.h"
#include "Player.h"
#include "Game.h"
#include "Date.h"
using namespace std;

vector<Team> readTeamsFromCSV(const string& filename) {
    ifstream inputFile(filename);
    vector<Team> teams;
    string line;

    if (!inputFile.is_open()) {
        throw runtime_error("Could not open file");
    }

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string name;

        getline(inputString, name, ',');
        
        Team team(name);
        teams.push_back(team);
    }

    inputFile.close();
    return teams;
}

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
                        player.setGoals(player.getGoals() + goals);
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
vector<Game>readGamesFromFiles() {
    vector<Game> allGames;

    // Iterate over the 38 files
    for (int fileNumber = 1; fileNumber <= 38; ++fileNumber) {
        // Construct the file name based on your naming convention
        string fileName = "../data/data-final/match_details_week_" + to_string(fileNumber) + ".csv";

        // Open the CSV file
        ifstream inputFile(fileName);

        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening file: " << fileName << endl;
            // Handle the error (e.g., log, notify user, etc.)
            continue; // Skip to the next file
        }

        // Read and ignore the header line
        string header;
        getline(inputFile, header);

        // Read the data from the file
        string line;
        int lineCount = 1;  // Add lineCount to keep track of the line causing the exception
        while (getline(inputFile, line)) {
            try {
                istringstream ss(line);
                string token;

                // Read each column separated by commas
                getline(ss, token, ',');
                string match = token;  // Assuming Date class has overloaded >> operator
                Date matchdate;
                matchdate.fromString(match);

                getline(ss, token, ',');
                Team homeTeam = Team(token);

                getline(ss, token, ',');
                Team awayTeam = Team(token);

                getline(ss, token, ',');
                int homeTeamGoals = stoi(token);

                getline(ss, token, ',');
                int awayTeamGoals = stoi(token);


                // Update the team stats
                homeTeam.addGoals(homeTeamGoals);
                homeTeam.addGoalsAgainst(awayTeamGoals);
                awayTeam.addGoals(awayTeamGoals);
                awayTeam.addGoalsAgainst(homeTeamGoals);
                homeTeam.addGamesPlayed();
                awayTeam.addGamesPlayed();
                homeTeam.updateGoalsFor();
                homeTeam.updateGoalsAgainst();
                awayTeam.updateGoalsFor();
                awayTeam.updateGoalsAgainst();

                getline(ss, token);
                int duration = stoi(token);

                // Add the Game object to the vector
                allGames.emplace_back(homeTeam, awayTeam, homeTeamGoals, awayTeamGoals, matchdate, duration);
            } catch (const exception& e) {
                cerr << "Error processing line " << lineCount << " in file " << fileName << ": " << e.what() << endl;
                // Handle the error (e.g., log, notify user, etc.)
            }
            ++lineCount;
        }

        // Close the file
        inputFile.close();
    }

    return allGames;
}

#endif