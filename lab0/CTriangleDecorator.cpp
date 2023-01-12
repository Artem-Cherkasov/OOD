#include "CTriangleDecorator.h"

double CTriangleDecorator::CalculateSideLength(sf::Vector2f pointA, sf::Vector2f pointB)
{
	return (double(sqrt((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y))));
}

int CTriangleDecorator::GetPerimeter() const
{
	return int(length1 + length2 + length3);
}

int CTriangleDecorator::GetSquare() const
{
	return int(0.5 * abs(((point2.x - point1.x) * (point3.y - point1.y)) - ((point3.x - point1.x) * (point2.y - point1.y))));
}

std::string CTriangleDecorator::GetDescription()const
{
	return "Triangle Perimeter: " + std::to_string(GetPerimeter()) + " " + "Square: " + std::to_string(GetSquare());
}