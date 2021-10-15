#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "../lib/systemFunc.h"
#include "../lib/tPoint.h"

int main() {
    std::cout << "branch" << std::endl;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Point moving");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    srand(time(NULL));

    tPoint **shapes = new tPoint *[7];
    shapes[0] = new tTriangle();
    shapes[1] = new tLine();
    shapes[2] = new tEllips();
    shapes[3] = new tRectangle();
    shapes[4] = new tPoint();
    shapes[5] = new tRomb();
    shapes[6] = new tCircle();
                
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int i = 0; i < 7; i++) {
        shapes[i]->directMovmentPattern(5);
        shapes[i]->directMovmentPattern(5);
        }

        for (int i = 0; i < 7; i++) {
        window.draw(*shapes[i]->getDrawShape());
        }
            
        window.display();
        }
  return 0;
}
