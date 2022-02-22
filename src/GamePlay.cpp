#include "GamePlay.hpp"
#include "GamePause.hpp"
#include "MainMenu.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include <time.h>


GamePlay::GamePlay(std::shared_ptr<Context> &context) :
    m_context(context),
    m_elapsedTime(sf::Time::Zero),
    m_isPaused(false),
    m_maxBolas(50)
    //m_bolas[0]
{

}

GamePlay::~GamePlay() 
{

}




void GamePlay::Init()
{
            //sf::CircleShape shape(100.f);
            //shape.setFillColor(sf::Color::Yellow);

    /* //Vai definir um raio aleatorio
    m_shape.setRadius(static_cast<float>(rand()%10+10));

    //Vai dar uma cor aleatoria
    m_shape.setFillColor(sf::Color(rand()%255+1, rand()%255+1, rand()%255+1, rand()%255+1));

    //Vai fazer spawn numa loc aleatoria
    m_shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand()% m_context->m_window->getSize().x - m_shape.getGlobalBounds().width),
            static_cast<float>(rand()% m_context->m_window->getSize().y - m_shape.getGlobalBounds().height)
        )
    );  */
}

void GamePlay::spawnBolas()
{
    /* 
    //Vai definir um raio aleatorio
    m_bolas.setRadius(static_cast<float>(rand()%10+10));

    //Vai dar uma cor aleatoria
    m_bolas.setFillColor(sf::Color(rand()%255+1, rand()%255+1, rand()%255+1, rand()%255+1));

    //Vai fazer spawn numa loc aleatoria
    m_bolas.setPosition(
        sf::Vector2f(
            static_cast<float>(rand()% m_context->m_window->getSize().x - m_bolas.getGlobalBounds().width),
            static_cast<float>(rand()% m_context->m_window->getSize().y - m_bolas.getGlobalBounds().height)
        )
    ); 
    */

   /* if(m_bolas.size() < m_maxBolas)
            {
                //m_bolas.push_back(Bolas(m_context->m_window->));
                m_bolas.push_back(Bolas(*this->m_context->m_window));
            } */

}

void GamePlay::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
        {
            m_context->m_states->Add(std::make_unique<GamePause>(m_context));
        }
    }
}

void GamePlay::Update(sf::Time deltaTime)
{
    if(!m_isPaused)
    {
        m_elapsedTime += deltaTime;

        if (m_elapsedTime.asSeconds() > 0.1)
        {
            /* if(m_bolas.size() < m_maxBolas)
            {
                //m_bolas.push_back(Bolas(m_context->m_window->));
                m_bolas.push_back(Bolas(*this->m_context->m_window));
            } */
            
        }
        if (m_elapsedTime.asSeconds() > 5) // apos 5 segundos o jogo acaba e volta de novo ao Main Menu
        {
            m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
        }

    }
}

void GamePlay::Draw()
{
    m_context->m_window->clear();
    //m_context->m_window->draw(m_shape);

    /* for (auto &i : m_bolas)
    {
        //m_context->m_window->draw(i);
		//i.draw(*m_context->m_window, m_context->m_states->GetCurrent);
    } */

    m_context->m_window->display();

}

void GamePlay::Pause()
{
    m_isPaused = true;
}

void GamePlay::Start()
{
    m_isPaused = false;
}
