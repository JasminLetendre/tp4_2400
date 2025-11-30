#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Commande.h"

#include "MiniDesignApp.h"
#include "CmdFusionerNuage.h"
#include "CmdCreerSurfaces.h"
#include "CmdDeplacerPoint.h"
#include "CmdSupprimerPoint.h"
#include <string>

class MiniDesignApp;

class CommandFactory {
public:
    Commande* createCommand(const std::string& code);
};

#endif