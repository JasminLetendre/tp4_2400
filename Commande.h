#ifndef COMMANDE_H
#define COMMANDE_H

class MiniDesignApp;
class Commande {
public:
    virtual ~Commande() = default;
    virtual void execute(MiniDesignApp* app) = 0;
    virtual void undo(MiniDesignApp* app) = 0;
protected:
    virtual void doExecute(MiniDesignApp* app) = 0;
    virtual void doUndo(MiniDesignApp* app) = 0;
};

#endif