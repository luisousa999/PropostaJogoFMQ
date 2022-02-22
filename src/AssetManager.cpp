#include "AssetManager.hpp"

// O asset manager e usado somente para obter a font a usar

Engine::AssetManager::AssetManager() {
}

Engine::AssetManager::~AssetManager() {
}

void Engine::AssetManager::AddFont(int id, const std::string &filePath)
{
    auto font = std::make_unique<sf::Font>();

    if(font->loadFromFile(filePath))
    {
        m_fonts[id] = std::move(font);
    }
}

const sf::Font &Engine::AssetManager::GetFont(int id) const
{
    return *(m_fonts.at(id).get());
}