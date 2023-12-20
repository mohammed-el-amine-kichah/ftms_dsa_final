#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#pragma once
#include <iomanip>

using namespace std;

class Player
{
public:
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    Player(string, int, string, int, string);
    string getName() const { return name; }
    string getPosition() const { return position; }
    int getNumber() const { return number; }
    int getGoals() const { return goals; }
    int getAge() const { return age; }
    int getTimePlayed() const { return timePlayed; }
    int getNumRedCards() const { return numRedCards; }
    int getNumYellowCards() const { return numYellowCards; }
    double getdistance() const { return distance; }
    string getTeam() const { return team; }
    void setGoals(int goalss) { this->goals = goalss; }
    void setTimePlayed(int timePlayedd) { this->timePlayed = timePlayedd; } 
    bool operator<(const Player& second) const;
    void addGoals(int g){goals += g;}
    void addRedCards(int red){numRedCards += red;}
    void addYellowCards(int yellow){numYellowCards += yellow;}
    void addDistance(double d){distance += d;}
    void updateGamesStarted(int gameStart){startTimea.push_back(gameStart);}
    void updateGamesEnded(int gameEnd){endTime.push_back(gameEnd);}

    void updateTimePlayed(int timePlayedaa){
        timePlayeda.push_back(timePlayedaa);
        timePlayed += timePlayedaa;}

    void updateGoals(){numberOfGoals.push_back(goals);};
    void updateIsOnPitch(bool isPlaying){isOnPitch.push_back(isPlaying);};
    void updateIsYellow(){isYellow.push_back(numYellowCards);};
    void updateIsRed(){isRed.push_back(numRedCards);};
    void updateDistance(){distancea.push_back(distance);};

    vector<int> getNumberOfGoals() { return numberOfGoals; }
    int getIsOnPitchI(int i) { return isOnPitch[i]; }
    int getIsYellowI(int i) { return isYellow[i]; }
    int getIsRedI(int i) { return isRed[i]; }
    double getDistanceI(int i) { return distancea[i]; }
    int getStartTimeI(int i) { return startTimea[i]; }
    int getEndTimeI(int i) { return endTime[i]; }
    int getTimePlayedI(int i) { return timePlayeda[i]; }

private:
    string name;
    string team;
    string position;

    int age;
    int number;
    int goals;
    int numRedCards;
    int numYellowCards;
    double distance;
    int timePlayed;


    vector<int> numberOfGoals;
    vector<int> isOnPitch;
    vector<int> isYellow;
    vector<int> isRed;
    vector<double> distancea;
    vector<int> startTimea;
    vector<int> endTime;
    vector<int> timePlayeda;
};

#endif