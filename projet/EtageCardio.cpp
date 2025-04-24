#include "EtageCardio.h"

EtageCardio::EtageCardio(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

EtageCardio::EtageCardio():Etage(){}

EtageCardio::~EtageCardio(){}

EtageCardio::EtageCardio(const EtageCardio& a): Etage(a) {
     nbr_chambre=a.nbr_chambre;
}

EtageCardio& operator=(const EtageCardio&){
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}


 ostream& operator <<(ostream& os , const EtageCardio& etageAlz);{
    out << static_cast<const Etage&>(etageAlz);
    out << etageAlz.nbr_chambre <<" ";
}


 ostream& operator <<(ostream& os , const EtageCardio* etageAlz);{
    out << static_cast<const Etage*>(etageAlz);
    out << etageAlz->nbr_chambre <<" ";
}

istream& operator>>(istream& in, EtageCardio& etageAlz) {
    in >> static_cast<EtageCardio&>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageCardio* etageAlz) {
    in >> static_cast<EtageCardio*>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz->nbr_chambre;
    return in;
}


void EtageCardio::afficherEtage(){
      cout << "Etage Alzheimer - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}




