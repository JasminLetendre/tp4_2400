#ifndef CMDDEPLACERPOINT_H
#define CMDDEPLACERPOINT_H

#include "Commande.h"
class CmdDeplacerPoint : public Commande {
public:
  virtual ~CmdDeplacerPoint() = default;
  CmdDeplacerPoint(int id, int oldX, int oldY, int newX, int newY)
      : pointId(id), ancienX(oldX), ancienY(oldY), nouveauX(newX),
        nouveauY(newY) {}
  void execute(MiniDesignApp *app) override;
  void undo(MiniDesignApp *app) override;

protected:
  void doExecute(MiniDesignApp *app) override;
  void doUndo(MiniDesignApp *app) override;

private:
  // Add any private members needed for the command
  int ancienX;
  int ancienY;
  int nouveauX;
  int nouveauY;
  int pointId;
};

#endif