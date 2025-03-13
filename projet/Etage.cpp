#include "Etage.h"
#include <iostream>
using namespace std;

Etage::Etage() : id(0), type("") {}

Etage::Etage(int idVal, string typeVal) : id(idVal), type(typeVal) {}

Etage::~Etage() {
    for (size_t i = 0; i < chambres.size(); ++i) {
        delete chambres[i];
    }
}

void Etage::ajouterChambre(Chambre* chambre) {
    chambres.push_back(chambre);
}
