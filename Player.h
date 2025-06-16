#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Texture& texture);
    void handleInput();
    void update();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    float speed = 5.0f;
};





