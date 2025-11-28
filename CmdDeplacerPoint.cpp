
#include "CmdDeplacerPoint.h"
    
void CmdDeplacerPoint::execute() {
    doExecute();
}

void CmdDeplacerPoint::undo() {
    doUndo();
}

void CmdDeplacerPoint::doExecute() {
    // Implementation of the actual execution logic
}

void CmdDeplacerPoint::doUndo() {
    // Implementation of the actual undo logic
}