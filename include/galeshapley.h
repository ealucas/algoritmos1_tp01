#ifndef GALESHAPLEY
#define GALESHAPLEY

#include <vector>
#include <iostream>
#include "bike.h"
#include "person.h"

#define POSSIBLE_DIRECTIONS 4

void findStablePairs(std::vector<Person>& peopleList, std::vector<Bike>& bikesList, int numPeopleBikes)
    {
        Person p;
        Person p2;
        int b;
        bool hasProposed[numPeopleBikes][numPeopleBikes];

        for (int i = 0; i < numPeopleBikes; i++)
        {
            for (int j = 0; j < numPeopleBikes; j++)
            {
                hasProposed[i][j] = false;
            }
        }

        p = peopleList.at(0);
        bool freePersonAvailable = true;

        while (freePersonAvailable)
        {
            freePersonAvailable = false;
            int i = 0;
            for (; i < numPeopleBikes; i++)
            {

                if (!hasProposed[p.getID()][p.getIndexPreference().at(i)])
                {
                    hasProposed[p.getID()][p.getIndexPreference().at(i)] = true;
                    break;
                }
            }

            b = p.getIndexPreference().at(i);
            if (bikesList.at(b).getEngagedID() == -1)
            {
                bikesList.at(b).setEngagedID(p.getID());
                peopleList.at(p.getID()).setEngagedID(b);
            }
            else
            {
                p2 = peopleList.at(bikesList.at(b).getEngagedID());
                int difference = bikesList.at(b).getPreference().at(p2.getID()) - bikesList.at(b).getPreference().at(p.getID());

                if (difference == 0)
                {
                    if (p.getID() < p2.getID())
                    {
                        peopleList.at(p2.getID()).setEngagedID(-1);
                        bikesList.at(b).setEngagedID(p.getID());
                        peopleList.at(p.getID()).setEngagedID(b);
                    }
                }

                if (difference > 0)
                {
                    peopleList.at(p2.getID()).setEngagedID(-1);
                    bikesList.at(b).setEngagedID(p.getID());
                    peopleList.at(p.getID()).setEngagedID(b);
                }
            }
            for (int j = 0; j < numPeopleBikes; j++)
            {
                if (peopleList.at(j).getEngagedID() == -1)
                {
                    p = peopleList.at(j);
                    freePersonAvailable = true;
                    break;
                }
            }
        }
    }

#endif