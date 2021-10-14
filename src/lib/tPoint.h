#ifndef T_POINT_H_
#define T_POINT_H_

#include <iomanip>
#include <iostream>
#include <cmath>
#include <random>

class tPoint {
    public:

    tPoint() {
        xCoord = 0;
        yCoord = 0;
    }

    tPoint(float xCoord, float yCoord) {
        setxCoord(xCoord);
        setyCoord(yCoord);
    }

    ~tPoint() {

    }

    float getxCoord();
    void setxCoord(float valueX);

    float getyCoord();
    void setyCoord(float valueY);

    void printCoord();

    private:
        float xCoord, yCoord;
};

#endif //  T_POINT_H_