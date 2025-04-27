#include "EtageCardio.h"
#include <iostream>
using namespace std;

EtageCardio::EtageCardio(int id, int nbr, string type) : Etage(id, type) {
    nbr_chambre = nbr;
}

EtageCardio::EtageCardio() : Etage() {}

EtageCardio::~EtageCardio() {}

EtageCardio::EtageCardio(const EtageCardio& a) : Etage(a) {
    nbr_chambre = a.nbr_chambre;
}

EtageCardio& EtageCardio::operator=(const EtageCardio& other) {
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}

ostream& operator <<(ostream& os, const EtageCardio& etageCardio) {
    os << static_cast<const Etage&>(etageCardio);
    os << " Nombre de chambres: " << etageCardio.nbr_chambre << " ";
    return os;
}

ostream& operator <<(ostream& os, const EtageCardio* etageCardio) {
    os << static_cast<const Etage*>(etageCardio);
    os << " Nombre de chambres: " << etageCardio->nbr_chambre << " ";
    return os;
}

istream& operator>>(istream& in, EtageCardio& etageCardio) {
    in >> static_cast<Etage&>(etageCardio);
    cout << "Entrez le nombre de chambres: ";
    in >> etageCardio.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageCardio* etageCardio) {
    in >> static_cast<Etage*>(etageCardio);
    cout << "Entrez le nombre de chambres: ";
    in >> etageCardio->nbr_chambre;
    return in;
}

void EtageCardio::afficherEtage() {
    cout << "Etage Cardio - ID: " << Etage::getId() << endl;
    for (auto chambre : chambres) {
        chambre->afficherChambre();
    }
}
