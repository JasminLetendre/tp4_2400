#ifndef SURFACECREATIONSTRATEGY_H
#define SURFACECREATIONSTRATEGY_H

#include <vector>
class ModeleOrthese;
class Surface;
class SurfaceCreationStrategy {
public:
    virtual std::vector<Surface*> createSurface(ModeleOrthese& modele) = 0;
    virtual ~SurfaceCreationStrategy() = default;
};

#endif