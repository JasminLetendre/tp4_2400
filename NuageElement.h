#ifndef NUAGEELEMENT_H
#define NUAGEELEMENT_H

#include "PointComponent.h"
#include "Element.h"
#include <vector>

class NuageElement: public Element
{
private:
    char symboleTexture;
    std::vector<Element*> enfants;

public:
    NuageElement(std::vector<Element*> p, char symbole);
    std::vector<Element*> getEnfants() const;
    void AjouterEnfant(Element* e);
    void deplacer(int dx, int dy) override;
    PointComponent* collecterPoints() const override;
};

#endif
