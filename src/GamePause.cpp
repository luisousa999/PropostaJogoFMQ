#include "GamePause.hpp"

#include <SFML/Window/Event.hpp>


GamePause::GamePause(std::shared_ptr<Context> &context) : m_context(context)
{
}

GamePause::~GamePause() 
{
}

void GamePause::Init()
{
    // Texto pausa
    m_pauseText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pauseText.setString("Game Paused!");

    m_pauseText.setOrigin(m_pauseText.getLocalBounds().width / 2,
                          m_pauseText.getLocalBounds().height / 2);

    m_pauseText.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2);
}

void GamePause::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Escape: //ao clicar vai fechar o pause menu
                {
                    m_context->m_states->PopCurrent();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}

void GamePause::Update(sf::Time deltaTime)
{
}

void GamePause::Draw()
{
    m_context->m_window->draw(m_pauseText);
    m_context->m_window->display();
}