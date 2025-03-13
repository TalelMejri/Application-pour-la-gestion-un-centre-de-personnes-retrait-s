#ifndef CHAMBREPERSONNEL_H_INCLUDED
#define CHAMBREPERSONNEL_H_INCLUDED

#include "Chambre.h"

class ChambrePersonnel : public Chambre {
public:
    ChambrePersonnel(int id) : Chambre(id, "Personnel") {}

    void afficherChambre()  {
        cout << "Chambre Personnel - ID: " << id << endl;
    }
};

#endif // CHAMBREPERSONNEL_H_INCLUDED
