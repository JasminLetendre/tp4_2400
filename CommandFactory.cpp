#include "CommandFactory.h"
#include "iostream"

Commande* CommandFactory::createCommand(char code/*,MiniDesignApp* app*/) {
    switch (code) {
        case 'D':
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
        case 'C':
            return new CmdCreerSurfaces();
        case 'F':
            return new CmdFusionerNuage();
        case 'S':
            return new CmdSupprimerPoint();
        default:
            return nullptr;
    }
}