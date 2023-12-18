#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#pragma once

using namespace std;

class Player
{
public:
    Player(string, int, string, int, string);
    string getName() const { return name; }
    string getPosition() const { return position; }
    int getNumber() const { return number; }
    int getGoals() const { return goals; }
    int getAge() const { return age; }
    int getNumRedCards() const { return numRedCards; }
    int getNumYellowCards() const { return numYellowCards; }
    bool getIsPunished() const { return isPunished; }
    bool getIsPlaying() const { return isPlaying; }
    double getdistance() const { return distance; }
    int getStartTime() const { return startTime; }
    int getReplacedTime() const { return replacedTime; }
    int getTimePlayed() const { return timePlayed; }
    string getTeam() const { return team; }
    void setGoals(int goalss) { this->goals = goalss; }
    bool operator<(const Player& second) const;
    vector<int> numberOfGoals;
    vector<int> isOnPitch;
    vector<int> isYellow;
    vector<int> isRed;
    vector<int> distancea;
    vector<int> startTimea;
    vector<int> endTime;
    vector<int> timePlayeda;
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
    bool isPunished; // true when he has a red card
    bool isPlaying;  // true when he is on the pitch
    int startTime;
    int replacedTime;
    int timePlayed; // in minutes
    int gamesStarted;
    int gamesPlayed;

};

#endif