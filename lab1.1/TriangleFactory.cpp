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
	sf::Vector2f defàultVectorPos(100, 100);
	sf::ConvexShape* triangle = new sf::ConvexShape();
	triangle->setFillColor(sf::Color::Cyan);
	triangle->setPosition(defàultVectorPos);
	triangle->setPointCount(3);
	triangle->setPoint(0, { m_vect1 });
	triangle->setPoint(1, { m_vect2 });
	triangle->setPoint(2, { m_vect3 });

	return new CTriangleDecorator(triangle);
}

CShapeDecorator* CTriangleFactory::createCertainDecorator(sf::Vector2f vect1, sf::Vector2f vect2, sf::Vector2f vect3)
{
	sf::Vector2f defàultVectorPos(100, 100);
	sf::ConvexShape* triangle = new sf::ConvexShape();
	triangle->setFillColor(sf::Color::Cyan);
	triangle->setPosition(defàultVectorPos);
	triangle->setPointCount(3);
	triangle->setPoint(0, { vect1 });
	triangle->setPoint(1, { vect2 });
	triangle->setPoint(2, { vect3 });

	return new CTriangleDecorator(triangle);
}

CTriangleFactory& CTriangleFactory::GetInstance()
{
	static CTriangleFactory singleton;
	return singleton;
}