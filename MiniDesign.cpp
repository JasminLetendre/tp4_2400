#include "AffichageStrategy.h"
#include "CommandFactory.h"
#include "GestionnaireCommandes.h"
#include "MiniDesignApp.h"
#include "ModeleOrthese.h"
#include "SurfaceCreationStrategy.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string args;
  if (argc > 1) {
    ostringstream oss;
    for (int i = 1; i < argc; ++i)
      oss << argv[i] << " ";
    args = oss.str();
  } else {
    cout << "Entrez les points au format (x,y) :\n> ";
    getline(cin, args);
  }

  MiniDesignApp app(args);
  app.executerBoucle();

  return 0;
}