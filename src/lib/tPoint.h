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
    void rotateShape();
     void fireworksPattern(int choice);
    void directMovmentPattern(int choice);
    void randomMovmentPattern(int choice);

    protected:
        float randFloat(float firstNum, float secondNum);

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

    tCircle()
      : tCircle(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tCircle(float x, float y, sf::Color color) {
        shape = new sf::CircleShape(50);
        shape->setPosition(x, y);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

class tTriangle : public tPoint {
    public:

    tTriangle()
      : tTriangle(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tTriangle(float x, float y, sf::Color color) {
        shape = new sf::CircleShape(100,3);
        shape->setOrigin(shape->getPosition().x + 100, shape->getPosition().y + 100);
        shape->setPosition(x, y);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

class tRectangle : public tPoint {
    public:

    tRectangle()
      : tRectangle(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tRectangle(float x, float y, sf::Color color) {
        shape = new sf::RectangleShape(sf::Vector2f(120, 50));
        shape->setOrigin(shape->getPosition().x + 60, shape->getPosition().y + 25);
        shape->setPosition(x, y);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

class tEllips : public tPoint {
    public:

    tEllips()
      : tEllips(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tEllips(float x, float y, sf::Color color) {
        shape = new sf::CircleShape(50);
        shape->setOrigin(shape->getPosition().x + 50, shape->getPosition().y + 50);
        shape->setPosition(x, y);
        shape->setScale(2, 1);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

class tLine : public tPoint {
    public:

    tLine()
      : tLine(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tLine(float x, float y, sf::Color color) {
        shape = new sf::RectangleShape(sf::Vector2f(140, 8));
        shape->setOrigin(shape->getPosition().x + 70, shape->getPosition().y + 4);
        shape->setPosition(x, y);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

class tRomb : public tPoint {
    public:

    tRomb()
      : tRomb(rand() % 550 + FIELD_BOARDS, rand() % 550 + FIELD_BOARDS, sf::Color(rand() % 255, rand() % 255, 
        rand() % 255)){};

    private:

    tRomb(float x, float y, sf::Color color) {
        shape = new sf::CircleShape(60, 4);
        shape->setOrigin(shape->getPosition().x + 30, shape->getPosition().y + 2);
        shape->setPosition(x, y);
        this->setColor(color);
        float defaultDirection = randFloat(1, 4 * M_PI);
        direction = sf::Vector2f(cos(defaultDirection), sin(defaultDirection));
    }
};

#endif //  T_POINT_H_
