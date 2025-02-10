/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------

#ifndef ROAD_H
#define ROAD_H
#endif

#ifndef VEHICULE_H
#define VEHICULE_H
#include "Vehicule.h"
#endif

#ifndef SIGNALISATION_H
#define SIGNALISATION_H
#include "Signalisation.h"
#endif

#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Intersection.h"
#endif

#ifndef LIS
#define LIS
#include <list>
#endif

#ifndef VEC
#define VEC
#include <vector>
#endif

#ifndef IO
#define IO
#include <iostream>
#endif



using namespace std;

class Simulation;
class Road
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateur
//-------------------------------------------- Constructeurs - destructeur
    
    void addVehicule(Vehicule* vehicule);
    void removeVehicule(list<Vehicule*>::iterator &it);
    void addSignalisation(Signalisation * signalisation);
    inline void addIntersectionEnd(Intersection* intersection){intersectionEnd = intersection;}
    


    inline vector <Signalisation*> getSignalisation(){return signalisation_road;}
    inline list <Vehicule*> getVehicules(){return vehicules_road;}
    inline Intersection* getIntersectionEnd(){return intersectionEnd;}
    inline int getOriantation(){return oriantation;}
    inline int getDirection(){return direction;}
    inline int getNum(){return num;}

    inline int getxStart(){return xStart;}
    inline int getyStart(){return yStart;}
    inline int getxEnd(){return xEnd;}
    inline int getyEnd(){return yEnd;}





    Road (int nu, int ori, int direc, int xstart, int ystart, int xend, int yend);
    virtual ~Road ( );
    friend class Simulation;
    //Road (const Road & road);

//------------------------------------------------------------------ PRIVE

protected:
    int num; 
    int oriantation; // 0 NorthSouth or 1 EastWest (only straight raods)
    int direction; //0 if the circulation diraction is in the direction off ascending x or y(depending on the oriantation), 1 for the negative x or y

    float xEnd, yEnd;
    float xStart, yStart;

    list <Vehicule*> vehicules_road; //list of vehicules on this road
    vector <Signalisation*> signalisation_road; //list of signalisations on this road
    Intersection* intersectionEnd;


};

//-------------------------------- Autres définitions dépendantes de <Xxx>



