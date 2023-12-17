#ifndef DRIVER_H
#define DRIVER_H

#include "../include/Team.h"
#include "Player.h"
#include "Coach.h"
#include "President.h"

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class IODriver
{
private:

        string m_inputFileName;
        string m_outputFileName;
        map<string, int> m_positionMap;

    public:

        IODriver() {}
        ~IODriver() {}

        IODriver( string inputFileName, string outputFileName );

        void createPositionMap( vector<Team> teams );
        vector<Team> parseCSV();
        map<double, int> createScoringDistribution( string teamName );
        void createCSVHeader();
        void writeResultToCSV( vector<Team> leaguePositions );
        vector<Player> readPlayersFromCSV (string);
        vector<Player> readPlayers(string);
        vector<Coach> readCoachesFromCSV (string);
        vector<President> readPresidentsFromCSV (string);

    };

    #endif
