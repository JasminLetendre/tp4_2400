#ifndef CMDSUPPRIMERPOINT_H
#define CMDSUPPRIMERPOINT_H

#include "Commande.h"
#include <memory>
class MiniDesignApp;
class Element;
class CmdSupprimerPoint : public Commande {
public:
    virtual ~CmdSupprimerPoint() = default;
    CmdSupprimerPoint(int pointIdVal) : pointId(pointIdVal), point(nullptr) {}
    void execute(MiniDesignApp* app) override;
    void undo(MiniDesignApp* app) override;
protected:
    void doExecute(MiniDesignApp* app) override;
    void doUndo(MiniDesignApp* app) override;
private:
    int pointId;
    std::shared_ptr<Element> point;
};

#endif