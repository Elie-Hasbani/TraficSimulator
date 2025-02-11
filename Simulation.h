
#ifndef SIMULATION_H
#define SIMULATION_H
#endif


#if ! defined ROAD_H
#include "Road.h"
#define ROAD_H
#endif

#if ! defined VEHICULE_H
#include "Vehicule.h"
#define VEHICULE_H
#endif


#ifndef VEC
#define VEC
#include <vector>
#endif

#ifndef LIS
#define LIS
#include <list>
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

using namespace std;


class Simulation
{

    public:
    
    

    void addRoad(Road * road);

    void update();
    int checkObstacleRoad(Road * road);
    int getNextRoadRoad(Vehicule *vehicule, Road*road);



    virtual ~Simulation();

    Simulation();
   

    protected:
    vector <Road*> roads;



};