#include "tPoint.h"

float tPoint::randFloat(float firstNum, float secondNum) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = secondNum - firstNum;
    float r = random * diff;
    return firstNum + r;
}

sf::Color tPoint::getColor() {
    return shape->getFillColor();
    }

sf::Vector2f tPoint::getPosition() {
    return shape->getPosition();
    }

sf::Shape *tPoint::getDrawShape() {
    return shape;
    }

void tPoint::directMovmentPattern(int choice) {
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

 void tPoint::fireworksPattern(int choice) {
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

void tPoint::randomMovmentPattern(int choice) {
  if (shape->getPosition().y < 10) {
    float newAngle = -randFloat(225, 315) * M_PI/180;
    direction.x = cos(newAngle);
    direction.y = sin(newAngle);
    if (choice == 3 || choice == 5) {
      this->setColor(sf::Color(rand() % 255, rand() % 255, 
      rand() % 255));
    }
  }
  if (shape->getPosition().y > 590) {
    float newAngle = -randFloat(45, 135) * M_PI/180;
    direction.x = cos(newAngle);
    direction.y = sin(newAngle);
    if (choice == 3 || choice == 5) {
      this->setColor(sf::Color(rand() % 255, rand() % 255, 
      rand() % 255));
    }
  }

  if (shape->getPosition().x < 10) {
    float newAngle = randFloat(-45, 45) * M_PI/180;
    direction.x = cos(newAngle);
    direction.y = sin(newAngle);
    if (choice == 3 || choice == 5) {
      this->setColor(sf::Color(rand() % 255, rand() % 255, 
      rand() % 255));
    }
  }
  if (shape->getPosition().x > 590) {
    float newAngle = randFloat(135, 225) * M_PI/180;
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

void tPoint::rotateShape() {
  shape->rotate(moveSpeed);
}

void tPoint::setPosition() {
  shape->setPosition(x, y);
}

void tPoint::setColor(sf::Color color) {
  shape->setFillColor(color);
}

void tPoint::printCoord() {
  std::cout << shape->getPosition().x << std::endl;
  std::cout << shape->getPosition().y << std::endl;
}
