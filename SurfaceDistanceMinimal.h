#ifndef SURFACEDISTANCEMINIMAL_H
#define SURFACEDISTANCEMINIMAL_H
#include "Surface.h"
#include "SurfaceCreationStrategy.h"

class SurfaceDistanceMinimal : public SurfaceCreationStrategy {
public:
  SurfaceDistanceMinimal() = default;
  std::vector<std::shared_ptr<Surface>>
  createSurface(ModeleOrthese &modele) override;
};
#endif