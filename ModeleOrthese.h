#ifndef MODELEORTHESE_H
#define MODELEORTHESE_H

#include "Element.h"
#include <vector>
#include "Surface.h"
#include "SurfaceCreationStrategy.h"

class ModeleOrthese
{
private:
    std::vector<Element*> elements;
    Surface* surface;

public:
    ModeleOrthese();
    std::vector<Element*> getElements() const;
    void ajouterElement(Element* e);
    void supprimerElement(int id);
    void deplacerElement(int id, int dx, int dy);
    void recalculerSurface(SurfaceCreationStrategy* strategy);
};

#endif
