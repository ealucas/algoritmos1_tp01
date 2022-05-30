#ifndef PERSON
#define PERSON
#include <vector>
class Person{
    public:
        Person();
        int getID();
        void setEngagedID(int id); 
        int getEngagedID();
        void setID(int id); 
        std::vector<int> getPreference();
        void setPreference(std::vector<int> preference);
        std::vector<int> getIndexPreference();
        void setIndexPreference(std::vector<int> indexes);


    private:
        int personID;
        int engagedBikeID;
        std::vector<int> personPreferences;
        std::vector<int> preferenceIndexes;
        int iCoordinate;
        int jCoordinate;
};


#endif