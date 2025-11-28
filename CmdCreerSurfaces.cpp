
#include "CmdCreerSurfaces.h"
    
void CmdCreerSurfaces::execute(MiniDesignApp* app) {
    doExecute(app);
}

void CmdCreerSurfaces::undo(MiniDesignApp* app) {
    doUndo(app);
}

void CmdCreerSurfaces::doExecute(MiniDesignApp* app) {
    // Implementation of the actual execution logic
    app->getSurfaceCreationStrategy()->createSurfaces(app->getModele());

}

void CmdCreerSurfaces::doUndo(MiniDesignApp* app) {
    // Implementation of the actual undo logic
}