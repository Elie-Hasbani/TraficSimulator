#ifndef DOUBLEROAD_H
#define DOUBLEROAD_H
#include "DoubleRoad.h"
#endif

#ifndef ROAD_H
#define ROAD_H
#include "Road.h"
#endif

#ifndef VEHICULE_H
#define VEHICULE_H
#include "Vehicule.h"
#endif

#ifndef SIGNALISATION_H
#define SIGNALISATION_H
#include "Signalisation.h"
#endif


DoubleRoad::DoubleRoad(int nu, int ori){
    roadDirection1 = new Road(nu, ori, 0);
    roadDirection2 = new Road(nu, ori, 1);


}


void DoubleRoad::addSignalistaion(int direc, Signalisation* signalisation){
    if(!direc){
        roadDirection1 -> addSignalisation(signalisation);
    }
    else{
        roadDirection2 -> addSignalisation(signalisation);
    }
}

void DoubleRoad::addVehicule(int direc, Vehicule* vehicule){
    if(!direc){
        roadDirection1 -> addVehicule(vehicule);
    }
    else{
        roadDirection2 -> addVehicule(vehicule);
    }
}