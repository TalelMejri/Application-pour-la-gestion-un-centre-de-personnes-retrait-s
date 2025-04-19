#ifndef CHAMBREPERSONNEL_H_INCLUDED
#define CHAMBREPERSONNEL_H_INCLUDED

#include "Chambre.h"

class ChambrePersonnel : public Chambre {
    bool estequipee;
public:
    ChambrePersonnel(int ,int,bool);
    void afficherChambre();
};

#endif // CHAMBREPERSONNEL_H_INCLUDED
