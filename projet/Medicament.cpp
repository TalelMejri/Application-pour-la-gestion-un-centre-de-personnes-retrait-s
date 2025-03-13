#include "Medicament.h"

Medicament::Medicament() : id(0), nom(""), quantite(0), dateLimit{0, 0, 0} {}

Medicament::Medicament(int idVal, string nomVal, int qteVal, DATE_Med dateVal)
    : id(idVal), nom(nomVal), quantite(qteVal), dateLimit(dateVal) {}

Medicament::~Medicament() {
}

void Medicament::afficherMedicament() {
    cout << "Medicament ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Quantite: " << quantite << endl;
    cout << "Date de Limite: " << dateLimit.jour << "/" << dateLimit.mois << "/" << dateLimit.annee << endl;
}

bool Medicament::estPerime(DATE_Med dateActuelle) {
    if (dateActuelle.annee > dateLimit.annee) {
        return true;
    } else if (dateActuelle.annee == dateLimit.annee) {
        if (dateActuelle.mois > dateLimit.mois) {
            return true;
        } else if (dateActuelle.mois == dateLimit.mois) {
            if (dateActuelle.jour > dateLimit.jour) {
                return true;
            }
        }
    }
    return false;
}
