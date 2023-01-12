#pragma once
#include "ÑShapeDecorator.h"

class CRectangleDecorator : public CShapeDecorator
{
public:
	CRectangleDecorator(sf::Shape* rectangle, sf::Vector2f sizeVector)
		: CShapeDecorator(rectangle)
	{
		m_height = int(sizeVector.y);
		m_width = int(sizeVector.x);
	}
	std::string GetDescription() const override;
	int GetPerimeter() const override;
	int GetSquare() const override;
private:
	int m_height;
	int m_width;
};