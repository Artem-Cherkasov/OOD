#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "CMovementDecorator.h"
#include "stdafx.h"

class CShapeDecorator : public CMovementDecorator
{
public:
	CShapeDecorator(sf::Shape* shape);
	virtual std::string GetDescription() const = 0;
	virtual int GetPerimeter() const = 0;
	virtual int GetSquare() const = 0;
	sf::Shape* GetShape();
	void SetPos(float x, float y) const override;
	void SetFillColor(sf::Color color) const override;
	void Draw(sf::RenderWindow& window) const override;
	sf::FloatRect GetGlobalBounds() const override;
	sf::Vector2f GetPosition() const override;

private:
	sf::Shape* m_shape;
};
