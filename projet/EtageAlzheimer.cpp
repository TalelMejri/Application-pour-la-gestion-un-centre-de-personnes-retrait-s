#include "EtageAlzheimer.h"
#include <iostream>
#include <fstream>

using namespace std;

EtageAlzheimer::EtageAlzheimer(int id, int nbr, string type) : Etage(id, type) {
    nbr_chambre = nbr;
}

EtageAlzheimer::EtageAlzheimer() : Etage() {}

EtageAlzheimer::~EtageAlzheimer() {}

EtageAlzheimer::EtageAlzheimer(const EtageAlzheimer& a) : Etage(a) {
    nbr_chambre = a.nbr_chambre;
}

EtageAlzheimer& EtageAlzheimer::operator=(const EtageAlzheimer& other) {
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}

ostream& operator <<(ostream& os, const EtageAlzheimer& etageAlz) {
    os << static_cast<const Etage&>(etageAlz);
    os << "  " << etageAlz.nbr_chambre << " ";
    return os;
}

ostream& operator <<(ostream& os, const EtageAlzheimer* etageAlz) {
    os << static_cast<const Etage*>(etageAlz);
    os << "  " << etageAlz->nbr_chambre << " ";
    return os;
}

istream& operator>>(istream& in, EtageAlzheimer& etageAlz) {
    in >> static_cast<Etage&>(etageAlz);
    cout << "Entrez le nombre de chambres: ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageAlzheimer* etageAlz) {
    in >> static_cast<Etage*>(etageAlz);
    cout << "Entrez le nombre de chambres: ";
    in >> etageAlz->nbr_chambre;
    return in;
}

void EtageAlzheimer::afficherEtage() {
    cout << "Etage Alzheimer - ID: " << Etage::getId() << endl;
    for (auto chambre : chambres) {
        chambre->afficherChambre();
    }
}

void EtageAlzheimer::ecrirerEtageAlzheimerDansFichier(){
    try{
            ofstream of("BD\\Etage.txt", ios::app);
            of<<"EtageAlzheimer"<<" ";
            of<<this;
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}



