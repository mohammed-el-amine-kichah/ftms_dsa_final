#include "../include/IODriver.h"
#include "../include/Team.h"

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>


IODriver::IODriver( string inputFileName, string outputFileName )
{
    m_inputFileName = inputFileName;
    m_outputFileName = outputFileName;
}

vector<Team> IODriver::parseCSV( )
{
    ifstream inputFile;
    inputFile.open( m_inputFileName );
    string line = "";
    vector<Team> teams;

    while ( getline(inputFile, line) )
    {
        
        stringstream inputString(line);
        string tempString;
        string name;
        double xG;
        double xGA;

        // Parse team name
        getline(inputString, name, ',');

        // Parse xG
        getline(inputString, tempString, ',');
        xG = atof(tempString.c_str());

        // Parse xGA
        getline(inputString, tempString);
        xGA = atof(tempString.c_str());

        // Create goal scoring distubtion for team
       // map<double, int> scoringDistribution = createScoringDistribution( name );
        map<double, int> scoringDistribution ;
        

        // Add to teams vector.
        Team team = Team( name, xG, xGA, scoringDistribution);
        teams.push_back( team );
        line = "";
    }

    inputFile.close();

    createPositionMap( teams );
    createCSVHeader();
    return teams;
}



vector<Player> IODriver::readPlayersFromCSV(string inputFileName) {
    ifstream inputFile(inputFileName); // Open the file directly during initialization

    if (!inputFile.is_open()) {
        // Handle file open error here if needed
        cerr << "Error opening file: " << inputFileName << endl;
        return {}; // Return an empty vector in case of an error
    }

    string line;
    vector<Player> players;

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string teamName;
        string tempString;
        string name;
        string position;

        int number;
        int age;

        // Parse team name
        getline(inputString, teamName, ',');

        // Parse player number
        getline(inputString, tempString, ',');
         try {
    int number = stoi(tempString);
} catch (const invalid_argument& e) {
    cerr << "Failed to convert string daz"<<tempString <<" to integer: " << tempString << endl;
    throw;
}
   

        // Parse player name
        getline(inputString, name, ',');

        // Parse player age
        getline(inputString, tempString, ',');
        try {
    int age = stoi(tempString);
} catch (const invalid_argument& e) {
    cerr << "Failed to convert string to integer: " << tempString << endl;
    throw;
}
        

        // Parse player position
        getline(inputString, position, ',');

        // Add to players vector
        players.emplace_back(teamName, number, name, age, position);
    }

    inputFile.close();
    return players;
}

vector<Player> IODriver::readPlayers(string inputFileName) {
    ifstream inputFile(inputFileName); // Open the file directly during initialization

    if (!inputFile.is_open()) {
        // Handle file open error here if needed
        cerr << "Error opening file: " << inputFileName << endl;
        return {}; // Return an empty vector in case of an error
    }

    string line;
    vector<Player> players;

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string teamName;
        string tempString;
        string name;
        string position;

        int number;
        int age;

        // Parse team name
        getline(inputString, teamName, ',');

        // Parse player number
        getline(inputString, tempString, ',');
         try {
    int number = stoi(tempString);
} catch (const invalid_argument& e) {
    cerr << "Failed to convert string daz"<<tempString <<" to integer: " << tempString << endl;
    throw;
}
   

        // Parse player name
        getline(inputString, name, ',');

        // Parse player age
        getline(inputString, tempString, ',');
        try {
    int age = stoi(tempString);
} catch (const invalid_argument& e) {
    cerr << "Failed to convert string to integer: " << tempString << endl;
    throw;
}
        

        // Parse player position
        getline(inputString, position, ',');
        for (int i=)
        // Add to players vector
        players.emplace_back(teamName, number, name, age, position);
    }

    inputFile.close();
    return players;
}



vector<Coach> IODriver::readCoachesFromCSV(string inputFileName) {
    ifstream inputFile(inputFileName); // Open the file directly during initialization

    if (!inputFile.is_open()) {
        // Handle file open error here if needed
        cerr << "Error opening file: " << inputFileName << endl;
        return {}; // Return an empty vector in case of an error
    }

    string line;
    vector<Coach> coaches;

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string teamName;
        string tempString;
        string name;
        int age;
        int salary;

        // Parse team name
        getline(inputString, teamName, ',');

        // Parse coach name
        getline(inputString, name, ',');

        // Parse coach age
        getline(inputString, tempString, ',');
        try {
            age = stoi(tempString);
        } catch (const invalid_argument& e) {
            cerr << "Failed to convert string to integer: " << tempString << endl;
            throw;
        }

        // Parse coach salary
        getline(inputString, tempString, ',');
        try {
            salary = stoi(tempString);
        } catch (const invalid_argument& e) {
            cerr << "Failed to convert string to integer: " << tempString << endl;
            throw;
        }

        // Add to coaches vector
        coaches.emplace_back(teamName, name, age, salary);
    }

    inputFile.close();
    return coaches;
}




vector<President>IODriver:: readPresidentsFromCSV(string inputFileName) {
    ifstream inputFile(inputFileName); // Open the file directly during initialization

    if (!inputFile.is_open()) {
        // Handle file open error here if needed
        cerr << "Error opening file: " << inputFileName << endl;
        return {}; // Return an empty vector in case of an error
    }

    string line;
    vector<President> presidents;

    while (getline(inputFile, line)) {
        stringstream inputString(line);
        string teamName;
        string tempString;
        string name;
        int age;
        string wealth;

        // Parse team name
        getline(inputString, teamName, ',');

        // Parse president name
        getline(inputString, name, ',');

        // Parse president age
        getline(inputString, tempString, ',');
        try {
    int age = stoi(tempString);
} catch (const invalid_argument& e) {
    cerr << "Failed to convert string to integer: " << tempString << endl;
    throw;
}
        

        // Parse president wealth
        getline(inputString, wealth, ',');

        // Add to presidents vector
        presidents.emplace_back(teamName, name, age, wealth);
    }

    inputFile.close();
    return presidents;
}




// new code for parsing goals scored into a team distribution for scorring
map<double, int> IODriver::createScoringDistribution( string teamName )
{
    ifstream inputFile;
    inputFile.open( "data/2022/" + teamName + ".csv");
    string line = "";
    vector<int> goals;
    map<double, int> scoringDistribution; 

    // Parse historic goals scored
    while ( getline(inputFile, line) )
    {
        stringstream inputString(line);
        string tempString;
        string name;

        // Record goal
        getline(inputString, tempString);
        goals.push_back( atoi(tempString.c_str()) );
        line = "";
    }
    sort( goals.begin(), goals.end() );
    inputFile.close();

    // Create Distribution
    double proportion = 0;
    int position = 0;
    // cout << teamName << "\n";
    for ( int i=0; i < goals[goals.size()-1]; i++)
    {
        int count = 0;
        while ( goals[position] == i)
        {
            count++;
            position++;
        }

        proportion = proportion + (double) count / goals.size();
        scoringDistribution.insert( {proportion, i} );
    }

    return scoringDistribution;
}

void IODriver::createPositionMap( vector<Team> teams )
{
    for ( int i = 0; i < teams.size(); i++ )
    {
        m_positionMap.insert( pair<string, int>(teams[i].getName(),i));
    }
}

void IODriver::createCSVHeader()
{
    ofstream outputFile( m_outputFileName );

    map<string, int>::iterator it;
    for (it = m_positionMap.begin(); it != m_positionMap.end(); it++)
    {
        outputFile << it->first << ",";
    }
    outputFile << "\n";

    outputFile.close();
}

void IODriver::writeResultToCSV( vector<Team> leaguePositions )
{
    ofstream outputFile( m_outputFileName, ios::app );

    // Map positions for the current sim run.
    for ( int i = 0; i < leaguePositions.size(); i++ )
    {
        map<string, int>::iterator it =
                        m_positionMap.find( leaguePositions[i].getName() );
        if ( it != m_positionMap.end() )
        {
            it->second = i+1;
        }
    }

    // Write these positions to results csv in alphabetical order.
    map<string, int>::iterator it;
    for (it = m_positionMap.begin(); it != m_positionMap.end(); it++)
    {
        outputFile << it->second << ",";
    }

    outputFile << "\n";
    outputFile.close();
}