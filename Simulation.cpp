



#ifndef SIMULATION_H
#define SIMULATION_H
#include "simulation.h"
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

#ifndef CMATH
#define CMATH
#include <cmath>
#endif

using namespace std;    




void Simulation::addRoad(Road * road){
    roads.push_back(road);

}




int Simulation::checkObstacleRoad(Road * road){
     
    
    list <Vehicule*> vehicules = road -> getVehicules();
    vector<Signalisation*> signs = road->getSignalisation();



    int oriantation = road->getOriantation();
    if(oriantation == 0){
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){




            for (vector<Signalisation*>::iterator it2 = signs.begin(); it2 != signs.end(); ++it2){
                float dist = fabs((*it) ->getyPos() - (*it2) -> getyPos());
                if ( dist <= 100.0){
                    (*it) -> Forward(1 , oriantation, dist);
                    (*it) -> decelerte();
                    

                    break;
                } 
                
            }


            for(list <Vehicule*>::iterator it3 = vehicules.begin(); it3 != vehicules.end(); ++it3){
                if((*it) ->operator!=(*(*it3))){
                    if((*it) -> getDecelerate() == 0){
                        double dist = fabs((*it) ->getyPos() - (*it3) -> getyPos());
                        if (  dist  <= 100.0){
                            (*it) -> Forward(1 , oriantation, dist);
                            (*it) -> decelerte();

                            break;
                        } 
                    }
                   
                }

            }


 
            if((*it) -> getDecelerate() == 0){
                (*it) -> Forward(0, oriantation, 0);
            }

            (*it) ->unDecelerte();
            

        }
   
    }



    /*else{
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
            for (vector<Signalisation*>::iterator it2 = road->getSignalisation().begin(); it2 != road.getSignalisation().end(); ++it2){
                if (  ( (*it) ->getyPos() - (*it2) -> getyPos())  <= 50){
                    (*it) -> Forward(1 , oriantation);

                    break;
                } 
                
            }

            (*it) -> Forward(0, oriantation);
        }


        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
            for(list <Vehicule*>::iterator it3 = vehicules.begin(); it3 != vehicules.end(); ++it3){
                if((*it) -> getDecelerate() == 0){
                    if ( ( (*it) ->getxPos() - (*it3) -> getxPos())  <= 50){
                        (*it) -> Forward(1 , oriantation);
                        (*it) ->unDecelerte();

                        break;
                    } 
                    
                    (*it) ->unDecelerte();
                }

            }

            (*it) -> Forward(0, oriantation);
        }

    }*/

    return 0;
    
}

void Simulation::update(){
    

    
} 

Simulation::Simulation(){
    int x = 1;

    #ifdef MAP
    cout << "Appel au constructeur de Simulation" << endl;
    #endif


}

Simulation::~Simulation(){

    #ifdef MAP
    cout << "Appel au destructeur de Simulation" << endl;
    #endif


}