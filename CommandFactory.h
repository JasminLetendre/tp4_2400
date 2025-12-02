#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Commande.h"

#include "CmdCreerSurfaces.h"
#include "CmdDeplacerPoint.h"
#include "CmdFusionerNuage.h"
#include "CmdSupprimerPoint.h"
#include "MiniDesignApp.h"
#include <string>

class MiniDesignApp;

class CommandFactory {
public:
  Commande *createCommand(const std::string &code);
};

#endif