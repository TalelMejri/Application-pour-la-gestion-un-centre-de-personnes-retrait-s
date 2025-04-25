#ifndef ETAGECARDIO_H_INCLUDED
#define ETAGECARDIO_H_INCLUDED

#include "Etage.h"

class EtageCardio : public Etage {
    int nbr_chambre;
public:
    EtageCardio(int, int, string);
    EtageCardio();
    virtual ~EtageCardio();
    EtageCardio& operator=(const EtageCardio&);
    EtageCardio(const EtageCardio&);

    friend ostream& operator <<(ostream&, const EtageCardio&);
    friend istream& operator >>(istream&, EtageCardio&);
    friend ostream& operator <<(ostream&, const EtageCardio*);
    friend istream& operator >>(istream&, EtageCardio*);

    void afficherEtage() override;
};

#endif // ETAGECARDIO_H_INCLUDED
