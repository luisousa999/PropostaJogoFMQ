#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{
    private:
        std::shared_ptr<Context> m_context;
        sf::Text m_playButton;
        sf::Text m_creditsInButton;
        sf::Text m_creditsOutButton;

        sf::Text m_playedText;
        int m_played;

        sf::Text m_creditsText;
        int m_credits;
        
        bool m_isPlayButtonSelected;
        bool m_isPlayButtonPressed;

        bool m_isCreditsInButtonSelected;
        bool m_isCreditsInButtonPressed;

        bool m_isCreditsOutButtonSelected;
        bool m_isCreditsOutButtonPressed;


    public:
        MainMenu(std::shared_ptr<Context> &context);
        ~MainMenu();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
};