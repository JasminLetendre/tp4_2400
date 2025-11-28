#ifndef COMMANDE_H
#define COMMANDE_H

class Commande {
public:
    virtual ~Commande() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
protected:
    virtual void doExecute() = 0;
    virtual void doUndo() = 0;
};

#endif