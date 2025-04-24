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

 ostream& operator <<(ostream& os , const Etage& etage);{
    os<<" "<<etage.id;
    os<<" "<<etage.type;
    os << static_cast <const Chambre&>(r);
    for (auto emp : r.chambre) {
        os << *emp <<" ";
    }
}

 ostream& operator <<(ostream& os , const Etage* etage);{
    os<<" "<<etage->id;
    os<<" "<<etage->type;
    os << static_cast <const Chambre*>(r);
    for (auto emp : r->chambre) {
        os << *emp <<" ";
    }
}


 istream& operator>>(istream& is , const Etage& etage);{
    cout<<"id: ";
    is>>etage.id;
    cout<<"FloorNumber: ";
    is>>etage.floorNumber;
    os << static_cast <const Chambre&>(r);
    for (auto emp : r.chambre) {
        is >> *emp;
        cout <<" ";
    }
}

 istream& operator>>(istream& is , const Etage* etage);{
    cout<<"id: ";
    is>>etage->id;
    cout<<"FloorNumber: ";
    is>>etage->floorNumber;
    os << static_cast <const Chambre*>(r);
    for (auto emp : r->chambre) {
        is >> *emp;
        cout <<" ";
    }
}

Etage::Etage(const Etage& A)  {
    id=A.id;
    type=A.type;
    Chambre* p;
    for (unsigned int i = 0; i < A.chambres.size(); i++) {
        if (typeid(*A.chambres[i]) == typeid(ChambrePatient)) {
             p = static_cast<Chambre*>(new Medecin(*A.chambres[i]));
        } else if (typeid(*A.employes[i]) == typeid(ChambrePersonnel)) {
             p = static_cast<Chambre*>(new ChambrePersonnel(*A.chambres[i]));
        } else {
            p = new Chambre(*A.chambres[i]);
        }
        chambres.push_back(p);
    }
}

Etage& Etage::operator=(const Etage& e) {
    if (this != &e) {
        id=A.id;
        type=A.type;
        Chambre* p;
           for (unsigned int i = 0; i < chambres.size(); i++) {
            delete chambres[i];
        }
        chambres.clear();

    for (unsigned int i = 0; i < A.chambres.size(); i++) {
        if (typeid(*A.chambres[i]) == typeid(ChambrePatient)) {
             p = static_cast<Chambre*>(new Medecin(*A.chambres[i]));
        } else if (typeid(*A.employes[i]) == typeid(ChambrePersonnel)) {
             p = static_cast<Chambre*>(new ChambrePersonnel(*A.chambres[i]));
        } else {
            p = new Chambre(*A.chambres[i]);
        }
        chambres.push_back(p);
    }
    }
    return *this;
}
