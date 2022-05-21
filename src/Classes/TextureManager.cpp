#include "../Headers/TextureManager.h"
#include <SFML/Graphics/Texture.hpp>

// Functions

void TextureManager::addTexture(const char* textureName, const char* path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        std::cout << "ERROR::TEXTURE_MANAGER::CANT_LOAD_TEXTURE\nPath: " << path << '\n';
    }

    texture.setRepeated(true);
    this->textures.insert(std::pair<const char*, sf::Texture>(textureName, texture));
}

const sf::Texture* TextureManager::getTexture(const char* textureName) const
{
    auto it = this->textures.find(textureName);
    if (it == this->textures.end()) {
        std::cout << "ERROR::TEXTURE_MANAGER::CANT_FIND_TEXTURE\nName: " << textureName << '\n';
        return new sf::Texture();
    }
    return &it->second;
}
