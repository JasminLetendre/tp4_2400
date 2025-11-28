#ifndef CMDFUSIONERNUAGE_H
#define CMDFUSIONERNUAGE_H

#include "Commande.h"

class CmdFusionerNuage : public Commande {
public:
    virtual ~CmdFusionerNuage() = default;
    void execute() override;
    void undo() override;
protected:
    void doExecute() override;
    void doUndo() override;
};

#endif