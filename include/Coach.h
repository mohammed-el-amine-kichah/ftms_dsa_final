#ifndef COACH_H
#define COACH_H
#include<iostream>
using namespace std;

#pragma once

class Coach {
    private :
    string team;
    string name;
    int age;
    int salary;

    public :
    Coach() {}
    ~Coach() {}
    Coach(string,string,int,int);
    string getTeam() const { return team;}
    string getName() const { return name;}
    int getAge() const { return age;}
    int getSalary() const { return salary;}
};

Coach::Coach(string T,string N,int a,int s):team(T),name(N),age(a),salary(s)
{
    
}
#endif