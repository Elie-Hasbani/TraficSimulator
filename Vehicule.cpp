

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

void Vehicule::Forward(int obstacle, int oriantation, double dist){

    if(speed < max_speed && !obstacle){/*to re accelerate */}


    if (!obstacle){

  
        speed = speed*(1+ 0.5*(1-speed/max_speed));


        if (!direction){
            if (oriantation == 0){
                yPos += speed;
            }
            else{
                xPos += speed;
            }
        }

        else{
              if (oriantation == 0){
                yPos -= speed;
            }
            else{
                xPos -= speed;
            }
        }
        
    }

 

    else{

        speed = max_speed* sqrt(((dist-10.0)/90.0));
        if (dist < 10){
            speed = 0;
        }

        


        if (!direction){
            if (oriantation == 0){
                yPos += speed;
            }
            else{
                xPos += speed;
            }
        }

        else{
              if (oriantation == 0){
                yPos -= speed;
            }
            else{
                xPos -= speed;
            }
        }
        
    }

    cout<< (*this) <<endl;

}

int Vehicule::operator != (const Vehicule & unVehicule){
    if (this->xPos == unVehicule.xPos && this -> yPos == unVehicule.yPos){
        return 0;
    }

    return 1;


}

ostream & operator <<(ostream& flux, const Vehicule & vehicule){
    cout<< "voiture numero " << vehicule.nbVoiture << " en position" << " (" <<vehicule.xPos<<","<< vehicule.yPos<<") "<< "de vitesse " << vehicule.speed << " en oriantation "<< vehicule.oriantation <<" ("<<vehicule.nbVoiture<<")";

    return flux;
}