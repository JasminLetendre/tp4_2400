#ifndef POINTTEXTUREDECORATOR_H
#define POINTTEXTUREDECORATOR_H

#include "PointComponent.h"
#include <string>
#include <memory>

class PointTextureDecorator : public PointComponent {
private:
    std::shared_ptr<PointComponent> wrappee;
    char texture;

public:
    PointTextureDecorator(std::shared_ptr<PointComponent> component, char tex);

    int& getX() const override;
    int& getY() const override;
    std::string getTextures() const override;
};

#endif