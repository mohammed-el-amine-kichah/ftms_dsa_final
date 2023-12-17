#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include "Coach.h"
#include "President.h"
#include <string>
#include <map>

class Team
{
private:

    string m_name;              // Team name.
    vector<Player> m_players;   // Team players.
    Coach m_coach;              // Team coach.
    President m_president;      // Team president.
    
    double m_xG;                // Expected goals.
    double m_xGA;               // Expected goals against.
    int m_totalGoalsFor;        // Total goals scored during season.
    int m_totalGoalsAgainst;    // Total goals scored against during season.
    int m_totalPoints;          // Total points for current season.
    int m_goalDifference;       // Goals for - goals against
    int m_totalWins;            // Total games won.
    int m_totalDraws;           // Total games drawn.
    int m_totalLosses;          // Total games lost.
    int m_totalGamesPlayed;     // Total games played;
    map<double, int> m_scoringDistribution;

public:

    /**
        Default constructor and destructor.
    */
   
    ~Team() {}

    /**
        Constructor for simulations that only take season
        xG/xGA into account.
    */
    Team( string name, double xG, double xGA, map<double, int> scoringDistribution );

    /**
        Accessor methods.
    */
    string getName() { return m_name; }
    string getCoachName() { return m_coach.getName(); }
    string getPresidentName() { return m_president.getName(); }
    vector<Player> getPlayers() { return m_players; }
    double get_xG() { return m_xG; }
    double get_xGA() { return m_xGA; }
    int getTotalGoalsfor() { return m_totalGoalsFor; }
    int getTotalGoalsAgainst() { return m_totalGoalsAgainst; }
    int getTotalPoints() { return m_totalPoints; }
    int getGoalDifference() { return m_goalDifference; }
    int getTotalWins() { return m_totalWins; }
    int getTotalLosses() { return m_totalLosses; }
    int getTotalDraws() { return m_totalDraws; }
    int getTotalGamesPlayed() { return m_totalGamesPlayed; }

    bool operator<(const Team& team) const ;

    /**
        Mutator methods.
    */
    void set_xG( double xG ) { m_xG = xG; }
    void set_xGA( double xGA ) { m_xGA = xGA; }
    void incrementPoints( int amount ) { m_totalPoints += amount; }

    /**
        Methods for incrementing overall goals for and against.
        Used during the lifetime of a game.
    */
    void goalScored( int amount );
    void goalAgainstScored( int amount );


    /**
        Methods for logging wins, draws and losses. Will also update
        total points for this team based on results.
    */
    void logWin();
    void logDraw();
    void logLoss();

    /**
        Method which compares this -> team to another team.

        Returns true if this -> team has higher total points.
        If this -> team has equal points returns true if this -> team
        has a higher goal difference.

        Used when sorted league table.
    */
    bool compareTo( Team t );

    /**
        Prints team name and statistics.

        Format: "Team name: [teamName]"
                "xG:         [xG]"
                "xGA:        [xGA]"
    */
    void toString();

    // methode to populate the team players from csv file
    //void populateTeamPlayers(string teamName);
    void addPlayer(const Player& player);
    void addCoach(const Coach& coach);
    void addPresident(const President& president);
    void printTeamPlayers();
};

#endif
