#pragma once
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <memory>

class Universe
{
    public:
        Universe(int Passedwidth, int Passedheight);

        double getUniverseRadius(void){return universeRadius;}
        int getNumberOfParticles(void){return numberOfParticles;}
        int getWidth(void){return width;}
        int getHeight(void){return height;}

        void setUniverseRadius(double uRad){universeRadius = uRad;}
        void setNumberOfParticles(int num){numberOfParticles = num;}

        //use of references
        CelestialBody& getCelestialBody(int index){return *(CBVector[index]);}

        friend std::ostream &operator<<(std::ostream  &output, Universe &U);

        void step(double deltaTime);

        
    private:
        double universeRadius;
        int numberOfParticles;
        std::vector<std::shared_ptr<CelestialBody>> CBVector;

        int width;
        int height;
};


#endif