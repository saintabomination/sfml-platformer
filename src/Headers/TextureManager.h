#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../Headers.h"

class TextureManager
{
    private:
        std::map<const char*, sf::Texture> textures;

    public:
        // Constructor
        TextureManager(){};

        // Functions
        void addTexture(const char* textureName, const char* path);
        const sf::Texture* getTexture(const char* textureName) const;
};

#endif // TEXTUREMANAGER_H
