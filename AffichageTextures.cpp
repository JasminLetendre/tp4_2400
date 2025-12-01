#include "AffichageTextures.h"
#include "ModeleOrthese.h"
#include "PointComponent.h"
#include "affichage.h"
#include <iostream>
#include <vector>

void AffichageTextures::afficher() {
    auto elements = modele->getElements();
    
    if (elements.empty()) {
        std::cout << "Aucun élément à afficher.\n";
        return;
    }
    
    // Create a grid for visual display
    std::vector<std::vector<std::string>> grille(HAUTEUR, std::vector<std::string>(LARGEUR, " "));

    // Collect all points with their coordinates
    std::vector<Point> pointsForLines;
    
    // First, draw lines between consecutive points

    // TODO : Seulement afficher si surface existe
 /*   for (const auto& element : elements) {
        auto points = element->collecterPoints();
        
        for (const auto& point : points) {
            pointsForLines.push_back({point->getX(), point->getY()});
        }
    }
    
    // TODO : Seulement afficher si surface existe
    // Draw lines between consecutive points
    for (size_t i = 0; i < pointsForLines.size(); ++i) {
        size_t next = (i + 1) % pointsForLines.size();
        tracerLigne(grille, 
                    pointsForLines[i].x, pointsForLines[i].y,
                    pointsForLines[next].x, pointsForLines[next].y);
    }*/
    
    // Then overlay the IDs on top of the lines
    for (const auto& element : elements) {
        auto points = element->collecterPoints();
        
        for (const auto& point : points) {
            int x = point->getX();
            int y = point->getY();
            
            // Mark on grid if within bounds (IDs override lines)
            if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR) {
                std::string textures = point->getTextures();
                
                if (!textures.empty()) {
                    grille[y][x] = textures;  // Just take the first texture for simplicity
                }else{
                    grille[y][x] = '.';
                }
            }
        }
    }

    for (int y = HAUTEUR - 1; y >= 0; --y) {
        for (int x = 0; x < LARGEUR; ++x)
            std::cout << grille[y][x];
        std::cout << '\n';
    }
}