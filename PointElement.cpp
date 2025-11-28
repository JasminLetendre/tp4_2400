#include "PointElement.h"

PointComponent* PointElement::getPointComponent() const {
    return point;
}

PointElement::PointElement(PointComponent* p) : point(p) {}

void PointElement::deplacer(int dx, int dy) {
    // Regarder si sa va fonctionner
    *getPointComponent()->getX() += dx;
    *getPointComponent()->getY() += dy;
}

PointComponent* PointElement::collecterPoints() const {
    return nullptr;
}