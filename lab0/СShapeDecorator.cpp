#include "ÑShapeDecorator.h"

CShapeDecorator::CShapeDecorator(sf::Shape* shape)
{
	m_shape = shape;
}

sf::Shape* CShapeDecorator::GetShape()
{
	return m_shape;
}

void CShapeDecorator::SetFillColor(sf::Color color) const {
	m_shape->setFillColor(color);
}

void CShapeDecorator::SetPos(float x, float y) const {
	m_shape->setPosition(x, y);
}

void CShapeDecorator::Draw(sf::RenderWindow& window) const {
	if (GetMoved()) {
		sf::FloatRect globalBounds = GetGlobalBounds();
		sf::RectangleShape frame;
		frame.setSize(sf::Vector2f(globalBounds.width, globalBounds.height));
		frame.setPosition(sf::Vector2f(globalBounds.left, globalBounds.top));
		frame.setFillColor(sf::Color(0, 0, 0, 0));
		frame.setOutlineThickness(1);
		frame.setOutlineColor(sf::Color::White);
		window.draw(frame);
		window.draw(*m_shape);
	}
	else
		window.draw(*m_shape);
}

sf::FloatRect CShapeDecorator::GetGlobalBounds() const {
	return m_shape->getGlobalBounds();
}

sf::Vector2f CShapeDecorator::GetPosition() const {
	return m_shape->getPosition();
}