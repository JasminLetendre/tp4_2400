#ifndef AFFICHAGESTRATEGY_H
#define AFFICHAGESTRATEGY_H
class AffichageStrategy {
public:
    virtual void afficher() = 0;
    virtual ~AffichageStrategy() = default;
};
#endif