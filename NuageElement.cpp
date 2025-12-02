#include "NuageElement.h"
#include <memory>
#include <string>
#include <vector>

std::vector<std::shared_ptr<Element>> &NuageElement::getEnfants() {
  return enfants;
}

NuageElement::NuageElement(std::vector<std::shared_ptr<Element>> p,
                           const std::string &symbole, int idNuage)
    : Element(idNuage), symboleTexture(symbole), enfants(p) {}

void NuageElement::AjouterEnfant(std::shared_ptr<Element> e) {
  enfants.push_back(e);
}

void NuageElement::deplacer(int dx, int dy) {
  for (const auto &enfant : enfants) {
    enfant->deplacer(dx, dy);
  }
}

std::vector<std::shared_ptr<PointComponent>> NuageElement::collecterPoints() {
  std::vector<std::shared_ptr<PointComponent>> points;

  for (const auto &enfant : enfants) {
    auto enfantPoints = enfant->collecterPoints();
    points.insert(points.end(), enfantPoints.begin(), enfantPoints.end());
  }

  return points;
}

void NuageElement::appliquerTexture(const std::string &symbole) {
  for (auto &enfant : enfants) {
    enfant->appliquerTexture(symbole);
  }
}
