#include "MiniDesignApp.h"
MiniDesignApp::MiniDesignApp(AffichageStrategy* affichage, SurfaceCreationStrategy* surface)
    : affichageStrategy(affichage), surfaceStrategy(surface) {}
MiniDesignApp::~MiniDesignApp() {
    delete affichageStrategy;
    delete surfaceStrategy;
}
void MiniDesignApp::executerBoucle() {
    // Implementation of the main application loop
}
