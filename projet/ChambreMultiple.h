#ifndef CHAMBREMULTIPLE_H_INCLUDED
#define CHAMBREMULTIPLE_H_INCLUDED

#include "ChambrePersonnel.h"
#include "ChambrePatient.h"

class ChambreMultiple : public ChambrePatient, public ChambrePersonnel {
private:
    bool isOccupiedByPatient;

public:
    ChambreMultiple(int id, int  floor,bool IsVisited,bool estEquipee, bool occupied);

    void occuperChambre() {
        isOccupiedByPatient = true;
    }

    void libererChambre() {
        isOccupiedByPatient = false;
    }

    void afficherChambreMultiple();

    virtual ~ChambreMultiple() {}
};

#endif // CHAMBREMULTIPLE_H_INCLUDED
