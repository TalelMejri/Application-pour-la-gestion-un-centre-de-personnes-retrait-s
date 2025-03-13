#include "Personnel.h"
#include <iostream>
using namespace std;

Personnel::Personnel() : Personne() {
    poste = "";
    salaire = 0.0;
}

Personnel::Personnel(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DATE date_naissance, string poste, double salaire)
    : Personne(id, nom, prenom, cinn, email, password, tlf, date_naissance) {
    this->poste = poste;
    this->salaire = salaire;
}

Personnel::~Personnel() {
}

void Personnel::afficherPersonne() {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prénom: " << prenom << endl;
    cout << "CIN: " << cinn << endl;
    cout << "Email: " << email << endl;
    cout << "Téléphone: " << tlf << endl;
    cout << "Date de naissance: " << date_naissance.jour << "/" << date_naissance.mois << "/" << date_naissance.anne << endl;
    cout << "Poste: " << poste << endl;
    cout << "Salaire: " << salaire << " TND" << endl;
}

void Personnel::modifier() {
    cout << "Modifier les informations du personnel:" << endl;
    cout << "Nouveau poste: ";
    cin>>poste;
    cout << "Nouveau salaire: ";
    cin >> salaire;
}
