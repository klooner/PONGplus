#include "ball.h"
#include <cmath>
Ball::Ball()
{
    size = sf::Vector2f(20,20);
    ball.setSize(size);
    ball.setFillColor(sf::Color::White);
    ball.setPosition((1000 - size.x)/2,(600 - size.y)/2);

    movement = sf::Vector2f(1,0);
}

void Ball::update(sf::Time delta, Pad &p1, Pad &p2)
{
	if(getCollision(p1) && movement.x < 0)
	{
		double factorx = (int(ball.getPosition().x)%500)/285;
		double factory = ((ball.getPosition().y + size.y/2) - (p1.getPos().y + p1.getSize().y/2))/(p1.getSize().y/2);
		movement = sf::Vector2f(1,(0.3 + 0.7*(1-factorx)) * factory);
		double vel = 0.5 + 0.5*factorx;
		movement = sf::Vector2f(vel*movement.x/sqrt(movement.x*movement.x + movement.y * movement.y),vel*movement.y/sqrt(movement.x*movement.x + movement.y * movement.y));
	}
	else if(getCollision(p2) && movement.x > 0)
	{
		double factorx = (int(ball.getPosition().x)%500)/285;
		double factory = ((ball.getPosition().y + size.y/2) - (p2.getPos().y + p2.getSize().y/2))/(p2.getSize().y/2);
		movement = sf::Vector2f(-1,(0.3 + 0.7*(1-factorx)) * factory);
		double vel = 0.5 + 0.5*factorx;
		movement = sf::Vector2f(vel*movement.x/sqrt(movement.x*movement.x + movement.y * movement.y),vel*movement.y/sqrt(movement.x*movement.x + movement.y * movement.y));
	}

	if(ball.getPosition().y < 0)
	{
		ball.setPosition(ball.getPosition().x, 0);
		movement = sf::Vector2f(movement.x, movement.y*(-1));
	}
	else if(ball.getPosition().y + size.y > 600)
	{
		ball.setPosition(ball.getPosition().x, 600 - size.y);
		movement = sf::Vector2f(movement.x, movement.y*(-1));
	}

	if(ball.getPosition().x < 0 || ball.getPosition().x > 1000) ball.setPosition((1000 - size.x)/2,(600 - size.y)/2);

    ball.move(movement.x * delta.asMilliseconds(), movement.y * delta.asMilliseconds());

}

void Ball::render(sf::RenderWindow &window)
{
    window.draw(ball);
}

bool Ball::getCollision(Pad &pad)
{
	return pad.getPos().x < ball.getPosition().x + size.x &&
	pad.getPos().x + pad.getSize().x > ball.getPosition().x &&
	pad.getPos().y < ball.getPosition().y + size.y && 
	pad.getPos().y + pad.getSize().y > ball.getPosition().y;
}

sf::Vector2f Ball::getMovement()
{
	return movement;
}

sf::Vector2f Ball::getSize()
{
	return size;
}