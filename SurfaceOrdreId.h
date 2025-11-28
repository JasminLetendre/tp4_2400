#ifndef SURFACEORDREID_H
#define SURFACEORDREID_H
#include "SurfaceCreationStrategy.h"


class SurfaceOrdreId : public SurfaceCreationStrategy {
public:
    std::vector<Surface*> createSurface(ModeleOrthese& modele) override;
};
#endif