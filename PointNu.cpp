#include "PointNu.h"

PointNu::PointNu(int xVal, int yVal) : x(xVal), y(yVal) {}

int &PointNu::getX() const { return const_cast<int &>(x); }

int &PointNu::getY() const { return const_cast<int &>(y); }

std::string PointNu::getTextures() const { return ""; }

void PointNu::addTexture(char symbole) {
  // No-op for PointNu as it does not store textures
}