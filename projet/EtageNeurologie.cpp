#include "EtageNeurologie.h"
#include <iostream>
#include <fstream>

using namespace std;

EtageNeurologie::EtageNeurologie(int id, int nbr, string type) : Etage(id, type) {
    nbr_chambre = nbr;
}

EtageNeurologie::EtageNeurologie() : Etage() {}

EtageNeurologie::~EtageNeurologie() {}

EtageNeurologie::EtageNeurologie(const EtageNeurologie& a) : Etage(a) {
    nbr_chambre = a.nbr_chambre;
}

EtageNeurologie& EtageNeurologie::operator=(const EtageNeurologie& other) {
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}

ostream& operator <<(ostream& os, const EtageNeurologie& etageAlz) {
    os << static_cast<const Etage&>(etageAlz);
    os << "  " << etageAlz.nbr_chambre ;
    return os;
}

ostream& operator <<(ostream& os, const EtageNeurologie* etageAlz) {
    os << static_cast<const Etage*>(etageAlz);
    os << "  " << etageAlz->nbr_chambre ;
    return os;
}

istream& operator>>(istream& in, EtageNeurologie& etageAlz) {
    in >> static_cast<Etage&>(etageAlz);
    bool isConsole = (&in == &cin);
    if (isConsole) cout << "Entrez le nombre de chambres: ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageNeurologie* etageAlz) {
    in >> static_cast<Etage*>(etageAlz);
    bool isConsole = (&in == &cin);
    if (isConsole)cout << "Entrez le nombre de chambres: ";
    in >> etageAlz->nbr_chambre;
    return in;
}

void EtageNeurologie::afficherEtage() {
    cout << "Etage Neurologie - ID: " << Etage::getId() <<" Nbr Chambre : " <<  nbr_chambre<< endl;
    for (auto chambre : chambres) {
        chambre->afficherChambre();
    }
}




