#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <string>
#include <map>

class Team
{
private:

    string name;              // Team name.
    string coachName;         // Team coach.
    string PresidentName;     // Team president.
    vector<Player> players;   // Team players.
    
    int totalGoalsFor;        // Total goals scored during season.
    int totalGoalsAgainst;    // Total goals scored against during season.
    int totalPoints;          // Total points for current season.
    int totalGoalDifference;  // Goals for - goals against
    int totalWins;            // Total games won.
    int totalDraws;           // Total games drawn.
    int totalLosses;          // Total games lost.
    int totalGamesPlayed;  
    
    //for comparition
    int Cpoints;
    int CgoalDifference;
    int CgoalsFor;
    int Cwins;
    int CMP;
    int CDraws;
    int CLoses;


       // Total games played;
    vector<int> points;
    vector<int> goalsFor;
    vector<int> goalsAgainst;
    
    vector<int> goalDifference;
    vector<int> Wins;
    vector<int> MP;
    vector<int> Draws;
    vector<int> Loses;

public:
    friend std::ostream& operator<<(std::ostream& out, const Team& team);
    ~Team() {}
    Team( string name1, string coachName1="", string PresidentName1="");

    string getName() const { return name; }
    string getCoachName() const { return coachName; }
    string getPresidentName() const { return PresidentName; }
    vector<Player> getPlayers() { return players; }
    int getTotalGoalsfor() { return totalGoalsFor; }
    int getTotalGoalsAgainst() { return totalGoalsAgainst; }
    int getTotalPoints() { return totalPoints; }
    int getTotalGoalDifference() { return totalGoalDifference; }


    int getGoalDifferenceI(int i) { return goalDifference[i]; }
    int getWinsI(int i) { return Wins[i]; };

    //for comparision
    int getCpoints() const { return Cpoints; }
    int getCgoalDifference() const { return CgoalDifference; }
    int getCgoalsFor() const { return CgoalsFor; }
    int getCwins() const { return Cwins; }
    int getCMP() const { return CMP; }
    int getCDraws() const { return CDraws; }
    int getCLoses() const { return CLoses; }

    int getTotalWins() { return totalWins; }
    int getTotalLosses() { return totalLosses; }
    int getTotalDraws() { return totalDraws; }
    int getTotalGamesPlayed() { return totalGamesPlayed; }
    int getPoints(int i) { return points[i]; }
    int getGoalsFor(int i) { return goalsFor[i]; }
    int getGoalsAgainst(int i) { return goalsAgainst[i]; }

    void addGoals(int g){totalGoalsFor += g;}
    void addGoalsAgainst(int g){totalGoalsAgainst += g;}
    void addGoalDifference(int g){totalGoalDifference += g;}
    void addPoints(int p){totalPoints += p;}
    void addWins(){totalWins ++;}
    void addLosses(){totalLosses ++;}
    void addDraws(){totalDraws ++;}
    void addGamesPlayed(){totalGamesPlayed ++;}

    void updatePoints(){points.push_back(totalPoints);};
    void updateGoalsFor(){goalsFor.push_back(totalGoalsFor);};
    void updateGoalsAgainst(){goalsAgainst.push_back(totalGoalsAgainst);};
    void updateGoalDiffrence(){goalDifference.push_back(totalGoalDifference);};
    void updateWins(){Wins.push_back(totalWins);};
    void updateMP(){MP.push_back(totalGamesPlayed);};
    void updateDraws(){Draws.push_back(totalDraws);};
    void updateLoses(){Loses.push_back(totalLosses);};

    bool operator<(const Team& team) const ;

    /**
        Mutator methods.
    */

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
    bool compareTo( int round, Team t );
    bool compareTo(  Team t ) ;

    /**
        Prints team name and statistics.
    */
    void toString();

    // methode to populate the team players from csv file
    //void populateTeamPlayers(string teamName);
    void addPlayer(const Player& player);
    void printTeamPlayers();
    void InfoAt(int );
};
ostream& operator<<(ostream& out, const Team& team) {
    out << setw(20) << left << team.getName() 
    << setw(16) << left << team.getCMP() 
    << setw(16) << left << team.getCwins() 
    << setw(16) << left << team.getCDraws() 
    << setw(16) << left << team.getCLoses() 
    << setw(16) << left << team.getCpoints() ;
    return out;
}
#endif