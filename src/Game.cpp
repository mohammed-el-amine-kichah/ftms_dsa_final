#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../include/Game.h"
#include "../include/Team.h"

using namespace std;

vector<Game> Game::readGamesFromFiles() {
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


void Game::printGameInfo(){
    cout << "Home Team: " << homeTeam.getName() << ", Away Team: " << awayTeam.getName()
              << ", Home Goals: " << homeTeamGoals << ", Away Goals: " << awayTeamGoals
              << ", Date: " << match << ", Duration: " << duration << " minutes" << endl;
    // Add more details as needed
}