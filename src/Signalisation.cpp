


#ifndef SIGNALISATION_H
#define SIGNALISATION_H
#include "Signalisation.h"
#endif

#ifndef IO
#define IO
#include <iostream>
#endif


using namespace std; 



Signalisation::Signalisation(float x, float y){
    xPos = x;
    yPos = y;

    #ifdef MAP
    cout << "Appel au constructeur de Signalisation" << endl;
    #endif
}

Signalisation::~Signalisation(){

     #ifdef MAP
    cout << "Appel au destructeur de Signalisation" << endl;
    #endif


}

Signalisation::Signalisation(const Signalisation & autreSignalisation){
    xPos = autreSignalisation.xPos;
    yPos = autreSignalisation.yPos;

    #ifdef MAP
    cout << "Appel au constructeur de copie de Signalisation" << endl;
    #endif

}