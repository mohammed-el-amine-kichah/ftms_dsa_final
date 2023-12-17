#include "../include/Player.h"

Player::Player(string T,int n, string N, int a,string p):team(T),number(n) ,name(N), age(a),position(p)
{
    goals = 0;
    numRedCards = 0;
    numYellowCards = 0;
    distance = 0;
    isPunished = false;
    isPlaying = false;
}
bool Player::operator < (const Player &second) const {
    // we compare by goals
    if (this->getGoals() < second.getGoals())
        return true;
    
    if (this->getGoals() > second.getGoals())
        return false;
    
    // if they scored the same number of goals we compare by assists
    if (this->getAssists() < second.getAssists())
        return true;
    
    if (this->getAssists() > second.getAssists())
        return false;
        
    // if they scored the same number of goals and the same numbers of assists we compare by minutes played
    // if a player scored same goals but played less minutes it will be considered better than the others)

    if (this->getTimePlayed() > second.getTimePlayed())
        return true;
    
    if (this->getTimePlayed() < second.getTimePlayed())
        return false;

    // if they have same number of goals and same number goals we compare by name 
    if (this->getName() < second.getName())
        return true;
    
    return true;
    
}