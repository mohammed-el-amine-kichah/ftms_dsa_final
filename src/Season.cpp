#include <iostream>
#include <vector>
#include "../include/Season.h"


void Season::printGW(int round, vector<Team> &teams)
{
    BinarySearchTree <Team> TeamBST; 
    for( Team team:teams)
    {
        team.InfoAt(round);
        TeamBST.insert(team);
    }

    TeamBST.printTree();
}