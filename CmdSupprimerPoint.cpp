
#include "CmdSupprimerPoint.h"
    
void CmdSupprimerPoint::execute() {
    doExecute();
}

void CmdSupprimerPoint::undo() {
    doUndo();
}

void CmdSupprimerPoint::doExecute() {
    // Implementation of the actual execution logic
}

void CmdSupprimerPoint::doUndo() {
    // Implementation of the actual undo logic
}