#include "ChambrePatient.h"

ChambrePatient::ChambrePatient(int id,int floor,bool Visited ):Chambre(id,floor){
    IsVisited=Visited;
}

ChambrePatient::ChambrePatient():Chambre(){}

ChambrePatient::~ChambrePatient(){}

ChambrePatient::ChambrePatient(const ChambrePatient& a):Chambre(a){
        this->IsVisited = other.IsVisited;
}

ChambrePatient::ChambrePatient& operator=(const ChambrePatient& other){
    if (this != &other) {
        Chambre::operator=(other);
        this->IsVisited = other.IsVisited;
    }
    return *this;
}

friend ostream& operator <<(ostream& out, const ChambrePatient& ChP){
    out << static_cast<const Chambre&>(ChP);
    out<<ChP.IsVisited<<" " ;
}
friend istream& operator >>(istream& in, ChambrePatient& ChP){
    in >> static_cast<Chambre&>(ChP);
    cout<<"Is it visited?; ";
    in>>ChP.IsVisited;
}
friend ostream& operator <<(ostream&, const ChambrePatient*){
    out << static_cast<const Chambre*>(ChP);
    out<<ChP->IsVisited<<" " ;
}

friend istream& operator >>(istream&, ChambrePatient*){
    in >> static_cast<Chambre*>(ChP);
    cout<<"Is it visited?; ";
    in>>ChP->IsVisited;
    }

void ChambrePatient::afficherChambrePatient(){
    Chambre::afficherChambre();
    cout<<IsVisited;
}

