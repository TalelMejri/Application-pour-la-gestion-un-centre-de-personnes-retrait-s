#include "Personne.h"

Personne::Personne() {
    id = 0;
    nom = "";
    prenom = "";
    cinn = "";
    email = "";
    password = "";
    tlf = "";
    date_naissance.jour=0;
    date_naissance.mois=0;
    date_naissance.anne=0;
}

Personne::Personne(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DATE date_naissance) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->cinn = cinn;
    this->email = email;
    this->password = password;
    this->tlf = tlf;
    this->date_naissance = date_naissance;
}

Personne::Personne(const Personne& p) {
    id = p.id;
    nom = p.nom;
    prenom = p.prenom;
    cinn = p.cinn;
    email = p.email;
    password = p.password;
    tlf = p.tlf;
    date_naissance = p.date_naissance;
}

void Personne::afficherPersonne() {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prénom: " << prenom << endl;
    cout << "CIN: " << cinn << endl;
    cout << "Email: " << email << endl;
    cout << "Téléphone: " << tlf << endl;
    cout << "Date de naissance: " << date_naissance.jour << "/" << date_naissance.mois << "/" << date_naissance.anne << endl;
}

Personne::~Personne() {
}

void Personne::saisir_personne() {
    cout << "Entrez l'ID : ";
    cin >> id;
    cin.ignore();

    cout << "Entrez le nom : ";
    getline(cin, nom);

    cout << "Entrez le prénom : ";
    getline(cin, prenom);

    cout << "Entrez le CIN : ";
    getline(cin, cinn);

    cout << "Entrez l'email : ";
    getline(cin, email);

    cout << "Entrez le mot de passe : ";
    getline(cin, password);

    cout << "Entrez le téléphone : ";
    getline(cin, tlf);

    cout << "Entrez la date de naissance (jour mois année) : ";
    cin >> date_naissance.jour >> date_naissance.mois >> date_naissance.anne;
}
