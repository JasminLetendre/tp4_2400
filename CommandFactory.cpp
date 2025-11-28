#include "CommandFactory.h"
#include "iostream"

Commande* CommandFactory::createCommand(char code) {
    switch (code) {
        case 'D': {
            int id, oldX, oldY, newX, newY;
            std::cout << "Enter point ID: ";
            std::cin >> id;
            std::cout << "Enter old X position: ";
            std::cin >> oldX;
            std::cout << "Enter old Y position: ";
            std::cin >> oldY;
            std::cout << "Enter new X position: ";
            std::cin >> newX;
            std::cout << "Enter new Y position: ";
            std::cin >> newY;
            return new CmdDeplacerPoint(id, oldX, oldY, newX, newY);
        }
        case 'C': {
            return new CmdCreerSurfaces();
        }
        case 'F': {
            int idNuage;
            char symbole;
            int n;
            std::vector<int> idsElements;
            std::cout << "Enter Nuage ID: ";
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
        }
        case 'S': {
            int pointId;
            std::cout << "Enter point ID to delete: ";
            std::cin >> pointId;
            return new CmdSupprimerPoint(pointId);
        }
        default: {
            return nullptr;
        }
    }
}