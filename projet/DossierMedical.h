#ifndef DOSSIERMEDICAL_H_INCLUDED
#define DOSSIERMEDICAL_H_INCLUDED

#include <iostream>
#include <list>
#include "Medicament.h"

using namespace std;

class DossierMedical {
private:

    list<Medicament*> medicaments;

public:
    DossierMedical();
    ~DossierMedical();
    friend ostream& operator <<(ostream&,const DossierMedical &);
    friend istream& operator >>(istream& ,DossierMedical&);
    friend ostream& operator <<(ostream&,const DossierMedical *);
    friend istream& operator >>(istream& ,DossierMedical*);
    DossierMedical & operator=(const DossierMedical&) ;
    DossierMedical(const DossierMedical&);
    int rechercherMedicamentParId(int id);
    void modifierMedicamentParId(int id, Medicament* nouveauMedicament);
    void supprimerMedicamentParId(int id);
    void ajouterMedicament(Medicament* medicament);
    void afficherDossierMedical();

    list<Medicament*>getMedicaments()  { return medicaments; }
};

#endif // DOSSIERMEDICAL_H_INCLUDED
