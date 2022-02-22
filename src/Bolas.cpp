#include "Bolas.hpp"

void Bolas::initShape(const sf::RenderWindow& window)
{
    //Vai definir um raio aleatorio
    m_shape.setRadius(static_cast<float>(rand()%10+10));

    //Vai dar uma cor aleatoria
    m_shape.setFillColor(sf::Color(rand()%255+1, rand()%255+1, rand()%255+1, rand()%255+1));

    //Vai fazer spawn numa loc aleatoria
    m_shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand()% m_context->m_window->getSize().x - m_shape.getGlobalBounds().width),
            static_cast<float>(rand()% m_context->m_window->getSize().y - m_shape.getGlobalBounds().height)
        )
    );
}

Bolas::Bolas(const sf::RenderWindow& window)//std::shared_ptr<Context> &context) :m_context(context)
{
    Bolas::initShape(*m_context->m_window);//);
}

Bolas::~Bolas() {

}

const sf::CircleShape Bolas::getShape() const
{
    return m_shape;
}



/* void Bolas::draw(sf::RenderTarget &target)
{
    target.draw(m_shape);
} */

void Bolas::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_shape);
}
