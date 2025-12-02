
#include "CmdFusionerNuage.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"
#include "PointTextureDecorator.h"
#include <iostream>
#include <string>

void CmdFusionerNuage::execute(MiniDesignApp *app) { doExecute(app); }

void CmdFusionerNuage::undo(MiniDesignApp *app) { doUndo(app); }

void CmdFusionerNuage::doExecute(MiniDesignApp *app) {
  std::shared_ptr<NuageElement> nuage = std::make_shared<NuageElement>(
      std::vector<std::shared_ptr<Element>>{}, symbole, idNuage);

  for (auto id : idsElements) {
    std::shared_ptr<Element> element = app->getModele().getElement(id);
    element->appliquerTexture(symbole);
    nuage->AjouterEnfant(element);
  }

  app->getModele().ajouterElement(nuage);
}

void CmdFusionerNuage::doUndo(MiniDesignApp *) {
  // Do nothing / not for this tp
}

CmdFusionerNuage::CmdFusionerNuage(int idNuageVal,
                                   const std::string &symboleVal,
                                   const std::vector<int> &idsElementsVal)
    : idNuage(idNuageVal), symbole(symboleVal), idsElements(idsElementsVal) {}
