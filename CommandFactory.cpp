#include "CommandFactory.h"
#include "SurfaceCreationStrategy.h"
#include "SurfaceDistanceMinimal.h"
#include "SurfaceOrdreId.h"
#include <iostream>
#include <string>

Commande *CommandFactory::createCommand(const std::string &code) {
  if (code == "d") {
    int id, oldX = 0, oldY = 0, newX, newY;
    std::cout << "Enter point ID: ";
    std::cin >> id;
    std::cout << "Enter new X position: ";
    std::cin >> newX;
    std::cout << "Enter new Y position: ";
    std::cin >> newY;
    return new CmdDeplacerPoint(id, oldX, oldY, newX, newY);
  } else if (code == "c1") {
    return new CmdCreerSurfaces(new SurfaceOrdreId());
  } else if (code == "c2") {
    return new CmdCreerSurfaces(new SurfaceDistanceMinimal());
  } else if (code == "f") {
    int idNuage;
    std::string symbole;
    int n;
    std::vector<int> idsElements;
    std::cout << "Enter new Nuage ID: ";
    std::cin >> idNuage;
    std::cout << "Enter texture symbol: ";
    std::cin >> symbole;
    std::cout << "Enter number of elements to fuse: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      int elemId;
      std::cout << "Enter element ID " << (i + 1) << ": ";
      std::cin >> elemId;
      idsElements.push_back(elemId);
    }
    return new CmdFusionerNuage(idNuage, symbole, idsElements);
  } else if (code == "s") {
    int pointId;
    std::cout << "Enter point ID to delete: ";
    std::cin >> pointId;
    return new CmdSupprimerPoint(pointId);
  }

  return nullptr;
}