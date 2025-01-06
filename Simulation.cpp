



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

#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Intersection.h"
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
        double dist;
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){

            for (list<Vehicule*>::iterator it2 = vehicules.begin(); it2 != vehicules.end(); ++it2){
                if((*it) ->operator!=(*(*it2))){
                    dist = (*it2) -> getyPos() - (*it) ->getyPos();
                    if ( dist >= 0 && dist <= 100.0){
                        (*it) -> Forward(1 , oriantation, dist);
                        (*it) -> decelerte();
                        

                        break;
                    } 
                }
                
            }


            for(vector <Signalisation*>::iterator it3 = signs.begin(); it3 != signs.end(); ++it3){

                
                if((*it) -> getDecelerate() == 0){
                    dist = (*it3) -> getyPos() - (*it) ->getyPos();
                    if ( dist >=0 && dist  <= 100.0){
                        (*it) -> Forward(1 , oriantation, dist);
                        (*it) -> decelerte();

                        break;
                    } 
                }
                   
                

            }


 
            if((*it) -> getDecelerate() == 0){
                (*it) -> Forward(0, oriantation, 0);
            }

            (*it) ->unDecelerte();
            

        }
   
    }



    else{
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){


            for (vector<Signalisation*>::iterator it2 = signs.begin(); it2 != signs.end(); ++it2){
                float dist = fabs((*it) ->getxPos() - (*it2) -> getxPos());
                if ( dist <= 100.0){
                    (*it) -> Forward(1 , oriantation, dist);
                    (*it) -> decelerte();
                    

                    break;
                } 
                
            }


            for(list <Vehicule*>::iterator it3 = vehicules.begin(); it3 != vehicules.end(); ++it3){
                if((*it) ->operator!=(*(*it3))){
                    if((*it) -> getDecelerate() == 0){
                        double dist = fabs((*it) ->getxPos() - (*it3) -> getxPos());
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

    return 0;
    
}



int Simulation::checkVehiculeEndOfRoad(Road*road, Vehicule*vehicule){
    //list <Vehicule*> vehicules = road -> getVehicules();

    float limit;
    if(road -> getOriantation() == 0){
        if(road -> getDirection() == 0){
            if(road -> getyEnd() - vehicule->getyPos() <= 10){
                return 1;
            }

        }

        else{
            if(vehicule->getyPos() - road -> getyStart() <= 10){
                return 1;
            }

        }
    }

    else{

        if(road -> getDirection() == 0){
            if(road -> getxEnd() - vehicule->getxPos() <= 10){
                return 1;
            }
        }

        else{
            if(vehicule->getxPos() - road -> getxStart() <= 10){
                return 1;
            }

        }

    }

    /*list<Vehicule*>::reverse_iterator ri;
    for(ri = vehicules.rbegin(); ri!=vehicules.rend(); ++ri){
        if(road -> getOriantation() == 0){
            if(road -> get)
            if((*ri) -> getxPos() >= limit)

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