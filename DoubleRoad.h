#ifndef DOUBLEROAD_H
#define DOUBLEROAD_H
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


class DoubleRoad
{

    DoubleRoad(int nu, int ori);
    void addVehicule(int direction, Vehicule * Vehicule);
    void addSignalistaion(int direction, Signalisation* signalisation);




    protected:
    Road* roadDirection1;
    Road* roadDirection2;
};