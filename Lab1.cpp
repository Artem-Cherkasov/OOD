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

	std::vector<CMovementDecorator*> shapes;
	std::vector<CShapeDecorator*> createdShapes;

	CRectangleFactory& rectangleFactory = CRectangleFactory::GetInstance();

	while (inputFile >> shape)
	{
		if (shape == circleShape)
		{
			int x, y, r;
			inputFile >> x >> y >> r;
			CCircleFactory* circleFactory = new CCircleFactory(x, y, r);
			createdShapes.push_back(circleFactory->createDecorator());
			/*sf::Vector2f vector(x, y);
			sf::CircleShape* circle = new sf::CircleShape(r);
			circle->setPosition(vector);
			circle->setFillColor(sf::Color::Green);
			window.draw(*circle);
			CCircleDecorator* circleType = new CCircleDecorator(circle, r);
			shapes.push_back(circleType);
			outputFile << circleType->GetDescription() << std::endl;*/
		}
		if (shape == rectangleShape)
		{
			int x1, y1, x2, y2;
			inputFile >> x1 >> y1 >> x2 >> y2;
			//CRectangleFactory& rectangleFactory = CRectangleFactory::GetInstance(x1, y1, x2, y2);
			//CRectangleFactory* rectangleFactory = new CRectangleFactory(x1, y1, x2, y2);
			createdShapes.push_back(rectangleFactory.createCertainDecorator(x1, y1, x2, y2));
			//window.draw(createdShapes.end())
			/*int x1, y1, x2, y2;
			inputFile >> x1 >> y1 >> x2 >> y2;
			sf::Vector2f sizeVector(x2 - x1, y2 - y1);
			sf::Vector2f positionVector((x1 + x2) / 2, (y1 + y2) / 2);
			sf::RectangleShape* rectangle = new sf::RectangleShape();
			rectangle->setSize(sizeVector);
			rectangle->setPosition(positionVector);
			rectangle->setFillColor(sf::Color::Red);
			window.draw(*rectangle);
			CRectangleDecorator* rectangleType = new CRectangleDecorator(rectangle, sizeVector);
			shapes.push_back(rectangleType);
			outputFile << rectangleType->GetDescription() << std::endl;*/
		}
		if (shape == triangleShape)
		{
			sf::Vector2f vector1, vector2, vector3;
			inputFile >> vector1.x >> vector1.y >> vector2.x >> vector2.y >> vector3.x >> vector3.y;
			CTriangleFactory* triangleFactory = new CTriangleFactory(vector1, vector2, vector3);
			createdShapes.push_back(triangleFactory->createDecorator());
			/*sf::ConvexShape* triangle = new sf::ConvexShape();
			triangle->setFillColor(sf::Color::Cyan);
			triangle->setPosition(defаultVectorPos);
			triangle->setPointCount(3);
			triangle->setPoint(0, { vector1 });
			triangle->setPoint(1, { vector2 });
			triangle->setPoint(2, { vector3 });
			window.draw(*triangle);
			CTriangleDecorator* triangleType = new CTriangleDecorator(triangle);
			shapes.push_back(triangleType);
			outputFile << triangleType->GetDescription() << std::endl;*/
		}
	}

	for (size_t i = 0; i < createdShapes.size(); i++)
	{
		window.draw(*createdShapes[i]->GetShape());
		outputFile << createdShapes[i]->GetDescription() << std::endl;
	}

	/*int index = -1;
	float dX = 0;
	float dY = 0;
	std::vector<CMovementDecorator*> selectedShapes;
	while (window.isOpen()) {
		sf::Vector2i pos = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				if (event.type == sf::Event::MouseButtonPressed)
					if (event.key.code == sf::Mouse::Left)
						for (size_t i = 0; i < shapes.size(); i++)
							if (shapes[i]->GetGlobalBounds().contains(pos.x, pos.y)) {
								shapes[i]->SetMoved(true);
								selectedShapes.push_back(shapes[i]);
							}
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left)
					for (size_t i = 0; i < shapes.size(); i++)
						if (shapes[i]->GetGlobalBounds().contains(pos.x, pos.y)) {
							if (shapes[i]->GetMoved()) {
								index = i;
								dX = pos.x - shapes[i]->GetPosition().x;
								dY = pos.y - shapes[i]->GetPosition().y;
							}
							else {
								index = i;
								shapes[i]->SetMoved(true);
								selectedShapes.clear();
								selectedShapes.push_back(shapes[i]);
								dX = pos.x - shapes[i]->GetPosition().x;
								dY = pos.y - shapes[i]->GetPosition().y;
								for (size_t j = 0; j < shapes.size(); j++)
									if (j != i)
										shapes[j]->SetMoved(false);
							}
						}
				
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
					if (!selectedShapes.empty()) {
						CCompound* compoundFigure = new CCompound();
						for (CMovementDecorator* figure : selectedShapes) {
							compoundFigure->Add(figure);
							std::vector<CMovementDecorator*>::iterator itShapes = find(shapes.begin(), shapes.end(), figure);
							if (itShapes != shapes.end())
								shapes.erase(itShapes);
						}
						selectedShapes.clear();
						index = -1;
						shapes.push_back(compoundFigure);
					}
				}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
					if (selectedShapes.size() == 1 && static_cast<CCompound*>(selectedShapes.front())) {
						CCompound* compoundFigure = dynamic_cast<CCompound*>(selectedShapes.front());
						std::vector<CMovementDecorator*> figures = compoundFigure->GetFigures();

						std::vector<CMovementDecorator*>::iterator itShapes = find(shapes.begin(), shapes.end(), compoundFigure);
						if (itShapes != shapes.end())
							shapes.erase(itShapes);
						for (CMovementDecorator* figure : figures) {
							shapes.push_back(figure);
						}
						selectedShapes.clear();
						index = -1;
					}
				}

			if (event.type == sf::Event::MouseButtonReleased)
				if (event.key.code == sf::Mouse::Left)
					index = -1;
		}

		if (index != -1 && shapes[index]->GetMoved())
			shapes[index]->SetPos(pos.x - dX, pos.y - dY);

		window.clear();
		for (size_t i = 0; i < shapes.size(); i++)
		{
			shapes[i]->Draw(window);
		}
		window.display();
	}*/

	window.display();
	sf::sleep(sf::seconds(5));

	return 0;
}
