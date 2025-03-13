#include "MedecinInfirmier.h"

MedecinInfirmier::MedecinInfirmier()
    : Medecin(), Infirmier() {}

MedecinInfirmier::MedecinInfirmier(int idVal, string nomVal, string prenomVal, string emailVal, string adresseVal,
                                   string telVal, string sexeVal, DATE dateNaissanceVal, double salaireVal,
                                   string specialiteVal, int experienceVal)
    : Medecin(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal, salaireVal, specialiteVal),
      Infirmier(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal, experienceVal) {}

MedecinInfirmier::~MedecinInfirmier() {
}

void MedecinInfirmier::afficherPersonne() {
    Medecin::afficherPersonne();
    Infirmier::afficherPersonne();
}

void MedecinInfirmier::modifier() {
    Medecin::modifier();
    Infirmier::modifier();
}
