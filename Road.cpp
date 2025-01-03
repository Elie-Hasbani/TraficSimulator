
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
    vehicules_road.push_back(vehicule);

}





Road::Road( int nu, int ori){
    num = nu;
    oriantation = ori;

    #ifdef MAP
    cout << "Appel au constructeur de Road" << endl;
    #endif
}

Road::~Road(){

    #ifdef MAP
    cout << "Appel au destructeur de Raod" << endl;
    #endif


}





