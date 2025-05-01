#include "driver.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Formula1
{
private:
    vector<Driver> grid;

public:
    void addDriver(const Driver& driver)
    {
        grid.push_back(driver);
    }

    void loadDataFromFiles(const string& driverFileName, const string& racesFileName)
    {
        ifstream driverData(driverFileName);
        ifstream racesData(racesFileName);

        if (!driverData.is_open())
        {
            cerr << "Erro ao abrir o arquivo: " << driverFileName << endl;
            return;
        }
        if (!racesData.is_open())
        {
            cerr << "Erro ao abrir o arquivo: " << racesFileName << endl;
            return;
        }

        string driverLine, racesLine;
        while (getline(driverData, driverLine) && getline(racesData, racesLine))
        {
            stringstream driverStream(driverLine);
            stringstream racesStream(racesLine);

            string name, team, ageStr;
            int age;

            getline(driverStream, name, '|');
            getline(driverStream, team, '|');
            getline(driverStream, ageStr, '|');
            age = stoi(ageStr);

            vector<int> driverRaces;
            int position;
            while (racesStream >> position)
            {
                driverRaces.push_back(position);
            }

            addDriver(Driver(name, team, age, 0, driverRaces));
        }

        driverData.close();
        racesData.close();
    }

    void setScore()
    {
        for (Driver& driver : grid)
        {
            int score = 0;
            for (int position : driver.getRaces())
            {
                switch (position)
                {
                case 1: score += 25; break;
                case 2: score += 18; break;
                case 3: score += 15; break;
                case 4: score += 12; break;
                case 5: score += 10; break;
                case 6: score += 8; break;
                case 7: score += 6; break;
                case 8: score += 4; break;
                case 9: score += 2; break;
                case 10: score += 1; break;
                default: break;
                }
            }
            driver.setTotalPoints(score);
        }
    }

    void printGrid() const
    {
        for (const Driver& driver : grid)
        {
            driver.printDriver();
            driver.printDriveRaces();
        }
    }
};
