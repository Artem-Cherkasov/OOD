#include "CCompound.h"

void CCompound::Add(CMovementDecorator* figure) {
	auto figureLocal = figure;
	figureLocal->SetMoved(false);
	m_figures.push_back(figureLocal);
}

sf::FloatRect CCompound::GetGlobalBounds() const {
	auto defaultFrame = m_figures.at(0)->GetGlobalBounds();
	sf::Vector2f minPoint;
	minPoint.x = defaultFrame.left;
	minPoint.y = defaultFrame.top;

	sf::Vector2f maxPoint;
	maxPoint.x = defaultFrame.left + defaultFrame.width;
	maxPoint.y = defaultFrame.top + defaultFrame.height;

	for (CMovementDecorator* figure : m_figures) {
		auto localFrame = figure->GetGlobalBounds();

		if (localFrame.left < minPoint.x)
			minPoint.x = localFrame.left;
		if (localFrame.top < minPoint.y)
			minPoint.y = localFrame.top;
		if (localFrame.left + localFrame.width > maxPoint.x)
			maxPoint.x = localFrame.left + localFrame.width;
		if (localFrame.top + localFrame.height > maxPoint.y)
			maxPoint.y = localFrame.top + localFrame.height;
	}

	return sf::FloatRect(minPoint.x, minPoint.y, abs(maxPoint.x - minPoint.x), abs(maxPoint.y - minPoint.y));
}

sf::Vector2f CCompound::GetPosition() const {
	auto globalBounds = GetGlobalBounds();

	return sf::Vector2f(globalBounds.left, globalBounds.top);
}

void CCompound::SetPos(float x, float y) const {
	sf::Vector2f d;
	d.x = x - GetPosition().x;
	d.y = y - GetPosition().y;

	for (CMovementDecorator* figure : m_figures)
		figure->SetPos(figure->GetPosition().x + d.x, figure->GetPosition().y + d.y);
}

void CCompound::SetFillColor(sf::Color color) const {
	for (CMovementDecorator* figure : m_figures)
		figure->SetFillColor(color);
}

void CCompound::Draw(sf::RenderWindow& window) const {
	if (GetMoved()) {
		sf::FloatRect globalBounds = GetGlobalBounds();
		sf::RectangleShape frame;
		frame.setSize(sf::Vector2f(globalBounds.width, globalBounds.height));
		frame.setPosition(sf::Vector2f(globalBounds.left, globalBounds.top));
		frame.setFillColor(sf::Color(0, 0, 0, 0));
		frame.setOutlineThickness(1);
		frame.setOutlineColor(sf::Color::White);
		window.draw(frame);
		for (CMovementDecorator* figure : m_figures)
			figure->Draw(window);
	}
	else
		for (CMovementDecorator* figure : m_figures)
			figure->Draw(window);
}

std::vector<CMovementDecorator*> CCompound::GetFigures() const {
	return m_figures;
}