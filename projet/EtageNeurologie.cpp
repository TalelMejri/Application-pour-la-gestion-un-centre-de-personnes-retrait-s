#include "EtageNeurologie.h"


EtageNeurologie::EtageNeurologie(int id,int nbr,string type):Etage(id,type){
    nbr_chambre=nbr;
}

EtageNeurologie::EtageNeurologie():Etage(){}

EtageNeurologie::~EtageNeurologie(){}

EtageNeurologie::EtageNeurologie(const EtageNeurologie& a): Etage(a) {
     nbr_chambre=a.nbr_chambre;
}

EtageNeurologie& operator=(const EtageNeurologie&){
    if (this != &other) {
        Etage::operator=(other);
        this->nbr_chambre = other.nbr_chambre;
    }
    return *this;
}


 ostream& operator <<(ostream& os , const EtageNeurologie& etageAlz);{
    out << static_cast<const Etage&>(etageAlz);
    out << etageAlz.nbr_chambre <<" ";
}


 ostream& operator <<(ostream& os , const EtageNeurologie* etageAlz);{
    out << static_cast<const Etage*>(etageAlz);
    out << etageAlz->nbr_chambre <<" ";
}

istream& operator>>(istream& in, EtageNeurologie& etageAlz) {
    in >> static_cast<EtageNeurologie&>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz.nbr_chambre;
    return in;
}

istream& operator>>(istream& in, EtageNeurologie* etageAlz) {
    in >> static_cast<EtageNeurologie*>(etageAlz);
    cout << "Entrez le nombre de chambres ";
    in >> etageAlz->nbr_chambre;
    return in;
}


void EtageNeurologie::afficherEtage(){
      cout << "Etage Alzheimer - ID: " << Etage::getId() << endl;
        for (auto chambre : chambres) {
            chambre->afficherChambre();
        }
}







