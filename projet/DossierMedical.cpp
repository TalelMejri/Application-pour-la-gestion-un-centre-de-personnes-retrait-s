#include "DossierMedical.h"
#include <iostream>
using namespace std;

DossierMedical::DossierMedical() {}

DossierMedical::~DossierMedical() {
    for (auto med : medicaments) {
        delete med;
    }
    medicaments.clear();
}

DossierMedical::DossierMedical(const DossierMedical& other) {
    for (auto med : other.medicaments) {
        Medicament* copieMed = new Medicament(*med);
        medicaments.push_back(copieMed);
    }
}

DossierMedical& DossierMedical::operator=(const DossierMedical& other) {
    if (this != &other) {
        for (auto med : medicaments) {
            delete med;
        }
        medicaments.clear();

        for (auto med : other.medicaments) {
                Medicament* copieMed = new Medicament(*med);
                medicaments.push_back(copieMed);
        }
    }
    return *this;
}

void DossierMedical::ajouterMedicament(Medicament* medicament) {
    medicaments.push_back(medicament);
}

void DossierMedical::afficherDossierMedical() {
    if (medicaments.empty()) {
        cout << "Aucun medicament dans le dossier medical." << endl;
    } else {
        int i = 1;
        for (auto med : medicaments) {
            cout << "Medicament " << i++ << ":" << endl;
            med->afficherMedicament();
            cout << endl;
        }
    }
}

ostream& operator<<(ostream& os, const DossierMedical& dossier) {
    int i = 1;
    for (auto med : dossier.medicaments) {
        os << "Medicament " << i++ << ":\n" << *med << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const DossierMedical* dossier) {
    int i = 1;
    for (auto med : dossier->medicaments) {
        os << "Medicament " << i++ << ":\n" << *med << endl;
    }
    return os;
}

istream& operator>>(istream& is, DossierMedical& dossier) {
    int n;
    cout << "Combien de medicaments voulez-vous ajouter ? ";
    is >> n;
    for (int i = 0; i < n; ++i) {
        Medicament* med = new Medicament();
        cout << "Medicament " << i + 1 << ":\n";
        is >> *med;
        dossier.ajouterMedicament(med);
    }
    return is;
}

istream& operator>>(istream& is, DossierMedical* dossier) {
    int n;
    cout << "Combien de medicaments voulez-vous ajouter ? ";
    is >> n;
    for (int i = 0; i < n; ++i) {
        Medicament* med = new Medicament();
        cout << "Medicament " << i + 1 << ":\n";
        is >> *med;
        dossier->ajouterMedicament(med);
    }
    return is;
}

int DossierMedical::rechercherMedicamentParId(int id) {
    int index = 0;
    for (auto it = medicaments.begin(); it != medicaments.end(); ++it) {
        if ((*it)->getId() == id) {
            return index;
        }
        ++index;
    }
    return -1;
}

void DossierMedical::modifierMedicamentParId(int id, Medicament* nouveauMedicament) {
    int index = rechercherMedicamentParId(id);
    if (index != -1) {
        auto it = medicaments.begin();
        advance(it, index);
        *it = nouveauMedicament;
        cout << "Médicament modifié avec succès." << endl;
    } else {
        cout << "Médicament non trouvé." << endl;
    }
}

void DossierMedical::supprimerMedicamentParId(int id) {
    int index = rechercherMedicamentParId(id);
    if (index != -1) {
        auto it = medicaments.begin();
        advance(it, index);
        delete *it;
        medicaments.erase(it);
        cout << "Médicament supprimé avec succès." << endl;
    } else {
        cout << "Médicament non trouvé." << endl;
    }
}
