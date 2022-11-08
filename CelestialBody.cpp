#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CelestialBody.h"
#include "Universe.h"

CelestialBody::CelestialBody(double xPosition, double yPosition, double xVelocity, double yVelocity, double givenMass, std::string filename, double passedRadius, int width, int height, double givenRadius)
{    
    double setXWindow, setYWindow;

    xPos = xPosition;
    yPos = yPosition;

    xVel = xVelocity;
    yVel = yVelocity;

    mass = givenMass;

    nameOfCB = filename;

    uRadius = givenRadius;

    if(!CBtexture.loadFromFile(nameOfCB))
    {
        std::cout << "Error in loading image " << nameOfCB << std::endl;
    }

    setXWindow = ((getRadius()) + xPos) * (width/(getRadius() * 2));
    setYWindow = ((getRadius()) - yPos) * (height/(getRadius() * 2));
    
    CBSprite.setTexture(CBtexture);
    CBSprite.setPosition(setXWindow, setYWindow);
}

std::ostream &operator<<(std::ostream  &output, CelestialBody &CB)
{ 
    output << CB.xPos << CB.yPos << CB.xVel << CB.yVel << CB.mass << CB.nameOfCB;
    return output;            
}

std::istream &operator>>(std::istream  &input, CelestialBody &CB)
{ 
    input >> CB.xPos >> CB.yPos >> CB.xVel >> CB.yVel >> CB.mass >> CB.nameOfCB;
    return input;            
}