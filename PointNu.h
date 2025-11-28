#ifndef POINT_H
#define POINT_H

#include "PointComponent.h"
#include <string>


class PointNu : public PointComponent
{
private:
    int* x;
    int* y;

public:
    PointNu(int* x, int* y);

    int* getX() const override;
    int* getY() const override;
    std::string getTextures() const override;
};

#endif
