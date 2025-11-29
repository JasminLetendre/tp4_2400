#include "PointTextureDecorator.h"

PointTextureDecorator::PointTextureDecorator(std::shared_ptr<PointComponent> component, char tex) : wrappee(component), texture(tex) {}

int& PointTextureDecorator::getX() const {
    return wrappee->getX();
}

int& PointTextureDecorator::getY() const {
    return wrappee->getY();
}

std::string PointTextureDecorator::getTextures() const {
    std::string baseTextures = wrappee->getTextures();
    return baseTextures + texture;
}