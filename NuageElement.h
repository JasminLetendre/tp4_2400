#ifndef NUAGEELEMENT_H
#define NUAGEELEMENT_H

#include "PointComponent.h"
#include "Element.h"
#include <vector>
#include <memory>

class NuageElement: public Element
{
private:
    char symboleTexture;
    std::vector<std::shared_ptr<Element>> enfants;

public:
    NuageElement(std::vector<std::shared_ptr<Element>> p, char symbole);
    std::vector<std::shared_ptr<Element>> getEnfants() const;
    void AjouterEnfant(std::shared_ptr<Element> e);
    void deplacer(int dx, int dy) override;
    std::vector<std::shared_ptr<PointComponent>> collecterPoints() const override;
};

#endif
