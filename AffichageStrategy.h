#ifndef AFFICHAGESTRATEGY_H
#define AFFICHAGESTRATEGY_H

class ModeleOrthese;

class AffichageStrategy {
private:
    ModeleOrthese* modele;
public:
    AffichageStrategy(ModeleOrthese* modele) : modele(modele) {}
    virtual void afficher() = 0;
    virtual ~AffichageStrategy() = default;
};
#endif