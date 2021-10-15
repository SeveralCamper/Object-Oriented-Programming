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
    virtual void directMovmentPattern(int choice);
    void randomMovmentPattern(int choice);

    protected:
        float randFloat(float firstNum, float secondNum);

        tPoint(float x, float y, sf::Color color) {
            shape = new sf::CircleShape(5);
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

    void directMovmentPattern(int choice) override {
        if (shape->getPosition().y < 10) {
            float newAngle = -randFloat(215, 325) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        if (shape->getPosition().y > 590) {
            float newAngle = -randFloat(35, 145) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }

        if (shape->getPosition().x < 10) {
            float newAngle = randFloat(-35, 35) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        if (shape->getPosition().x > 590) {
            float newAngle = randFloat(125, 245) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        shape->setPosition(this->getPosition().x + direction.x * moveSpeed,
            this->getPosition().y + direction.y * moveSpeed); 
        }

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

    void directMovmentPattern(int choice) override {
        if (shape->getPosition().x <= 10 || shape->getPosition().x >= 590) {
            direction.x *= -1;
            if (choice == 4 || choice == 5) {
                this->setColor(sf::Color(rand() % 255, rand() % 255, 
                rand() % 255));
                }
            }

            if (shape->getPosition().y <= 10 || shape->getPosition().y >= 590) {
            direction.y *= -1;
            if (choice == 4 || choice == 5) {
                this->setColor(sf::Color(rand() % 255, rand() % 255, 
                rand() % 255));
                }
            }
            shape->setPosition(this->getPosition().x + direction.x * moveSpeed,
                this->getPosition().y + direction.y * moveSpeed);
            shape->setOrigin(shape->getPosition().x - 275, shape->getPosition().y - 275);
            shape->rotate(2);       
        }

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

    void directMovmentPattern(int choice) override {
        if (shape->getPosition().y < 10) {
            float newAngle = -randFloat(215, 325) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        if (shape->getPosition().y > 590) {
            float newAngle = -randFloat(35, 145) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }

        if (shape->getPosition().x < 10) {
            float newAngle = randFloat(-35, 35) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        if (shape->getPosition().x > 590) {
            float newAngle = randFloat(125, 245) * M_PI/180;
            direction.x = cos(newAngle);
            direction.y = sin(newAngle);
            if (choice == 3 || choice == 5) {
            this->setColor(sf::Color(rand() % 255, rand() % 255, 
            rand() % 255));
            }
        }
        shape->setPosition(this->getPosition().x + direction.x * moveSpeed,
            this->getPosition().y + direction.y * moveSpeed);   
    }

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

    void directMovmentPattern(int choice) override {
        if (shape->getPosition().x <= 10 || shape->getPosition().x >= 590) {
            direction.x *= -1;
            if (choice == 4 || choice == 5) {
                this->setColor(sf::Color(rand() % 255, rand() % 255, 
                rand() % 255));
                }
            }

            if (shape->getPosition().y <= 10 || shape->getPosition().y >= 590) {
            direction.y *= -1;
            if (choice == 4 || choice == 5) {
                this->setColor(sf::Color(rand() % 255, rand() % 255, 
                rand() % 255));
                }
            }
            shape->setPosition(this->getPosition().x + direction.x * moveSpeed,
                this->getPosition().y + direction.y * moveSpeed);
            shape->setOrigin(shape->getPosition().x - 275, shape->getPosition().y - 275);
            shape->rotate(2);       
        }

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
