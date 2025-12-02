#ifndef ELEMENT_H
#define ELEMENT_H

#include "PointComponent.h"
#include <memory>
#include <vector>
class Element {
public:
  Element(int id) : id(id) {}
  virtual ~Element() = default;

  virtual void deplacer(int dx, int dy) = 0;
  virtual std::vector<std::shared_ptr<PointComponent>> collecterPoints() = 0;
  virtual void appliquerTexture(const std::string &symbole) = 0;

  int id;
};

#endif