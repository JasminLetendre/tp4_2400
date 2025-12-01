#include "SurfaceOrdreId.h"
#include "Element.h"
#include "ModeleOrthese.h"
#include <vector>
#include <memory>
#include <algorithm>
std::vector<std::shared_ptr<Surface>> SurfaceOrdreId::createSurface(ModeleOrthese& modele) {
    // Implementation of surface creation in order of ID
    std::vector<std::shared_ptr<Element>> elements = modele.getElements(); 

    std::vector<std::shared_ptr<Surface>> surfaces;

    // Sort elements by ID to ensure correct order
    std::sort(elements.begin(), elements.end(), 
              [](const std::shared_ptr<Element>& a, const std::shared_ptr<Element>& b) {
                  return a->id < b->id;
              });

    // Create surfaces between consecutive elements by ID
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        int idA = elements[i]->id;
        int idB = elements[i + 1]->id;
        surfaces.push_back(std::make_shared<Surface>(idA, idB));
    }
    
    // Close the shape by connecting last element to first
    if (elements.size() >= 2) {
        surfaces.push_back(std::make_shared<Surface>(elements.back()->id, elements.front()->id));
    }

    return surfaces;
}
