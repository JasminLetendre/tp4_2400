#include "SurfaceOrdreId.h"
#include "Element.h"
#include "ModeleOrthese.h"
#include "NuageElement.h"
#include <algorithm>
#include <memory>
#include <vector>
std::vector<std::shared_ptr<Surface>>
SurfaceOrdreId::createSurface(ModeleOrthese &modele) {

  std::vector<std::shared_ptr<Element>> allElements = modele.getElements();
  std::vector<std::shared_ptr<Surface>> surfaces;

  for (const auto &element : allElements) {
    auto nuage = std::dynamic_pointer_cast<NuageElement>(element);
    if (nuage) {

      std::vector<std::shared_ptr<Element>> enfants = nuage->getEnfants();

      if (enfants.empty())
        continue;

      std::sort(
          enfants.begin(), enfants.end(),
          [](const std::shared_ptr<Element> &a,
             const std::shared_ptr<Element> &b) { return a->id < b->id; });

      for (size_t i = 0; i < enfants.size() - 1; ++i) {
        int idA = enfants[i]->id;
        int idB = enfants[i + 1]->id;
        surfaces.push_back(std::make_shared<Surface>(idA, idB));
      }

      if (enfants.size() >= 2) {
        surfaces.push_back(
            std::make_shared<Surface>(enfants.back()->id, enfants.front()->id));
      }
    }
  }

  return surfaces;
}
