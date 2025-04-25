#ifndef CHAMBREPATIENT_H_INCLUDED
#define CHAMBREPATIENT_H_INCLUDED

#include "Chambre.h"

class ChambrePatient : public virtual Chambre {
    bool IsVisited;

public:
    ChambrePatient();
    ChambrePatient(int, int, bool);
    virtual ~ChambrePatient();
    ChambrePatient(const ChambrePatient&);
    ChambrePatient& operator=(const ChambrePatient&);

    friend ostream& operator<<(ostream&, const ChambrePatient&);
    friend istream& operator>>(istream&, ChambrePatient&);

    void afficherChambre() const override;

    bool getIsVisited() const { return IsVisited; }
    void toggleIsVisited() { IsVisited = !IsVisited; }
};

#endif // CHAMBREPATIENT_H_INCLUDED
