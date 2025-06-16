#include "Banana.h"

Banana::Banana(sf::Vector2f position, const sf::Texture& texture)
    : sprite(texture)
{
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(0.05f, 0.05f));
}

void Banana::update() {
    sprite.move(sf::Vector2f(0.f, fallSpeed));
}

void Banana::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Banana::getBounds() const {
    return sprite.getGlobalBounds();
}



