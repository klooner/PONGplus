#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "pad.h"

class Ball
{
    sf::Vector2f size;
    sf::RectangleShape ball;
    sf::Vector2f movement;

    public:

    Ball();

    void update(sf::Time delta, Pad &p1, Pad &p2);
    void render(sf::RenderWindow &window);

    bool getCollision(Pad &pad);

    sf::Vector2f getMovement();
    sf::Vector2f getSize();
};

#endif // BALL_H
