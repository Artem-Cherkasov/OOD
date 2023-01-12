#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Visitor.h"
#include "stdafx.h"

class CShapeDecorator
{
public:
	CShapeDecorator(sf::Shape* shape);
	virtual std::string GetDescription() const = 0;
	virtual int GetPerimeter() const = 0;
	virtual int GetSquare() const = 0;
	virtual void Accept(Visitor* visitor);
	sf::Shape* GetShape();

private:
	sf::Shape* m_shape;
};
