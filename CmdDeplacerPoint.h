#ifndef CMDDEPLACERPOINT_H
#define CMDDEPLACERPOINT_H

#include "Commande.h"

class CmdDeplacerPoint : public Commande {
public:
    virtual ~CmdDeplacerPoint() = default;
    void execute() override;
    void undo() override;
protected:
    void doExecute() override;
    void doUndo() override;
};

#endif