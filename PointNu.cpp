#include "PointNu.h"

PointNu::PointNu(int* xVal, int* yVal) : x(xVal), y(yVal) {}

int* PointNu::getX() const {
    return x; 
}

int* PointNu::getY() const {
    return y; 
}

std::string PointNu::getTextures() const {
    return ""; 
}