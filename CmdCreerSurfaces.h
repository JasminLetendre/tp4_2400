#ifndef CMDCREERSURFACES_H
#define CMDCREERSURFACES_H

#include "Commande.h"
class MiniDesignApp;
class SurfaceCreationStrategy;

class CmdCreerSurfaces : public Commande {
public:
    virtual ~CmdCreerSurfaces() = default;
    void execute(MiniDesignApp* app) override;
    void undo(MiniDesignApp* app) override;
protected:
    void doExecute(MiniDesignApp* app) override;
    void doUndo(MiniDesignApp* app) override;
private:
    SurfaceCreationStrategy* strategy;
};

#endif