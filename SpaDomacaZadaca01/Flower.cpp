#include "Flower.h"

Flower::Flower(sf::RenderWindow* window)
{
	this->window = window;
}

void Flower::draw()
{
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Magenta);
	circle.setPosition(sf::Vector2f(
		window->getSize().x / 2 - circle.getRadius(), 
		window->getSize().y / 2 - circle.getRadius())
	);

	window->draw(circle);
}
