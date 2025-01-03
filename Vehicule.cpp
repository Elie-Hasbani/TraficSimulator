

#include "Vehicule.h"

#ifndef IO
#define IO
#include <iostream>
#endif

#ifndef CMATH
#define CMATH
#include <cmath>
#endif

using namespace std; 

int Vehicule::nbtot = 0;

Vehicule::Vehicule(float x, float y, double spe){
    xPos = x;
    yPos = y;
    max_speed = speed = spe;

    nbtot++;
    nbVoiture = nbtot;

    #ifdef MAP
    cout << "Appel au constructeur de Vehicule" << endl;
    #endif
}

Vehicule::~Vehicule(){

    
    #ifdef MAP
    cout << "Appel au destructeur de Vehicule" << endl;
    #endif
}

void Vehicule::Forward(int obstacle, int oriantaion, double dist){

    if(speed < max_speed && !obstacle){/*to re accelerate */}


    if (!obstacle){
        if (oriantaion == 0){
            yPos += speed;
        }
        else{
            xPos += speed;
        }
        
    }
    else{

        speed = max_speed* sqrt(((dist-5.0)/95.0));
        if (dist < 5){
            speed = 0;
        }

        if(oriantaion == 0){
            yPos += speed;
        }

        else{
            xPos += speed;
        }
        
    }

    cout<< "voiture numero " << nbVoiture << " en position "<< xPos << ", "<<yPos<< " de vitesse " << speed<<endl;

}

int Vehicule::operator != (const Vehicule & unVehicule){
    if (this->xPos == unVehicule.xPos && this -> yPos == unVehicule.yPos){
        return 0;
    }

    return 1;


}