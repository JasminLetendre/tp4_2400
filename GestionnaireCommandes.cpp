#include "GestionnaireCommandes.h"

void GestionnaireCommandes::executerCommande(Commande* cmd) {
    cmd->execute();
    pileUndo.push_back(cmd);
    pileRedo.clear();
}

void GestionnaireCommandes::undo() {
    if (!pileUndo.empty()) {
        Commande* cmd = pileUndo.back();
        pileUndo.pop_back();
        cmd->undo();
        pileRedo.push_back(cmd);
    }
}

void GestionnaireCommandes::redo() {
    if (!pileRedo.empty()) {
        Commande* cmd = pileRedo.back();
        pileRedo.pop_back();
        cmd->execute();
        pileUndo.push_back(cmd);
    }
}