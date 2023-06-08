#include "Echantillon.h"

Echantillon::Echantillon(string nomFichier, int numColonne)
{
    ifstream file(nomFichier, ios::in);
    if(!file)
    {
        cout << "Erreur lors de l'ouverture du fichier...veuillez reessayer" << endl;
    }
    else
    {
        char ligne[40];
        char *token = NULL;
        int cote, indice;

        file.getline(ligne, 40);
        cout << ligne << endl;
        
        while(!file.eof())
        {
            file.getline(ligne, 40);
            token = strtok(ligne, ";");
            
            for(int i=0; i < numColonne; i++)
            {
                token = strtok(NULL, ";");
            }
            
            cote = atoi(token);
            indice = cote - 1;
            data.incrementeEffectif(indice);
        }
        file.close();
    }
}

Echantillon::~Echantillon() {}

DataSource1D& Echantillon::getDataSource() 
{ 
    return data; 
}