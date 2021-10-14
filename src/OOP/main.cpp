#include <iostream>
#include <SFML/Graphics.hpp>
#include "../lib/dinamicArrTransformations.h"
#include "../lib/tPoint.h"

int main()
{
    tPoint point(10, 10);
    point.printCoord();

    sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 1. kychka-pc.ru");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		window.draw(shape);
		window.display();
	}

    std::cout << "First ex. - Dinamic Array\n";
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    printArray(arr, size);
    delete[] arr;
    std::cout << "\n";

    std::cout << "Second ex. - Dinamic Matrix\n";
    size = rand() % 10 + 1;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
}
