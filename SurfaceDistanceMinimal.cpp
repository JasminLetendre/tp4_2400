#include "SurfaceDistanceMinimal.h"
#include "ModeleOrthese.h"
#include "NuageElement.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<Surface>>
SurfaceDistanceMinimal::createSurface(ModeleOrthese &modele) {
  std::vector<std::shared_ptr<Element>> allElements = modele.getElements();
  std::vector<std::shared_ptr<Surface>> surfaces;

  for (const auto &element : allElements) {
    auto nuage = std::dynamic_pointer_cast<NuageElement>(element);
    if (nuage) {
      std::vector<std::shared_ptr<Element>> enfants = nuage->getEnfants();

      if (enfants.empty())
        continue;
      if (enfants.size() == 1)
        continue;

      std::vector<bool> visited(enfants.size(), false);
      std::vector<std::shared_ptr<Element>> orderedElements;

      orderedElements.push_back(enfants[0]);
      visited[0] = true;

      for (size_t i = 0; i < enfants.size() - 1; ++i) {
        auto currentElement = orderedElements.back();
        auto currentPoints = currentElement->collecterPoints();

        if (currentPoints.empty())
          continue;

        int currentX = currentPoints[0]->getX();
        int currentY = currentPoints[0]->getY();

        double minDistance = std::numeric_limits<double>::max();
        size_t nearestIndex = 0;

        for (size_t j = 0; j < enfants.size(); ++j) {
          if (visited[j])
            continue;

          auto points = enfants[j]->collecterPoints();
          if (points.empty())
            continue;

          int x = points[0]->getX();
          int y = points[0]->getY();

          double distance =
              std::sqrt(std::pow(x - currentX, 2) + std::pow(y - currentY, 2));

          if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = j;
          }
        }

        orderedElements.push_back(enfants[nearestIndex]);
        visited[nearestIndex] = true;
      }

      for (size_t i = 0; i < orderedElements.size() - 1; ++i) {
        int idA = orderedElements[i]->id;
        int idB = orderedElements[i + 1]->id;
        surfaces.push_back(std::make_shared<Surface>(idA, idB));
      }

      if (orderedElements.size() >= 2) {
        surfaces.push_back(std::make_shared<Surface>(
            orderedElements.back()->id, orderedElements.front()->id));
      }
    }
  }

  return surfaces;
}