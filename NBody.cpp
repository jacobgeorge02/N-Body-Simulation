#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "CelestialBody.h"
#include "Universe.h"

int main(int argc, char* argv[])
{
	Universe u(500, 500);

	sf::RenderWindow window(sf::VideoMode(u.getWidth(), u.getHeight()), "Solar System");

	double totalTime = std::stod(argv[1]);
	double deltaT = std::stod(argv[2]);
	double currentTime = 0;

    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		if (currentTime >= totalTime)
			window.close();

        for (int i = 0; i < u.getNumberOfParticles(); ++i) 
		{
			window.draw(u.getCelestialBody(i));
		}

		u.step(deltaT);
		currentTime += deltaT;

		window.display();
	}

	std::cout << u;

    return 0;
}
