#include "CmdDeplacerPoint.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"

    
void CmdDeplacerPoint::execute(MiniDesignApp* app) {
    doExecute(app);
}

void CmdDeplacerPoint::undo(MiniDesignApp* app) {
    doUndo(app);
}

void CmdDeplacerPoint::doExecute(MiniDesignApp* app) {
    app->getModele().deplacerElement(pointId, nouveauX - ancienX, nouveauY - ancienY);
}

void CmdDeplacerPoint::doUndo(MiniDesignApp* app) {
    // Implementation of the actual undo logic
    app->getModele().deplacerElement(pointId, ancienX - nouveauX, ancienY - nouveauY);
}