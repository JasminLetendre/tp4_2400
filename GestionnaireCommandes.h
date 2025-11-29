#ifndef GESTIONNAIRECOMMANDES_H
#define GESTIONNAIRECOMMANDES_H

#include "Commande.h"
#include <vector>

class GestionnaireCommandes {
private:
    std::vector<Commande*> pileUndo;
    std::vector<Commande*> pileRedo;
public:
    void executerCommande(Commande* cmd, MiniDesignApp* app);
    void undo(MiniDesignApp* app);
    void redo(MiniDesignApp* app);
};

#endif