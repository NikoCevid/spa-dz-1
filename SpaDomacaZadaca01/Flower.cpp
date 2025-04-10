#include "Flower.h"

Flower::Flower(sf::RenderWindow* window)
{
    this->window = window;
    sunRadius = 20.0f;
    shrinking = true;
}

void Flower::draw()
{
    
    float elapsed = animationClock.getElapsedTime().asSeconds();

    if (elapsed > 0.05f) {
        if (shrinking)
            sunRadius -= 0.5f;
        else
            sunRadius += 0.5f;

        if (sunRadius <= 15.0f)
            shrinking = false;
        else if (sunRadius >= 40.0f)
            shrinking = true;

        animationClock.restart();
    }

    // SUNCE
    sf::CircleShape sun(sunRadius);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(50, 50);
    window->draw(sun);

    // CVIJET 
    sf::CircleShape center(50);
    center.setFillColor(sf::Color::Magenta);
    center.setPosition(window->getSize().x / 2 - center.getRadius(),
        window->getSize().y / 2 - center.getRadius());
    window->draw(center);

    // LATICE
    for (int i = 0; i < 8; ++i)
    {
        sf::CircleShape petal(30);
        petal.setFillColor(sf::Color::Red);
        float angle = i * 45 * 3.14f / 180.0f;
        float offsetX = std::cos(angle) * 70;
        float offsetY = std::sin(angle) * 70;
        petal.setPosition(center.getPosition().x + 50 + offsetX - petal.getRadius(),
            center.getPosition().y + 50 + offsetY - petal.getRadius());
        window->draw(petal);
    }

    // STABLJIKA
    sf::RectangleShape stem(sf::Vector2f(20, 100));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(center.getPosition().x + center.getRadius() - 10,
        center.getPosition().y + center.getRadius() + 40);
    window->draw(stem);
}
