#ifndef ELEMENT_H
#define ELEMENT_H

#include "PointComponent.h"

class Element {
protected:
    int id;

public:
    virtual ~Element() = default;
    
    virtual void deplacer(int dx, int dy) = 0;
    virtual PointComponent* collecterPoints() = 0;
};

#endif