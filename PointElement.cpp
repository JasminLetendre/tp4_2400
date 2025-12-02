#include "PointElement.h"
#include "PointTextureDecorator.h"

std::shared_ptr<PointComponent> PointElement::getPointComponent() const {
  return point;
}

PointElement::PointElement(std::shared_ptr<PointComponent> p, int id)
    : Element(id), point(p) {}

void PointElement::deplacer(int dx, int dy) {
  point->getX() = dx;
  point->getY() = dy;
}

std::vector<std::shared_ptr<PointComponent>> PointElement::collecterPoints() {
  std::vector<std::shared_ptr<PointComponent>> points;
  points.push_back(point);
  return points;
}

void PointElement::appliquerTexture(const std::string &symbole) {
  point = std::shared_ptr<PointComponent>(
      new PointTextureDecorator(point, symbole));
}

void PointElement::setPointComponent(std::shared_ptr<PointComponent> p) {
  point = p;
}