#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include <iostream>
#include "DataSource1D.h"
#include "string.h"
#include <fstream>

using namespace std;

class Echantillon
{
    private:
        DataSource1D data;

    public:
        Echantillon(string nomFichier, int numColonne);
        ~Echantillon();

        DataSource1D& getDataSource();
};

#endif