#ifndef DATASOURCE1D_H
#define DATASOURCE1D_H

#include <iostream>
using namespace std;

class DataSource1D
{
    private:
        int donnees[10];
        int effectifTotal;

        int _size;

        void setDonnee(int indice, int val);
        void setEffectifTotal(int val);

    public:
        DataSource1D();

        void incrementeEffectif(int indice);
        void initialiseEffectif(int indice, int valeur);

        int* getDonnees();
        int getEffectifTotal() const;

        void Affiche() const;

        int size();
};

#endif