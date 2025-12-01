#ifndef POINTTEXTUREDECORATOR_H
#define POINTTEXTUREDECORATOR_H

#include "PointComponent.h"
#include <string>
#include <memory>

class PointTextureDecorator : public PointComponent {
private:
    std::shared_ptr<PointComponent> wrappee;
    std::string texture = "";

public:
    PointTextureDecorator(std::shared_ptr<PointComponent> component, std::string tex);

    int& getX() const override;
    int& getY() const override;
    std::string getTextures() const override;
    void addTexture(char symbole) override;
};

#endif