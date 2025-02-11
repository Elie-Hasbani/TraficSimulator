#if ! defined SIMULATION_H
#include "Simulation.h"
#define SIMULATION_H
#endif

#ifndef ROAD_H
#define ROAD_H
#include "Road.h"
#endif


#ifndef VEHICULE_H
#define VEHICULE_H
#include "Vehicule.h"
#endif

#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Intersection.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

#include <chrono>
#include <thread>



int main(){
    Road* road1 = new Road(0, 0, 0,      0, 0, 0, 700);
    Road* road2 = new Road(1, 1, 0,      0, 0, 1000, 0);
    
    Intersection * intersection1 = new Intersection;
    intersection1 -> roadNumbers.push_back(1);

    Vehicule* veh1 = new Vehicule(0, 0, 40);
    Vehicule* veh2 = new Vehicule(0, 70.222, 50);
    Vehicule* veh3 = new Vehicule(150, 0, 30);
    Vehicule* veh4 = new Vehicule(0, 0, 40);

    Signalisation * sign1 = new Signalisation(150, 700);
    Signalisation * sign2 = new Signalisation(5, 5);

    


    road1 -> addSignalisation(sign1);

    road1 -> addIntersectionEnd(intersection1);

    /*vector<Signalisation*> signs = road1->getSignalisation();
    for (vector<Signalisation*>::iterator it2 = (signs).begin(); it2 != (signs).end(); ++it2){
        cout<< (*it2) ->getxPos() <<" , " << (*it2) -> getyPos()<<endl;
    }*/


    road1 -> addVehicule(veh1);
    road1 -> addVehicule(veh2);

    road2 -> addVehicule(veh3);
    road2 -> addVehicule(veh4);



    list <Vehicule*> veh = road1->getVehicules();
    for(list <Vehicule*>::iterator it = (veh).begin(); it != (veh).end(); ++it){
        cout<< *(*it) <<endl;

    }
   


    Simulation simu;
    simu.addRoad(road1);
    simu.addRoad(road2);
    
    


    const float tickDuration = 0.016f; // Durée d'un tick (60 FPS, en secondes)
    auto lastTime = std::chrono::high_resolution_clock::now();

    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - lastTime;

        if (elapsedTime.count() >= tickDuration) {
            lastTime = currentTime;

            simu.checkObstacleRoad(road1);
            simu.checkObstacleRoad(road2);

            // Pause pour ralentir la boucle (si besoin)
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    


    return 0;



}