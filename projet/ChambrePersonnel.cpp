#include "ChambrePersonnel.h"

    
ChambrePersonnel::ChambrePersonnel(int id,int floor,bool estquiped ):Chambre(id,floor){
    estequipee=estquiped;
}

ChambrePersonnel::ChambrePersonnel():Chambre(){}

ChambrePersonnel::~ChambrePersonnel(){}

ChambrePersonnel::ChambrePersonnel(const ChambrePersonnel& a):Chambre(a){
        this->estequipee = other.estequipee;
}

ChambrePersonnel::ChambrePersonnel& operator=(const ChambrePersonnel& other){
    if (this != &other) {
        Chambre::operator=(other);
        this->estequipee = other.estequipee;
    }
    return *this;
}

friend ostream& operator <<(ostream& out, const ChambrePersonnel& ChP){
    out << static_cast<const Chambre&>(ChP);
    out<<ChP.IsVisited<<" " ;
}
friend istream& operator >>(istream& in, ChambrePersonnel& ChP){
    in >> static_cast<Chambre&>(ChP);
    cout<<"Is it visited?; ";
    in>>ChP.IsVisited;
}
friend ostream& operator <<(ostream&, const ChambrePersonnel*){
    out << static_cast<const Chambre*>(ChP);
    out<<ChP->estequipee<<" " ;
}
friend istream& operator >>(istream&, ChambrePersonnel*){
    in >> static_cast<Chambre*>(ChP);
    cout<<"Is it visited?; ";
    in>>ChP->estequipee;
    }


void ChambrePersonnel::afficherChambrePersonnel(){
    Chambre::afficherChambre();
    cout<<estequipee;
}

