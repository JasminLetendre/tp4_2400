#include "PointTextureDecorator.h"
#include <algorithm>
#include <string>

PointTextureDecorator::PointTextureDecorator(
    std::shared_ptr<PointComponent> component, std::string tex)
    : wrappee(component), texture(tex) {}

int &PointTextureDecorator::getX() const { return wrappee->getX(); }

int &PointTextureDecorator::getY() const { return wrappee->getY(); }

std::string PointTextureDecorator::getTextures() const {
  std::string allTextures = wrappee->getTextures() + texture;
  // Sort textures alphabetically for consistent display
  std::sort(allTextures.begin(), allTextures.end());
  return allTextures;
}

void PointTextureDecorator::addTexture(char symbole) { texture += symbole; }