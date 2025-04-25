#ifndef ETAGEALZHEIMER_H_INCLUDED
#define ETAGEALZHEIMER_H_INCLUDED

#include "Etage.h"

class EtageAlzheimer : public Etage {
    int nbr_chambre;
public:
    EtageAlzheimer(int, int, string);
    EtageAlzheimer();
    virtual ~EtageAlzheimer();
    EtageAlzheimer& operator=(const EtageAlzheimer&);
    EtageAlzheimer(const EtageAlzheimer&);

    friend ostream& operator <<(ostream&, const EtageAlzheimer&);
    friend istream& operator >>(istream&, EtageAlzheimer&);
    friend ostream& operator <<(ostream&, const EtageAlzheimer*);
    friend istream& operator >>(istream&, EtageAlzheimer*);

    void afficherEtage() override;
};

#endif // ETAGEALZHEIMER_H_INCLUDED
