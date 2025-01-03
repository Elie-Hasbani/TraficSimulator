#ifndef SIGNALISATION_H
#define SIGNALISATION_H
#endif

#ifndef IO
#define IO
#include <iostream>
#endif

using namespace std; 


class Signalisation
{
    public:
    Signalisation(float x, float y);
    virtual ~Signalisation();
    Signalisation(const Signalisation & autreSignalisation);

    inline int getxPos(){return xPos;}
    inline int getyPos(){return yPos;}





    protected:
    float xPos, yPos; 
    

};