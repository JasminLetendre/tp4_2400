#ifndef MODELEORTHESE_H
#define MODELEORTHESE_H

#include "Element.h"
#include <vector>
#include "Surface.h"
#include "SurfaceCreationStrategy.h"
#include <memory>

class ModeleOrthese
{
private:
    std::vector<std::shared_ptr<Element>> elements;
    Surface* surface;

public:
    ModeleOrthese();
    std::vector<std::shared_ptr<Element>> getElements() const;
    void ajouterElement(std::shared_ptr<Element> e);
    std::shared_ptr<Element> getElement(int id) const;
    void supprimerElement(int id);
    void deplacerElement(int id, int dx, int dy);
    void recalculerSurface(SurfaceCreationStrategy* strategy);
};

#endif
