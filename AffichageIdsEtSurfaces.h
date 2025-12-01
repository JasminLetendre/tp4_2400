#ifndef AFFICHAGEIDSETSURFACES_H
#define AFFICHAGEIDSETSURFACES_H
#include "AffichageStrategy.h"
#include <memory>

class ModeleOrthese;

class AffichageIdsEtSurfaces : public AffichageStrategy {
private:
    ModeleOrthese* modele;
public:
    AffichageIdsEtSurfaces(ModeleOrthese* modele) : AffichageStrategy(modele), modele(modele) {}
    void afficher() override;
};
#endif