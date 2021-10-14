#include "tPoint.h"
#include <SFML/Graphics.hpp>

float tPoint::getxCoord() {
        return xCoord;
    }

void tPoint::setxCoord(float xCoord) {
    this->xCoord = xCoord;
}

float tPoint::getyCoord() {
    return yCoord;
}

void tPoint::setyCoord(float yCoord) {
    this->yCoord = yCoord;
}

void tPoint::printCoord() {
    std::cout << getxCoord() << std::endl;
    std::cout << getyCoord() << std::endl;
}