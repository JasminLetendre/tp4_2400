#include "CommandFactory.h"
#include "SurfaceCreationStrategy.h"
#include "SurfaceDistanceMinimal.h"
#include "SurfaceOrdreId.h"
#include <iostream>
#include <string>

Commande *CommandFactory::createCommand(const std::string &code) {
  if (code == "d") {
    int id, oldX = 0, oldY = 0, newX, newY;
    std::cout << "ID du point à déplacer: ";
    std::cin >> id;
    std::cout << "Nouvelle position (x y): ";
    std::cin >> newX >> newY;
    return new CmdDeplacerPoint(id, oldX, oldY, newX, newY);
  } else if (code == "c1") {
    return new CmdCreerSurfaces(new SurfaceOrdreId());
  } else if (code == "c2") {
    return new CmdCreerSurfaces(new SurfaceDistanceMinimal());
  } else if (code == "f") {
    int idNuage;
    std::string symbole;
    std::vector<int> idsElements;
    std::cout << "IDs de points/nuages à fusionner (ex: 0 2 5): ";
    int id;
    while (std::cin >> id) {
      idsElements.push_back(id);
      if (std::cin.peek() == '\n') break;
    }
    std::cout << "Symbole de texture: ";
    std::cin >> symbole;
    std::cout << "ID du nouveau nuage: ";
    std::cin >> idNuage;
    return new CmdFusionerNuage(idNuage, symbole, idsElements);
  } else if (code == "s") {
    int pointId;
    std::cout << "Id du point à supprimer: ";
    std::cin >> pointId;
    return new CmdSupprimerPoint(pointId);
  }

  return nullptr;
}