#ifndef CHAMBREMULTIPLE_H_INCLUDED
#define CHAMBREMULTIPLE_H_INCLUDED

#include "ChambrePersonnel.h"
#include "ChambrePatient.h"

class ChambreMultiple : public ChambrePatient, public ChambrePersonnel {
private:
    bool isOccupiedByPatient;

public:
    ChambreMultiple(int id, string type, bool occupied);

    void occuperChambre() {
        isOccupiedByPatient = true;
    }

    void libererChambre() {
        isOccupiedByPatient = false;
    }

    void afficherChambreMultiple() {
        ChambrePatient::afficherChambre();
        if (isOccupiedByPatient) {
            cout << "Cette chambre est occupée par un patient." << endl;
        } else {
            cout << "Cette chambre est libre." << endl;
        }
    }

    virtual ~ChambreMultiple() {}
};

#endif // CHAMBREMULTIPLE_H_INCLUDED
