#ifndef POINTTEXTUREDECORATOR_H
#define POINTTEXTUREDECORATOR_H

#include "PointComponent.h"
#include <string>

class PointTextureDecorator : public PointComponent {
private:
    PointComponent* wrappee;
    char texture;

public:
    PointTextureDecorator(PointComponent* component, char tex);

    int getX() const override;
    int getY() const override;
    std::string getTextures() const override;
};

#endif