#include "CommandFactory.h"

Commande* CommandFactory::createCommand(char code, MiniDesignApp* app) {
    // TODO: APP ????

    switch (code) {
        case 'D':
            return new CmdDeplacerPoint();
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