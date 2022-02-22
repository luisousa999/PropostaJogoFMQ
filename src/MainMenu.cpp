#include "MainMenu.hpp"
#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context> &context) :
        m_context(context), 
        m_isPlayButtonSelected(true),           m_isPlayButtonPressed(false),
        m_isCreditsInButtonSelected(false),     m_isCreditsInButtonPressed(false), 
        m_isCreditsOutButtonSelected(false),    m_isCreditsOutButtonPressed(false)
{

}

MainMenu::~MainMenu() {

}

void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "Fonts/Ubuntu-B.ttf");

    // START
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString("Start");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                           m_playButton.getLocalBounds().height / 2);

    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 150.f);

    // CREDITS IN
    m_creditsInButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_creditsInButton.setString("Credits In");
    m_creditsInButton.setOrigin(m_creditsInButton.getLocalBounds().width / 2,
                                m_creditsInButton.getLocalBounds().height / 2);

    m_creditsInButton.setPosition(m_context->m_window->getSize().x / 2,
                                  m_context->m_window->getSize().y / 2 - 25.f);

    m_creditsInButton.setCharacterSize(20);

    // CREDITS OUT
    m_creditsOutButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_creditsOutButton.setString("Credits Out");
    m_creditsOutButton.setOrigin(m_creditsOutButton.getLocalBounds().width / 2,
                                 m_creditsOutButton.getLocalBounds().height / 2);

    m_creditsOutButton.setPosition(m_context->m_window->getSize().x / 2,
                                   m_context->m_window->getSize().y / 2 + 25.f);

    m_creditsOutButton.setCharacterSize(20);

    // NMRO DE JOGADAS REALIZADAS
    m_playedText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playedText.setString("Rounds Played : " + std::to_string(m_played));
    m_playedText.setPosition(0.f, 20.f);
    m_playedText.setCharacterSize(15);

    // NMRO DE CREDITOS DISPONIVEIS
    m_creditsText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_creditsText.setString("Credits : " + std::to_string(m_credits));
    m_creditsText.setCharacterSize(15);
}

void MainMenu::ProcessInput()
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
                case sf::Keyboard::Up: //MUDA O BUTTON SELECIONADO PARA MUDAR CORES SE CLICAR NA UP ARROW
                {
                    if(m_isCreditsInButtonSelected)
                    {
                        m_isPlayButtonSelected = true;
                        m_isCreditsInButtonSelected = false;
                        m_isCreditsOutButtonSelected = false;
                    }
                    else if(m_isCreditsOutButtonSelected)
                    {
                        m_isPlayButtonSelected = false;
                        m_isCreditsInButtonSelected = true;
                        m_isCreditsOutButtonSelected = false;
                    }

                    break;
                }

                case sf::Keyboard::Down: //MUDA O BUTTON SELECIONADO PARA MUDAR CORES SE CLICAR NA DOWN ARROW
                {
                    if(m_isPlayButtonSelected)
                    {
                        m_isPlayButtonSelected = false;
                        m_isCreditsInButtonSelected = true;
                        m_isCreditsOutButtonSelected = false;
                    }

                    else if(m_isCreditsInButtonSelected)
                    {
                        m_isPlayButtonSelected = false;
                        m_isCreditsInButtonSelected = false;
                        m_isCreditsOutButtonSelected = true;
                    }

                    break;
                }
                
                //Ao clicar Enter e estiver com determinado botao selecionado este o botao pressionado passara a verdadeiro
                case sf::Keyboard::Return: 
                {
                    m_isPlayButtonPressed = false;
                    m_isCreditsInButtonPressed = false;
                    m_isCreditsOutButtonPressed = false;

                    if (m_isPlayButtonSelected)
                    {
                        m_isPlayButtonPressed = true;
                    }
                    else if (m_isCreditsInButtonSelected)
                    {
                        m_isCreditsInButtonPressed = true;
                    }
                    else
                    {
                        m_isCreditsOutButtonPressed = true;
                    }

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

void MainMenu::Update(sf::Time deltaTime)
{
    // Muda a cor do botao selecionado
    if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_creditsInButton.setFillColor(sf::Color::White);
        m_creditsOutButton.setFillColor(sf::Color::White);

    }
    else if(m_isCreditsInButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_creditsInButton.setFillColor(sf::Color::Black);
        m_creditsOutButton.setFillColor(sf::Color::White);
    }
    else if(m_isCreditsOutButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_creditsInButton.setFillColor(sf::Color::White);
        m_creditsOutButton.setFillColor(sf::Color::Black);
    }

    // Açoes do press buttons
    // START COM DINHEIRO DISPONIVEL
    if(m_isPlayButtonPressed && m_credits >= 1)
    {
        m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
        m_played += 1;
        m_credits -= 1;
        m_isPlayButtonPressed = false;
    }
    // START SEM DINHEIRO PARA JOGAR
    else if (m_isPlayButtonPressed && m_credits <= 0)
    {
        
    }
    //ADICIONAR +1 FICHA
    else if(m_isCreditsInButtonPressed)
    {
        m_credits += 1;
        m_creditsText.setString("Credits : " + std::to_string(m_credits));
        m_isCreditsInButtonPressed = false;

    }
    //CASH OUT
    else if(m_isCreditsOutButtonPressed)
    {
        m_credits = 0;
        m_creditsText.setString("Credits : " + std::to_string(m_credits));
        m_isCreditsOutButtonPressed = false;
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_creditsInButton);
    m_context->m_window->draw(m_creditsOutButton);
    m_context->m_window->draw(m_creditsText);
    m_context->m_window->draw(m_playedText);
    m_context->m_window->display();
}
