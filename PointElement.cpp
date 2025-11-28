#include "PointElement.h"

PointComponent* PointElement::getPointComponent() const {
    return point;
}

PointElement::PointElement(PointComponent* p) : point(p) {}

void PointElement::deplacer(int dx, int dy) {
    *getPointComponent()->getX() += dx;
    *getPointComponent()->getY() += dy;
}

std::vector<PointComponent*> PointElement::collecterPoints() const {
    return {getPointComponent()};
}