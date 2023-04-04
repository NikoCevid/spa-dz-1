#pragma once
#include <SFML/Graphics.hpp>

class Flower
{
public:
	Flower(sf::RenderWindow* window);
	void draw();
private:
	sf::RenderWindow* window;
};

