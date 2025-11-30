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
    auto points = app->getModele().getElement(pointId)->collecterPoints();
    
    if (!points.empty()) {
        ancienX = points.at(0)->getX();
        ancienY = points.at(0)->getY();
    } else {
        ancienX = 0;
        ancienY = 0;
    }
    
    app->getModele().deplacerElement(pointId, nouveauX, nouveauY);
}

void CmdDeplacerPoint::doUndo(MiniDesignApp* app) {
    // Implementation of the actual undo logic
    app->getModele().deplacerElement(pointId, ancienX, ancienY);
}