#include "EtudeStatistique1D.h"

EtudeStatistique1D::EtudeStatistique1D(DataSource1D &donnees) : data(donnees) {}

DataSource1D& EtudeStatistique1D::getDataSource()
{
    return data;
}

void EtudeStatistique1D::Affiche() const
{

}