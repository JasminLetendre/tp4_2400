#ifndef POINTELEMENT_H
#define POINTELEMENT_H

#include "PointComponent.h"

class PointElement: public Element
{
private:
    PointComponent* point;

public:
    PointElement(PointComponent* p);
    PointComponent* getPointComponent() const;
    void deplacer(int dx, int dy) override;
    PointComponent* collecterPoints() const override;
};

#endif
