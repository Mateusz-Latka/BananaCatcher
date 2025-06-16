#include "Player.h"

Player::Player(const sf::Texture& texture)
    : sprite(texture)
{
    sprite.setScale(sf::Vector2f(0.15f, 0.15f));
    sprite.setPosition(sf::Vector2f(370.f, 470.f));
}



void Player::handleInput() {
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        movement.x += speed;

    sprite.move(movement);
}

void Player::update() {
    sf::Vector2f pos = sprite.getPosition();
    auto bounds = sprite.getGlobalBounds();
    float width = bounds.size.x;

    if (pos.x < 0.f) {
        sprite.setPosition(sf::Vector2f(0.f, pos.y));
    }
    if (pos.x + width > 800.f) {
        sprite.setPosition(sf::Vector2f(800.f - width, pos.y));
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

