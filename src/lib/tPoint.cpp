#include "tPoint.h"

float tPoint::randFloat(float firstNum, float secondNum) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = secondNum - firstNum;
    float r = random * diff;
    return firstNum + r;
}

sf::Color tPoint::getColor() {
    return point.getFillColor();
    }

sf::Vector2f tPoint::getPosition() {
    return point.getPosition();
    }

sf::CircleShape tPoint::getDrawPoint() {
    return point;
    }

void tPoint::directMovmentPattern(int choice) {
    if (this->getPosition().x <= 10 || this->getPosition().x >= 590) {
      direction.x *= -1;
      if (choice == 4) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }

    if (this->getPosition().y <= 10 || this->getPosition().y >= 590) {
      direction.y *= -1;
      if (choice == 4) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }
    this->setPosition(this->getPosition().x + direction.x * moveSpeed,
        this->getPosition().y + direction.y * moveSpeed);
  }

void tPoint::randomMovmentPattern(int choice) {
    if (this->getPosition().y < 10) {
        float newAngle = -randFloat(225, 315) * M_PI/180;
      direction.x = cos(newAngle);
      direction.y = sin(newAngle);
      if (choice == 3) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }
    if (this->getPosition().y > 590) {
        float newAngle = -randFloat(45, 135) * M_PI/180;
      direction.x = cos(newAngle);
      direction.y = sin(newAngle);
      if (choice == 3) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }

    if (this->getPosition().x < 10) {
        float newAngle = randFloat(-45, 45) * M_PI/180;
      direction.x = cos(newAngle);
      direction.y = sin(newAngle);
      if (choice == 3) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }
    if (this->getPosition().x > 590) {
        float newAngle = randFloat(135, 225) * M_PI/180;
      direction.x = cos(newAngle);
      direction.y = sin(newAngle);
      if (choice == 3) {
          this->setColor(sf::Color(rand() % 255, rand() % 255, 
        rand() % 255));
      }
    }
    this->setPosition(this->getPosition().x + direction.x * moveSpeed,
        this->getPosition().y + direction.y * moveSpeed);
}

void tPoint::setPosition(float x, float y) {
    point.setPosition(sf::Vector2f(x, y));
    }

void tPoint::setColor(sf::Color color) {
    point.setFillColor(color);
    }

void tPoint::printCoord() {
    std::cout << point.getPosition().x << std::endl;
    std::cout << point.getPosition().y << std::endl;
}
