
#include "CmdSupprimerPoint.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"

void CmdSupprimerPoint::execute(MiniDesignApp* app) {
    doExecute(app);
}

void CmdSupprimerPoint::undo(MiniDesignApp* app) {
    doUndo(app);
}

void CmdSupprimerPoint::doExecute(MiniDesignApp* app) {
    point = app->getModele().getElements()[pointId]; 
    app->getModele().supprimerElement(pointId);
}

void CmdSupprimerPoint::doUndo(MiniDesignApp* app) {
    app->getModele().ajouterElement(point);
}