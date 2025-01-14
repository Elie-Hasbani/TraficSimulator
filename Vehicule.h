/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#ifndef VEHICULE_H
#define VEHICULE_H
#endif 

#ifndef IO
#define IO
#include <iostream>
#endif

using namespace std; 


class Vehicule
{
    
//----------------------------------------------------------------- PUBLIC

public:



//----------------------------------------------------- Méthodes publiques
   
    void Forward(int Obstacle, int oriantation, double dist);
    inline void changeDirection(int direc){direction = direc;}

    
    inline int getxPos(){return xPos;}
    inline int getyPos(){return yPos;}
    inline int getSpeed(){return speed;}

    inline void changeMinDist(float dist){minDistToObstacle = dist;}
    inline float getMinDist(){return minDistToObstacle;}

//------------------------------------------------- Surcharge d'opérateur
    int operator !=(const Vehicule & unVehicule);
    friend ostream & operator <<(ostream& flux, const Vehicule & vehicule);



//-------------------------------------------- Constructeurs - destructeur
    Vehicule(float xPos = 50, float yPos = 10, double speed = 10);
    virtual ~Vehicule ( );
   


//------------------------------------------------------------------ PRIVE

protected:
float xPos, yPos;
int direction; 

double max_speed;
double speed;
float minDistToObstacle;

int nbVoiture;
static int nbtot;




};

//-------------------------------- Autres définitions dépendantes de <Xxx>



