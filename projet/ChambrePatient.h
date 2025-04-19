#ifndef CHAMBREPATIENT_H_INCLUDED
#define CHAMBREPATIENT_H_INCLUDED

#include "Chambre.h"

class ChambrePatient : public Chambre {
    bool IsVisited;
public:
     ChambrePatient(int ,int,bool);
     void afficherChambre();
};

#endif // CHAMBREPATIENT_H_INCLUDED
