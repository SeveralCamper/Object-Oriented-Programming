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

    sf::Shape *getDrawShape();
    
    void setPosition();
    void directMovmentPattern(int choice);
    void randomMovmentPattern(int choice);

    float randFloat(float firstNum, float secondNum);

    protected:
        tPoint(float x, float y, sf::Color color) {
            shape = new sf::CircleShape(2);
            this->setColor(color);
            shape->setPosition(x, y);
            float defaultDirection = randFloat(1, 4 * M_PI);
            direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
        }

        sf::Color getColor();
        sf::Vector2f getPosition();

        void printCoord();
        void setColor(sf::Color color);

        sf::Color color;
        sf::Shape *shape;
        sf::Vector2f direction;

        float x, y;
        float moveSpeed = 5;
        float defaultDirection;
};

class tCircle : public tPoint {
    public:

    tCircle() {
        shape = new sf::CircleShape(50);
        shape->setFillColor(color);
    }

    private:
};

class tTriangle : public tPoint {
    public:

    tTriangle() {
        shape = new sf::CircleShape(100,3);
		shape->setFillColor(color);
    }

    private:
};

class tRectangle : public tPoint {
    public:

    tRectangle() {
        shape = new sf::RectangleShape(sf::Vector2f(120, 50));
		shape->setOrigin(shape->getPosition().x + 60, shape->getPosition().y + 25);
		shape->setFillColor(color);
    }

    private:
};

class tEllips : public tPoint {
    public:

    tEllips() {
        shape = new sf::CircleShape(50);
		shape->setFillColor(color);
		shape->setOrigin(shape->getPosition().x + 50, shape->getPosition().y + 50);
		shape->setScale(2, 1);
    }

    private:
};

class tLine : public tPoint {
    public:

    tLine() {
        shape = new sf::RectangleShape(sf::Vector2f(120, 6));
		shape->setFillColor(color);
		shape->setOrigin(shape->getPosition().x + 60, shape->getPosition().y+3);
    }

    private:
};

class tRomb : public tPoint {
    public:

    tRomb() {
        shape = new sf::CircleShape(50, 4);
		shape->setFillColor(color);
		shape->setOrigin(shape->getPosition().x + 25, shape->getPosition().y + 2);
		shape->setScale(2, 1);
    }

    private:
};



#endif //  T_POINT_H_