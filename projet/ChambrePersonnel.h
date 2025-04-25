#ifndef CHAMBREPERSONNEL_H_INCLUDED
#define CHAMBREPERSONNEL_H_INCLUDED

#include "Chambre.h"

class ChambrePersonnel : public virtual Chambre {
    bool estequipee;

public:
    ChambrePersonnel();
    ChambrePersonnel(int, int, bool);
    virtual ~ChambrePersonnel();
    ChambrePersonnel(const ChambrePersonnel&);
    ChambrePersonnel& operator=(const ChambrePersonnel&);

    friend ostream& operator<<(ostream&, const ChambrePersonnel&);
    friend istream& operator>>(istream&, ChambrePersonnel&);
    friend ostream& operator<<(ostream&, const ChambrePersonnel*);
    friend istream& operator>>(istream&, ChambrePersonnel*);

    void afficherChambre() const override;

    bool getEquiped() const { return estequipee; }
    void toggleEquiped() { estequipee = !estequipee; }
};

#endif // CHAMBREPERSONNEL_H_INCLUDED
