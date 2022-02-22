#pragma once

#include <SFML/System/Time.hpp>

namespace Engine
{
    class State
    {
        public:
            State(){};
            virtual ~State(){};

            
            virtual void Init() = 0;                     //init definicao dada por outras classes
            virtual void ProcessInput() = 0;             // vai lidar eventos de key press
            virtual void Update(sf::Time deltaTime) = 0; // metodo que lida com os inputs do ProcessInput e muda o estado da state, p.e. muda a pos das bolas.
                                                         //sf::Time -> esta porçao assegura que corre aos mesmos fps em todas as maq, infinitos loops no movimento, maquinas mais rapidas mais updates - faster
            virtual void Draw() = 0;

            virtual void Pause(){};     //Pause e Unpause
            virtual void Start(){};     //do pause menu
    };
}