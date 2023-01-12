#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class CMovementDecorator
{
public:
	virtual void SetPos(float x, float y) const = 0;
	virtual void SetFillColor(sf::Color color) const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual sf::Vector2f GetPosition() const = 0;
	void SetMoved(bool isMoved);
	bool GetMoved() const;
private:
	bool m_isMoved;
};