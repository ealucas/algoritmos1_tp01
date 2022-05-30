// numero de visitantes | numero de bicicletas
// numero de linhas | numero de colunas
// mapa da orla (matriz)
// preferencias do 1 visitante
// preferenciuas do segundo visitante etc...

// calcualr distancias

// stable matching
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <queue>
#include "bike.h"
#include "person.h"
#include "bfs.h"
#include "galeshapley.h"


int main(int argc, char **argv)
{
    std::ifstream file;
    file.open(argv[1]);
    int numPeopleBikes;
    int rows, cols;
    std::vector<Bike> bikesList;
    std::vector<Person> peopleList;
    file >> numPeopleBikes;
    file >> rows;
    file >> cols;
    // le entradas iniciais
    for (int i = 0; i < numPeopleBikes; i++)
    {
        Bike newBike;
        Person newPerson;
        newBike.setID(i);
        newPerson.setID(i);
        bikesList.push_back(newBike);
        peopleList.push_back(newPerson);
    }

    char **matrix = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
    }

    // cria matriz representando o
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> matrix[i][j];
            if (isdigit(matrix[i][j]))
            {
                int aux = (int)(matrix[i][j] - '0');
                bikesList.at(aux).setICoordinate(i);
                bikesList.at(aux).setJCoordinate(j);
            }
        }
    }
    // para cada bike na lista, calcule as distancias para cada pessoa
    for (unsigned int i = 0; i < bikesList.size(); i++)
    {
        calculateDistances(matrix, rows, cols, bikesList.at(i), numPeopleBikes);
    }

    int aux;
    // ordena  preferencias
    std::vector<int> peoplePreferences; // indexes das preferencias
    std::vector<int> peopleRank;        // preferencias como são lidas

    // le do arquivo de entrada e ordena preferencias das pessoas com base nas notas das bikes
    for (int i = 0; i < numPeopleBikes; i++)
    {
        for (int j = 0; j < numPeopleBikes; j++)
        {
            file >> aux;
            peoplePreferences.push_back(j);
            peopleRank.push_back(aux);
        }

        sort(peoplePreferences.begin(), peoplePreferences.end(), [&](int a, int b)
             { return peopleRank.at(a) > peopleRank.at(b); });
        peopleList.at(i).setPreference(peopleRank);
        peopleList.at(i).setIndexPreference(peoplePreferences);
        peoplePreferences.clear();
        peopleRank.clear();
    }

    // acha os pares estáveis

    findStablePairs(peopleList, bikesList, numPeopleBikes);

    // imprime saídas

    for (int i = 0; i < numPeopleBikes; i++)
    {
        std::cout << static_cast<char>(peopleList.at(i).getID() + 97) << " " << peopleList.at(i).getEngagedID() << std::endl;
    }

    return 0;
};
