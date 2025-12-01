#ifndef SURFACECREATIONSTRATEGY_H
#define SURFACECREATIONSTRATEGY_H

#include <vector>
#include <memory>

class ModeleOrthese;
class Surface;
class SurfaceCreationStrategy {
public:
    virtual std::vector<std::shared_ptr<Surface>> createSurface(ModeleOrthese& modele) = 0;
    virtual ~SurfaceCreationStrategy() = default;
};

#endif