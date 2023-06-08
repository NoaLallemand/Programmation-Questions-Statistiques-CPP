#include "EtudeStatistique1D.h"
#include <iomanip>

using namespace std;

EtudeStatistique1D::EtudeStatistique1D(DataSource1D &donnees) : data(donnees) 
{
    calculeMoyenne();
    calculeMode();
    calculeMediane();

    //Affiche();
}

DataSource1D& EtudeStatistique1D::getDataSource()
{
    return data;
}

void EtudeStatistique1D::Affiche() const
{
    cout << "Moyenne = " << fixed << setprecision(2) << moyenne << endl;
    
    cout << "Affichage du/des mode(s) : " << endl;
    for(int i=0; i < 3; i++)
    {
        if(mode[i] != 0)
        {
            cout << "Mode " << (i+1) << " = " << mode[i] << endl; 
        }
    }

    cout << "Mediane = " << fixed << setprecision(2) << mediane << endl;
}


// ---------------------------------------------------------

double EtudeStatistique1D::getMoyenne() { return moyenne; }

void EtudeStatistique1D::calculeMoyenne()
{
    int somme = 0;
    int* donnees = data.getDonnees();

    for(int i=0; i < data.size(); i++)
    {
        somme += donnees[i] * (i+1);
    }
    moyenne = ((double)somme / data.getEffectifTotal());
}

int* EtudeStatistique1D::getMode() { return mode; }

void EtudeStatistique1D::calculeMode()
{
    int i;
    for(i = 0; i < 3; i++){
        mode[i] = 0;
    }

    int* donnees = data.getDonnees();
    int max = donnees[0];

    for(i = 1; i < data.size(); i++)
    {
        if(donnees[i] > max)
        {
            max = donnees[i];
        }
    }

    int nbMode = 0;
    for(i = 0 ;i < data.size() && nbMode < 3; i++)
    {
        if(donnees[i] == max && nbMode < 3)
        {
            mode[nbMode] = i + 1;
            nbMode++;
        }
    }
}

double EtudeStatistique1D::getMediane() { return mediane; }

void EtudeStatistique1D::calculeMediane()
{
    int effectifTotal = data.getEffectifTotal() - 1;

    int milieu = effectifTotal/2;
    bool milieuTrouve = false, fini = false;

    if(effectifTotal % 2 == 0) //on a un effectif total pair
    {
        //Ici on récupère les 2 valeurs "centrales" et on calcule la moyenne de ces 2 valeurs.
        int valeursMilieu[2];

        for(int i=0; i < data.size() && fini == false; i++)
        {
            for(int j=0; j < data.getDonnees()[i] && fini == false; j++)
            {
                milieu--;
                if(milieu == 0)
                {
                    if(milieuTrouve == false)
                    {
                        valeursMilieu[0] = (i+1);
                        milieu = 1;
                        milieuTrouve = true;
                    }
                    else
                    {
                        valeursMilieu[1] = (i+1);
                        fini = true;
                    }
                }
            }
        }

        mediane = (double)(valeursMilieu[0] + valeursMilieu[1]) / 2;
    }
    else //on a un effectif total impair
    {
        for(int i=0; i < data.size() && fini == false; i++)
        {
            for(int j=0; j < data.getDonnees()[i] && fini == false; j++)
            {
                milieu--;
                if(milieu == 0)
                {
                    mediane = (i+1);
                    fini = true;
                }
            }
        }
    }
}