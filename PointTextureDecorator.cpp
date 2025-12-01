#include "PointTextureDecorator.h"
#include <string>

PointTextureDecorator::PointTextureDecorator(std::shared_ptr<PointComponent> component, std::string tex) : wrappee(component), texture(tex) {}

int& PointTextureDecorator::getX() const {
    return wrappee->getX();
}

int& PointTextureDecorator::getY() const {
    return wrappee->getY();
}

std::string PointTextureDecorator::getTextures() const {
    return texture;
}

void PointTextureDecorator::addTexture(char symbole) {
    texture += symbole;
}