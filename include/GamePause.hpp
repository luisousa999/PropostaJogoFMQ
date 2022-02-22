#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class GamePause : public Engine::State
{
    private:
        std::shared_ptr<Context> m_context;
        sf::Text m_pauseText;

    public:
        GamePause(std::shared_ptr<Context> &context);
        ~GamePause();
    
        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
};