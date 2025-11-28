#ifndef ELEMENT_H
#define ELEMENT_H

#include "PointComponent.h"

class Element {

public:
  virtual ~Element() = default;

  virtual void deplacer(int dx, int dy) = 0;
  virtual std::vector<PointComponent*> collecterPoints() const = 0;

  int id;
};

#endif