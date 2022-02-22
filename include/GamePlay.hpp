#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <memory>
#include <array>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Game.hpp"
#include "State.hpp"
#include "Bolas.hpp"

class GamePlay : public Engine::State
{
    private:
        std::shared_ptr<Context> m_context;
        sf::Time m_elapsedTime;
        bool m_isPaused;

        //sf::CircleShape m_shape;
        std::vector<Bolas> m_bolas;
        int m_maxBolas;
        /* 
        std::vector<Bolas> m_bolas;
        int m_maxBolas;
        */
    public:
        GamePlay(std::shared_ptr<Context> &context);
        ~GamePlay();

        void spawnBolas();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
        void Pause() override;
        void Start() override;
};