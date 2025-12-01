#include "SurfaceOrdreId.h"
#include "Element.h"
#include "NuageElement.h"
#include "ModeleOrthese.h"
#include <vector>
#include <memory>
#include <algorithm>
std::vector<std::shared_ptr<Surface>> SurfaceOrdreId::createSurface(ModeleOrthese& modele) {
    // Implementation of surface creation in order of ID (only for points in NuageElements)
    std::vector<std::shared_ptr<Element>> allElements = modele.getElements(); 
    std::vector<std::shared_ptr<Surface>> surfaces;

    // Process each NuageElement separately
    for (const auto& element : allElements) {
        auto nuage = std::dynamic_pointer_cast<NuageElement>(element);
        if (nuage) {
            // Get children of this nuage
            std::vector<std::shared_ptr<Element>> enfants = nuage->getEnfants();
            
            if (enfants.empty()) continue;

            // Sort children by ID to ensure correct order
            std::sort(enfants.begin(), enfants.end(), 
                      [](const std::shared_ptr<Element>& a, const std::shared_ptr<Element>& b) {
                          return a->id < b->id;
                      });

            // Create surfaces between consecutive elements by ID within this nuage
            for (size_t i = 0; i < enfants.size() - 1; ++i) {
                int idA = enfants[i]->id;
                int idB = enfants[i + 1]->id;
                surfaces.push_back(std::make_shared<Surface>(idA, idB));
            }
            
            // Close the shape by connecting last element to first within this nuage
            if (enfants.size() >= 2) {
                surfaces.push_back(std::make_shared<Surface>(enfants.back()->id, enfants.front()->id));
            }
        }
    }

    return surfaces;
}
