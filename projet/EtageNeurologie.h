#ifndef ETAGENUROLOGIE_H_INCLUDED
#define ETAGENUROLOGIE_H_INCLUDED

#include "Etage.h"

class EtageNeurologie : public Etage {
public:
    EtageNeurologie(int id) : Etage(id, "Neurologie") {}

    void afficherEtage()  {
        cout << "Etage Neurologie - ID: " << id << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
    }
};

#endif // ETAGENUROLOGIE_H_INCLUDED
