#ifndef SURFACEDISTANCEMINIMAL_H
#define SURFACEDISTANCEMINIMAL_H
#include "SurfaceCreationStrategy.h"

class SurfaceDistanceMinimal : public SurfaceCreationStrategy {
public:
    void createSurface() override;
};
#endif