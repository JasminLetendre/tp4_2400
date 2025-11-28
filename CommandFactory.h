#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Commande.h"
#include "CmdFusionerNuage.h"
#include "CmdCreerSurfaces.h"
#include "CmdDeplacerPoint.h"
#include "CmdSupprimerPoint.h"

class MiniDesignApp;

class CommandFactory {
public:
    Commande* createCommand(char code);
};

#endif