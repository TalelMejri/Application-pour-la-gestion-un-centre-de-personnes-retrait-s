#ifndef ETAGEALZHEIMER_H_INCLUDED
#define ETAGEALZHEIMER_H_INCLUDED

#include "Etage.h"

class EtageAlzheimer : public Etage {
public:
    EtageAlzheimer(int id) : Etage(id, "Alzheimer") {}

    void afficherEtage()  {
        cout << "Etage Alzheimer - ID: " << id << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
    }
};

#endif // ETAGEALZHEIMER_H_INCLUDED
