#ifndef MEDECININFIRMIER_H_INCLUDED
#define MEDECININFIRMIER_H_INCLUDED

#include "Medecin.h"
#include "Infirmier.h"

class MedecinInfirmier : public Medecin, public Infirmier {
public:
    MedecinInfirmier();
    MedecinInfirmier(int, string, string, string, string, string, string, DATE, double, string, int);
    ~MedecinInfirmier();

    void afficherPersonne() ;
    void modifier() ;
};

#endif // MEDECININFIRMIER_H_INCLUDED
