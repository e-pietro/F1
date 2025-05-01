#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Driver
{
private:
    string name;
    string team;
    int age;
    int totalPoints;
    vector<int> races;

public:
    // Construtores
    Driver(string name, string team, int age, int totalPoints, vector<int> races)
        : name(name), team(team), age(age), totalPoints(totalPoints), races(races) {}

    Driver() : name("Desconhecido"), team("Sem Equipe"), age(-1), totalPoints(0), races(0) {}

    // Métodos de acesso
    string getName() const { return name; }
    string getTeam() const { return team; }
    int getAge() const { return age; }
    int getTotalPoints() const { return totalPoints; }
    const vector<int>& getRaces() const { return races; }

    void setTotalPoints(int points) { totalPoints = points; }

    // Métodos de impressão
    void printDriver() const
    {
        cout << "Name: " << name
             << "; Team: " << team
             << "; Age: " << age
             << "; Total Points: " << totalPoints << endl;
    }

    void printDriveRaces() const
    {
        for (size_t i = 0; i < races.size(); ++i)
        {
            cout << "Race " << i + 1 << " = " << races[i] << "; ";
        }
        cout << endl;
    }
};
#endif
