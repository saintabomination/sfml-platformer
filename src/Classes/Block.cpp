#include "../Headers/Block.h"

// Constructor

Block::Block(const sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
    this->shape.setTexture(texture);
    this->shape.setPosition(position);
    this->shape.setSize(size);
}

// Accessors

const sf::FloatRect Block::getBounds() const
{
    return this->shape.getGlobalBounds();
}

// Functions

void Block::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
