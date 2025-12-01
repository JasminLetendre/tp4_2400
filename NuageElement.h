#ifndef NUAGEELEMENT_H
#define NUAGEELEMENT_H

#include "PointComponent.h"
#include "Element.h"
#include <vector>
#include <memory>
#include <string>

class NuageElement: public Element
{
private:
    std::string symboleTexture;
    std::vector<std::shared_ptr<Element>> enfants;

public:
    NuageElement(std::vector<std::shared_ptr<Element>> p, const std::string& symbole, int idNuage);
    std::vector<std::shared_ptr<Element>>& getEnfants();
    void AjouterEnfant(std::shared_ptr<Element> e);
    void deplacer(int dx, int dy) override;
    std::vector<std::shared_ptr<PointComponent>> collecterPoints() override;
};

#endif
