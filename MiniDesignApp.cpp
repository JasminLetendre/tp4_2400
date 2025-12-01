#include "MiniDesignApp.h"

#include "AffichageIdsEtSurfaces.h"
#include "AffichageStrategy.h"
#include "AffichageTextures.h"
#include "CommandFactory.h"
#include "GestionnaireCommandes.h"
#include "ModeleOrthese.h"
#include "PointElement.h"
#include "PointNu.h"
#include "SurfaceCreationStrategy.h"
#include "affichage.h"

#include <iostream>
#include <utility>

MiniDesignApp::MiniDesignApp(const std::string &args)
    : modele_(std::make_unique<ModeleOrthese>()), 
      gestionCmd_(std::make_unique<GestionnaireCommandes>()),
      factory_(std::make_unique<CommandFactory>()), 
      affichageCourante_(nullptr),
      surfaceCourante_(nullptr), texturesNuages_{'o', '#', '$'} {
  std::vector<Point> pointsInitiaux = creerPoints(args);
  
  // Create PointElements from the initial points and add them to the model
  int id = 0;
  for (const auto& point : pointsInitiaux) {
    auto pointNu = std::make_shared<PointNu>(point.x, point.y);
    auto pointElement = std::make_shared<PointElement>(pointNu, id++);
    modele_->ajouterElement(pointElement);
  }
  
  // Set default affichage strategy
  affichageCourante_ = std::make_unique<AffichageTextures>(modele_.get());
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
  if (cmd == "a") {
    // Implementation of display strategy
    std::cout << "\n=== Affichage des points avec textures ===\n";
    
    auto elements = modele_->getElements();
    
    if (elements.empty()) {
        std::cout << "Aucun élément à afficher.\n";
        return true;
    }

    
    for (const auto& element : elements) {
        auto points = element->collecterPoints();

        if(points.size() == 1) {
          std::cout << "Point ID:" << element->id 
                    << " (" << points[0]->getX() << "," << points[0]->getY() << ")";
          
          std::string textures = points[0]->getTextures();

          if (textures.empty()) {
            textures = " ";
          }

          std::cout << " Textures: \'" << textures << "\'";
          
          std::cout << "\n";
        }else{
          std::cout << "Nuage ID:" << element->id << " contient les elements:";

          for (const auto& enfant : static_cast<NuageElement*>(element.get())->getEnfants()) {
            std::cout << " " << enfant->id;
          }

          std::cout << "\n";
        }
    }

    std::cout << std::endl;
    return true;
  }

  if (cmd == "o1") {
    affichageCourante_ = std::make_unique<AffichageTextures>(modele_.get());
    std::cout << "Mode d'affichage: Textures\n";
    affichageCourante_->afficher();
    return true;
  }
  
  if (cmd == "o2") {
    affichageCourante_ = std::make_unique<AffichageIdsEtSurfaces>(modele_.get());
    std::cout << "Mode d'affichage: IDs et Surfaces\n";
    affichageCourante_->afficher();
    return true;
  }

  if(cmd == "f" || cmd == "d" || cmd == "s" || cmd == "c1" || cmd == "c2") {
    auto commande = factory_->createCommand(cmd);

    if (!commande) {
      std::cout << "Commande inconnue: " << cmd << "\n";
      return true;
    }

    gestionCmd_->executerCommande(std::move(commande), this);

    return true;
  }

  if (cmd == "q") {
    return false;
  }
  if (cmd == "u") {
    gestionCmd_->undo(this);
    return true;
  }
  if (cmd == "r") {
    gestionCmd_->redo(this);
    return true;
  }

  auto commande = factory_->createCommand(cmd);

  if (!commande) {
    std::cout << "Commande inconnue: " << cmd << "\n";
    return true;
  }

  gestionCmd_->executerCommande(std::move(commande), this);

  return true;
}
