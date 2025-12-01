#include "SurfaceDistanceMinimal.h"
#include "ModeleOrthese.h"
#include "NuageElement.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <limits>

std::vector<std::shared_ptr<Surface>> SurfaceDistanceMinimal::createSurface(ModeleOrthese& modele) {
    // Implementation of surface creation based on minimal distance (only for points in NuageElements)
    std::vector<std::shared_ptr<Element>> allElements = modele.getElements(); 
    std::vector<std::shared_ptr<Surface>> surfaces;

    // Process each NuageElement separately
    for (const auto& element : allElements) {
        auto nuage = std::dynamic_pointer_cast<NuageElement>(element);
        if (nuage) {
            // Get children of this nuage
            std::vector<std::shared_ptr<Element>> enfants = nuage->getEnfants();
            
            if (enfants.empty()) continue;
            if (enfants.size() == 1) continue; // Can't create surfaces with only one point

            // Create surfaces using greedy nearest neighbor algorithm
            std::vector<bool> visited(enfants.size(), false);
            std::vector<std::shared_ptr<Element>> orderedElements;
            
            // Start with the first element
            orderedElements.push_back(enfants[0]);
            visited[0] = true;
            
            // Greedy algorithm: always connect to the nearest unvisited point
            for (size_t i = 0; i < enfants.size() - 1; ++i) {
                auto currentElement = orderedElements.back();
                auto currentPoints = currentElement->collecterPoints();
                
                if (currentPoints.empty()) continue;
                
                int currentX = currentPoints[0]->getX();
                int currentY = currentPoints[0]->getY();
                
                // Find nearest unvisited element
                double minDistance = std::numeric_limits<double>::max();
                size_t nearestIndex = 0;
                
                for (size_t j = 0; j < enfants.size(); ++j) {
                    if (visited[j]) continue;
                    
                    auto points = enfants[j]->collecterPoints();
                    if (points.empty()) continue;
                    
                    int x = points[0]->getX();
                    int y = points[0]->getY();
                    
                    double distance = std::sqrt(std::pow(x - currentX, 2) + std::pow(y - currentY, 2));
                    
                    if (distance < minDistance) {
                        minDistance = distance;
                        nearestIndex = j;
                    }
                }
                
                orderedElements.push_back(enfants[nearestIndex]);
                visited[nearestIndex] = true;
            }
            
            // Create surfaces between consecutive elements in the ordered list
            for (size_t i = 0; i < orderedElements.size() - 1; ++i) {
                int idA = orderedElements[i]->id;
                int idB = orderedElements[i + 1]->id;
                surfaces.push_back(std::make_shared<Surface>(idA, idB));
            }
            
            // Close the shape by connecting last element to first within this nuage
            if (orderedElements.size() >= 2) {
                surfaces.push_back(std::make_shared<Surface>(orderedElements.back()->id, orderedElements.front()->id));
            }
        }
    }

    return surfaces;
}