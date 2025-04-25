#ifndef CHAMBREMULTIPLE_H_INCLUDED
#define CHAMBREMULTIPLE_H_INCLUDED

#include "ChambrePatient.h"
#include "ChambrePersonnel.h"

class ChambreMultiple : public ChambrePatient, public ChambrePersonnel {
private:
    bool isOccupiedByPatient;

public:
    ChambreMultiple();
    ChambreMultiple(int id, int floor, bool isVisited, bool estEquipee, bool occupied);
    ChambreMultiple(const ChambreMultiple&);
    virtual ~ChambreMultiple();
    ChambreMultiple& operator=(const ChambreMultiple&);

    friend ostream& operator<<(ostream&, const ChambreMultiple&);
    friend istream& operator>>(istream&, ChambreMultiple&);
    friend ostream& operator<<(ostream&, const ChambreMultiple*);
    friend istream& operator>>(istream&, ChambreMultiple*);

    void occuperChambre();
    void libererChambre();
    void afficherChambre() const override;
};

#endif // CHAMBREMULTIPLE_H_INCLUDED
