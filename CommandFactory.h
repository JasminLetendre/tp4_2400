#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Commande.h"
#include "MiniDesignApp.h"
#include "CmdFusionerNuage.h"
#include "CmdCreerSurfaces.h"
#include "CmdDeplacerPoint.h"
#include "CmdSupprimerPoint.h"

class CommandFactory {
public:
    Commande* createCommand(char code, MiniDesignApp* app);
};

#endif