#ifndef CMDSUPPRIMERPOINT_H
#define CMDSUPPRIMERPOINT_H

#include "Commande.h"

class CmdSupprimerPoint : public Commande {
public:
    virtual ~CmdSupprimerPoint() = default;
    void execute() override;
    void undo() override;
protected:
    void doExecute() override;
    void doUndo() override;
    
};

#endif