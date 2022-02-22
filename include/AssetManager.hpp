#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Font.hpp>

namespace Engine
{
    class AssetManager
    {
    private:
        std::map<int, std::unique_ptr<sf::Font> > m_fonts;
    public:
        AssetManager();
        ~AssetManager();

        void AddFont(int id, const std::string &filePath);
        
        const sf::Font &GetFont(int id) const;
    };   
}
