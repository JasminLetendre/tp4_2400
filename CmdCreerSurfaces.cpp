
#include "CmdCreerSurfaces.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"

void CmdCreerSurfaces::execute(MiniDesignApp *app) { doExecute(app); }

void CmdCreerSurfaces::undo(MiniDesignApp *app) { doUndo(app); }

void CmdCreerSurfaces::doExecute(MiniDesignApp *app) {
  app->getModele().recalculerSurface(strategy);
}

void CmdCreerSurfaces::doUndo(MiniDesignApp *app) {
  // Do nothing for now
}