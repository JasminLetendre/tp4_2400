#include "GestionnaireCommandes.h"

void GestionnaireCommandes::executerCommande(Commande *cmd,
                                             MiniDesignApp *app) {
  cmd->execute(app);
  pileUndo.push_back(cmd);
  pileRedo.clear();
}

void GestionnaireCommandes::undo(MiniDesignApp *app) {
  if (!pileUndo.empty()) {
    Commande *cmd = pileUndo.back();
    pileUndo.pop_back();
    cmd->undo(app);
    pileRedo.push_back(cmd);
  }
}

void GestionnaireCommandes::redo(MiniDesignApp *app) {
  if (!pileRedo.empty()) {
    Commande *cmd = pileRedo.back();
    pileRedo.pop_back();
    cmd->execute(app);
    pileUndo.push_back(cmd);
  }
}