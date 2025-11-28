#ifndef CMDCREERSURFACES_H
#define CMDCREERSURFACES_H

#include "Commande.h"

class CmdCreerSurfaces : public Commande {
public:
    virtual ~CmdCreerSurfaces() = default;
    void execute() override;
    void undo() override;
protected:
    void doExecute() override;
    void doUndo() override;
};

#endif