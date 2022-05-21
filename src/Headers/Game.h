#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "TextureManager.h"
#include "Block.h"
#include "Player.h"

class Game
{
    private:
        sf::RenderWindow* window;
        sf::Event sfEvent;

        // Clocks
        sf::Clock dtClock;
        float dtElapsed;

        // Managers
        TextureManager textureManager;

        // Components
        Player player;
        std::vector<Block> blocks;

        // Initialisers
        void initWindow();
        void initTextures();
        void initBlocks();
        void initPlayer();

    public:
        // Constructor and Destructor
        Game();
        virtual ~Game();

        // Update Functions
        void updateSFMLEvents();
        void updateClocks();
        void updateKeys();
        void update();

        // Accessors
        const float getDt() const;

        // Render Functions
        void renderBlocks();
        void renderPlayer();
        void render();

        // Functions
        void run();
};

#endif // GAME_H
