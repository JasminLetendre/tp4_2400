#ifndef SURFACECREATIONSTRATEGY_H
#define SURFACECREATIONSTRATEGY_H

class SurfaceCreationStrategy {
public:
    virtual void createSurface() = 0;
    virtual ~SurfaceCreationStrategy() = default;
};

#endif