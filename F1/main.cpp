#include "driver.hpp"
#include "formula1.cpp"
#include <iostream>

using namespace std;

int main()
{
    Formula1 championship;

    // Carrega os dados dos pilotos e das corridas
    championship.loadDataFromFiles("driverData.txt", "racesData.txt");

    // Calcula as pontuações
    championship.setScore();

    // Imprime o grid com as pontuações
    cout << "Grid final com pontuações:" << endl;
    championship.printGrid();

    return 0;
}
