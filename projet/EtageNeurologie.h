#ifndef ETAGENUROLOGIE_H_INCLUDED
#define ETAGENUROLOGIE_H_INCLUDED

#include "Etage.h"

class EtageNeurologie : public Etage {
    int nbr_chambre;
public:
    EtageNeurologie(int, int, string);
    EtageNeurologie();
    virtual ~EtageNeurologie();
    EtageNeurologie& operator=(const EtageNeurologie&);
    EtageNeurologie(const EtageNeurologie&);

    friend ostream& operator <<(ostream&, const EtageNeurologie&);
    friend istream& operator >>(istream&, EtageNeurologie&);
    friend ostream& operator <<(ostream&, const EtageNeurologie*);
    friend istream& operator >>(istream&, EtageNeurologie*);

    void afficherEtage() override;
};

#endif // ETAGENUROLOGIE_H_INCLUDED
