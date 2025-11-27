#include "PointElement.h"

PointComponent* PointElement::getPointComponent() const {
    return point;
}

PointElement::PointElement(PointComponent* p) : point(p) {}

void PointElement::deplacer(int dx, int dy) {
    // TODO: PointComponent n'a rien qui permet de deplacer sans detruire et recreer a voir si on garde comme ca
}

PointComponent* PointElement::collecterPoints() const {
    return point;
}