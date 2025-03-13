#include "Responsable.h"
#include <iostream>
using namespace std;

Responsable::Responsable() : Personne() {}

Responsable::Responsable(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DATE date_naissance)
    : Personne(id, nom, prenom, cinn, email, password, tlf, date_naissance) {}

Responsable::~Responsable() {
    for (size_t i = 0; i < employes.size(); i++) {
        delete employes[i];
    }
    employes.clear();
}

void Responsable::ajouterEmploye(Personnel* employe) {
    employes.push_back(employe);
    cout << "Employé ajouté avec succès." << endl;
}

int Responsable::rechercherEmploye(int id) {
    for (size_t i = 0; i < employes.size(); i++) {
        if (employes[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

void Responsable::supprimerEmploye(int id) {
    int index = rechercherEmploye(id);
    if (index != -1) {
        employes.erase(employes.begin() + index);
        cout << "Employé supprimé avec succès." << endl;
    } else {
        cout << "Employé introuvable." << endl;
    }
}

void Responsable::afficherEmployes() {
    if (employes.empty()) {
        cout << "Aucun employé à afficher." << endl;
        return;
    }
    cout << "Liste des employés :" << endl;
     for (size_t i = 0; i < employes.size(); i++) {
        employes[i]->afficherPersonne();
        cout << "-----------------------------" << endl;
    }
}

void Responsable::modifier(int id) {
    int index = rechercherEmploye(id);
    if (index != -1) {
        employes[index]->modifier();
        cout << "Employé modifié avec succès." << endl;
    } else {
        cout << "Employé introuvable." << endl;
    }
}

