#ifndef ETAGECARDIO_H_INCLUDED
#define ETAGECARDIO_H_INCLUDED

#include "Etage.h"

class EtageCardio : public Etage {
public:
    EtageCardio(int id) : Etage(id, "Cardio") {}

    void afficherEtage()  {
        cout << "Etage Cardio - ID: " << id << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
    }
};

#endif // ETAGECARDIO_H_INCLUDED
