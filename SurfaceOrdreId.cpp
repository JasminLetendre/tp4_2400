#include "SurfaceOrdreId.h"
#include "Element.h"
#include "ModeleOrthese.h"
#include <vector>
#include <memory>
std::vector<Surface*> SurfaceOrdreId::createSurface(ModeleOrthese& modele) {
    // Implementation of surface creation in order of ID
    std::vector<std::shared_ptr<Element>> elements = modele.getElements(); 

    return {};
}
