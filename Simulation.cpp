



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
    

    int beginValue = 100000;
    
    for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
        //(re)setting the minimum distance to an obstacle for each vehicule

        (*it) ->changeMinDist(beginValue);
    }

    int oriantation = road->getOriantation();
    if(oriantation == 0){

        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){    
            //for each vehicule we see if there's a vehicule near it(behid it). because they are ordered(see road.cpp), we can break for the first vehicule that is 
            //too far and so, in each loop, the vehicule that directly before the last one is seen to see if there's any vehicule beofre it and update the minimial 
            //distance to an obstacale(attribute of the vehicule). So if a vehicule that was seen for the car in the last loop is reseen by the current vehicule
            //the minimal distance is updated for the seen vehicule, because it will necerely be nearer.(orderd list)       


            if(it != vehicules.end()){
                list<Vehicule*>::iterator it2 = next(it); //vehicule rignt before it

                if(it2 != vehicules.end()){
                    double dist = (*it) -> getyPos() - (*it2) ->getyPos();
                    if ( dist >= 0 && dist <= 100.0){
                        (*it2) -> changeMinDist(dist); //min dist to an obstacle

                    } 
                }

            }

            /*for (list<Vehicule*>::iterator it2 = vehicules.begin(); it2 != vehicules.end(); ++it2){
                if((*it) ->operator!=(*(*it2))){
                    double dist = (*it) -> getyPos() - (*it2) ->getyPos();

                    if(dist > 100){break;} //ordered list of vehicules
                    if ( dist >= 0 && dist <= 100.0){
                        (*it2) -> changeMinDist(dist); //min dist to an obstacle

                    } 
                }
                
            }*/

            
            


        }

        for(vector <Signalisation*>::iterator it3 = signs.begin(); it3 != signs.end(); ++it3){
            
            for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
                double dist = (*it3) -> getyPos() - (*it) ->getyPos();

                
                //cout<<"entered1"<<endl;
                if(dist > 100){break;} //ordered list of vehicules
                //cout<<"entered2"<<endl;
                if ( dist >=0 && dist  <= 100.0){
                    
                    if(dist < (*it) -> getMinDist()){ 
                        (*it) -> changeMinDist(dist);
                    }
                    break;

                }            
                

            }

        }
        
        list<Vehicule*>::iterator it = vehicules.begin(); //check if vehicule aproaching end of road
        double dist = road -> getyEnd() - (*it) -> getyPos();
        if ( dist >=0 && dist  <= 100.0){
            if(dist <= (*it) -> getMinDist()){  //if there's a signalisation at the end of the raod, it will still choose the end of road (<=)
                (*it) -> changeMinDist(dist);
                //cout<<"entered"<<endl;
                if((*it)->getSpeed() == 0){ //check if the vehicule stoped--> reached the end of the road
                    cout<<*(*it)<<" is at the end of the road"<<endl;
                
                } 
            }
        }

            
    }



    else{
        for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){    
            //for each vehicule we see if there's a vehicule near it(behid it). because they are ordered(see road.cpp), we can break for the first vehicule that is 
            //too far and so, in each loop, the vehicule that directly before the last one is seen to see if there's any vehicule beofre it and update the minimial 
            //distance to an obstacale(attribute of the vehicule). So if a vehicule that was seen for the car in the last loop is reseen by the current vehicule
            //the minimal distance is updated for the seen vehicule, because it will necerely be nearer.(orderd list)                             
            for (list<Vehicule*>::iterator it2 = vehicules.begin(); it2 != vehicules.end(); ++it2){
                if((*it) ->operator!=(*(*it2))){
                    double dist = (*it) -> getxPos() - (*it2) ->getxPos();

                    

                    if(dist > 100){break;} //ordered list of vehicules
                    if ( dist >= 0 && dist <= 100.0){
                        (*it2) -> changeMinDist(dist); //min dist to an obstacle

                    } 
                }
                
            }

        }

        for(vector <Signalisation*>::iterator it3 = signs.begin(); it3 != signs.end(); ++it3){
            
            for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
                double dist = (*it3) -> getxPos() - (*it) ->getxPos();

                
                //cout<<"entered1"<<endl;
                if(dist > 100){break;} //ordered list of vehicules
                //cout<<"entered2"<<endl;
                if ( dist >=0 && dist  <= 100.0){
                    
                    if(dist < (*it) -> getMinDist()){
                        (*it) -> changeMinDist(dist);
                    }

                }            
                

            }

        }

    }

    for(list <Vehicule*>::iterator it = vehicules.begin(); it != vehicules.end(); ++it){
    //update each vehicule

        if((*it) -> getMinDist() == beginValue){
            (*it) -> Forward(0, oriantation, 0);
        }

        else{
            (*it) -> Forward(1, oriantation, (*it) -> getMinDist());
        }  
    }

    cout<<endl;
    return 0;
    
}


void Simulation::vehiculeChangeRoad(Vehicule *vehicule, Road*road){
    Intersection * intersection = road -> getIntersectionEnd();
    


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