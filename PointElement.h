#ifndef POINTELEMENT_H
#define POINTELEMENT_H

#include "PointComponent.h"
#include "Element.h"

class PointElement: public Element
{
private:
    PointComponent* point;

public:
    PointElement(PointComponent* p);
    PointComponent* getPointComponent() const;
    void deplacer(int dx, int dy) override;
    std::vector<PointComponent*> collecterPoints() const override;
};

#endif
