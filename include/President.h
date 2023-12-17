#ifndef PRESIDENT_H
#define PRESIDENT_H

#pragma once
#include <string>
using namespace std;

class President {
private:
    string teamName;
    string name;
    int age;
    string wealth;

public:

    President() {}
    ~President() {}

    President(const string& teamName, const string& name, int age, const string& wealth)
        : teamName(teamName), name(name), age(age), wealth(wealth) {}

    // Getters
    string getTeamName() const { return teamName; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getWealth() const { return wealth; }
};

#endif 