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

#ifndef IO
#define IO
#include <iostream>
#endif

#include <chrono>
#include <thread>



int main(){
    Road* road1 = new Road(1, 0);
    //Road road2(2, 0);

    Vehicule* veh1 = new Vehicule(5, 0, 30);
    Vehicule* veh2 = new Vehicule(10, 0, 20);


    Signalisation * sign1 = new Signalisation(100, 30);
    Signalisation * sign2 = new Signalisation(5, 5);


    road1 -> addSignalisation(sign1);
    //road1 -> addSignalisation(sign2);

    /*vector<Signalisation*> signs = road1->getSignalisation();
    for (vector<Signalisation*>::iterator it2 = (signs).begin(); it2 != (signs).end(); ++it2){
        cout<< (*it2) ->getxPos() <<" , " << (*it2) -> getyPos()<<endl;
    }*/


    road1 -> addVehicule(veh1);
    //road1 -> addVehicule(veh2);

    /*list <Vehicule*> veh = road1->getVehicules();
    for(list <Vehicule*>::iterator it = (veh).begin(); it != (veh).end(); ++it){
        cout<< (*it) ->getxPos() <<endl;

    }*/
   


    Simulation simu;
    simu.addRoad(road1);
    
    


    const float tickDuration = 0.016f; // Durée d'un tick (60 FPS, en secondes)
    auto lastTime = std::chrono::high_resolution_clock::now();

    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - lastTime;

        if (elapsedTime.count() >= tickDuration) {
            lastTime = currentTime;

            simu.checkObstacleRoad(road1);

            
            

            // Pause pour ralentir la boucle (si besoin)
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    




    

    return 0;



}