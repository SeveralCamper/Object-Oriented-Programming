#ifndef T_POINT_H_
#define T_POINT_H_

#include <iomanip>
#include <iostream>

class tPoint {
    public:

    float getxCoord() {
        return xCoord;
    }

    void setxCoord(float valueX) {
        xCoord = valueX;
    }

    float getyCoord() {
        return yCoord;
    }

    void setyCoord(float valueY) {
        yCoord = valueY;
    }

    tPoint(float valueX, float valueY) {
        setxCoord(valueX);
        setyCoord(valueY);
    }

    void printCoord() {
        std::cout << getxCoord() << std::endl;
        std::cout << getyCoord() << std::endl;
    }

    private:
        float xCoord, yCoord;
};

#endif //  T_POINT_H_