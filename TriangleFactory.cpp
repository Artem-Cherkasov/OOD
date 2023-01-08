#include "stdafx.h"
#include "TriangleFactory.h"

CTriangleFactory::CTriangleFactory(const sf::Vector2f vect1, const sf::Vector2f vect2, const sf::Vector2f vect3)
    : m_vect1(vect1)
    , m_vect2(vect2)
    , m_vect3(vect3)
{
}

CShapeDecorator* CTriangleFactory::createDecorator() const
{
	sf::Vector2f def�ultVectorPos(100, 100);
	sf::ConvexShape* triangle = new sf::ConvexShape();
	triangle->setFillColor(sf::Color::Cyan);
	triangle->setPosition(def�ultVectorPos);
	triangle->setPointCount(3);
	triangle->setPoint(0, { m_vect1 });
	triangle->setPoint(1, { m_vect2 });
	triangle->setPoint(2, { m_vect3 });

	return new CTriangleDecorator(triangle);
}