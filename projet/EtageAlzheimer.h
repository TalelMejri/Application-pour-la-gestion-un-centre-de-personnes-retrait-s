#ifndef ETAGEALZHEIMER_H_INCLUDED
#define ETAGEALZHEIMER_H_INCLUDED

#include "Etage.h"

class EtageAlzheimer : public Etage {
public:
    EtageAlzheimer(int id) : Etage(id, "Alzheimer") {}

    void afficherEtage() {
        cout << "Etage Alzheimer - ID: " << id << endl;
        for (size_t i = 0; i < chambres.size(); ++i) {
            chambres[i]->afficherChambre();
        }
    }
};

#endif // ETAGEALZHEIMER_H_INCLUDED
