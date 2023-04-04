#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
	int WINDOW_HEIGHT = 600;
	int WINDOW_WIDTH = 800;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Flower flower(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		flower.draw();

		window.display();
	}

	return 0;
}