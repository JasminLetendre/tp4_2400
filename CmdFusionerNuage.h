#ifndef CMDFUSIONERNUAGE_H
#define CMDFUSIONERNUAGE_H

#include "Commande.h"
#include "NuageElement.h"
#include <string>
#include <vector>

class MiniDesignApp;

class CmdFusionerNuage : public Commande {
public:
  virtual ~CmdFusionerNuage() = default;
  CmdFusionerNuage(int idNuage, const std::string &symbole,
                   const std::vector<int> &idsElements);
  void execute(MiniDesignApp *app) override;
  void undo(MiniDesignApp *app) override;

protected:
  void doExecute(MiniDesignApp *app) override;
  void doUndo(MiniDesignApp *app) override;

private:
  int idNuage;
  std::string symbole;
  std::vector<int> idsElements;
  std::shared_ptr<NuageElement> nuage;
};

#endif