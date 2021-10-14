#ifndef T_POINT_H_
#define T_POINT_H_

#include <iomanip>
#include <iostream>
#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

#define FIELD_BOARDS 10

class tPoint {
    public:

    tPoint()
      : tPoint(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    ~tPoint() {

    }

    sf::CircleShape getDrawPoint();

    void directMovmentPattern(int choice);
    void randomMovmentPattern(int choice);

    float randFloat(float firstNum, float secondNum);

    private:
        tPoint(float x, float y, sf::Color color) {
            point = sf::CircleShape(1);
            this->setPosition(x, y);
            this->setColor(color);
            float defaultDirection = randFloat(1, 4 * M_PI);
            direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
        }

        sf::Color getColor();
        sf::Vector2f getPosition();

        void printCoord();
        void setColor(sf::Color color);
        void setPosition(float x, float y);

        sf::CircleShape point;
        sf::Vector2f direction;
        float moveSpeed = 5;
        float defaultDirection;
};

#endif //  T_POINT_H_