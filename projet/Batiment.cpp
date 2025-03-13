#include "Batiment.h"
#include <iostream>
using namespace std;

Batiment::Batiment() : nom(""), adresse("") {}

Batiment::Batiment(string nomVal, string adresseVal) : nom(nomVal), adresse(adresseVal) {}

Batiment::~Batiment() {
    for (size_t i = 0; i < etages.size(); ++i) {
        delete etages[i];
    }
    for (size_t i = 0; i < personnes.size(); ++i) {
        delete personnes[i];
    }
}

void Batiment::ajouterEtage(Etage* etage) {
    etages.push_back(etage);
}

void Batiment::ajouterPersonne(Personne* personne) {
    personnes.push_back(personne);
}

void Batiment::afficherBatiment() {
    cout << "Batiment: " << nom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Etages: " << endl;
    for (size_t i = 0; i < etages.size(); ++i) {
        etages[i]->afficherEtage();
    }
    cout << "Personnes: " << endl;
    for (size_t i = 0; i < personnes.size(); ++i) {
        personnes[i]->afficherPersonne();
    }
}

void Batiment::supprimerEtage(int id) {
    for (size_t i = 0; i < etages.size(); ++i) {
        if (etages[i]->getId() == id) {
            delete etages[i];
            etages.erase(etages.begin() + i);
            break;
        }
    }
}

void Batiment::supprimerPersonne(int id) {
    for (size_t i = 0; i < personnes.size(); ++i) {
        if (personnes[i]->getId() == id) {
            delete personnes[i];
            personnes.erase(personnes.begin() + i);
            break;
        }
    }
}
