#ifndef MINIDESIGNAPP_H
#define MINIDESIGNAPP_H
#include <memory>
#include <string>
#include <vector>

class ModeleOrthese;
class AffichageStrategy;
class SurfaceCreationStrategy;
class GestionnaireCommandes;
class CommandFactory;

class MiniDesignApp {
public:
    explicit MiniDesignApp(const std::string& args);
    void executerBoucle();
    ModeleOrthese& getModele();
    const ModeleOrthese& getModele() const;
    GestionnaireCommandes& getGestionnaireCommandes();
    const GestionnaireCommandes& getGestionnaireCommandes() const;
    const std::vector<char>& getTexturesNuages() const;
    void setAffichageStrategy(std::unique_ptr<AffichageStrategy> strategy);
    void setSurfaceCreationStrategy(std::unique_ptr<SurfaceCreationStrategy> strategy);

private:
    void afficherMenu() const;
    bool traiterCommande(const std::string& cmd);

    std::unique_ptr<ModeleOrthese> modele_;
    std::unique_ptr<GestionnaireCommandes> gestionCmd_;
    std::unique_ptr<CommandFactory> factory_;
    std::unique_ptr<AffichageStrategy> affichageCourante_;
    std::unique_ptr<SurfaceCreationStrategy> surfaceCourante_;
    std::vector<char> texturesNuages_;
};
#endif