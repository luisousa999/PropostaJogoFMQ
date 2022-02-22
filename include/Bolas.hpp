#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "State.hpp"
#include "Game.hpp"

class Bolas : public sf::Drawable
{
    private:
        std::shared_ptr<Context> m_context;
        sf::CircleShape m_shape;
        void initShape(const sf::RenderWindow& window);

    public:
        Bolas(const sf::RenderWindow& window);//std::shared_ptr<Context> &context);
        ~Bolas();

        const sf::CircleShape getShape() const;
        
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    
};