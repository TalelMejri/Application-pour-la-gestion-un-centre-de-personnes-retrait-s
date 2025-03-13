#include "Infirmier.h"
#include <iostream>
using namespace std;

Infirmier::Infirmier() : Personnel(), experience(0) {}

Infirmier::Infirmier(int idVal, string nomVal, string prenomVal, string emailVal, string adresseVal,
                     string telVal, string sexeVal, DATE dateNaissanceVal, double salaireVal, string posteVal, int experienceVal)
    : Personnel(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal, posteVal, salaireVal),
      experience(experienceVal) {}


Infirmier::~Infirmier() {
}

void Infirmier::afficherPersonne() {
    Personnel::afficherPersonne();
    cout << "Experience: " << experience << " years" << endl;
}

void Infirmier::modifier() {
    Personnel::modifier();
    cout << "Modifier l'experience de l'infirmier (en annees): ";
    cin >> experience;
    cout << "Experience mise a jour: " << experience << " ans" << endl;
}
