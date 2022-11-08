#pragma once
#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <string>
#include <cmath>

class CelestialBody : public sf::Drawable
{
    public:
        CelestialBody();
        CelestialBody(double xPosition, double yPosition, double xVelocity, double yVelocity, double givenMass, std::string filename, double passedRadius, int width, int height, double givenRadius);

        void setPosition(double x, double y) 
        {
            xPos = x; 
            yPos = y;
        }

        void newSetPosition(double x, double y)
        {
            double setXWindow, setYWindow;

            xPos = x;
            yPos = y;

            setXWindow = ((getRadius()) + xPos) * (500/(getRadius() * 2));
            setYWindow = ((getRadius()) - yPos) * (500/(getRadius() * 2));

            CBSprite.setPosition(setXWindow, setYWindow);
        }

        void setVelocity(double x, double y) {xVel = x; yVel = y;}
        void setMass(double massGiven) {mass = massGiven;}
        void setRadius(double givenRadius) {uRadius = givenRadius;}
        void setXforce(double givenXForce) {xForce = givenXForce;}
        void setYforce(double givenYForce) {yForce = givenYForce;}

        double getXPosition(void) {return xPos;}
        double getYPosition(void) {return yPos;}
        double getXVelocity(void) {return xVel;}
        double getYVelocity(void) {return yVel;}
        double getMass(void) {return mass;}
        double getRadius(void) {return uRadius;}
        double getXForce(void){return xForce;}
        double getYForce(void){return yForce;}

        sf::Sprite getSprite(void) {return CBSprite;}
        std::string getName(void) {return nameOfCB;}

        friend std::istream &operator>>(std::istream  &input, CelestialBody &CB);
        friend std::ostream &operator<<(std::ostream  &output, CelestialBody &CB);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(CBSprite, states);
        }

        double xPos;
        double yPos;
        double xVel;
        double yVel;
        double mass;
        double uRadius;
        double xForce;
        double yForce;

        std::string nameOfCB;
        sf::Texture CBtexture;
        sf::Sprite CBSprite;
};


#endif