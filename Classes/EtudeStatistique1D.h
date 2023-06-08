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

    public:
        EtudeStatistique1D(DataSource1D &donnees);

        DataSource1D& getDataSource();
        void Affiche() const;
};

#endif