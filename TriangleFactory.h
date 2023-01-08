#pragma once
#include "ShapeFactory.h"
#include "ÑShapeDecorator.h"
#include "CTriangleDecorator.h"

class CTriangleFactory : public CShapeFactory
{
public:
    CTriangleFactory(const sf::Vector2f vect1, const sf::Vector2f vect2, const sf::Vector2f vect3);

    CShapeDecorator* createDecorator() const override;

private:
    const sf::Vector2f m_vect1;
    const sf::Vector2f m_vect2;
    const sf::Vector2f m_vect3;
};