#include "pad.h"

Pad::Pad(bool p1): isP1(p1)
{
    size = sf::Vector2f(15,80);
    pad.setSize(size);
    pad.setFillColor(sf::Color::White);
    movement =  sf::Vector2f(0,0);
    boundArea = sf::Vector2f(300,600);

    if(p1){

        pad.setPosition(sf::Vector2f(0,300 - size.y/2));
        boundOrigin = sf::Vector2f(0,0);

        up = sf::Keyboard::W;
        down = sf::Keyboard::S;
        left = sf::Keyboard::A;
        right = sf::Keyboard::D;

    }else{

        pad.setPosition(sf::Vector2f(1000 - size.x,300 - size.y/2));
        boundOrigin = sf::Vector2f(700,0);

        up = sf::Keyboard::Up;
        down = sf::Keyboard::Down;
        left = sf::Keyboard::Left;
        right = sf::Keyboard::Right;
    }
}

void Pad::update(sf::Time delta)
{
    pad.move(movement.x * delta.asMilliseconds(), movement.y * delta.asMilliseconds());

    float x = pad.getPosition().x;
    float y = pad.getPosition().y;

    if(x < boundOrigin.x)
    {
        pad.setPosition(boundOrigin.x,y);
    }
    if(x + size.x > boundOrigin.x + boundArea.x)
    {
        pad.setPosition(boundOrigin.x + boundArea.x - size.x,y);
    }
    if(y < boundOrigin.y)
    {
        pad.setPosition(x,boundOrigin.y);
    }
    if(y + size.y > boundOrigin.y + boundArea.y)
    {
        pad.setPosition(x,boundOrigin.y + boundArea.y - size.y);
    }

}

void Pad::render(sf::RenderWindow &window)
{
    window.draw(pad);
}

void Pad::handleInput(sf::Event e)
{

    movement = sf::Vector2f(0,0);

    //if(e.type == sf::Event::KeyPressed){

        if(sf::Keyboard::isKeyPressed(up))
        {
            movement += sf::Vector2f(0,-0.5);
        }
        if(sf::Keyboard::isKeyPressed(down))
        {
            movement += sf::Vector2f(0,0.5);
        }
        if(sf::Keyboard::isKeyPressed(left))
        {
            movement += sf::Vector2f(-0.5,0);
        }
        if(sf::Keyboard::isKeyPressed(right))
        {
            movement += sf::Vector2f(0.5,0);
        }
   // }

}

sf::Vector2f Pad::getSize()
{
    return size;
}

sf::Vector2f Pad::getPos()
{
    return pad.getPosition();
}

