#ifndef AFFICHAGETEXTURES_H
#define AFFICHAGETEXTURES_H
#include "AffichageStrategy.h"
#include <memory>

class ModeleOrthese;

class AffichageTextures : public AffichageStrategy {
private:
  ModeleOrthese *modele;

public:
  AffichageTextures(ModeleOrthese *modele)
      : AffichageStrategy(modele), modele(modele) {}
  void afficher() override;
};
#endif