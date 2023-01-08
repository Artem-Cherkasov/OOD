#pragma once
#include "ÑShapeDecorator.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(sf::Shape* circle, int radius)
		:CShapeDecorator(circle)
	{
		m_radius = radius;
	}
	std::string GetDescription() const override;
	int GetPerimeter() const override;
	int GetSquare() const override;
private:
	int m_radius;
};