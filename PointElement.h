#ifndef POINTELEMENT_H
#define POINTELEMENT_H

#include "PointComponent.h"
#include "Element.h"
#include <memory>

class PointElement: public Element
{
private:
    std::shared_ptr<PointComponent> point;

public:
    PointElement(std::shared_ptr<PointComponent> p);
    std::shared_ptr<PointComponent> getPointComponent() const;
    void deplacer(int dx, int dy) override;
    std::vector<std::shared_ptr<PointComponent>> collecterPoints() const override;
};

#endif
