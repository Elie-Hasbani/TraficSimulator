
#ifndef ROAD_H
#define ROAD_H
#include "Road.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

using namespace std; 

void Road::addSignalisation(Signalisation * signalisation){
    signalisation_road.push_back(signalisation);

}

void Road::addVehicule(Vehicule* vehicule){
    vehicule -> changeOriantation(oriantation);
    vehicule -> changeDirection(direction);

    if(oriantation == 0){
        if(vehicules_road.begin() == vehicules_road.end()){
            vehicules_road.push_back(vehicule);
            return;
        }

        list <Vehicule*>::iterator it = vehicules_road.begin();
        while (it != vehicules_road.end() && (*it) -> yPos  >= vehicule -> yPos){
            ++it;
        }

        vehicules_road.insert(it, vehicule);


    }

    else{
        if(vehicules_road.begin() == vehicules_road.end()){
            vehicules_road.push_back(vehicule);
            return;
        }

        list <Vehicule*>::iterator it = vehicules_road.begin();
        while (it != vehicules_road.end() && (*it) -> xPos  >= vehicule -> xPos){
            ++it;
        }

        vehicules_road.insert(it, vehicule);



    }
    
    
    /////orders the vehicules when inserted depending on the oriantation and direction.(ex if 0,0  I order them from biger yPos to smaller yPos)
}

void Road::removeVehicule(list<Vehicule*>::iterator & it){
    vehicules_road.erase(it);

}





Road::Road( int nu, int ori, int direc, int xstart, int ystart, int xend, int yend){
    num = nu;
    oriantation = ori;
    direction = direc;

    xStart = xstart;
    yStart = ystart;
    xEnd = xend;
    yEnd = yend;
   

    #ifdef MAP
    cout << "Appel au constructeur de Road" << endl;
    #endif
}

Road::~Road(){

    #ifdef MAP
    cout << "Appel au destructeur de Raod" << endl;
    #endif


}





