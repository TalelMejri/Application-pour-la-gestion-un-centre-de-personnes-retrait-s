#ifndef CHAMBREPATIENT_H_INCLUDED
#define CHAMBREPATIENT_H_INCLUDED

#include "Chambre.h"

class ChambrePatient : public Chambre {
    bool IsVisited;
public:
    ChambrePatient();
    ChambrePatient(int, int);
    virtual ~ChambrePatient();
    ChambrePatient& operator=(const ChambrePatient&);

    friend ostream& operator <<(ostream&, const ChambrePatient&);
    friend istream& operator >>(istream&, ChambrePatient&);
    friend ostream& operator <<(ostream&, const ChambrePatient*);
    friend istream& operator >>(istream&, ChambrePatient*);

    ChambrePatient(const ChambrePatient&);

    void afficherChambrePatient();

    bool getIsVisited() { return IsVisited; }

    void setIsVisited() { IsVisited!=IsVisited}
};

#endif // CHAMBREPATIENT_H_INCLUDED
