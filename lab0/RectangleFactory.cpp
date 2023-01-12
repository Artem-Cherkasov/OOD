#include "stdafx.h"
#include "RectangleFactory.h"

CRectangleFactory::CRectangleFactory(const int pointA_x, const int pointA_y, const int pointB_x, const int pointB_y)
    : m_pointA_x(pointA_x)
    , m_pointA_y(pointA_y)
    , m_pointB_x(pointB_x)
    , m_pointB_y(pointB_y)
{
}

CShapeDecorator* CRectangleFactory::createDecorator() const
{
    sf::Vector2f sizeVector(m_pointB_x - m_pointA_x, m_pointB_y - m_pointA_y);
    sf::Vector2f positionVector((m_pointB_x + m_pointA_x) / 2, (m_pointA_y + m_pointB_y) / 2);
    sf::RectangleShape* rectangle = new sf::RectangleShape();
    rectangle->setSize(sizeVector);
    rectangle->setPosition(positionVector);
    rectangle->setFillColor(sf::Color::Red);

    return new CRectangleDecorator(rectangle, sizeVector);
};

CShapeDecorator* CRectangleFactory::createCertainDecorator(int x1, int y1, int x2, int y2)
{
    sf::Vector2f sizeVector(x2 - x1, y2 - y1);
    sf::Vector2f positionVector((x2 + x1) / 2, (y2 + y1) / 2);
    sf::RectangleShape* rectangle = new sf::RectangleShape();
    rectangle->setSize(sizeVector);
    rectangle->setPosition(positionVector);
    rectangle->setFillColor(sf::Color::Red);

    return new CRectangleDecorator(rectangle, sizeVector);
}

CRectangleFactory& CRectangleFactory::GetInstance()
{
    static CRectangleFactory singleton;
    return singleton;
}