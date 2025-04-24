#include "EtageAlzheimer.h"

EtageAlzheimer::EtageAlzheimer(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

EtageAlzheimer::EtageAlzheimer():Etage(){}

EtageAlzheimer::~EtageAlzheimer(){}

EtageAlzheimer::EtageAlzheimer(const EtageAlzheimer& a): Etage(a) {
     nbr_chambre=a.nbr_chambre;
}

EtageAlzheimer& operator=(const EtageAlzheimer&){
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}


 ostream& operator <<(ostream& os , const EtageAlzheimer& etageAlz);{
    out << static_cast<const Etage&>(etageAlz);
    out << etageAlz.nbr_chambre <<" ";
}


 ostream& operator <<(ostream& os , const EtageAlzheimer* etageAlz);{
    out << static_cast<const Etage*>(etageAlz);
    out << etageAlz->nbr_chambre <<" ";
}

istream& operator>>(istream& in, EtageAlzheimer& etageAlz) {
    in >> static_cast<EtageAlzheimer&>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageAlzheimer* etageAlz) {
    in >> static_cast<EtageAlzheimer*>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz->nbr_chambre;
    return in;
}


void EtageAlzheimer::afficherEtage(){
      cout << "Etage Alzheimer - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}




