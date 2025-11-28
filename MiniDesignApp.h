#ifndef MINIDESIGNAPP_H
#define MINIDESIGNAPP_H
#include "ModeleOrthese.h"
#include "AffichageStrategy.h"
#include "SurfaceCreationStrategy.h"
#include "GestionnaireCommandes.h"
#include "CommandFactory.h"

class MiniDesignApp {
private:
    ModeleOrthese modele;
    AffichageStrategy* affichageStrategy;
    SurfaceCreationStrategy* surfaceStrategy;
    GestionnaireCommandes gestionnaireCommandes;
    CommandFactory commandFactory;
public:
    MiniDesignApp(AffichageStrategy* affichage, SurfaceCreationStrategy* surface);
    ~MiniDesignApp();
    void executerBoucle();
};
#endif