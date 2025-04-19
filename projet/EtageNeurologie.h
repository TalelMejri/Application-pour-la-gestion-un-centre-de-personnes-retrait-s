#ifndef ETAGENUROLOGIE_H_INCLUDED
#define ETAGENUROLOGIE_H_INCLUDED

#include "Etage.h"

class EtageNeurologie : public Etage {
    int nbr_chambre;
public:
    EtageNeurologie(int,int,string);
    void afficherEtage() ;
};

#endif // ETAGENUROLOGIE_H_INCLUDED
