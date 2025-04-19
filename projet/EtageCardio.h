#ifndef ETAGECARDIO_H_INCLUDED
#define ETAGECARDIO_H_INCLUDED

#include "Etage.h"

class EtageCardio : public Etage {
     int nbr_chambre;
public:
    EtageCardio(int ,int,string);
    void afficherEtage() ;
};

#endif // ETAGECARDIO_H_INCLUDED
