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
  std::vector<std::vector<std::string>> grille(
      HAUTEUR, std::vector<std::string>(LARGEUR, " "));

  std::vector<std::shared_ptr<Surface>> surfaces = modele->getSurfaces();

  if (!surfaces.empty()) {
    // Draw each surface (line between two points)
    for (const auto &surface : surfaces) {
      // Find the elements by ID
      std::shared_ptr<Element> elementA = nullptr;
      std::shared_ptr<Element> elementB = nullptr;

      for (const auto &elem : elements) {
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

  // Then overlay the IDs on top of the lines
  for (const auto &element : elements) {
    auto points = element->collecterPoints();

    for (const auto &point : points) {
      int x = point->getX();
      int y = point->getY();

      // Mark on grid if within bounds (IDs override lines)
      if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR) {
        std::string textures = point->getTextures();

        if (!textures.empty()) {
          grille[y][x] = textures; // Just take the first texture for simplicity
        } else {
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