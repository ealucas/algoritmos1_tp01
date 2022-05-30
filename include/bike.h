#ifndef BIKE
#define BIKE
#include <vector>
class Bike{
    public:
        Bike();
        //getters e setters 
        int getID();
        void setID(int id);

        int getEngagedID();
        void setEngagedID(int id);

        std::vector<int> getPreference();
        void setPreference(std::vector<int> preference);

        std::vector<int> getIndexPreference();
        void setIndexPreference(std::vector<int> preference);

        void setICoordinate(int coordindate);
        int getICoordidante();

        void setJCoordinate(int coordindate);
        int getJCoordidante();

    private:
        int bikeID;
        std::vector<int> bikePreferences;
        std::vector<int> preferenceIndexes;
        int engagedPersonID;
        int iCoordinate;
        int jCoordinate;
};


#endif