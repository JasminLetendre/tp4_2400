
#include "CmdFusionerNuage.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"
#include "PointTextureDecorator.h"
#include <iostream>
#include <string>

void CmdFusionerNuage::execute(MiniDesignApp* app) {
    doExecute(app);
}

void CmdFusionerNuage::undo(MiniDesignApp* app) {
    doUndo(app);
}

void CmdFusionerNuage::doExecute(MiniDesignApp* app) {
    std::shared_ptr<NuageElement> nuage = std::make_shared<NuageElement>(std::vector<std::shared_ptr<Element>>{}, symbole, idNuage);
    
    for (auto id : idsElements)
    {
        std::shared_ptr<Element> element = app->getModele().getElement(id);
        auto points = element->collecterPoints();
        for (auto& p : points)
        {
            p = std::shared_ptr<PointComponent>(new PointTextureDecorator(p, symbole));
        }
        nuage->AjouterEnfant(element);
    }

    for (auto enfant : nuage->getEnfants())
    {
        std::cout << "Symbole enfant ID " << enfant->id << ": " << enfant->collecterPoints()[0]->getTextures() << std::endl;
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

CmdFusionerNuage::CmdFusionerNuage(int idNuageVal, const std::string& symboleVal, const std::vector<int>& idsElementsVal)
    : idNuage(idNuageVal), symbole(symboleVal), idsElements(idsElementsVal) {}
