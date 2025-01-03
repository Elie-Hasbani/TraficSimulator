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
    void addSignalisation(Signalisation * signalisation);
    


    inline vector <Signalisation*> getSignalisation(){return signalisation_road;}
    inline list <Vehicule*> getVehicules(){return vehicules_road;}
    inline int getOriantation(){return oriantation;}



    Road (int nu, int ori);
    virtual ~Road ( );
    //Road (const Road & road);

//------------------------------------------------------------------ PRIVE

protected:
    int num; 
    int oriantation; // 0 NorthSouth or 1 EastWest (only straight raods)

    list <Vehicule*> vehicules_road; //list of vehicules on this road
    vector <Signalisation*> signalisation_road; //list of signalisations on this road


};

//-------------------------------- Autres définitions dépendantes de <Xxx>



