#include "ModeleOrthese.h"
#include <algorithm>

ModeleOrthese::ModeleOrthese() : surface(nullptr) {}
std::vector<std::shared_ptr<Element>> ModeleOrthese::getElements() const {
    return elements;
}

std::shared_ptr<Element> ModeleOrthese::getElement(int id) const {
    for (const auto& e : elements) {
        if (e->id == id) {
            return e;
        }
    }
    return nullptr;
}

void ModeleOrthese::ajouterElement(std::shared_ptr<Element> e){
    elements.push_back(e);
}

void ModeleOrthese::supprimerElement(int id){
    elements.erase(std::remove_if(elements.begin(), elements.end(),
                   [id](const std::shared_ptr<Element>& e) { return e->id == id; }),
                   elements.end());
}

void ModeleOrthese::deplacerElement(int id, int dx, int dy){
    for (const auto& e : elements) {
        if (e->id == id) {
            e->deplacer(dx, dy);
            break;
        }
    }
}

void ModeleOrthese::recalculerSurface(SurfaceCreationStrategy* strategy){
    // Implementation needed
}