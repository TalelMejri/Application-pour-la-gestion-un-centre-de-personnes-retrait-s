#ifndef DOSSIERMEDICAL_H_INCLUDED
#define DOSSIERMEDICAL_H_INCLUDED

#include <iostream>
#include <vector>
#include "Medicament.h"

using namespace std;

class DossierMedical {
private:
    vector<Medicament*> medicaments;

public:
    DossierMedical();
    ~DossierMedical();

    void ajouterMedicament(Medicament* medicament);
    void afficherDossierMedical();

    vector<Medicament*> getMedicaments() { return medicaments; }
};

#endif // DOSSIERMEDICAL_H_INCLUDED
