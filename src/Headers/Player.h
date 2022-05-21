#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"
#include "Block.h"

class Player
{
    private:
        sf::RectangleShape shape;
        float speed;

    public:
        // Constructor
        Player();

        // Modifiers
        void setTexture(const sf::Texture* newTexture);
        void setSpeed(const float newSpeed);

        // Functions
        void move(sf::Vector2f movementVector);
        void update(std::vector<Block> blocks);
        void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
