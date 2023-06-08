#include "DataSource1D.h"

DataSource1D::DataSource1D()
{
    for(int i=0; i<10; i++)
    {
        setDonnee(i, 0);
    }
    setEffectifTotal(0);
}

void DataSource1D::setDonnee(int indice, int val)
{
    donnees[indice] = val;   
}

void DataSource1D::setEffectifTotal(int val)
{
    if(val >= 0)
        effectifTotal = val;
}

int* DataSource1D::getDonnees() 
{ 
    return(donnees); 
}

int DataSource1D::getEffectifTotal() const { return(effectifTotal); }

void DataSource1D::incrementeEffectif(int indice)
{
    if(indice >= 0 && indice < 10)
    {
        donnees[indice]++;
        effectifTotal += 1;
    }   
}

void DataSource1D::initialiseEffectif(int indice, int valeur)
{
    if(indice >= 0 && indice < 10)
    {
        if(valeur >= 0)
        {
            int ancienneVal = donnees[indice];

            if(valeur == ancienneVal) return;
            
            int difference = valeur - ancienneVal; 
            effectifTotal += difference;

            setDonnee(indice, valeur);
        }
    }
}

void DataSource1D::Affiche() const
{
    cout << "Affichage du DataSource1D" << endl;
    for(int i=0; i<10; i++)
    {
        cout << "Indice " << i << ": " << donnees[i] << endl;
    }
    cout << "Effectif total : " << getEffectifTotal() << endl;
}