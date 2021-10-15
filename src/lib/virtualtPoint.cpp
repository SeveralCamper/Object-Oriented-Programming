#include "virtualtPoint.h"

float tPoint1::randFloat(float firstNum, float secondNum) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = secondNum - firstNum;
    float r = random * diff;
    return firstNum + r;
}

sf::Color tPoint1::getColor() {
    return shape->getFillColor();
    }

sf::Vector2f tPoint1::getPosition() {
    return shape->getPosition();
    }

sf::Shape *tPoint1::getDrawShape() {
    return shape;
    }

void tPoint1::directMovmentPattern(int choice) {
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
  }

void tPoint1::rotateShape() {
  shape->rotate(moveSpeed);
}

void tPoint1::setPosition() {
  shape->setPosition(x, y);
}

void tPoint1::setColor(sf::Color color) {
  shape->setFillColor(color);
}

void tPoint1::printCoord() {
  std::cout << shape->getPosition().x << std::endl;
  std::cout << shape->getPosition().y << std::endl;
}
