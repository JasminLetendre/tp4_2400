
#include "CmdFusionerNuage.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"

void CmdFusionerNuage::execute(MiniDesignApp* app) {
    doExecute(app);
}

void CmdFusionerNuage::undo(MiniDesignApp* app) {
    doUndo(app);
}

void CmdFusionerNuage::doExecute(MiniDesignApp* app) {
    std::shared_ptr<NuageElement> nuage = std::make_shared<NuageElement>(std::vector<std::shared_ptr<Element>>{}, symbole);
    
    for (auto id : idsElements)
    {
        nuage->AjouterEnfant(app->getModele().getElement(id));
    }

    app->getModele().ajouterElement(nuage);
}

void CmdFusionerNuage::doUndo(MiniDesignApp* app) {
    app->getModele().supprimerElement(idNuage);
    
    for (auto id : idsElements)
    {
        app->getModele().ajouterElement(app->getModele().getElement(id));
    }
}

CmdFusionerNuage::CmdFusionerNuage(int idNuageVal, char symboleVal, const std::vector<int>& idsElementsVal)
    : idNuage(idNuageVal), symbole(symboleVal), idsElements(idsElementsVal) {}
