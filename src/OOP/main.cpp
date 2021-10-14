#include <iostream>
#include <SFML/Graphics.hpp>
#include "../lib/dinamicArrTransformations.h"
#include "../lib/tPoint.h"

int main() {
    std::cout << "Select a movement pattern" << std::endl;
    std::cout << "1. Random movement" << std::endl;
    std::cout << "2. Direct movement" << std::endl;
    std::cout << "3. Random movement with color change" << std::endl;
    std::cout << "4. Direct movement with color change" << std::endl;
    int choice = 0;
    std::cin >> choice;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Point moving");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
	srand(time(NULL));
    tPoint points[100];
    for (int i = 0; i < 100; i++) {
        points[i] = tPoint();
    }
    
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (int i = 0; i < 100; i++) {
      if(choice == 1) {
          points[i].randomMovmentPattern(choice);
       } else if (choice == 2) {
           points[i].directMovmentPattern(choice);
       } else if (choice == 3) {
           points[i].randomMovmentPattern(choice);
       } else if (choice == 4) {
           points[i].directMovmentPattern(choice);
       }
      window.draw(points[i].getDrawPoint());
    }
    window.display();
  }

  return 0;
}
