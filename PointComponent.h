#ifndef POINTCOMPONENT_H
#define POINTCOMPONENT_H

#include <string>

class PointComponent {
public:
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual std::string getTextures() const = 0;

    virtual ~PointComponent() = default;
};

#endif