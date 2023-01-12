#include "stdafx.h"
#include "CircleFactory.h"

CCircleFactory::CCircleFactory(const int x, const int y, const int r)
    : m_x(x)
    , m_y(y)
    , m_r(r)
{
}

CShapeDecorator* CCircleFactory::createDecorator() const
{
    sf::Vector2f vector(m_x, m_y);
    sf::CircleShape* circle = new sf::CircleShape(m_r);
    circle->setPosition(vector);
    circle->setFillColor(sf::Color::Green);

    return new CCircleDecorator(circle, m_r);
};