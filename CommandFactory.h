#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Commande.h"
#include "MiniDesignApp.h"

class CommandFactory {
public:
    Commande* createCommand(char code, MiniDesignApp* app);
};

#endif