#include "Medecin.h"


Medecin::Medecin()
    : Personne(), salaire(0.0), specialite(""), categories() {}

Medecin::Medecin(int idVal, string nomVal, string prenomVal, string emailVal, string adresseVal, string telVal, string sexeVal, DATE dateNaissanceVal, double salaireVal,
                  string specialiteVal)
    : Personne(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal), salaire(salaireVal), specialite(specialiteVal), categories() {}

Medecin::~Medecin() {
}

void Medecin::afficherPersonne() {
    Personne::afficherPersonne();
    cout << "Salaire: " << salaire << endl;
    cout << "Specialite: " << specialite << endl;
}

void Medecin::modifier() {
    cin>>salaire;
    cin>>specialite;
}

void Medecin::ajouterCategory(Category category) {
    categories.push_back(category);
}

void Medecin::afficherCategories() {
    cout << "Categories de Medecin " << nom << ":" << endl;
    for (size_t i = 0; i < categories.size(); i++) {
        cout << "Category " << i + 1 << ":" << endl;
        categories[i].afficherCategory();
    }
}

