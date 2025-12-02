#ifndef SURFACEORDREID_H
#define SURFACEORDREID_H
#include "SurfaceCreationStrategy.h"

class SurfaceOrdreId : public SurfaceCreationStrategy {
public:
  SurfaceOrdreId() = default;
  std::vector<std::shared_ptr<Surface>>
  createSurface(ModeleOrthese &modele) override;
};
#endif