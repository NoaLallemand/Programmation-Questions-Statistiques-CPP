#ifndef ETUDESTATISTQUE1D_H
#define ETUDESTATISTQUE1D_H

#include <iostream>
#include <string.h>
#include "DataSource1D.h"

using namespace std;

class EtudeStatistique1D
{
    private:
        DataSource1D &data;

        double moyenne;
        int mode[3];
        double mediane;


    public:
        EtudeStatistique1D(DataSource1D &donnees);

        DataSource1D& getDataSource();
        void Affiche() const;

        double getMoyenne();
        void calculeMoyenne();

        int* getMode();
        void calculeMode();

        double getMediane();
        void calculeMediane();
};

#endif