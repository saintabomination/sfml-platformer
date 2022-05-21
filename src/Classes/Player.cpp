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

void Player::update(std::vector<Block> blocks)
{
    this->shape.move(sf::Vector2f(0.f, 80.f * game.getDt()));
    for (Block block : blocks)
    {
        if (
            this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height > block.getBounds().top &&
            this->shape.getGlobalBounds().top < block.getBounds().top + block.getBounds().height &&
            this->shape.getGlobalBounds().left < block.getBounds().width + block.getBounds().left &&
            this->shape.getGlobalBounds().left > block.getBounds().left - this->shape.getGlobalBounds().width
        ) {
            this->shape.setPosition(sf::Vector2f(
                this->shape.getGlobalBounds().left,
                block.getBounds().top - this->shape.getGlobalBounds().height
            ));
        }
    }
}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
