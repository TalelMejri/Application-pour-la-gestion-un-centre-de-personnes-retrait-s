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


friend ostream& operator <<(ostream& os , const Etage& etage);{
    os<<"id: "<<etage.id;
    os<<"FloorNumber: "<<etage.type;
    os << static_cast <const Chambre&>(r);
    for (auto emp : r.chambre) {
        os << *emp <<" ";
    }
}

friend ostream& operator <<(ostream& os , const Etage* etage);{
    os<<"id: "<<etage->id;
    os<<"FloorNumber: "<<etage->type;
    os << static_cast <const Chambre*>(r);
    for (auto emp : r->chambre) {
        os << *emp <<" ";
    }
}


friend istream& operator>>(istream& is , const Etage& etage);{
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

friend istream& operator>>(istream& is , const Etage* etage);{
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

