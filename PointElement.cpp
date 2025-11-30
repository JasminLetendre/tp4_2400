#include "PointElement.h"

std::shared_ptr<PointComponent> PointElement::getPointComponent() const {
    return point;
}

PointElement::PointElement(std::shared_ptr<PointComponent> p) : point(p) {}

void PointElement::deplacer(int dx, int dy) {
    point->getX() = dx;
    point->getY() = dy;
}

std::vector<std::shared_ptr<PointComponent>> PointElement::collecterPoints() const {
    return {point};
}