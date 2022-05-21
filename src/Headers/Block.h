#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
    private:
        sf::RectangleShape shape;

    public:
        // Constructor
        Block(const sf::Texture* texture, sf::Vector2f position, sf::Vector2f size);

        // Accessors
        const sf::FloatRect getBounds() const;

        // Functions
        void render(sf::RenderTarget &target);
};

#endif // BLOCK_H
