#ifndef TEAH
#define TEAH

#include "Player.h"
#include "Coach.h"
#include "President.h"
#include <string>
#include <map>

class Team
{
private:

    string name;              // Team name.
    vector<Player> players;   // Team players.
    Coach coach;              // Team coach.
    President president;      // Team president.
    
    double xG;                // Expected goals.
    double xGA;               // Expected goals against.
    int totalGoalsFor;        // Total goals scored during season.
    int totalGoalsAgainst;    // Total goals scored against during season.
    int totalPoints;          // Total points for current season.
    int goalDifference;       // Goals for - goals against
    int totalWins;            // Total games won.
    int totalDraws;           // Total games drawn.
    int totalLosses;          // Total games lost.
    int totalGamesPlayed;     // Total games played;
    map<double, int> scoringDistribution;

public:

    /**
        Default constructor and destructor.
    */
   
    ~Team() {}

    /**
        Constructor for simulations that only take season
        xG/xGA into account.
    */
    Team( string name1, double xG1, double xGA1, map<double, int> scoringDistribution1 );

    /**
        Accessor methods.
    */
    string getName() { return name; }
    string getCoachName() { return coach.getName(); }
    string getPresidentName() { return president.getName(); }
    vector<Player> getPlayers() { return players; }
    double get_xG() { return xG; }
    double get_xGA() { return xGA; }
    int getTotalGoalsfor() { return totalGoalsFor; }
    int getTotalGoalsAgainst() { return totalGoalsAgainst; }
    int getTotalPoints() { return totalPoints; }
    int getGoalDifference() { return goalDifference; }
    int getTotalWins() { return totalWins; }
    int getTotalLosses() { return totalLosses; }
    int getTotalDraws() { return totalDraws; }
    int getTotalGamesPlayed() { return totalGamesPlayed; }

    bool operator<(const Team& team) const ;

    /**
        Mutator methods.
    */
    void set_xG( double xG ) { xG = xG; }
    void set_xGA( double xGA ) { xGA = xGA; }
    void incrementPoints( int amount ) { totalPoints += amount; }

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
    void addCoach(const Coach& coach1);
    void addPresident(const President& president1);
    void printTeamPlayers();
};

#endif