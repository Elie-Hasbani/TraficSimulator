



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

#include <random>

using namespace std;    




void Simulation::addRoad(Road * road){
    roads.push_back(road);

}


int Simulation::checkObstacleRoad(Road * road){
  
    
    list <Vehicule*> vehicules = road ->vehicules_road;
    vector<Signalisation*> signs = road-> signalisation_road;
    
    if(vehicules.begin() != vehicules.end()){

        int beginValue = 100000;
        
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
            //(re)setting the minimum distance to an obstacle for each vehicule
            (*it) -> changeMinDist(beginValue);
        }

        int oriantation = road-> oriantation;
        int direction = road -> direction;
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){    
            //for each vehicule we see if there's a vehicule near it(behid it). because they are ordered(see road.cpp), we can break for the first vehicule that is 
            //too far and so, in each loop, the vehicule that directly before the last one is seen to see if there's any vehicule beofre it and update the minimial 
            //distance to an obstacale(attribute of the vehicule). So if a vehicule that was seen for the car in the last loop is reseen by the current vehicule
            //the minimal distance is updated for the seen vehicule, because it will necerely be nearer.(orderd list)       


            if(it != vehicules.end()){
                list<Vehicule*>::iterator it2 = next(it); //vehicule rignt before it

                if(it2 != vehicules.end()){
                    double dist = (!oriantation)*((*it) -> yPos - (*it2) ->yPos) + oriantation*((*it) -> xPos - (*it2) ->xPos);
                    if ( dist >= 0 && dist <= 100.0){
                        (*it2) -> changeMinDist(dist); //min dist to an obstacle

                    } 
                }
            }
        }

        for(vector <Signalisation*>::iterator it3 = signs.begin(); it3 != signs.end(); ++it3){
            
            for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
                double dist = (!oriantation)*((*it3) -> yPos - (*it) ->yPos) + oriantation*((*it3) -> xPos - (*it) ->xPos);

                if(dist > 100){break;} //ordered list of vehicules
                if ( dist >=0 && dist  <= 100.0){
                    
                    if(dist < (*it) -> minDistToObstacle){ 
                        (*it) -> changeMinDist(dist);
                    }
                    break;

                }                                
            }
        }
        
        list<Vehicule*>::iterator it = (road -> vehicules_road).begin(); //check if vehicule aproaching end of road
        double dist = (!oriantation)*(road -> yEnd - (*it) -> yPos) + oriantation*(road -> xEnd - (*it) -> xPos);
        
        if ( dist >=0 && dist  <= 100.0){
            if(dist <= (*it) -> minDistToObstacle){  //if there's a signalisation at the end of the raod, it will still choose the end of road (<=)
                (*it) -> changeMinDist(dist);
                if((*it)-> speed == 0){ //check if the vehicule stoped--> reached the end of the road
                    cout<<*(*it)<<" is at the end of the road"<<endl;
                    int new_road = getNextRoadRoad((*it), road);
                    roads[new_road] -> addVehicule(*it);
                    road -> removeVehicule(it);
                } 
            }
        }            
        


        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
        //update each vehicule

            if((*it) -> minDistToObstacle == beginValue){
                (*it) -> Forward(0);
            }

            else{
                (*it) -> Forward(1);
                
            }  
        }

        cout<<endl;
    
    }

    return 0;
    
}


int Simulation::getNextRoadRoad(Vehicule *vehicule, Road*road){
    Intersection * intersection = road -> intersectionEnd;
    vector<int> roads = intersection->roadNumbers;
    

    int min = 0;
    int max = intersection->roadNumbers.size() - 1;

    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(min, max); 

    // Générer un nombre aléatoire
    int new_road_index = distrib(gen);

    return intersection->roadNumbers[new_road_index];


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