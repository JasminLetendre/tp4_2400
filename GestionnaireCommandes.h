#ifndef GESTIONNAIRECOMMANDES_H
#define GESTIONNAIRECOMMANDES_H

#include "Commande.h"
#include "MiniDesignApp.h"

class GestionnaireCommandes {
private:
    vector<Commande*> pileUndo;
    vector<Commande*> pileRedo;
public:
    void executerCommande(Commande* cmd);
    void undo();
    void redo();
};

#endif