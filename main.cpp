#include <iostream>
#include <SFML/Graphics.hpp>
#include "pad.h"
#include "ball.h"

const int MAX_WIDTH = 1000;
const int MAX_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(MAX_WIDTH,MAX_HEIGHT), "PONG++");

    window.setFramerateLimit(60);

    sf::Clock ticks;
    sf::Time timeSinceLastUpdate = sf::seconds(0.f);

    sf::Time TimePerFrame = sf::seconds(1.f/60.f);

    Pad p1(true);
    Pad p2(false);

    Ball ball;

    while(window.isOpen()){

        sf::Event event;

        sf::Time delta = ticks.restart();

       timeSinceLastUpdate += delta;

        while(timeSinceLastUpdate > TimePerFrame){

            timeSinceLastUpdate -= TimePerFrame;

            while(window.pollEvent(event)){


                if(event.type == sf::Event::Closed)window.close();

                p1.handleInput(event);
                p2.handleInput(event);

                p1.update(TimePerFrame);
                p2.update(TimePerFrame);
                ball.update(TimePerFrame, p1, p2);

            }

            window.clear(sf::Color(239,176,107));

            p1.render(window);
            p2.render(window);
            ball.render(window);

            window.display();

        }
    }



    return 0;
}

