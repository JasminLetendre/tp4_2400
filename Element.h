#ifndef ELEMENT_H
#define ELEMENT_H

#include "PointComponent.h"
#include <vector>
#include <memory>
class Element {

public:
  virtual ~Element() = default;

  virtual void deplacer(int dx, int dy) = 0;
  virtual std::vector<std::shared_ptr<PointComponent>> collecterPoints() const = 0;

  int id;
};

#endif