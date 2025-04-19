#include "Resident.h"
#include <iostream>
using namespace std;

Resident::Resident() : Personne(), solde(0), dossierMedical(NULL) {}

Resident::Resident(int idVal, string nomVal, string prenomVal, string emailVal, string adresseVal,
                   string telVal, string sexeVal, DATE dateNaissanceVal, float soldeInit)
    : Personne(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal){
          solde = soldeInit;
          dossierMedical = NULL;
    }

Resident::~Resident() {
    if (dossierMedical != NULL) {
        delete dossierMedical;
    }
}

void Resident::afficherPersonne() {
    Personne::afficherPersonne();
    cout << "Solde: " << solde << " dinars" << endl;
    if (dossierMedical != NULL) {
        cout << "Dossier Medical:" << endl;
        dossierMedical->afficherDossierMedical();
    } else {
        cout << "Aucun dossier medical." << endl;
    }
}

void Resident::modifier() {
    float soldeVal;
    cin>>soldeVal;
    solde=soldeVal;
    cout << "Solde modifie: " << solde << " dinars" << endl;
}
