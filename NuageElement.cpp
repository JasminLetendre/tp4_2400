#include "NuageElement.h"

std::vector<Element*> NuageElement::getEnfants() const {
    return enfants;
}

NuageElement::NuageElement(std::vector<Element*> p, char symbole) : symboleTexture(symbole), enfants(p) {}

void NuageElement::AjouterEnfant(Element* e) {
    enfants.push_back(e);
}

void NuageElement::deplacer(int dx, int dy) {
    for (Element* enfant : enfants) {
        enfant->deplacer(dx, dy);
    }
}

PointComponent* NuageElement::collecterPoints() const {
    // TODO: 
}