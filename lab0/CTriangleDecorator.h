#pragma once
#include "ÑShapeDecorator.h"

class CTriangleDecorator : public CShapeDecorator
{
public:
	CTriangleDecorator(sf::Shape* triangle)
		:CShapeDecorator(triangle)
	{
		point1 = triangle->getPoint(0);
		point2 = triangle->getPoint(1);
		point3 = triangle->getPoint(2);
		length1 = CalculateSideLength(point1, point2);
		length2 = CalculateSideLength(point1, point3);
		length3 = CalculateSideLength(point3, point2);
	}
	std::string GetDescription() const override;
	int GetPerimeter() const override;
	int GetSquare() const override;
private:
	sf::Vector2f point1;
	sf::Vector2f point2;
	sf::Vector2f point3;
	double length1;
	double length2;
	double length3;
	double CalculateSideLength(sf::Vector2f point1, sf::Vector2f point2);
};
