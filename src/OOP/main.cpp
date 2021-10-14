#include <iostream>
#include <SFML/Graphics.hpp>
#include "../lib/dinamicArrTransformations.h"
#include "../lib/tPoint.h"

int main() {
    std::cout << "Select a motion pattern" << std::endl;
    std::cout << "1. Direct motion" << std::endl;
    std::cout << "2. Random motion" << std::endl;
    std::cout << "3. Direct motion with random color change" << std::endl;
    std::cout << "4. Random motion with random color change" << std::endl;
    int choice = 0;
    std::cin >> choice;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Random Point moving");
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
          points[i].directMovmentPattern();
       } else if (choice == 0) {
           points[i].randomMovmentPattern();
       }
      window.draw(points[i].getDrawPoint());
    }
    window.display();
  }

  return 0;
}
