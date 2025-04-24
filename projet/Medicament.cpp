#include "Medicament.h"

Medicament::Medicament() : id(0), nom(""), quantite(0), dateLimit{0, 0, 0} {}

Medicament::Medicament(int idVal, string nomVal, int qteVal, DATE_Med dateVal)
    : id(idVal), nom(nomVal), quantite(qteVal), dateLimit(dateVal) {}

Medicament::~Medicament() {
}

Medicament::Medicament(const Medicament& other) {
    id = other.id;
    nom = other.nom;
    quantite = other.quantite;
    dateLimit = other.dateLimit;
}

Medicament& Medicament::operator=(const Medicament& other) {
    if (this != &other) {
        id = other.id;
        nom = other.nom;
        quantite = other.quantite;
        dateLimit = other.dateLimit;
    }
    return *this;
}

bool Medicament::operator<(const Medicament& other) {
    DATE_Med currentDate = {0, 0, 0};

    bool isCurrentExpired = estPerime(currentDate);
    bool isOtherExpired = other.estPerime(currentDate);

    if (isCurrentExpired && !isOtherExpired) {
        return true;
    }

    if (!isCurrentExpired && isOtherExpired) {
        return false;
    }

    if (dateLimit.annee < other.dateLimit.annee) {
        return true;
    } else if (dateLimit.annee == other.dateLimit.annee) {
        if (dateLimit.mois < other.dateLimit.mois) {
            return true;
        } else if (dateLimit.mois == other.dateLimit.mois) {
            return dateLimit.jour < other.dateLimit.jour;
        }
    }
    return false;
}


ostream& operator<<(ostream& os, const Medicament& m) {
    os << "Medicament ID: " << m.id << endl;
    os << "Nom: " << m.nom << endl;
    os << "Quantite: " << m.quantite << endl;
    os << "Date de Limite: " << m.dateLimit.jour << "/" << m.dateLimit.mois << "/" << m.dateLimit.annee << endl;
    return os;
}
ostream& operator<<(ostream& os, const Medicament* m) {
    os << "Medicament ID: " << m->id << endl;
    os << "Nom: " << m->nom << endl;
    os << "Quantite: " << m->quantite << endl;
    os << "Date de Limite: " << m->dateLimit.jour << "/" << m->dateLimit.mois << "/" << m->dateLimit.annee << endl;
    return os;
}

istream& operator>>(istream& is, Medicament& m) {
    cout << "Enter Medicament ID: ";
    is >> m.id;
    cout << "Enter Nom: ";
    is >> m.nom;
    cout << "Enter Quantite: ";
    is >> m.quantite;
    cout << "Enter Date de Limite (jour mois annee): ";
    is >> m.dateLimit.jour >> m.dateLimit.mois >> m.dateLimit.annee;
    return is;
}

istream& operator>>(istream& is, Medicament* m) {
    cout << "Enter Medicament ID: ";
    is >> m->id;
    cout << "Enter Nom: ";
    is >> m->nom;
    cout << "Enter Quantite: ";
    is >> m->quantite;
    cout << "Enter Date de Limite (jour mois annee): ";
    is >> m->dateLimit.jour >> m->dateLimit.mois >> m->dateLimit.annee;
    return is;
}

void Medicament::afficherMedicament() {
    cout << "Medicament ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Quantite: " << quantite << endl;
    cout << "Date de Limite: " << dateLimit.jour << "/" << dateLimit.mois << "/" << dateLimit.annee << endl;
}

bool Medicament::estPerime(DATE_Med dateActuelle) const  {
    return (dateActuelle.annee > dateLimit.annee) ||
           (dateActuelle.annee == dateLimit.annee && dateActuelle.mois > dateLimit.mois) ||
           (dateActuelle.annee == dateLimit.annee && dateActuelle.mois == dateLimit.mois && dateActuelle.jour > dateLimit.jour);
}

