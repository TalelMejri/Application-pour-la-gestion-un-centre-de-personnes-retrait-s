#include "EtageCardio.h"
#include <iostream>
#include <fstream>

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

ostream& operator <<(ostream& os, const EtageCardio& etageAlz) {
    os << static_cast<const Etage&>(etageAlz);
    os << "  " << etageAlz.nbr_chambre ;
    return os;
}

ostream& operator <<(ostream& os, const EtageCardio* etageAlz) {
    os << static_cast<const Etage*>(etageAlz);
    os << "  " << etageAlz->nbr_chambre ;
    return os;
}

istream& operator>>(istream& in, EtageCardio& etageAlz) {
    in >> static_cast<Etage&>(etageAlz);
    bool isConsole = (&in == &cin);
    if (isConsole) cout << "Entrez le nombre de chambres: ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageCardio* etageAlz) {
    in >> static_cast<Etage*>(etageAlz);
    bool isConsole = (&in == &cin);
    if (isConsole)cout << "Entrez le nombre de chambres: ";
    in >> etageAlz->nbr_chambre;
    return in;
}

void EtageCardio::afficherEtage() {
    cout << "Etage Cardio - ID: " << Etage::getId() <<" Nbr Chambre : " <<  nbr_chambre<< endl;
    for (auto chambre : chambres) {
        chambre->afficherChambre();
    }
}




