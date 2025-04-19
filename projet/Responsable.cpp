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
    cout << "Employ� ajout� avec succ�s." << endl;
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
        cout << "Employe supprime avec succes." << endl;
    } else {
        cout << "Employe introuvable." << endl;
    }
}

void Responsable::afficherEmployes() {
    if (employes.empty()) {
        cout << "Aucun employe � afficher." << endl;
        return;
    }
    cout << "Liste des employes :" << endl;
     for (size_t i = 0; i < employes.size(); i++) {
        employes[i]->afficherPersonne();
        cout << "-----------------------------" << endl;
    }
}

void Responsable::modifier(int id) {
    int index = rechercherEmploye(id);
    if (index != -1) {
        employes[index]->modifier();
        cout << "Employ� modifi� avec succ�s." << endl;
    } else {
        cout << "Employ� introuvable." << endl;
    }
}

