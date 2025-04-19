#ifndef ETAGEALZHEIMER_H_INCLUDED
#define ETAGEALZHEIMER_H_INCLUDED

#include "Etage.h"

class EtageAlzheimer : public Etage {
 int nbr_chambre;
public:
    EtageAlzheimer(int id,int,string);
    void afficherEtage() ;
};

#endif // ETAGEALZHEIMER_H_INCLUDED
