#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "CelestialBody.h"
#include "Universe.h"

Universe::Universe(int Passedwidth, int Passedheight)
{
    double xP, yP, xV, yV, M;
    std::string name;

    width = Passedwidth;
    height = Passedheight;

    std::cin >> numberOfParticles >> universeRadius;

    for (int i = 0; i < numberOfParticles; i++)
    {
        std::cin >> xP >> yP >> xV >> yV >> M >> name;
        CBVector.push_back(std::make_shared<CelestialBody>(xP, yP, xV, yV, M, name, universeRadius, width, height, universeRadius));
    }
}

void Universe::step(double seconds)
{
    std::vector<std::shared_ptr<CelestialBody>>::iterator firstIterator;
    std::vector<std::shared_ptr<CelestialBody>>::iterator secondIterator;
    std::vector<std::shared_ptr<CelestialBody>>::iterator thirdIterator;

    double mass1, mass2, totalNetForce;
    double netFx;
    double netFy;
    double accelerationX, accelerationY;
    double calcRadius;
    double xnewPos, ynewPos;
    double deltaX, deltaY, newX, oldX, newY, oldY;
    double newVelX, newVelY;

    for (firstIterator = CBVector.begin(); firstIterator != CBVector.end(); firstIterator++)
    {
        mass1 = (*firstIterator)->getMass();

        (*firstIterator)->setXforce(0);
        (*firstIterator)->setYforce(0);
        
        for (secondIterator = CBVector.begin(); secondIterator != CBVector.end(); secondIterator++)
        {
            if (*firstIterator != *secondIterator)
            {
                mass2 = (*secondIterator)->getMass();

                oldX = (*firstIterator)->getXPosition();
                newX = (*secondIterator)->getXPosition();
                
                oldY = (*firstIterator)->getYPosition();
                newY = (*secondIterator)->getYPosition();

                deltaX = newX - oldX;
                deltaY = newY - oldY;

                calcRadius = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));

                totalNetForce = (0.0000000000667) * ((mass1 * mass2) / pow(calcRadius, 2.0));

                netFx = (*firstIterator)->getXForce() + ((totalNetForce * deltaX) / calcRadius);
                netFy = (*firstIterator)->getYForce() + ((totalNetForce * deltaY) / calcRadius);

                (*firstIterator)->setXforce(netFx);
                (*firstIterator)->setYforce(netFy);
            }
        }
    }

    double mass4;

    for (thirdIterator = CBVector.begin(); thirdIterator != CBVector.end(); thirdIterator++)
    {
        mass4 = (*thirdIterator)->getMass();

        accelerationX = (*thirdIterator)->getXForce() / mass4;
        accelerationY = (*thirdIterator)->getYForce() / mass4;

        newVelX = (*thirdIterator)->getXVelocity() + (seconds * accelerationX);
        newVelY = (*thirdIterator)->getYVelocity() + (seconds * accelerationY);

        (*thirdIterator)->setVelocity(newVelX, newVelY);

        xnewPos = (*thirdIterator)->getXPosition() + (seconds * newVelX);
        ynewPos = (*thirdIterator)->getYPosition() + (seconds * newVelY);

        (*thirdIterator)->newSetPosition(xnewPos, ynewPos);
    }
}

std::ostream &operator<<(std::ostream &output, Universe &U)
{
    std::vector<std::shared_ptr<CelestialBody>>::iterator accessVector;
    for (accessVector = U.CBVector.begin(); accessVector != U.CBVector.end(); accessVector++)
    {
        output << std::scientific << (*accessVector)->getXPosition() << "\t" << std::scientific << (*accessVector)->getYPosition() << "\t" << std::scientific << (*accessVector)->getXVelocity() << "\t" << std::scientific << (*accessVector)->getYVelocity()  << "\t" <<std::scientific << (*accessVector)->getMass() << "\t" <<std::scientific << (*accessVector)->getName() << std::endl;
    }

    return output;
}