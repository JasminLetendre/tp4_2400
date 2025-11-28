#ifndef SURFACEDISTANCEMINIMAL_H
#define SURFACEDISTANCEMINIMAL_H
#include "Surface.h"
#include "SurfaceCreationStrategy.h"

class SurfaceDistanceMinimal : public SurfaceCreationStrategy {
public:
    std::vector<Surface*> createSurface(ModeleOrthese& modele) override;
};
#endif