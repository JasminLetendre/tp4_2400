#ifndef GESTIONNAIRECOMMANDES_H
#define GESTIONNAIRECOMMANDES_H

#include "Commande.h"
#include <vector>

class GestionnaireCommandes {
private:
    std::vector<Commande*> pileUndo;
    std::vector<Commande*> pileRedo;
public:
    void executerCommande(Commande* cmd);
    void undo();
    void redo();
};

#endif