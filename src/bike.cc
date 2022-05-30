#include "bike.h"

Bike::Bike(){
    bikeID = -1;
    engagedPersonID = -1;
    bikePreferences.clear();
}

void Bike::setID(int id){
    bikeID = id;
}

int Bike::getID(){
    return bikeID; 
}

void Bike::setEngagedID(int id){
    engagedPersonID = id;
}
int Bike::getEngagedID(){
    return engagedPersonID; 
}

std::vector<int> Bike::getPreference(){
    return bikePreferences;
}

void Bike::setPreference(std::vector<int> preference){
    bikePreferences = preference;
}

std::vector<int> Bike::getIndexPreference(){
    return preferenceIndexes;
};

void Bike::setIndexPreference(std::vector<int> preference){
    preferenceIndexes = preference;
};

void Bike::setICoordinate(int coordindate){
    iCoordinate = coordindate;
}
int Bike::getICoordidante(){
    return iCoordinate;
};

void Bike::setJCoordinate(int coordindate){
    jCoordinate = coordindate;
}

int Bike::getJCoordidante(){
    return jCoordinate;
}