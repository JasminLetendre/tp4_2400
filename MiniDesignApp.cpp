#include "MiniDesignApp.h"

#include "CommandFactory.h"
#include "GestionnaireCommandes.h"
#include "ModeleOrthese.h"
#include "SurfaceCreationStrategy.h"
#include "affichage.h"

#include <iostream>
#include <utility>

MiniDesignApp::MiniDesignApp(const std::string &args)
    : modele_(nullptr), gestionCmd_(std::make_unique<GestionnaireCommandes>()),
      factory_(std::make_unique<CommandFactory>()), affichageCourante_(nullptr),
      surfaceCourante_(nullptr), texturesNuages_{'o', '#', '$'} {
  std::vector<Point> pointsInitiaux = creerPoints(args);
  //    TODO : faire le constructeur réel de ModeleOrthese.
  // modele_ = std::make_unique<ModeleOrthese>(pointsInitiaux, texturesNuages_);
}

ModeleOrthese &MiniDesignApp::getModele() { return *modele_; }

const ModeleOrthese &MiniDesignApp::getModele() const { return *modele_; }

GestionnaireCommandes &MiniDesignApp::getGestionnaireCommandes() {
  return *gestionCmd_;
}

const GestionnaireCommandes &MiniDesignApp::getGestionnaireCommandes() const {
  return *gestionCmd_;
}

const std::vector<char> &MiniDesignApp::getTexturesNuages() const {
  return texturesNuages_;
}

void MiniDesignApp::setAffichageStrategy(
    std::unique_ptr<AffichageStrategy> strategy) {
  affichageCourante_ = std::move(strategy);
}

void MiniDesignApp::setSurfaceCreationStrategy(
    std::unique_ptr<SurfaceCreationStrategy> strategy) {
  surfaceCourante_ = std::move(strategy);
}

void MiniDesignApp::executerBoucle() {
  std::string cmd;

  while (true) {
    afficherMenu();

    std::cout << "> ";
    if (!std::getline(std::cin, cmd)) {
      break;
    }

    if (cmd.empty())
      continue;

    if (!traiterCommande(cmd))
      break;
  }
}

void MiniDesignApp::afficherMenu() const {
  std::cout << "\nCommandes:\n"
            << "a  - Afficher les points et les nuages\n"
            << "o1 - Afficher l'orthèse avec les textures des points\n"
            << "o2 - Afficher l'orthèse avec les IDs des points\n"
            << "f  - Fusionner des points/nuages dans un nouveau nuage\n"
            << "d  - Deplacer un point (ID)\n"
            << "s  - Supprimer un point (ID)\n"
            << "u  - Annuler la dernière commande (undo)\n"
            << "r  - Réappliquer la dernière commande annulée (redo)\n"
            << "c1 - Créer les surfaces selon l'ordre des IDs\n"
            << "c2 - Créer les surfaces selon la distance minimale\n"
            << "q  - Quitter\n";
}

bool MiniDesignApp::traiterCommande(const std::string &cmd) {
  if (cmd == "q") {
    return false;
  }
  if (cmd == "u") {
    gestionCmd_->undo();
    return true;
  }
  if (cmd == "r") {
    gestionCmd_->redo();
    return true;
  }

  auto commande = factory_->createCommand(cmd[0]/*, this*/);

  if (!commande) {
    std::cout << "Commande inconnue: " << cmd << "\n";
    return true;
  }

  gestionCmd_->executerCommande(std::move(commande));

  return true;
}
