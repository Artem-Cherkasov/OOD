#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CCompound.h"
#include "CMovementDecorator.h"
#include "RectangleFactory.h"
#include "CircleFactory.h"
#include "TriangleFactory.h"
#include "DescriptionGetterVisitor.h"

const std::string circleShape = "CIRCLE";
const std::string rectangleShape = "RECTANGLE";
const std::string triangleShape = "TRIANGLE";

const int windowWidth = 1000;
const int windowHeight = 800;
const sf::Vector2f defаultVectorPos(100, 100);

const std::string inputFileOpenError = "Failed to open input file";
const std::string outputFileOpenError = "Failed to open output file";

int main()
{
    std::ifstream inputFile("input.txt");
	if (!inputFile.is_open())
	{
		std::cout << inputFileOpenError;
		return 1;
	}

	std::ofstream outputFile("output.txt");
	if (!outputFile.flush())
	{
		std::cout << outputFileOpenError;
		return 1;
	}

	std::string shape;
	sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), "Lab_1");
	window.clear();

	std::vector<CShapeDecorator*> createdShapes;

	CRectangleFactory& rectangleFactory = CRectangleFactory::GetInstance();
	CCircleFactory& circleFactory = CCircleFactory::GetInstance();
	CTriangleFactory& triangleFactory = CTriangleFactory::GetInstance();

	while (inputFile >> shape)
	{
		if (shape == circleShape)
		{
			int x, y, r;
			inputFile >> x >> y >> r;
			createdShapes.push_back(circleFactory.createCertainDecorator(x, y, r));
		}
		if (shape == rectangleShape)
		{
			int x1, y1, x2, y2;
			inputFile >> x1 >> y1 >> x2 >> y2;
			createdShapes.push_back(rectangleFactory.createCertainDecorator(x1, y1, x2, y2));
		}
		if (shape == triangleShape)
		{
			sf::Vector2f vector1, vector2, vector3;
			inputFile >> vector1.x >> vector1.y >> vector2.x >> vector2.y >> vector3.x >> vector3.y;
			createdShapes.push_back(triangleFactory.createCertainDecorator(vector1, vector2, vector3));
		}
	}

	for (size_t i = 0; i < createdShapes.size(); i++)
	{
		window.draw(*createdShapes[i]->GetShape());
		DescriptionGetterVisitor visitor(outputFile);
		createdShapes[i]->Accept(&visitor);
	}

	window.display();
	sf::sleep(sf::seconds(5));

	return 0;
}
