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

  std::vector<std::vector<std::string>> grille(
      HAUTEUR, std::vector<std::string>(LARGEUR, " "));

  std::vector<std::shared_ptr<Surface>> surfaces = modele->getSurfaces();

  if (!surfaces.empty()) {
    for (const auto &surface : surfaces) {
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
        auto pointsA = elementA->collecterPoints();
        auto pointsB = elementB->collecterPoints();

        if (!pointsA.empty() && !pointsB.empty()) {
          int x0 = pointsA[0]->getX();
          int y0 = pointsA[0]->getY();
          int x1 = pointsB[0]->getX();
          int y1 = pointsB[0]->getY();

          tracerLigne(grille, x0, y0, x1, y1);
        }
      }
    }
  }

  for (const auto &element : elements) {
    auto points = element->collecterPoints();

    for (const auto &point : points) {
      int x = point->getX();
      int y = point->getY();

      if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR) {
        std::string textures = point->getTextures();

        if (!textures.empty()) {
          grille[y][x] = textures;
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