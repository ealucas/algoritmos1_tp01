#include "person.h"
Person::Person()
{
    personID = -1;
    engagedBikeID = -1;
    personPreferences.clear();
}

int Person::getID(){
    return personID;
}

void Person::setID(int id){
    personID = id;
}

void Person::setEngagedID(int id){
    engagedBikeID = id;
}

int Person::getEngagedID(){
    return engagedBikeID; 
}

std::vector<int> Person::getPreference(){
    return personPreferences;
}
void Person::setPreference(std::vector<int> preference){
    personPreferences = preference;
}

std::vector<int> Person::getIndexPreference(){
    return preferenceIndexes;
};

void Person::setIndexPreference(std::vector<int> indexes){
    preferenceIndexes = indexes;
};

