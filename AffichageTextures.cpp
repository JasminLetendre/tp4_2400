#include "AffichageTextures.h"
#include "ModeleOrthese.h"
#include "PointComponent.h"
#include <iostream>
#include <vector>

AffichageTextures::AffichageTextures(ModeleOrthese* m) : modele(m) {}

void AffichageTextures::afficher() {
    std::cout << "\n=== Affichage des points avec textures ===\n";
    
    auto elements = modele->getElements();
    
    if (elements.empty()) {
        std::cout << "Aucun élément à afficher.\n";
        return;
    }
    
    for (const auto& element : elements) {
        auto points = element->collecterPoints();
        
        for (const auto& point : points) {
            std::cout << "Point ID:" << element->id 
                      << " (" << point->getX() << "," << point->getY() << ")";
            
            std::string textures = point->getTextures();
            if (!textures.empty()) {
                std::cout << " Textures: " << textures;
            }
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}