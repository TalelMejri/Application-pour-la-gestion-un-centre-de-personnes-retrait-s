#ifndef CHAMBREPATIENT_H_INCLUDED
#define CHAMBREPATIENT_H_INCLUDED

#include "Chambre.h"

class ChambrePatient : public Chambre {
public:
    ChambrePatient(int id) : Chambre(id, "Patient") {}

    void afficherChambre() override {
        cout << "Chambre Patient - ID: " << id << endl;
    }
};

#endif // CHAMBREPATIENT_H_INCLUDED
