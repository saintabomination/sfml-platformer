#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"
#include <SFML/Graphics/Texture.hpp>

class Player
{
    private:
        sf::RectangleShape shape;

    public:
        // Constructor
        Player();

        // Modifiers
        void setTexture(const sf::Texture* newTexture);

        // Functions
        void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
