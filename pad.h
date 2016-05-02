#ifndef PAD_H
#define PAD_H
#include <SFML/Graphics.hpp>

class Pad
{
    sf::Vector2f size;
    sf::RectangleShape pad;
    sf::Vector2f movement;

    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;

    bool isP1;

    sf::Vector2f boundOrigin;
    sf::Vector2f boundArea;

public:
    Pad(bool P1);

    void handleInput(sf::Event e);
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
    sf::Vector2f getSize();
    sf::Vector2f getPos();

};

#endif // PAD_H
