#pragma once
#include <SFML/Graphics.hpp>

class Banana {
public:
    Banana(sf::Vector2f position, const sf::Texture& texture);
    void update();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    float fallSpeed = 3.0f;
};



