#ifndef BFS
#define BFS

#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <queue>
#include "bike.h"
#include "person.h"

#define POSSIBLE_DIRECTIONS 4

bool isValidPosition(int i, int j, char **matrix, int rows, int cols)
{

    if (i < 0 || i > rows - 1 || j < 0 || j > cols - 1)
    {
        return false;
    } else {
        return true;
    }

}


void exploreNeighbours(int &currentRow, int &currentCol, int rows, int cols, char ** matrix, int ** visitedMatrix, std::queue<int> & queueRows, std::queue<int> & queueCols, int &nodesNextLayer){
    int directionsRowAxis[POSSIBLE_DIRECTIONS] = {0, -1, 0, 1};
    int directionsColAxis[POSSIBLE_DIRECTIONS] = {-1, 0, 1, 0};
    int newRow = 0;
    int newCol = 0;

    for(int i =0; i < POSSIBLE_DIRECTIONS; i++){
        newRow = currentRow + directionsRowAxis[i];
        newCol = currentCol + directionsColAxis[i];
        if (newRow < 0 || newCol < 0){
            continue;
        }

        if (newRow >= rows || newCol >= cols){
            continue;
        }

        if (visitedMatrix[newRow][newCol] == 1){
            continue;
        }

        if (matrix[newRow][newCol] == '-'){
            continue;
        }
        queueRows.push(newRow);
        queueCols.push(newCol);
        visitedMatrix[newRow][newCol] = 1;
        nodesNextLayer++;
    }
}
void calculateDistances(char ** matrix, int rows, int cols, Bike &bike, int bikesListSize)
{
    int **visitedMatrix = new int *[rows]; // matriz para consulta de (i,j)s visitados
    for (int i = 0; i < rows; i++)
    {
        visitedMatrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            visitedMatrix[i][j] = 0;
        }
    }
    std::queue<int> queueRows;
    std::queue<int> queueCols;
    int nodesNextLayer = 0;
    int nodesLeftInLayer = 1;
    std::vector<int> distances; // lista onde serão armazenadas as distancias em relacao a bike
    for(int i = 0; i < bikesListSize; i++){
        distances.push_back(-1);
    }
    int distance = 0;
    int currentRow = bike.getICoordidante();
    int currentCol = bike.getJCoordidante();
    queueRows.push(currentRow);
    queueCols.push(currentCol);
    visitedMatrix[currentRow][currentCol] = 1;
    while (queueRows.size() > 0){
        currentRow = queueRows.front();
        currentCol = queueCols.front();
        queueRows.pop();
        queueCols.pop();
        if (matrix[currentRow][currentCol] >= 'a' && matrix[currentRow][currentCol] <= 'j'){
            distances.at(matrix[currentRow][currentCol] - 'a') = distance;
            bike.setPreference(distances);
        }

        exploreNeighbours(currentRow, currentCol, rows, cols, matrix, visitedMatrix, queueRows, queueCols, nodesNextLayer);
        nodesLeftInLayer--;
        if (nodesLeftInLayer == 0){
            nodesLeftInLayer = nodesNextLayer;
            nodesNextLayer = 0;
            distance++;
        }
    }

}

#endif