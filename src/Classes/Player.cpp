#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

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

void Player::setSpeed(const float newSpeed)
{
    this->speed = newSpeed;
}

// Functions

void Player::move(sf::Vector2f movementVector)
{
    this->shape.move(movementVector * this->speed * game.getDt());
}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
