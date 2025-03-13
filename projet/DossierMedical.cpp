
#include "DossierMedical.h"
#include <iostream>
using namespace std;

DossierMedical::DossierMedical() {}

DossierMedical::~DossierMedical() {
}

void DossierMedical::ajouterMedicament(Medicament medicament) {
    medicaments.push_back(medicament);
}

void DossierMedical::afficherDossierMedical() {
    if (medicaments.empty()) {
        cout << "Aucun medicament dans le dossier medical." << endl;
    } else {
        for (size_t i = 0; i < medicaments.size(); ++i) {
            cout << "Medicament " << i + 1 << ":" << endl;
            medicaments[i].afficherMedicament();
            cout << endl;
        }
    }
}
