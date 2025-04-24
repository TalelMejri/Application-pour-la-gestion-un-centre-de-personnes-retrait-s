#ifndef CHAMBREPERSONNEL_H_INCLUDED
#define CHAMBREPERSONNEL_H_INCLUDED

#include "Chambre.h"

class ChambrePersonnel : public Chambre {
    bool estequipee;
public:
ChambrePersonnel();
ChambrePersonnel(int, int);
virtual ~ChambrePersonnel();
ChambrePersonnel& operator=(const ChambrePersonnel&);

friend ostream& operator <<(ostream&, const ChambrePersonnel&);
friend istream& operator >>(istream&, ChambrePersonnel&);
friend ostream& operator <<(ostream&, const ChambrePersonnel*);
friend istream& operator >>(istream&, ChambrePersonnel*);

ChambrePersonnel(const ChambrePersonnel&);

void afficherChambrePersonnel();

bool getEquiped() { return estequipee; }

void setEquiped() { estequipee!=estequipee}
};

#endif // CHAMBREPERSONNEL_H_INCLUDED
