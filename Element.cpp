#include "Element.h"

void Element::deplacer(int dx, int dy) {
}

std::vector<std::shared_ptr<PointComponent>> Element::collecterPoints() {
    static std::vector<std::shared_ptr<PointComponent>> points;
    return points;
}