#include "AffichageIdsEtSurfaces.h"
#include "ModeleOrthese.h"
#include "PointComponent.h"
#include "PointElement.h"
#include "affichage.h"
#include <iostream>
#include <vector>
#include <memory>

void AffichageIdsEtSurfaces::afficher() {
    auto elements = modele->getElements();
    
    if (elements.empty()) {
        std::cout << "Aucun élément à afficher.\n";
        return;
    }
    
    // Create a grid for visual display
    std::vector<std::vector<std::string>> grille(HAUTEUR, std::vector<std::string>(LARGEUR, " "));
    
    // First, draw lines between surfaces
    std::vector<std::shared_ptr<Surface>> surfaces = modele->getSurfaces();
    
    if(!surfaces.empty()) {
        // Draw each surface (line between two points)
        for (const auto& surface : surfaces) {
            // Find the elements by ID
            std::shared_ptr<Element> elementA = nullptr;
            std::shared_ptr<Element> elementB = nullptr;
            
            for (const auto& elem : elements) {
                if (elem->id == surface->idPointA) {
                    elementA = elem;
                }
                if (elem->id == surface->idPointB) {
                    elementB = elem;
                }
            }

            if (elementA && elementB) {
                // Get the points from the elements
                auto pointsA = elementA->collecterPoints();
                auto pointsB = elementB->collecterPoints();
                
                if (!pointsA.empty() && !pointsB.empty()) {
                    int x0 = pointsA[0]->getX();
                    int y0 = pointsA[0]->getY();
                    int x1 = pointsB[0]->getX();
                    int y1 = pointsB[0]->getY();
                    
                    // Draw the line between the two points
                    tracerLigne(grille, x0, y0, x1, y1);
                }
            }
        }
    }
    
    // Then overlay the IDs on top of the lines (only for PointElements, not NuageElements)
    for (const auto& element : elements) {
        // Only display ID if it's a PointElement, not a NuageElement
        if (std::dynamic_pointer_cast<PointElement>(element)) {
            auto points = element->collecterPoints();
            
            for (const auto& point : points) {
                int x = point->getX();
                int y = point->getY();
                
                // Mark on grid if within bounds (IDs override lines)
                if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR) {
                    char idChar = '0' + (element->id % 10);
                    grille[y][x] = idChar;
                }
            }
        }
    }
    
    // Print the grid
    for (int y = HAUTEUR - 1; y >= 0; --y) {
        for (int x = 0; x < LARGEUR; ++x)
            std::cout << grille[y][x];
        std::cout << '\n';
    }
}