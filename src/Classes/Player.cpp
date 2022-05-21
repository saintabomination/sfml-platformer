#include "../Headers/Player.h"

// Constructor

Player::Player()
{
    this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

// Modifiers

void Player::setTexture(const sf::Texture *newTexture)
{
    this->shape.setTexture(newTexture);
}

// Functions

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
