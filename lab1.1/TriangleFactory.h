#pragma once
#include "ShapeFactory.h"
#include "ÑShapeDecorator.h"
#include "CTriangleDecorator.h"

class CTriangleFactory : public CShapeFactory
{
public:
    
    static CTriangleFactory& GetInstance();
    CShapeDecorator* createDecorator() const override;
    CShapeDecorator* createCertainDecorator(sf::Vector2f vect1, sf::Vector2f vect2, sf::Vector2f vect3);

private:
    const sf::Vector2f m_vect1;
    const sf::Vector2f m_vect2;
    const sf::Vector2f m_vect3;
    CTriangleFactory(const sf::Vector2f vect1, const sf::Vector2f vect2, const sf::Vector2f vect3);
    CTriangleFactory() {};
    CTriangleFactory(const CTriangleFactory&) {};
    CTriangleFactory& operator=(CTriangleFactory&) {};
};