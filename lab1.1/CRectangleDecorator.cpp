#include "CRectangleDecorator.h"

int CRectangleDecorator::GetSquare() const
{
	return m_height * m_width;
}

int CRectangleDecorator::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

std::string CRectangleDecorator::GetDescription() const
{
	return "Rectangle Perimeter: " + std::to_string(GetPerimeter()) + " " + "Square: " + std::to_string(GetSquare());
}