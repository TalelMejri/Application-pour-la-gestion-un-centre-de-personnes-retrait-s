#ifndef RESIDENT_H_INCLUDED
#define RESIDENT_H_INCLUDED

#include "Personne.h"
#include "DossierMedical.h"

class Resident : public Personne {
private:
    float solde;
    DossierMedical* dossierMedical;

public:
    Resident();
    Resident(int, string, string, string, string, string, string, DATE, float);
    ~Resident();

    void afficherPersonne();
    void modifier() ;
    void modifierSolde(float);

    float getSolde() { return solde; }
    DossierMedical* getDossierMedical() { return dossierMedical; }

    void setSolde(float soldeVal) { solde = soldeVal; }
    void setDossierMedical(DossierMedical* dossierVal) { dossierMedical = dossierVal; }
};

#endif // RESIDENT_H_INCLUDED
