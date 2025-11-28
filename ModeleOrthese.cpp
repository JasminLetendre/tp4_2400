#include "ModeleOrthese.h"

ModeleOrthese::ModeleOrthese();
std::vector<Element*> ModeleOrthese::getElements() const {
    return elements;
}

void ModeleOrthese::ajouterElement(Element* e){
    elements.push_back(e);
}

void ModeleOrthese::supprimerElement(int id){
    elements.erase(std::remove_if(elements.begin(), elements.end(),
                   [id](Element* e) { return e->id == id; }),
                   elements.end());
}

void ModeleOrthese::deplacerElement(int id, int dx, int dy){
    for (Element* e : elements) {
        if (e->id == id) {
            e->deplacer(dx, dy);
            break;
        }
    }
}

void ModeleOrthese::recalculerSurface(SurfaceCreationStrategy* strategy){
    // Implementation needed
}