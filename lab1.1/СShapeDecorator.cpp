#include "ÑShapeDecorator.h"

CShapeDecorator::CShapeDecorator(sf::Shape* shape)
{
	m_shape = shape;
}

sf::Shape* CShapeDecorator::GetShape()
{
	return m_shape;
}

void CShapeDecorator::Accept(Visitor* visitor)
{
	visitor->Visit(this);
}