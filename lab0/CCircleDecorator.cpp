#define _USE_MATH_DEFINES
#include <cmath>
#include "CCircleDecorator.h"


int CCircleDecorator::GetPerimeter() const
{
	return M_PI * m_radius * 2;
}

int CCircleDecorator::GetSquare() const
{
	return M_PI * m_radius * m_radius;
}

std::string CCircleDecorator::GetDescription()const
{
	return "Circle Perimeter: " + std::to_string(GetPerimeter()) + " " + "Square: " + std::to_string(GetSquare());
}