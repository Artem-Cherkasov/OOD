#pragma once
#include "CMovementDecorator.h"

class CCompound : public CMovementDecorator {
public:
	void Add(CMovementDecorator* figure);
	void SetPos(float x, float y) const override;
	void SetFillColor(sf::Color color) const override;
	void Draw(sf::RenderWindow& window) const override;
	sf::FloatRect GetGlobalBounds() const override;
	sf::Vector2f GetPosition() const override;
	std::vector<CMovementDecorator*> GetFigures() const;
private:
	std::vector<CMovementDecorator*> m_figures;
};