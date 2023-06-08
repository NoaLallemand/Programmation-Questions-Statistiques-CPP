#include "Classes/DataSource1D.h"
#include "Classes/Echantillon.h"
#include "Classes/EtudeStatistique1D.h"
#include <iostream>

using namespace std;

int main()
{
    bool cont = true;
    int choixMainMenu;

    while(cont)
    {
        do
        {
            cout << "---GlissInpres - Menu---" << endl;
            cout << "Pour quel aspect de la station voulez-vous voir l'etude statistique ?" << endl;
            cout << "1) Pistes de ski" << endl << "2) Remontées" << endl << "3) Commerces" << endl;
            
            cout << "Votre choix: " << endl; cin >> choixMainMenu;
            if(choixMainMenu < 1 || choixMainMenu > 3)
            {
                cout << "Erreur! Veuillez tapper un chiffre entre 1 et 3 compris!" << endl;
            }

        }while(choixMainMenu < 1 || choixMainMenu > 3);

        Echantillon ech("DataSkiInpres.csv", choixMainMenu);

        DataSource1D donnees = ech.getDataSource();
        EtudeStatistique1D etud(donnees);
        etud.getDataSource().Affiche();
        etud.Affiche();
    }
}